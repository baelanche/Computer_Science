# Scheduling

## Multiple-Processor Scheduling

### Asymmetric multiprocessing

* Master 프로세서가 각 프로세서에 프로세스를 스케줄링하는 형태

### Symmetric multiprocessing (SMP)

* 각 프로세서가 알아서 스케줄링하는 형태
* 모든 프로세서가 공유하는 큐가 있고 각 프로세서가 가지는 개인적인 큐가 있음
* 많은 운영체제에서 사용하는 스케줄링 기법 (확장성이 좋음)

### Load Balancing

* 각 프로세서가 공평하게 일을하게 하는 기법

#### Push migration

* 주기적으로 각 프로세서들을 확인하여 오버헤드된 CPU 가 다른 CPU 에게 task 를 넘기는 방식

#### Pull migration

* idle 프로세서가 busy 프로세서의 task 를 가져오는 방식

## NUMA architecture and Scheduling

![numa](https://user-images.githubusercontent.com/48989903/139520135-1586c47e-3c59-4825-8f82-7be9d42aaf85.png)

* NUMA 아키텍처에서는 로컬메모리 액세스 속도가 월등히 빠르다.
* 다른 CPU 의 task 를 함부로 가져오면 안된다.

### Processor Affinity

* 프로세스는 현재 동작하는 프로세서에 대해 affinity 를 가지고 있다.
  * Sort affinity : 프로세스는 특정 프로세서에서 동작되지 않을수도 있다.
  * Hard affinity : 프로세스는 반드시 특정 프로세서에서 동작되어야 한다고 명시한다.

## Multicore Processors

* 코어들은 shared resource 를 가진다.
  * last level cache (LLC)
* 스케줄러는 이러한 코어 형태가 최대의 효율을 얻을 수 있게 고려해야한다.
* Multiple threads per core
  * e.g., hyperthreading in Intel 
  * memory stall 을 활용하여 메모리 검색이 진행되는 동안 다른 쓰레드에서 진행한다.

### Memory stall

* 메모리에서 데이터를 읽어오기 위해 연산을 멈추게 되는 동작

![stall](https://user-images.githubusercontent.com/48989903/144402584-2e61dd74-bf74-4dc9-a43b-3f37ec3147c3.png)

* 멀티 코어 프로세서에서는 하이퍼쓰레딩을 통해 늘 컴퓨팅하는 것처럼 동작한다.

## Algorithm Evaluation

### 1. Deterministic evaluation

* 스케줄링의 waiting, turnaround time 등을 계산을 통해 평가하는 방식
* 간단하고 빠르다.
* 간단한 예시에 적용하기 때문에 실제 컴퓨터에 적용하기는 힘들다.

### 2. Simulation

* 실제 시스템은 아니지만 그와 유사하면서 간단하게 구현한 모델을 평가하는 방식
* 비슷한 환경에서 테스트 할수는 있지만 정확하지는 않다.

### 3. Implementation

* 원본을 구현하여 평가하는 방식
* 구현이 어렵고 평가도 힘들다.

