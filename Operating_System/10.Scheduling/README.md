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

## NUMA architectur and Scheduling

![numa](https://user-images.githubusercontent.com/48989903/139520135-1586c47e-3c59-4825-8f82-7be9d42aaf85.png)

* NUMA 아키텍처에서는 로컬메모리 액세스 속도가 월등히 빠르다.
* 다른 CPU 의 task 를 함부러 가져오면 안된다.

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

