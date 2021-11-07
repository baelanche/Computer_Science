# Scheduler

## Implementation list

1. SJF (Shortest Job First)
2. SRTF (Shortest Remaining Time First)
3. RR (Round Robin)
4. Priority
5. Priority + Aging
6. Priority + PCP (Priority Ceiling Protocol)
7. Priority + PIP (Priority Inheritance Protocol)

## struct scheduler

```.c
const char *name;

int (*initialize)(void);
/* 성공시 0 리턴, 실패시 0 의외의 수 리턴 */

void (*finalize)(void);

void (*forked)(struct process *);
/* 프로세스가 새로 fork 되면 수행한다. */

void (*exiting)(struct process *);
/* 프로세스가 exit 될 때 수행한다. */

struct process *(*schedule)(void);
/* 
다음에 run 할 프로세스를 고른다.
current 프로세스는 레디큐에 들어간다. -> current 프로세스가 레디 상태라면 다음에 run 할 프로세스를 고른다.
current 프로세스가 block 상태라면 레디큐에 다음 프로세스를 넣으면 안된다.
*/

bool (*acquire)(int);
/* resource_id 를 통해 잘 부르면 true, 점유 상태거나 부를 수 없다면 false */

void (*release)(int);
/* resource_id 를 release 한다/ */
```

## process status

* PROCESS_READY : run 할 준비가 된 상태
* PROCESS_RUNNING : 프로세스가 현재 실행중인 상태
* PROCESS_WAIT : 다른 리소스에 의해 대기중인 상태
* PROCESS_EXIT : 프로세스가 종료된 상태

## Schduler Implemetation

### 1. SJF

* task 의 처리시간이 짧은것을 우선으로 처리한다.

```.c
static struct process *sjf_schedule(void)
 {
         struct process *next = NULL;
         struct process *ptr;
         int min = 9999;

         if (!current || current->status == PROCESS_WAIT) {
                 goto pick_next;
         }
         if (current->age < current->lifespan) {
                 return current;
         }

 pick_next:
         if (!list_empty(&readyqueue)) {
                 list_for_each_entry(ptr, &readyqueue, list) {
                         if (ptr->lifespan < min) {
                                 min = ptr->lifespan;
                                 next = ptr;
                         }
                 }
                 list_del_init(&next->list);
         }
         return next;
 }
```

* 현재 실행중인 task 가 없다 -> 최소시간의 task 를 스케줄링한다.
* 현재 실행중인 task 가 있다 -> task 를 마칠때까지 계속 수행한다.

### 2. SRTF

* task 의 처리시간이 짧은것을 우선으로 처리한다.
* 새로운 task 가 도착하면 처리시간이 짧은 task 를 다시 찾는다.

```.c
static void srtf_forked(struct process *new)
 {
         if(current) {
                 if(new->lifespan < current->age+1) {
                         list_add(&current->list, &readyqueue);
                         list_del_init(&new->list);
                         current = new;
                 }
         }
 }

static struct process *srtf_schedule(void)
 {
         struct process *next = NULL;
         struct process *ptr;
         int min = 9999;

         if (!current || current->status == PROCESS_WAIT) {
                 goto pick_next;
         }
         if (current->age < current->lifespan) {
                 return current;
         }

 pick_next:
         if (!list_empty(&readyqueue)) {
                 list_for_each_entry(ptr, &readyqueue, list) {
                         if (ptr->lifespan < min) {
                                 min = ptr->lifespan;
                                 next = ptr;
                         }
                 }
                 list_del_init(&next->list);
         }
         return next;
 }
```

* 새로 들어온 task 가 있다면 현재 처리중인 task 와 remaining time 을 비교하여 짧은 task 를 선택한다.
* 현재 실행중인 task 가 없다 -> 최소시간의 task 를 스케줄링한다.
* 현재 실행중인 task 가 있다 -> task 를 마칠때까지 계속 수행한다.

### 3. RR

* 모든 task 를 특정 quantum 만큼 실행한다.
  * quantum 이 1이라면 모든 task 를 1만큼 돌아가면서 수행한다.

```.c
static struct process *rr_schedule(void)
 {
         struct process *next = NULL;

         if (!current || current->status == PROCESS_WAIT) {
                 goto pick_next;
         }

         if (current->age < current->lifespan) {
                 list_add_tail(&current->list, &readyqueue);
         }

 pick_next:

         if (!list_empty(&readyqueue)) {
                 next = list_first_entry(&readyqueue, struct process, list);
                 list_del_init(&next->list);
         }
         return next;
 }
```

* 현재 처리중인 task 가 없다면 큐의 첫번째 task 를 실행한다.
* 현재 처리중인 task 가 있다면 큐의 마지막에 집어넣고 큐의 첫번째 task 를 실행한다.

### 4. Priority

* 프로세스의 Priority 가 높으면 먼저 처리한다.
* resource acquire/release 개념이 도입되어 상위 priority 를 가진 프로세스의 처리가 하위 프로세스에게 밀릴 수 있다. (Priority Inversion)

```.c
bool prio_acquire(int resource_id)
 {
         struct resource *r = resources + resource_id;
         if (!r->owner) {
                 r->owner = current;
                 return true;
         }

         current->status = PROCESS_WAIT;
         list_add_tail(&current->list, &r->waitqueue);
         return false;
 }

 void prio_release(int resource_id)
 {
         struct resource *r = resources + resource_id;
         struct process *ptr;
         struct process *head;

         assert(r->owner == current);
         r->owner = NULL;

         if (!list_empty(&r->waitqueue)) {
                 struct process *waiter =
                                 list_first_entry(&r->waitqueue, struct process, list);
                 list_for_each_entry_safe(ptr, head, &r->waitqueue, list) {
                         if (waiter->prio < ptr->prio)
                                 waiter = ptr;
                 }
                 assert(waiter->status == PROCESS_WAIT);
                 list_del_init(&waiter->list);
                 waiter->status = PROCESS_READY;
                 list_add_tail(&waiter->list, &readyqueue);
         }
 }
static struct process *prio_schedule(void)
 {
         struct process *next = NULL;
         struct process *ptr;
         struct process *head;
         int max_prio = 0;

         if (!current || current->status == PROCESS_WAIT) {
                 goto pick_next;
         }
         if (current->age < current->lifespan) {
                 if (!list_empty(&readyqueue)) {
                         list_for_each_entry_safe(ptr, head, &readyqueue, list) {
                                 if (current->prio < ptr->prio) {
                                         list_add(&current->list, &readyqueue);
                                         current = ptr;
                                         list_del_init(&current->list);
                                 }
                         }
                 }
                 return current;
         }

 pick_next:
         if (!list_empty(&readyqueue)) {
                 list_for_each_entry_reverse(ptr, &readyqueue, list) {
                         if (ptr->prio >= max_prio) {
                                 max_prio = ptr->prio;
                                 next = ptr;
                         }
                 }
                 list_del_init(&next->list);
         }
         return next;
 }
```

1. 먼저 프로세스가 fork 된다. 이때 별도의 처리는 없다.
2. schedule() 함수가 실행된다.
   * 현재 처리중인 프로세스가 없다 : priority 가 높은 프로세스가 running 프로세스가 된다.
   * 현재 처리중인 프로세스가 있다 : 현재 프로세스보다 priority 가 높은 프로세스가 있다면 이 프로세스가 current 프로세스가 된다.
3. current 프로세스에 한해서 acquire() 함수가 실행된다.
   * 자원을 점유하는 프로세스가 없다 : 현재 프로세스가 자원을 점유한다.
   * 자원을 점유하는 프로세스가 있다 : priority 에 관계없이 이 프로세스는 대기 상태가 된다. (Priority Inversion 이 발생할 수 있다)
4. 특정 프로세스의 자원 점유가 끝나면 release() 함수가 실행된다.
   * 대기중인 프로세스 중 priority 가 가장 높은 프로세스가 자원을 점유한다.

> 여기서 기억할 것  
> list_for_each_entry() : 리스트를 순회하다가 리스트를 지우면 리스트 순회를 멈춘다.  
> list_for_each_entry_safe() : 리스트 멤버를 지워도 계속 순회한다.

### 5. Priority + Aging

* 프로세스의 Priority 가 높으면 먼저 처리한다.
* resource acquire/release 개념이 도입되어 상위 priority 를 가진 프로세스의 처리가 하위 프로세스에게 밀릴 수 있다. (Priority Inversion)
* 순서가 오지 않은 프로세스들에 한해 priority 를 점차 늘려준다.
* 새로운 프로세스가 처리되게 되면 이 프로세스의 priority 는 초기화된다.

```.c
static struct process *pa_schedule(void)
 {
         struct process *next = NULL;
         struct process *ptr;
         struct process *head;
         int max_prio = 0;
         int age = 0;

         if (!current || current->status == PROCESS_WAIT) {
                 goto pick_next;
         }
         if (current->age < current->lifespan) {
                 if (!list_empty(&readyqueue)) {
                         list_for_each_entry_safe(ptr, head, &readyqueue, list) {
                                 ptr->prio = ptr->prio + 1;
                                 if (ptr->prio > MAX_PRIO) ptr->prio = MAX_PRIO;
                                 if (ptr->prio >= max_prio) {
                                         max_prio = ptr->prio;
                                         next = ptr;
                                 }
                         }
                         if (current->prio >= next->prio) return current;
                         list_add(&current->list, &readyqueue);
                         current->prio = current->prio + 1;
                         current = next;
                         list_del_init(&next->list);
                         current->prio = current->prio_orig;
                         return current;
                 }
         }

 pick_next:
         if (!list_empty(&readyqueue)) {
                 list_for_each_entry(ptr, &readyqueue, list) {
                         ptr->prio = ptr->prio + 1;
                         if (ptr->prio > MAX_PRIO) ptr->prio = MAX_PRIO;
                 }
         }

         if (!list_empty(&readyqueue)) {
                 list_for_each_entry_reverse(ptr, &readyqueue, list) {
                         if (ptr->prio > max_prio) {
                                 max_prio = ptr->prio;
                                 age = ptr->age;
                                 next = ptr;
                         } else if (ptr->prio == max_prio) {
                                 if (ptr->age < age)
                                         next = ptr;
                         }
                 }
                 list_del_init(&next->list);
                 next->prio = next->prio_orig;
         }

         if (current && next == NULL) {
                 if (list_empty(&readyqueue) && current->age < current->lifespan)
                         return current;
                 else if (list_empty(&readyqueue) && current->age == current->lifespan) return NULL;
         }

         return next;
 }
```

1. 스케줄링 할때마다 큐의 모든 프로세스 priority 가 1씩 증가한다.
2. priority 가 증가하고 나서 현재 처리중인 프로세스와 큐의 프로세스의 priority 를 비교하여 어느 프로세스를 처리할지 결정한다.
3. 만약 큐의 프로세스 중 후보가 2개 이상이라면
   * 프로세스의 처리횟수가 같다면 큐에서 앞자리에 해당하는 프로세스를 처리한다.
   * 프로세스의 처리횟수가 다르다면 처리횟수가 적은 프로세스를 처리한다.
4. 새로운 프로세스가 current 로 선정되면 레디큐로 돌아온 프로세스의 priority 는 초기화된다.
   * 다른 프로세스의 priority 가 1 증가된 시점에 새 프로세스를 선정하므로 사실상 priority + 1 로 초기화되는 것과 같다.

레디큐에 프로세스가 없을 때의 로직이 중간과정에 잘 구현되어있지 않아 마지막에 급하게 처리해주었다. (bad code)

### 6. Priority + PCP

* priority 순으로 통상 처리한다.
* 특정 프로세스가 자원을 점유하면 priority 를 대폭 증가시켜 자원 탈취를 막는다.

```.c
bool pcp_acquire(int resource_id)
 {
         struct resource *r = resources + resource_id;
         if (!r->owner) {
                 r->owner = current;
                 current->prio = MAX_PRIO;
                 return true;
         }

         current->status = PROCESS_WAIT;
         list_add_tail(&current->list, &r->waitqueue);
         return false;
 }

void pcp_release(int resource_id)
 {
         struct resource *r = resources + resource_id;
         struct process *ptr;
         struct process *head;

         assert(r->owner == current);
         r->owner->prio = r->owner->prio_orig;
         r->owner = NULL;

         if (!list_empty(&r->waitqueue)) {
                 struct process *waiter =
                                 list_first_entry(&r->waitqueue, struct process, list);
                 list_for_each_entry(ptr, &r->waitqueue, list) {
                         if (waiter->prio < ptr->prio)
                                 waiter = ptr;
                 }
                 assert(waiter->status == PROCESS_WAIT);
                 list_del_init(&waiter->list);
                 waiter->status = PROCESS_READY;
                 list_add_tail(&waiter->list, &readyqueue);
         }
 }
 
static struct process *pcp_schedule(void)
 {
         struct process *next = NULL;
         struct process *ptr;
         struct process *head;
         int max_prio = 0;

         if (!current || current->status == PROCESS_WAIT) {
                 goto pick_next;
         }
         if (current->age < current->lifespan) {
                 if (!list_empty(&readyqueue)) {
                         list_for_each_entry_safe(ptr, head, &readyqueue, list) {
                                 if (current->prio <= ptr->prio) {
                                         list_add(&current->list, &readyqueue);
                                         current = ptr;
                                         list_del_init(&current->list);
                                 }
                         }
                 }
                 return current;
         }

 pick_next:
         if (!list_empty(&readyqueue)) {
                 list_for_each_entry_reverse(ptr, &readyqueue, list) {
                         if (ptr->prio >= max_prio) {
                                 max_prio = ptr->prio;
                                 next = ptr;
                         }
                 }
                 list_del_init(&next->list);
         }
         return next;
 }
```

1. priority 가 가장 큰 프로세스가 current 프로세스가 된다.
2. 자원을 점유하는 순간에 priority 를 대폭 증가시켜 다른 프로세스에게 탈취당하지 않도록 한다.
3. 자원 점유를 해제하는 순간에 priority 를 원래대로 돌린다.

### 7. Priority + PIP

* low priority process 가 자원을 점유하고 high priority process 가 자원을 점유하면 high's priority 를 inheritance 한다.

```.c
bool pip_acquire(int resource_id)
 {
         struct resource *r = resources + resource_id;
         if (!r->owner) {
                 r->owner = current;
                 return true;
         }

         current->status = PROCESS_WAIT;
         r->owner->prio = current->prio;
         list_add_tail(&current->list, &r->waitqueue);
         return false;
 }

void pip_release(int resource_id)
 {
         struct resource *r = resources + resource_id;
         struct process *ptr;
         struct process *head;

         assert(r->owner == current);
         r->owner->prio = r->owner->prio_orig;
         r->owner = NULL;

         if (!list_empty(&r->waitqueue)) {
                 struct process *waiter =
                                 list_first_entry(&r->waitqueue, struct process, list);
                 list_for_each_entry(ptr, &r->waitqueue, list) {
                         if (waiter->prio < ptr->prio)
                                 waiter = ptr;
                 }
                 assert(waiter->status == PROCESS_WAIT);
                 list_del_init(&waiter->list);
                 waiter->status = PROCESS_READY;
                 list_add_tail(&waiter->list, &readyqueue);
         }
 }
 
static struct process *pip_schedule(void)
 {
         struct process *next = NULL;
         struct process *ptr;
         struct process *head;
         int max_prio = 0;

         if (!current || current->status == PROCESS_WAIT) {
                 goto pick_next;
         }
         if (current->age < current->lifespan) {
                 if (!list_empty(&readyqueue)) {
                         list_for_each_entry_safe(ptr, head, &readyqueue, list) {
                                 if (current->prio < ptr->prio) {
                                         list_add(&current->list, &readyqueue);
                                         current = ptr;
                                         list_del_init(&current->list);
                                 }
                         }
                 }
                 return current;
         }

 pick_next:
         if (!list_empty(&readyqueue)) {
                 list_for_each_entry_reverse(ptr, &readyqueue, list) {
                         if (ptr->prio >= max_prio) {
                                 max_prio = ptr->prio;
                                 next = ptr;
                         }
                 }
                 list_del_init(&next->list);
         }
         return next;
 } 
 ```
 
* priority scheduling 기반으로 구현했다.
* high priority process 는 자원 점유중인 low priority process 에게 priority 를 물려준다.
* release 할 때 priority 를 반납한다.

