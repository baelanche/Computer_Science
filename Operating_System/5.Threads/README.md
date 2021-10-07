# Threads

프로세스 내에서 실행되는 흐름의 단위를 말한다.

프로세스는 프로그램을 동작하는 멋진 방식이긴 하나
* 멀티코어에서 싱글 프로세스의 이점이 없다. (한개의 코어만 사용한다)
* 새로운 프로세스를 만드는데 경제적이지 않다.
* 프로세스 간의 통신이 오버헤드를 유발한다.

프로세스는 세세한 작업을 하는데에 불리하다고 생각했고, 그것을 해결할 쓰레드라는 개념이 탄생한다.

### 싱글쓰레드

![single_thread](https://user-images.githubusercontent.com/48989903/136342872-6b25a82a-f829-4f71-bd51-a5780b2e1f6d.png)

* 하나의 프로그램 카운터를 가진다.
* 프로세스는 한번에 한개 순차적으로 명령어를 수행한다.

### 멀티쓰레드

![multi_thread](https://user-images.githubusercontent.com/48989903/136342888-33e06102-2250-4329-b4e4-0cf19a12a409.png)

* 프로세스에 여러개의 쓰레드가 있으며 각각 쓰레드가 레지스터, 스택을 가지고 동작한다.
* 하나의 쓰레드는 다른 쓰레드의 스택에 접근할 수 있다.

## so, Thread ?

* 쓰레드는 주소 공간을 공유한다.
* 쓰레드는 고유의 Thread ID, PC & SP, Stack 영역을 가진다.

---

processes vs threads

하나의 프로세스는 여러개의 쓰레드를 가질 수 있다.
프로세스는 쓰레드가 동작하는 컨테이너이다.
쓰레드는 모두 같은 주소공간을 본다.
쓰레드는 스케줄링의 단위이다.

Benefits of Multi-threading

자원 공유가 확실해진다.
처리율 향상
반응성 향상

Concurrency vs Parallelism

Concurrency

시간 축으로 봤을 때 동시는 아니지만 여러 프로세스를 함께 처리

Parallelism

한 개 이상의 task 를 동시에 처리

Types of Parallelism

Data parallelism



Task parallelism

Amdahl's Law

parallelism 하게 처리할 수 있는 부분이 부분적으로 있을 수 있다.

Multithreading Models

Kernel threads
* 운영체제를 관리하는 
User threads

One-to-One Multithreading Model

