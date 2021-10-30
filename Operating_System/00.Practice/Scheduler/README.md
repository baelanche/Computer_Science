# Scheduler

## Implementation list

1. SJF (Shortest Job First)
2. SRTF (Shortest Remaining Time First)
3. RR (Round Robin)
4. Priority
5. Priority + Aging
6. Priority + PIP (Priority Inheritance Protocol)
7. Priority + PCP (Priority Ceiling Protocol)

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

### 5. Priority + Aging

### 6. Priority + PIP

### 7. Priority + PCP

