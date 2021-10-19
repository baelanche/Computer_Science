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

## rdt 2.2 : NAK free protocol

* rdt 2.1 only ACKs
* NAK 대신 ACK 를 보낸다.
* 중복된 ACK 를 받으면 NAK 라고 생각할 수 있게 된다.

## rdt 3.0 : channels with errors and loss

* 패킷이 모두 손실되는 경우를 고려한다. (data, ACKs)
* sender 는 ACK 를 특정 시간만큼 기다린다.
  * ACK 가 시간 내에 오지 않으면 재전송한다.
  * ACK 가 시간이 지나서 도착하면
    * 이미 재전송 했으니 중복되었을 것이다.
    * receiver 는 ACK 에 sequence 를 반드시 넣어보낸다.

#### No loss

![rdt_3_2](https://user-images.githubusercontent.com/48989903/137722656-f06ce5b1-712b-4e74-9cb2-8ff861cdd8d1.png)

#### Packet loss

![rdt_3_3](https://user-images.githubusercontent.com/48989903/137722730-ec0423d3-3ad8-4fb5-b971-2b920e01b956.png)

#### ACK loss

![rdt_3_1](https://user-images.githubusercontent.com/48989903/137722562-c3a846f0-fc41-4e08-8c9d-0f89332189af.png)

#### Premature timeout / delayed ACK

![rdt_3_4](https://user-images.githubusercontent.com/48989903/137722864-e75dbd23-a270-4111-920b-186b78ae45df.png)

### Performance of rdt 3.0

![bad_utilization](https://user-images.githubusercontent.com/48989903/137724833-3c8e73eb-ea86-42b7-bb84-51e3313a9314.png)

* 1 Gbps link, 15ms propagation delay, 8000 bit packet
* Delay<sub>trans</sub> = L/R = 8000bits/10<sup>9</sup>bits/sec = 8 microsecs
* RTT = 30 msec (2 x prop)
* Sender utilization = (L/R) / (RTT + (L / R)) = 0.008 / 30.008 = 0.00027
  * 1 Gbps link 에서 매 30 msec 마다 1KB 의 패킷이 33kB/sec 의 throughput 을 보여준다.
  * 사용률이 매우 떨어진다.

## Pipelined protocols

* sender 는 동시에 여러개의 패킷을 보낸다.
* generic forms : go-Back-N, selective repeat

![better_utilization](https://user-images.githubusercontent.com/48989903/137725255-c5ff86f2-9f0c-44a4-85c7-aca493b5db9d.png)

### Go-back-N

* sender 는 n 개의 패킷을 파이프라인을 통해 보낸다.
* receiver 는 cumulative ack 를 보낸다. (아래에 설명)
* sender 는 가장 오래된 패킷에 대해 타이머를 가진다.
  * 타이머가 만료되면 윈도우의 모든 패킷을 재전송한다.

![go_back_n](https://user-images.githubusercontent.com/48989903/137856052-3494f5b6-bdfa-4bd2-9363-b4179eef2d4f.png)

* 초록색 : ACK 를 받은 패킷
* 노란색 : 보냈지만 ACK 를 아직 못받은 패킷
* 파란색 : 아직 보내지 않은 패킷

<br/>

![go_back_n_prog](https://user-images.githubusercontent.com/48989903/137857640-3d4e110b-1117-43b9-be2f-fbcb0f8d6c81.png)

<br/>

* #### sender
  * ACK 를 받은 패킷은 윈도우에서 제외하고 다음 패킷을 윈도우에 포함시킨다.

<br/>

* #### receiver
  * 올바르게 받은 패킷 중 가장 높은 sequence 에 대해서 ACK 를 보낸다. (if send 10, 11 error, 12 then ACK = 10)

<br/>

### Selective Repeat

* sender 는 n 개의 패킷을 파이프라인을 통해 보낸다.
* receiver 는 각 패킷에 대해 ack 를 보낸다.
* sender 는 각 패킷에 대해 타이머를 유지한다.
  * 타이머가 만료되면 해당 패킷을 재전송한다.
* sender 는 ACK 가 오지 않은 패킷에 대해 재전송한다.

![selective_repeat_prog](https://user-images.githubusercontent.com/48989903/137858709-23c3461a-f1b7-4fb8-a5ac-d69bd0fac50e.png)

### Dilemma

![selective_repeat_d2](https://user-images.githubusercontent.com/48989903/137865321-31cf52ff-030e-4c7b-b741-7e60f10d3555.png)

* 한정된 패킷 순서번호를 사용할 때 패킷이 손실된 경우
  * sender 는 패킷 0, 1, 2 를 보낸다.
  * receiver 가 ACK 0 을 보내자 sender 는 패킷 3 을 보냈지만 손실되었다.
  * receiver 가 ACK 1 을 보내자 sender 는 패킷 0 을 보냈다.
  * receiver 는 패킷 3 을 받은 적이 없으므로 새로온 패킷 0 이 재전송인지 새로 전송된 건지 알 수 없다.

![selective_repeat_d1](https://user-images.githubusercontent.com/48989903/137858959-8f2cc485-9bc7-4a3b-8f78-058f7fd8f846.png)

* 한정된 패킷 순서번호를 사용할 때 ACK 가 손실된 경우
  * receiver 의 ACK 가 도착하지 않으면 sender 는 패킷을 재전송한다.
  * receiver 는 윈도우를 옮긴 상태이므로 받은 패킷이 재전송인지 새로 전송된 건지 알 수 없다.
