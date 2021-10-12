# Threads

## Implicit programming

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
