# Introduction to Operating Systems

* Operating System
* Computer Architecture

## Operating System?

* 유저와 컴퓨터 하드웨어 사이를 중재하는 역할을 하는 '프로그램'을 말한다.  
`하드웨어 : 기본적인 컴퓨터 동작을 하는 자원이나 기기를 말한다. ex) CPU, 메모리, 입출력기기`

* 하드웨어 자원을 제어하고 조정한다.

### What operating systems do?

* 프로그램을 실행하고 문제 해결에 도움을 준다.
* 컴퓨터를 편안히 사용가능하게 한다.
* 두가지 관점에서 정의할 수 있고 다음과 같다.
  * Application/user 관점
  
    * 자원 관리를 하지 않고도 좋은 성능을 낼 수 있게한다.
    * 쉬운 사용방법을 제공한다.
    * 컴퓨터 시스템 기반의 관점을 사용자에게 제공한다.
      * 프로세서 -> 프로세스, 쓰레드
      * 메모리 -> 가상 메모리 주소 공간
      * 저장소 -> 용량, 디렉토리, 파일
      * 입출력기기 -> 파일(입출력제어)
      * 네트워크 -> 파일(소켓, 파이프)

  * System 관점
    
    * 많은 사용자가 참여하는 애플리케이션을 다룬다.
    * 자원 관리의 역할을 한다.
      * CPU, 메모리, 입출력기기, 전력 등을 다룬다.
    * 프로그램을 관리한다.
      * 에러를 예방하고 컴퓨터의 부적절한 사용을 방지한다.

## Computer system architecture

현존하는 모든 컴퓨터는 폰노이만 아키텍처의 컴퓨터이다

초기의 컴퓨터 ENIAC 같은 경우는 입력과 출력에 대한 배선 연결이 무수히 많이 되어있었다.  
hardware 적 프로그래밍의 영역이다. flexible 하지 않다. 새로운 작업을 하려면 하드웨어적인 작업을 해야한다.  
칩과 선을 이용한 카운터, 가산기 등이 그 예이다.

폰노이만 아키텍처
CPU / memory 가 따로 존재
  * CPU는 memory로 부터 instruction을 가져와서 처리한다
  * 복잡한 배선이 CPU안에 다 내장되어 있다
  * 계산 결과를 다른 장치에 전달한다

---

CPU(Central Processing Unit)
* A.k.a. processor
* Most systems use a general-purpose processor - 일반컴퓨터라고 보면됨(intel i5, i7, ..., AMD, xeon, ...)
  * Has a flexibility to solve general problems
* But may have special-purpose processors as well
  * Also called as hardware accelerators
  * A device as a processor specialized to the devie's task
    * GPU (Graphic Processing Unit)
    * TPU (Tensor Processing Unit) for machine learning

프로세서가 하나인 컴퓨터는 이제는 거의/아예 없다(듀얼코어, 쿼드코어, ...)  
CPU는 전기를 써서 동작하는데 물리적인 열이 발생하게 된다.  
칩의 크기는 작아지고 처리하는 양은 많아지면서 CPU의 열이 과도하게 발생하게 되었다. (CPU로 계란후라이를 만드는 영상이 실제로 존재한다)  
때문에 전력은 유지하면서 전압을 낮추는 방식으로 개선하기 시작했다.  
하지만 어느순간부터 더 이상 전압을 낮추면 전류가 새어버리는 지점에 도달했고, 이 방법을 더이상 사용하기는 어려워졌다.  
이 현상을 전력 장벽(Power Wall)이라 한다.  
코어의 개수를 늘려가면서 성능을 올리는 방식으로 다시 바뀌게 되었다.


Multiprocessor Systems
* Systems with multiple processors
* A.k.a. parallel systems
  * Increased throughout
  * Economy of scale: Shared common resources(e.g.,files)
  * Increased reliability: Graceful degradation or fault tolerance

Multiprocessor Systems Classification
* Asymmetric Multiprocessing
  * Each processor is assigned a specific task (Boss-worker relationship)
* Symmetric Multiprocessing(SMP) - conventional computer
  * Each processor performs all tasks
* Single-chip multiprocessor(multicore)
  * Has multiple(usually symmetric) cores in a chip
  * Can leverage shared resources and short distances between cores
  * on-chip shared resource 를 코어들이 공유하면서 성능이 더 좋아짐

Uniform Memory Access architecture vs Non-Uniform Memory Access architecture

UMA : 모든 프로세서가 단일 메모리를 사용, 동일한 메모리 액세스 시간/속도
NUMA : 각 프로세서가 전용 메모리에 연결, 단일 주소 공간, 메모리 액세스 시간은 프로세서가 배치되는 거리에 따라 달라짐

UMA vs NUMA

UMA 아키텍처는 메모리에 액세스하는 프로세서에 대해 동일한 전체 대기 시간을 제공합니다. 
대기 시간이 일정하기 때문에 로컬 메모리에 액세스 할 때는 그리 유용하지 않습니다. 
반면 NUMA에서는 각 프로세서에 전용 메모리가있어 로컬 메모리에 액세스 할 때 대기 시간이 필요하지 않습니다. 
대기 시간은 프로세서와 메모리 사이의 거리가 변경되면 변경됩니다 (즉, 비 균일). 그러나 NUMA는 UMA 아키텍처에 비해 성능을 향상 시켰습니다.

Computer System Organization

* One or more CPUs, device controllers are connected through a common bus providing access to shared memory
* Concurrent execution of CPUs and devices compete for memory cycles
* Each device controller(DC) manages the particular device type
* Each device controller has a local buffer
* I/O is from/to the device to/from the local buffer of controller
* CPU and DC move data from/to main memory to/from local buffers

CPU가 I/O device 에 request 요청했을때 그 완료시기는 어떻게 알 수 있을까?
* Device controller notifies CPU of events by generating an interrupt
  * When an incoming request arrives from an I/O device
  * When it has finished its operation
* CPU detects interrupts through interrupt-request lines

여기서 interrupt 는 전압

Common Functions of Interrupts

* CPU is designed to execute a function when it detects an interrupt
  * Interrupt service routine, interrupt handler routine, interrupt handler
* Interrupt vector or Interrupt Descriptor Table(IDT) contains the addresses of all the service routines
* CPU looks up IDT with the receiving interrupt number/ID to find the corresponding interrupt handler

IDT(IV) 형태로 메모리에 구성되어있다 - 어떤 선에, 어떤 전압이 걸리면 어떻게 처리를 해야한다 - 소프트웨어적인 처리 방법

10101010 : Interrupt handler

* The device controller raises an interrupt
  * By asserting a signal on the interrupt request line
* CPU catches the interrupt, and dispatches it to the interrupt handler
* What CPU do after serving the interrupt request? What happed to the currently running program?

CPU : 자기의 일을 수행함 -> 주변장치에서 인터럽트 발생(핀에 시그널을 통해 앎) -> IDT에 정의되어 있는 i.handler를 처리 -> 자기의 일을 수행함

* Systems perserve the current state of the CPU
  * To come back after handling the interrupt
  * Save registers and the address of the interrupted instruction
  * Done by HW or/and operating systems
* Return to the last state by restoring the registers

CPU는 로컬버퍼에 접근 X, 메인메모리에만 접근할 수 있음

Storage Structure
* Main memory
  * Only storage media that the CPU can access directly
    * i.e., CPU cannot read data from disks directly
  * Random access, byte addressable
  * Typically volatile

* Secondary storage(disk)
  * Extension of main memory that provides large non-volatile storage capacity
  * Block addressable

---

Storage Definitions and Notation

* Bit = 0 or 1, bygte = 8bits
* Word = A computer architecture's native unit of data
  * 32-bit architecture: 32bits = 8 x 4bits = 4bytes = 1word
  * 64-bit architecture: 64bits = 8bytes = 1word

* Multiple bytes
  * Kilo = 1024 = 2^10
  * Mega = 1024 x 1024 = 2^20
  * Giga = 1024 x 1024 x 1024 = 2^30
  * Tera, peta, exa, zeta, yotta, ...

Tip calculating 2<sup>n</sup>

2<sup>36</sup> = 2<sup>30+6</sup> = 2<sup>30</sup> x 2<sup>6</sup> = Giga * 64 = 64Giga

2<sup>22</sup> = 2<sup>20+2</sup> = 2<sup>20</sup> * 2<sup>2</sup> = Mega * 4 = 4Mega

2<sup>9</sup> = 2<sup>10-1</sup> = 2<sup>10</sup> / 2<sup>1</sup> = Kilo / 2 = 512Bytes
