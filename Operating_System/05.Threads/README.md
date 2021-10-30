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

### so, Thread ?

* 쓰레드는 주소 공간을 공유한다.
* 쓰레드는 고유의 Thread ID, PC & SP, Stack 영역을 가진다.

## processes vs threads

* 하나의 프로세스는 여러개의 쓰레드를 가질 수 있다.
* 프로세스는 쓰레드가 동작하는 컨테이너이다.
* 쓰레드는 모두 같은 주소공간을 본다.
* 쓰레드는 스케줄링의 단위이다.

### Benefits of Multi-threading

* 자원 공유가 확실해진다.
* 처리율 향상 (overlapping)
* 반응성 향상 (concurrent events)

## Concurrency vs Parallelism

### Concurrency

![concurrency](https://user-images.githubusercontent.com/48989903/136529791-b2e5cc87-48a9-4e60-9825-934d75e525b1.png)

시간 축으로 봤을 때 동시는 아니지만 여러 프로세스를 함께 처리  
사람이 인지할 때는 동시와 다름이 없다.

### Parallelism

![parallelism](https://user-images.githubusercontent.com/48989903/136529809-e389ced7-e499-4397-be21-d46e1698f8e0.png)

한 개 이상의 task 를 동시에 처리  
물리적으로 동시에 처리하는 방식을 말한다.

#### Parallelism 이 없는 Concurrency 는 있지만 반대인 경우는 없다.

## Types of Parallelism

### Data parallelism

배열의 데이터를 모두 더해야 한다면 배열을 partitioning 하여 동시에 같은 operation 을 적용하면 된다.  
이런 경우를 data parallelism 이라 한다.

### Task parallelism

쓰레드를 분산하여 각각 다른 operation 을 수행할 경우를 말한다.

## Amdahl's Law

* S : serial
* N : processing cores

![amdahl](https://user-images.githubusercontent.com/48989903/136529901-d88fc2dc-a43c-4f5f-b63a-a657b8e9e62f.png)

parallel 하게 처리할 수 없는 부분이 부분적으로 있을 수 있다.  
이 때의 speed up 은 위에 나온 식대로 구한다.

e.g., A program is comprised of 40% serial part, 60% of parallel part, and two threads.
  * 1 / (0.4 + 0.6/2)

## Multithreading Models

#### Kernel threads
* 운영체제를 관리하고 돕는 역할 
* 스케줄링의 단위
#### User threads
* 유저 레벨의 쓰레드 라이브러리에서 만들어지고 관리되는 쓰레드

### One-to-One Multithreading Model

![onetoone](https://user-images.githubusercontent.com/48989903/136531549-ff4c1e3a-535f-46f3-a081-d06518b20d14.png)

* 유저 쓰레드와 커널 쓰레드가 일대일로 매핑되는 모델
* 유저 쓰레드 하나를 만들면 커널 쓰레드가 하나 만들어진다.
* 쓰레드의 context switch 가 상대적으로 부담스럽다.
* Many-to-One 모델보다 concurrency 하다.

### Many-to-One Multithreading Model

![manytoone](https://user-images.githubusercontent.com/48989903/136532441-fbe0ce9c-942d-4407-ac00-113f8d3f8067.png)

* 커널 쓰레드 한개에 많은 유저 쓰레드를 매핑하는 모델
* 커널 쓰레드 한개에 매핑된 유저 쓰레드들은 context switch 를 가볍게 할 수 있다.
* 스케줄링 대상이 커널 쓰레드이기 때문에 유저 쓰레드를 parallel 하게 동작시킬 방법이 없다. (concurrency 할 수는 있다)
* 하나의 쓰레드가 block 되면 모든 쓰레드가 block 된다.

### Many-to-Many Multithreading Model

![manytomany](https://user-images.githubusercontent.com/48989903/136534305-3432e773-4ffa-4cf9-8b13-8639a5ad75a3.png)

#### Two-level model

![twolevel](https://user-images.githubusercontent.com/48989903/136534365-649b0f2f-615d-4699-aa3e-cd1844943f31.png)

일대일 매핑 모델이 M:M 모델과 함께 있는 것을 말한다.

## Thread Libraries

쓰레드 라이브러리를 통해 유저가 쓰레드를 만들고 관리할 수 있다.

### Pthreads (POSIX Threads)

```.c
int pthread_create (pthread_t *tid, pthread_attr_t *attr, void *(start_routine)(void *), void *arg);
```
```.c
void pthread_exit (void *retval);
```
```.c
int pthread_join (pthread_t tid, void **thread_return);
```
