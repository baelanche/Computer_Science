# Scheduling

만약 프로세서가 1개이고 프로세스가 3개라면, 프로세서는 3개의 프로세스를 concurrent 하게 실행할 것이다.  
하드웨어는 주기적으로 timer interrupt 를 받고 이 interrupt 를 받으면 interrupt handler 에서 다음엔 어떤 프로세스를 동작시킬지 정한다.  
이 임무를 수행하는 곳을 scheduler 라고 하며 행위를 scheduling 이라 한다.

* 스케줄러는 CPU 가 다음 실행할 적절한 프로세스를 선택한다.
* timer set, clear 등의 instruction 은 커널모드에서만 실행할 수 있는 privileged instruction 이다.

## Context switch

* CPU 가 다른 프로세스로 switch 할 때, 시스템은 반드시 현재 프로세스의 상태를 저장하고 다음 프로세스의 상태를 부른다.
* context-switch 시간은 overhead 이다.
   * 스위칭 시간은 시스템에 도움되지 않는다.
* context-switch 시간은 하드웨어에 영향 받는다.

### Context switch from Process to Process

![context-switch](https://user-images.githubusercontent.com/48989903/137269897-4f991dc8-bf3f-4887-84d7-6745f0f925f7.png)

## Process Scheduling Overview

![scheduling](https://user-images.githubusercontent.com/48989903/137271328-a271c111-4ee9-4ac4-8ea9-6dd53a65cbb1.png)

* ready queue : 실행 준비된 프로세스들의 집합
* time slice expired : 프로세스가 특정 시간만큼 충분히 돌았으므로 ready queue 로 돌아간다.
* I/O request : 디스크 접근 요청 시스템 콜이 들어오면 I/O queue 에 담긴다. 완료되면 ready queue 로 돌아간다.
* fork : child process 도 ready queue 에 담긴다.

## Scheduling Queues

![scheduling_queue](https://user-images.githubusercontent.com/48989903/137271749-18b6d632-77b8-4a36-979b-77fb0c99b574.png)

실제 동작하는 컴퓨터에서는 수 많은 요청이 들어오므로 스케줄링을 효과적으로 할 구조가 필요하다.
