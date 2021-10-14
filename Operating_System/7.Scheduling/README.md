# Scheduling

만약 프로세서가 1개이고 프로세스가 3개라면, 프로세서는 3개의 프로세스를 concurrent 하게 실행할 것이다.  
하드웨어는 주기적으로 timer interrupt 를 받는데 이 interrupt 를 받으면 interrupt handler 에서 다음엔 어떤 프로세스를 동작시킬지 정한다.  
이 임무를 수행하는 곳을 scheduler 라고 하며 행위를 scheduling 이라 한다.

스케줄러는 CPU 가 다음 실행할 적절한 프로세스를 선택한다.

timer set, clear 등의 instruction 은 커널모드에서만 실행할 수 있는 privileged instruction 이다.

## Context switch

* CPU 가 다른 프로세스로 switch 할 때, 시스템은 반드시 현재 프로세스의 상태를 저장하고 다음 프로세스의 상태를 부른다.
* context-switch 시간은 overhead 이다.
   * 스위칭 시간은 시스템에 도움되지 않는다.
* context-switch 시간은 하드웨어에 영향 받는다.

### Context switch from Process to Process

