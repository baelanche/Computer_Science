# Synchronization

## Compiler and Synchronization

```.c
bool ready = false;
void wait(void) {
  while (ready == false)
    do_nothing();
}

void signal(void) {
  ready = true;
}
```

wait() 를 실행할 때마다 사용되는 ready 변수에 더 빠르게 접근하기위해 레지스터에 저장했다고 가정하자.
```.c
        ld    ready, &reg0
again:  bne   $reg0, false, exit
        noop
        j     again
exit:
        ...
```
컴파일러는 위 pseudo asssembly 를 통해 reg0 에 ready 의 상태를 넣어서 동작시켰다.  
어셈블리는 메모리에 접근하지 않고 동작하기 때문에 메모리에 ready = true 를 넣어도 반영되지 않는다.  
`volatile` 이라는 키워드를 활용하여 레지스터를 활용하고 싶지 않은 경우에 명시해 주어야 한다.  
(single thread 인 경우에는 아무 의미가 없는 키워드이다.)  
또 다른 경우, 컴파일러가 코드의 순서를 임의로 변경하는 것을 막기 위해 `Memory barrier` 를 사용할 수 있다.

## Classical Problems of Synchronization

1. Bounded-buffer problem
2. Readers and writers problem
3. Dining-philosophers problem

### Bounded Buffer Problem

* Producer/consumer problem 의 subproblem 이다.
  * Producer 와 consumer 가 buffer 를 공유하고 있다.
  * Producer : buffer 에 자원을 집어넣는 역할
  * Consumer : buffer 에서 자원을 빼는 역할
  * producer 와 consumer 모두 개수, 처리 속도를 알 수 없다.
  * 이런 상황에서 두 역할군 간의 발생하는 문제를 다루는 이론이다.
    * buffer 가 무제한인 unbounded, buffer 의 크기에 제한이 있는 bounded 로 나뉜다.
* producer 는 꽉 찬 buffer 에 자원을 집어넣으면 안되고, consumer 는 빈 buffer 에서 자원을 빼면 안된다.

#### sol., ring buffer

![ring_buffer](https://user-images.githubusercontent.com/48989903/144809376-cd6d3aed-73e8-41a8-bc1e-40a89313f6dc.png)

```.c
#define BUFFER_SIZE 8
struct item {...}
struct item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
```

* `in` 은 buffer 의 자원을 넣을 위치를 말한다.
* `out` 은 buffer 에서 자원을 뺄 위치를 말한다.
* `in == out` 일 때 buffer 는 비어있다.
* `((in + 1) % BUFFER_SIZE) == out` 일 때 buffer 는 꽉찬 상태이다.
* 위 로직으로 buffer 를 검증하기 때문에 실제로 쓰이는 buffer 는 7칸이 된다.

> Mutex, Semaphore 등으로 bounded buffer 를 구현할 수 있다.

### Readers-Writers Problem

* shared resource 에 여러명의 readers, writers 가 접근할 때
  * 여러명의 readers 를 허용할 수 있다.
  * 한번에 한명의 writer 만을 허용할 수 있다.

```.c
int nr_readers = 0;
Semaphore mutex = 1;
Semaphore rw = 1;

void Writer() {
  wait(&rw);
  do_write();
  signal(&rw);
}

void Reader() {
  wait(&mutex);
  nr_readers++;
  if (nr_readers == 1)
    wait(&rw);
  signal(&mutex);
  
  do_read();
  
  wait(&mutex);
  nr_readers--;
  if (nr_readers == 0)
    signal(&rw);
  signal(&mutex);
}
```

* reader 변수를 보호하기 위해 mutex 변수를 활용하였다.
* reader, writer 가 동시에 들어오는 것을 막기 위하여 rw 변수를 활용하였다.
* 위 코드에서는 reader 가 끊임없이 들어온다면 writer 의 starvation 이 일어날 수 있다.
  * writer 가 대기중이라면 더 이상의 reader 는 들어올 수 없는 등의 방식으로 해결할 수 있다.

### Dining Philosophers Problem

* shared resource 를 점유할 때 order 에 관한 문제를 일컫는다.
