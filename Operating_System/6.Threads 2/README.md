# Threads

## Implicit 

### 1. Thread Pools

* 쓰레드를 사용하기 편리하게 하기 위한 라이브러리이다.
* 쓰레드들이 모여있는 공간을 일컫는다.

![thread_pool](https://user-images.githubusercontent.com/48989903/136952820-1faf9a51-c46f-4f2e-b810-bac03163a805.png)

1. Task Queue 에서는 새로운 request 를 받는다.
2. dispatcher 는 일이 없는 thread 를 시켜 task 를 처리한다.
3. 완료된 task 는 Completed Tasks 로 이동한다.

### 2. Fork Join

![fork_join](https://user-images.githubusercontent.com/48989903/136953971-03887919-b161-42a1-9eae-9d47d1e4bc42.png)

* 멀티쓰레드 모델이다.
* 부모 쓰레드는 한개 혹은 그 이상의 자식 쓰레드를 만든다.
* 여러 층으로 구성될 수 있다.

### 3. OpenMP

* 컴파일러를 통해 멀티 프로세스를 지원하는 API 이다.

#### example

```.c
#pragma omp parallel
{
  printf("I am a parallel region.");
}

#pragma omp parallel for
for (i = 0; i < N; i++) {
  c[i] = a[i] + b[i];
}
```

#pragma ~ 라고 적어주면 컴파일러가 쓰레드를 코어의 개수만큼 만들어서 parallel 하게 처리한다.

## Issue in Threads

### fork() and exec()

쓰레드가 5개인 프로세스가 있다고 하자. 이 프로세스를 fork 하면,
1. 쓰레드 5개인 프로세스가 만들어진다.
2. fork 를 부른 쓰레드 하나가 새 프로세스를 관리한다.

둘 중 정답은 없다.  
UNIX 에서는 1번 : fork(), 2번 : fork1() 으로 처리하였다.

그렇다면 1번과 같은 멀티쓰레드 상태일때 exec() 를 호출하면 어떻게 될까?  
보통의 운영체제에서는 자원을 모두 날려버리고 쓰레드를 한개만 남긴다.

### Signal Handling

하나의 프로세스에 쓰레드가 4개 있다. 그 프로세스에 signal 을 보냈을 때, 어떤 쓰레드가 이것을 처리해야 할까?  
쓰레드에는 어떤 signal 을 받을지에 대해 masking 처리가 되어있다. 해당 signal 을 받겠다는 쓰레드가 여러개라면  
아무 쓰레드에나 넘겨준다.

### Thread Cancellation

* #### Asynchronous cancellation
  * 쓰레드를 종료하라는 명령을 받자마자 즉시 종료하는 경우
  * 이 방식으로는 쓰레드의 자원을 깔끔하게 해제 시키기에는 무리가 있다.
  
* #### Deferred cancellation
  * 좀 더 선호되는 안정된 방법이다.
  * 쓰레드를 종료하라고 직접 명령하지 않고 marking 을 해놓는다.
  * 쓰레드는 cancel 할 수 있을 때마다 주기적으로 marking 을 확인하여 종료/진행 한다.
  * cancellation point 는 대부분 pthread 관련 함수이다. (man pthread_cancel)

### Thread-Local Storage (TLS)

멀티 쓰레드 환경에서 쓰레드는 자원을 공유한다. 따라서 전역변수를 공유하게 되고 A 쓰레드에서 전역변수의 값을 수정하면  
B 쓰레드에서도 수정된 값을 사용하게 된다. 전역변수와 같은 위치에 TLS 변수를 선언하면 값은 공유하지 않고 사용할 수 있다.

#### Global variable
```.c
int global_var = 0;
__thread int TLS_var = 0;
```

#### Thread A
```.c
global_var = 11;
TLS_var = 12;
```

#### Thread B
```.c
global_var = 21;
TLS_var = 22;
```

각 쓰레드에서 변수를 출력해보면 global_var 는 때에 따라서 11 이 될수도 21 이 될수도 있지만,
TLS_var 는 쓰레드 내부에서 선언한 값으로 유지된다.

* Ease to use per-thread variables without worrying about synchronization
* Handling errno value
  * 함수 실행 실패시 반환되는 error number 를 정확하게 반환해주는데 유용하다.

### Threads in Linux

리눅스에서는 모든 executing context 는 task 형태로 abstract 된다.  
만약 두개의 task 가 주소 공간을 공유한다면 같은 프로세스에 속하는 thread 라 볼 수 있고
서로 다른 주소 공간을 보고있다면 다른 프로세스라 할 수 있다.
