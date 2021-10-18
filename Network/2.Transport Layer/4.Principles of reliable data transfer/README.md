# Principles of reliable data transfer

가상의 프로토콜 reliable data transfer 를 설계할 것이다.

## Overview

#### Reliable data transfer (rdt)

![rdt](https://user-images.githubusercontent.com/48989903/137705609-e155c3bd-7cb5-4898-a07f-d8940160b9a7.png)

* unidirectional(단방향) 만 다룰 것이다.
* finite state machines (FSM) 을 사용할 것이다.

## rdt 1.0 : reliable transfer over a reliable channel

* 채널은 perfectly reliable 하다.
  * 에러, 손실이 없다.
* FSM 을 sender, receiver 에 분리하여 둔다.

![fsm_1](https://user-images.githubusercontent.com/48989903/137707902-257088a5-e11b-4637-8994-7d3251e2479c.png)

* 상태가 1개 뿐이다.

## rdt 2.0 : channel with bit errors

* 채널에서 패킷 내의 비트를 flip (0 -> 1, 1 -> 0) 할 수 있다.
* 에러 발생 시 재전송을 요청한다.
  * acknowledgements (ACKs) : 잘 받았을 시 sender 에게 ACK 패킷을 보낸다.
  * negative acknowledgements (NAKs) : 에러 발생 시 sender 에게 NAK 패킷을 보낸다.
  * sender 는 NAK 를 받았을 시 재전송한다.
* 에러 감지가 가능하다.
* 피드백이 가능하다.

![fsm_2](https://user-images.githubusercontent.com/48989903/137707999-d4172ce5-5e0b-4d13-8409-4366483c4277.png)

* sender 
  * 데이터 전송시 state 를 바꾼다.
  * receive 패킷을 기다린다.
  * NAK 발생 시 재전송한다.
  * ACK 발생 시 초기 state 로 돌아간다.
* receiver
  * 에러 발생시 NAK 를 전송한다.
  * 정상 수신시 ACK 를 전송한다.

* 만약 ACK, NAK 가 에러나면 어떻게 할까?
  * sender 는 receiver 가 어떤 상태인지 모른다.
  * 재전송시 중복 데이터만 발생할 것이다.

* 중복 관리
  * ACK, NAK 의 에러 발생시 sender 는 일단 재전송한다.
  * sender 는 각 패킷에 sequence number 를 붙여서 보낸다.
  * receiver 는 패킷의 sequence number 가 중복일 시 버린다.

## rdt 2.1 : sender, handles garbled ACK/NAKs

![fsm_2_1](https://user-images.githubusercontent.com/48989903/137710764-ada4cccf-202d-40cc-9d78-cd80375e2e92.png)

* sender
  * sequence 0, checksum 을 부여하여 패킷을 전송한다.
  * 해당 패킷의 receive 를 기다린다.
    * NAK : 재전송한다.
    * ACK : state 를 변경한다.
  * sequence 1, checksum 을 부여하여 패킷을 전송한다.
  * 반복한다.

![fsm_2_2](https://user-images.githubusercontent.com/48989903/137711313-1bcfa0cd-92d2-45b9-85d8-a9bcbd9b35a8.png)

* receiver
  * sequence 0 을 기다린다.
    * 에러 시 : NAK 를 checksum 을 포함하여 전송한다.
    * 에러는 없지만 sequence 1 을 받았다 : ACK, checksum 를 보내지만 state 는 유지한다.
    * 에러도 없고 sequence 0 을 받았다 : ACK, checksum 을 보낸다.
    * sequence 1 을 기다리는 state 로 전환한다. 
