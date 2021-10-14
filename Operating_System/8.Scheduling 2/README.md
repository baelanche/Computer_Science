# Scheduling

## Goals

* 시스템은 각자 그들의 목적이 다르다.
* 일반적으로 아래 항목들을 고려한다.
  * No starvation
  * Fairness
  * Balance
* Batch systems : throughput, CPU 사용률
* Interative systems : Response time

### Criteria

* #### Maximize
   * CPU utilization
   * Throughput
* #### Minimize
   * Turnaround time : 프로세스를 끝내는데 걸리는 시간
   * Waiting time  : 프로세스 실행 중 대기하는 시간
   * Response time : 프로세스를 시작하는데 걸리는 시간

## Non-preemptive & Preemptive

* Non-preemptive (비선점형)
  * 스케줄러가 해당 job 이 실행을 종료할 때까지 기다리는 방식이다.

* Preemptive (선점형)
  * 스케줄러가 강제로 context-switch 를 하는 방식이다.

## FCFS/FIFO

* First-Come, First-Served
  * 큐에 도착한 순서대로 스케줄링 한다.
  * Non-preemptive
  * no starvation

* Problems : Convoy effect 
  * large process 뒤에 small process 가 온다면 평균 turnaround time 이 커진다.

### 1

![fcfs1](https://user-images.githubusercontent.com/48989903/137281274-ff26d1a7-3bb7-4df2-8464-5d0dc4457794.png)

* Turnaround time : P1(24), P2(27), P3(30)
  * avg : 17
* Waiting time : P1(0), P2(24), P3(27)
  * avg : 27

### 2

![fcfs2](https://user-images.githubusercontent.com/48989903/137281714-10ff19cd-e3c8-4a45-94e5-8b29d8419a50.png)

* Turnaround time : P2(3), P3(6), P1(30)
  * avg : 13
* Waiting time : P2(0), P3(3), P1(6)
  * avg : 3

2 번의 경우가 효율이 훨씬 좋다.

## SJF

* Shortest Job First
  * 가장 실행시간이 적은 job 을 먼저 실행한다.
  * 가장 적은 waiting time 을 보장한다.
  * Non-preemptive
  * Priority scheduling : 동시에 job 이 도착하면 실행시간이 짧은 job 에게 우선순위를 부여한다.

* Problems
  * Can potentially starve : 언제 처리될지 알수가 없다.
  * job 을 처리하는데 얼마나 걸리는지 알 수 없다.
 
 <br/>
 
 > ### Starvation  
 > 다른 job 들이 처리를 필요로 하여서 특정 job 이 처리를 못받는 상황

<br/>

![sjf1](https://user-images.githubusercontent.com/48989903/137283518-657ea526-b6e0-48ce-a6c7-14cb97eccba0.png)

* Turnaround time : P2(2), P3(7), P1(30)
  * avg : 13
* Waiting time : P2(0), P3(2), P1(7)
  * avg : 3

## SRTF

* Shortest Remaining Time First
  * SJF 의 preemptive 버전
  * job 이 도착할 때마다 현재 남은 runtime 이 가장 짧은 job 을 스케줄링 하는 방식

![srtf](https://user-images.githubusercontent.com/48989903/137290331-6a396d4a-0489-41f7-aed3-880e40f02a85.png)

1. P1 을 처리한다.
2. P1 이 6만큼 남은 시점에 runtime 이 4인 P2 가 들어와서 P2 를 처리한다.
3. P3 가 들어왔지만 P2 의 remain time 이 짧으므로 그대로 진행한다.
4. remain time 이 짧은 순서대로 진행한다.

* Turnaround time : 17, 4, 22, 5
  * avg : 12
* Waiting time : 0, 0, 13, 0, 9
  * avg : 5.5

## Priority Scheduling

* 각 job 은 priority 를 가지고 있다.
* CPU 는 priority 가 높은(낮은) job 부터 처리한다.
  * preemptive 일수도 non-preemptive 일수도 있다.

![priority](https://user-images.githubusercontent.com/48989903/137291468-2b3403e0-3b37-49b9-a31f-be9ebecca377.png)

* Starvation solution : Aging, priority boosting
  * job 의 대기시간이 길어길수록 priority 를 올려주는 방법

## Priority Inversion

![inversion](https://user-images.githubusercontent.com/48989903/137302910-cb4e5334-5d82-45b2-a6c1-15942a5460d3.png)

* 여러 task 를 동시에 처리하지 못하는 시스템이 있다고 하자.
* lower-priority task 가 resource 를 lock 했다.
* higher-priority task 가 resource 를 필요로한다. (low-priority task 의 일이 끝날때까지 block 될 것이다)
* intermediate-priority task 가 preemption 하였다.
* intermediate-priority task 가 higher-priority task 보다 높은 우선순위를 가진 모습이 되었다.
* 일반적으로 priority-based 한 스케줄링에서 발생할 수 있다.

### Solution for Priority Inversion

![inversion_solution](https://user-images.githubusercontent.com/48989903/137302988-099a2cdb-5275-4ec9-9351-c2004ea70e94.png)

#### * Priority Inheritance Protocol(PIP)
  * high-priority task 의 priority 를 low-priority task 에게 줌으로써 inversion 방지
  * resource 를 점유한 low-priority task 는 task 가 종료되면 priority 를 반환한다.

#### * Priority Ceiling Protocol(PCP)
  * shared resource 를 점유한 시점에 그 task 의 priority 를 대폭 늘림으로써 inversion 방지
  * priority 를 얼마나 늘려야할지 애매하다는 단점이 있다.
