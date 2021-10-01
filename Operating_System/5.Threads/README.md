# Threads

멀티쓰레드 : 각각 쓰레드가 레지스터, 스택을 가지고 동작한다.

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

