# Synchronization

* When threads can concurrently access and change shared variables, we say that part of code is a `critical section` and it may lead to a `lace condition`
* To make the program run correctly, we need a mechanism to `multi` threads
* A `locks` is one of such mechanisms. A correct implementation should provide `mutual exclusion` `progress`, and `bounded waiting` properties.

## Mutex Lock

* 기존 lock 과 동일한 방식으로 acquire, release 한다.
* acquire 를 실패하고 대기할때의 동작은 정의되어 있지 않다.
  * busy-wait(spinlock) : 바쁘게 대기하는 것을 일컫는다. (이전의 무한루프와 같이)
  * blocked : wait() 와 비슷하다. sleep 상태가 되어 조용히 기다린다.

> spinlock 을 busy-wait, mutex lock 을 blocked 로 설명하는 경우도 많다.  
> 그렇게 설명하지 않는 경우도 있어서, 그 절충안으로 mutex lock 은 두 경우를 모두 포함하는 개념으로 서술하겠다.

### Spinlock

![locks](https://user-images.githubusercontent.com/48989903/144698348-5afeeb7f-2bee-499a-aa1e-3cadcbfb0b62.png)

* critical section 구간이 짧다면 spinlock 을 이용하는것이 더 유리할 수 있다.
* 구현이 쉽다.
* context switch 가 일어나지 않는다.
* CPU 를 많이 사용한다.

## Semaphore

* 상태를 표현하는 정수형 변수 S 를 가진다.
  * 최대 S 개의 쓰레드는 semaphore 를 동시에 가진다.
* 두개의 operations 이 제공된다.
  * wait() : `S = S - 1` 을 수행하고, S >= 0 이 될때까지 대기한다.
    * busy-wait, blocked
  * signal() : `S = S + 1`

### Types of Semaphores

1. Binary Semaphore
   * S = 1
   * mutex lock 과 동일하다.

2. Counting Semaphore
   * S 는 2 이상
   * 여러 쓰레드들이 semaphore 안으로 들어왔을때의 synchronization 을 처리해주어야 한다.

### Problems

* code 의 영역에 semaphore 를 부여하기 때문에 어떤 variables 이 control 되는지 알기 어렵다.
* counting, control 하는 기능을 모두 가져서 이해하기 어렵다.

### Monitors

* 프로그래밍 언어가 object 수준의 접근을 synchronization 하는 컨셉 (e.g., java's synchronized)

### Condition Variables

* 쓰레드에게 발생한 event 중심으로 동작하는 컨셉
* 쓰레드들끼리 서로 흐름을 조정한다.
* condition variable 을 통해 semaphore 를 구현할 수 있고 그 반대도 가능하다.
  * 두 컨셉 모두 lock 을 기반으로 한다.
* operations
  * wait() : acquire 하겠다는 신호를 보낸다.
  * signal() : 대기중인 쓰레드에게 신호를 보낸다.
  * broadcast()(optional) : 대기중인 모든 쓰레드에게 신호를 보낸다.

### Spinlock vs Mutex lock

```.c
int widhdraw_*_lock(account, amount)
{
  pthread_*_lock(&lock);
  balance = get_balance(account);
  balance = balance - amount;
  set_balance(account, balance);
  pthread_*_lock(&lock);
  
  return balance;
}
```

* 위 예제를 spinlock 과 mutex lock 중 어느것을 이용하는 것이 좋을까?
* 정답은 알 수 없다.
* get_balance, set_balance 가 '단순' 한 로직이라면 spinlock 이 나을 것이다.
* 그러나 연산이 복잡하거나 db 와의 connection 을 열어야 한다던가 하는 경우라면 mutex lock 을 사용하는것이 훨씬 좋을 것이다.
