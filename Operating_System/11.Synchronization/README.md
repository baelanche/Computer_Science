# Synchronization

* 쓰레드는 address space 를 공유한다.
* 따라서 한 쓰레드가 변수의 값을 변경하면 다른 쓰레드도 그 값을 보게된다.
* 만약 두개의 쓰레드가 같은 변수의 값을 동시에 변경하면 어떻게 될까?

### e.g., 계좌에서 돈 인출하기

* 서로 다른 ATM 에서 20만원이 있는 같은 계좌에 동시에 접근하여 돈을 인출한다.
* 'A' ATM 에서 계좌에서 5만원을 뺀 값을 계좌에 대입하는 순간 'B' ATM 에서 preemtion 한다.
* 계좌 잔액상태가 아직 20만원 이기 때문에 'B' ATM 에서 5만원을 인출하고 현재 계좌 잔액에 15만원을 대입한다.
* 'A' ATM 에서도 마찬가지로 현재 계좌 잔액에 15만원을 대입한다.

## Synchronization Problem

* 둘 이상의 쓰레드가 공유 메모리에 동시에 접근하여 고치면 race condition 이 발생한다.
* 결과값을 예상할 수 없게 된다.
* 디버깅이 어렵다. (불확정성의 원리 - Heisenbugs)
* concurrency 를 제어하는 것이 synchronization 이다.

## Locks

* 두가지 함수를 통해 기능을 제공한다.
  * void acquire() : lock 이 free 될 때까지 기다리고, free 가 되면 lock 을 잡는다.
  * void release() : unlock 하고 대기중인 thread 가 acquire() 한다.

* Correctness
  * Multual exclusion : lock 을 잡으면 그 단위(구간/함수)는 하나의 쓰레드만 동작할 수 있다.
  * Progress : 아무도 lock 을 잡지않은 critical section 에 대해서, 쓰레드가 lock 을 시도하면 점유할 수 있다.
  * Bounded waiting : acquire() 한 후 대기중인 쓰레드는 언젠가 lock 을 점유할 수 있다.

### Initial Attempt

```.c
void acquire(struct lock *l) {
  while (l->held)
    l->held = 1;
}

void release(struct lock *l) {
  l->held = 0;
}
```

* 멀티쓰레드 환경에서 쓰레드가 acquire 을 동시에 실행한다면 이전 예시와 마찬가지로 synchronization 이 적절히 일어나지 않는다.

### Second Attempt

```.c
int interested[2] = {FALSE, FALSE};
void acquire(int my_id) {
  int other = 1 - my_id;
  interested[my_id] = TRUE;
  while (interested[other]);
}

void release(struct lock *l) {
  interested[my_id] = FALSE;
}
```

* 이 예제 역시 두 쓰레드가 동시에 실행된다면 적절히 수행되지 않는다.

### Peterson's Algorithm

```.c
int turn;
int interested[2] = {FALSE, FALSE};
void acquire(int my_id) {
  int other = 1 - my_id;
  interested[my_id] = TRUE;
  turn = other;
  while (interested[other] && turn == other);
}

void release(struct lock *l) {
  interested[my_id] = FALSE;
}
```

* T0, T1 이 있고 T0 가 근소한 차이로 먼저 실행됐다고 가정하자.
* T0 : interested = {TRUE, TRUE}, other = 1
* T1 : interested = {TRUE, TRUE}, other = 0
* T0 : whlie (interested[1] = true && turn = 0 == other = 1), 거짓이므로 lock 을 건다.
  * 근소하게 늦게 실행한 T1 이 turn = 0 을 대입하기 때문이다.
* T1 : while (interested[0] = true && turn = 0 == other = 0), 참이므로 기다린다.
* T0 가 release 하면 T1 의 while 이 (false && true) 가 되면서 lock 을 건다.

두개의 쓰레드에 한해서 synchronization 이 정상적으로 동작한다.

## Synchronization Hardware

* 하드웨어의 도움없이 소프트웨어 만으로 lock 을 구현하는 것은 거의 불가능하다.

### Disabling Interrupts

* interrupt 를 꺼버림으로써 synchronization 을 도울 수 있다.
  * critical section 실행 시 발생할 수 있는 context switch 를 꺼버림으로써 하나의 쓰레드가 수행을 먼저 마칠 수 있게 한다.
* user 가 컴퓨터에 영향을 줄 수 있는 interrupt 를 무시하게 설계할 수는 없다.
* 그렇다고 하드웨어에서 모든 interrupt 를 껐다가 켜게 하는 것은 엄청난 overhead 발생이다.
* 따라서 이 방식은 운영체제 내에서 제한적인 용도로 밖에 사용되지 않는다.

### Test-And-Set

* Atomic instruction : read-modify-write
* Test-And-Set instruction : read-modify-write -> simultaneously
* 새 값을 대입하고 이전값이 읽힌다.

```.c
struct lock {int held = 0;}
void acquire(struct lock *l) {
  while (TestAndSet(&l->held, 1));
}

void release(struct lock *l) {
  l->held = 0;
}
```

* TestAndSet(&l->held, 1); : &l->held 에 1을 대입하고 이전 값을 리턴한다.
* T0, T1 이 동시에 실행됐으며 T0 가 근소하게 빨리 처리된다고 가정하자.
* T0 : &l->held 에 1을 대입하고 리턴으로 기본값인 0을 받는다. false 를 리턴받으므로 다음 라인을 수행한다.
* T1 : &l->held 에 1을 대입하고 리턴으로 T0 가 대입한 1을 받는다. true 를 리턴받으므로 중지한다.
* T0 가 release 하면 T1 은 &l->held 에 1을 대입하고 리턴으로 T0 가 다시 대입한 0을 받는다. false 를 리턴받으므로 다음 라인을 수행한다.

### Compare-And-Swap

* 특정 변수에 대해 expect, new 값을 대입한다.
* 변수가 expect 와 같다면 new 값을 대입하고 old value 를 리턴한다. expect 와 다르면 old value 를 리턴한다.
* 이 과정이 한번에 일어난다. (컴퓨터 회로를 통해 하나의 instruction 으로 구현한다.)

```.c
void acquire(struct lock *l) {
  while (CompareAndSwap(&->held, 0, 1));
}
```

