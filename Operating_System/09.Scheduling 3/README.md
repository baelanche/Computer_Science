# Scheduling

## Multilevel Queue Scheduling

* ready queue 를 여러 큐로 분리한다.
* job 을 특색에 따라 큐에 할당한다.
* 각 큐는 자신의 스케줄링 방식을 가지고 있다.
* 큐들간의 priority 를 고려해야한다.
  * Fixed priority scheduling
    * starvation 이 발생할 수 있다.
  * Time slice
    * 각 큐는 특정한 스케줄에 필요한 CPU time 을 얻는다.

### Multilevel Feedback Queue

* priority 를 가진 여러 큐들이 존재한다.
* 큐를 모니터링하여 큐의 레벨을 조정한다.

### Example

* Q0 : RR with time quantum 8ms
* Q1 : RR time quantum 16ms
* Q2 : FCFS

![mlfq](https://user-images.githubusercontent.com/48989903/139374778-5ac1a80b-b81b-44ce-8898-0e8537b646f9.png)

* Q0 를 8ms 간 처리하였는데 생각보다 처리가 오래걸리고 배치프로세스의 형태인 것 같다.
* 큐의 레벨을 내리고 상위 큐들의 활동이 없을 때 더 오랜시간 처리를 하도록 한다.
* 그래도 오래 걸리면 다시 큐의 레벨을 내려 처리하도록 한다.

## Real-time Systems

### Soft real-time systems

* real-time 프로세스와 non-real-time 프로세스를 구분하여 관리하지만 real-time 프로세스의 deadline 을 지키는 것을 보장하지는 않는다.

### Hard real-time systems

* task 의 deadline 을 반드시 제공해야한다.

## Real-time CPU Scheduling

* 처리해야할 프로세스가 주기적으로 온다고 가정하자.
 * CPU period : p
 * CPU processing time : t
 * deadline : d
 * 0 <= t <= d <= p

![realtime](https://user-images.githubusercontent.com/48989903/139378536-e55d92e3-1b70-4cd3-af45-18d04fb959ef.png)

### Rate Monotonic Scheduling (RMS)

* rate(1/p) 를 고려하여 rate 가 높은 task 에 우선순위를 부여한다.

### Example 1

* P1 arrives at every 50 seconds, takes 20 seconds
* P2 arrives at every 100 seconds, takes 35 seconds
* P1's rate : 1/50, P2's rate : 1/100 따라서 P1 이 우선순위가 높다.

![rms1](https://user-images.githubusercontent.com/48989903/139378904-23e2f251-0463-4a44-98a0-b2f489894cf7.png)

1. P1 을 20초간 처리했다.
2. P2 를 30초간 처리한 순간에 P1 이 도착했다.
3. P1 의 rate 가 높으므로 P2 가 5초 남았지만 P1 을 먼저 처리한다.
4. P2 를 마저 처리한다.

### Example 2

* P1 arrives at every 50 seconds, takes 25 seconds
* P2 arrives at every 80 seconds, takes 35 seconds
* P1's rate : 1/50, P2's rate : 1/80, 따라서 P1 이 우선순위가 높다.

![rms2](https://user-images.githubusercontent.com/48989903/139379143-d32b62e8-a809-402e-9de3-2b7a98a9000d.png)

1. P1 을 25초간 처리했다.
2. P2 를 25초간 처리한 순간에 P1 이 도착했다.
3. P1 의 rate 가 높으므로 P2 가 10초 남았지만 P1 을 먼저 처리한다.
4. P2 의 dealine 을 맞추지 못했다.

RMS 로 스케줄링을 할 수 없다는 것은 static priority 로는 스케줄링 할 수 없다는 것을 보장한다.  
수식으로 RMS 스케줄링이 가능한지의 가능성을 알아볼 수 있다.

* CPU Utilization : process time / period
* RMS : N * (2<sup>1/N</sup> - 1)
  * 여기서 N 은 프로세스의 수이다.
  * if N = 2 then 83%
  * if N = INF then 69%
* Example 1 의 경우 CPU Utilization 이 75% 로 RMS 스케줄링이 가능할 것으로 보인다.
* Example 2 의 경우 CPU Utilization 이 93% 로 RMS 스케줄링이 불가능할 것으로 보인다.

### Earliest Deadline First (EDF)

* deadline 까지 남은 시간이 적을수록 priority 가 높다.
* dynamic priority 스케줄링이다.

### Example

* P1(p=50, t=25)
* P2(p=80, t=35)

![edf](https://user-images.githubusercontent.com/48989903/139380285-eccb7f3c-de81-4afc-ac1a-0d3a37c40e8f.png)

1. P1 을 25초간 처리했다.
2. P2 를 25초간 처리한 순간에 P1 이 도착했다.
3. deadline 이 P2 가 더 짧으므로 P2 를 마저 처리한다.
4. P1 을 20초간 처리한 순간에 P2 가 도착했다.
5. deadline 이 P1 이 더 짧으므로 P1 을 마저 처리한다.
6. P2 를 15초간 처리한 순간에 P1 이 도착했다.
7. deadline 이 P1 이 더 짧으므로 P1 이 preemption 한다.

