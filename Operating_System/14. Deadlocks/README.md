# Deadlocks

#### Conditions for Deadlock
* Mutual exclusion : 오직 한개의 task 가 resource 를 사용할 수 있다.
* Hold and wait : 하나의 resource 를 점유하는 task 가 다른 resource 를 점유하려다 기다리게 된다면 현재의 resource 는 잡은채로 기다린다.
* No preemption : resource 를 점유하고 있다면 다른 task 가 점유할 수 없다.
* Circular wait : task 의 관계 그래프를 그렸을 때 원형 모양으로 그려지게 된다.

## Strategies for Handling Deadlocks

* Deadlock prevention
* Deadlock avoidance
* Deadlock detection and recovery
* Ignoring deadlock

### Deadlock Prevention

Deadlock 은 위의 4가지 조건을 모두 만족했을때 발생할 수 있으므로 하나의 조건을 예방하여 방지할 수 있다.
* Mutual exclusion : sharable resource 를 사용한다.
* Hold and wait : 순차적으로 여러개의 resource 를 요구할 때, 하나의 resource 점유를 실패한다면 모두 반납하고 처음부터 다시 시도한다.
  * 구현하기 쉽다.
  * 자원 이용률이 낮다.
  * starvation 이 발생할 수 있다.
* No preemption : preemption 이 가능하게한다. (resource 에 따라 non-preemption 을 요구하는 경우가 있기 때문에 좋은 방법은 아니다)
* Circular wait : 모든 resource 에 순서를 부여하고 반드시 낮은 순서에서 높은 순서로만 점유할 수 있게 한다. (total ordering)

### Deadlock Avoidance

* deadlock 이 발생하였거나 unsafe state 인 resource 를 이용하지않고 safe state 인 resource 만 사용한다.

> ### safe state  
> resource 를 어떠한 순서로 할당하고 deadlock 을 피할 수 있는 상태를 말한다.  
> 즉, 어떤 task 가 요구한 resource 들을 만족시켰고 이러한 task 가 적어도 한개 이상인 경우이다.

![safe_state](https://user-images.githubusercontent.com/48989903/144836611-56467d7f-9638-4c13-8648-f71d26f335c3.png)

> 좌측이 시스템에서 제공할 수 있는 resource 이고 각 프로세스가 2,2,3 개의 resource 를 요구하고 있는 상황이다.  
> resource 를 P0 혹은 P1 에게 주면 해당 프로세스는 task 처리가 가능하므로 safe state 가 유지된다.  
> 만약 P2 에게 resource 를 할당한다면 완료되는 프로세스가 없으므로 deadlock, 즉 unsafe state 가 된다.

* 각 task 가 몇개의 resource 를 요구하는지를 알아야 하므로 구현하기 어렵다.

### How to find safe state?

![res_allo](https://user-images.githubusercontent.com/48989903/144854608-da06b27e-6b85-43c6-843e-95cbbb5c643c.png)

#### 1. Resource-Allocation Graph Algorithm
  * no cycle : no deadlock
  * cycle
    * resource 의 instance 가 1개 : deadlock
    * resource 의 instance 가 여러개 : deadlock 의 가능성이 있음
#### 2. Banker's Algorithm
  * process 들은 여러 타입의 resource 를 원한다.
  * process 가 resource 를 요구하는 매 순간 safe 한지 확인한다.

![banker1](https://user-images.githubusercontent.com/48989903/144857998-de711389-0b04-4152-912c-d5058b9ca179.png)

* P1 에서 (1, 0, 2) 의 resource 를 요구하였을때 safe 한지 판단한다.

![banker2](https://user-images.githubusercontent.com/48989903/144858113-cd41eb88-1ceb-4cc9-82ac-519348f4c67e.png)

* 남은 resource (2, 3, 0) 으로 P1 의 task 를 끝마칠 수 있으므로 safe 하다. 따라서, 할당하여도 괜찮다.

### Deadlock Recovery

* 거의 사용하지 않는다고 보아도 무방하다.

### Ignoring Deadlock

* 일부 핵심적인 시스템을 제외하고는 실제로 deadlock 을 무시하는 방식으로 운영체제가 구현되어 있다.
* avoidance 의 기법을 적용하기엔 overhead 가 있다.
* 운영체제보다 하위 시스템에서 deadlock 이 안 일어나도록 설계하기를 권장한다. (소프트웨어 등)
