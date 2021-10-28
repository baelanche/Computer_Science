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

### 2. SRTF

### 3. RR

### 4. Priority

### 5. Priority + Aging

### 6. Priority + PIP

### 7. Priority + PCP

