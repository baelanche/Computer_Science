# TCP

* point-to-poinrt : one sender, one receiver
* reliable, in-order
* pipelined
* full duplex data : sender, receiver 가 수신, 송신을 동시에 할 수 있다.
  * bi-directional(양방향) data flow
  * maximum segment size : 한번에 송신하는 데이터의 크기가 제한되어있다.
* connection-oriented
* flow controlled

![tcp_s1](https://user-images.githubusercontent.com/48989903/137860345-febd9b73-e389-4229-b8b7-3dc5a4b59428.png)

* sender : sequence = receiver's ack, ack = receiver's seq + 1
* receiver : sequence = ack, ack = sender's seq + 1

## Round trip time, Timeout

* RTT 보다는 timeout 이 길다.
  * RTT 는 매번 변한다.
* timeout 이 너무 짧으면 불필요하게 재전송 할일이 생긴다.
* timeout 이 너무 길면 손실에 대해 반응이 늦어진다.

#### Estimate RTT

* Sample RTT : RTT 를 측정한다.
* Sample RTT 에 대해 평균값을 구한다.
* EstimatedRTT : (1 - a) x EstimatedRTT + a x SampleRTT
* typical a = 0.125
* timeout interval : 혹시 모르니 margin 을 추가한다.
* safety margin : DevRTT = (1-b) x DevRTT + b x |SampleRTT - EstimatedRTT|
* typical b = 0.25
* Timeout Interval = EstimatedRTT + 4 x DevRTT

## Reliable data transfer

* sender
  * 데이터를 받았을 때
    * sequence 를 부여한 데이터 세그먼트 생성
    * sequence is byte-stream number (next seq num = seq num + length)
    * 타이머를 시작한다.
  * timeout
    * 재전송한다
    * 타이머를 다시 시작한다.
  * ack 를 받았을 때
    * 여전히 ack 를 못받은 세그먼트가 있다면 타이머를 시작한다.

![tcp_retrans](https://user-images.githubusercontent.com/48989903/138215879-bd133da8-8f04-4b96-a8ed-d40ad7c18583.png)

1. ack 가 오지 않았을 때는 재전송한다.
2. 타이머가 짧아서 재전송하였지만 receiver 쪽에서 마지막 패킷에 대한 ack 를 날리며 정상 종료된다.

![tcp_retrans2](https://user-images.githubusercontent.com/48989903/138216924-6e639ac7-b1c3-497c-a624-cbe06fc21669.png)

3. ack 를 통해 다음 seq 를 알려주었으니, 통신에 지장이 없다.

### receiver action

* delayed ack : receiver 는 세그먼트를 받았을 때 일단 기다린다. (500ms 정도) 만약 다음 세그먼트가 안오면 ack 를 보낸다.
* 만약 세그먼트가 순서대로 온다면 즉시 cumulative ack 를 보낸다.
* 만약 세그먼트가 순서가 어긋나게 온다면 즉시 duplicate ack 를 보낸다. (마지막으로 보낸 정상 ack 재전송)
* 만약 손실을 채우는 세그먼트가 온다면 즉시 ack 를 보낸다.

## fast retransmit

만약 3개의 duplicate ack 가 왔다면 손실을 의미한다.

![tcp_fast_retrans](https://user-images.githubusercontent.com/48989903/138217848-4edde1c4-7f99-49e4-a767-aefdc44643df.png)

1. 두번째 패킷이 손실되었다.
2. receiver 는 cumulative ack 를 보낸다. (정상적으로 받은 마지막 ack)
3. ack 가 3개 중복 되었으므로 sender 는 손실된 패킷부터 다시 재전송한다.

## flow control

receiver 는 sender 의 전송속도를 조절한다. sender 는 버퍼의 오버플로우 발생을 알 수 없기 때문에 receiver 가 정보를 전달한다.

![tcp_flow_control](https://user-images.githubusercontent.com/48989903/138277160-709c479d-6447-4228-9347-98862db47184.png)

* receiver 는 남은 버퍼 공간인 rwnd 를 TCP 헤더에 담아서 sender 에게 전달한다.

## Connection Management

* 정보를 주고 받기 전에 handshaking 절차를 거친다.

### 2-way handshake

* 딜레이가 일정하지 않다.
* 클라이언트가 응답을 못받아도 서버는 알 수 없다.

#### 실패 예제

![2way_f1](https://user-images.githubusercontent.com/48989903/138278702-be9e1e59-9469-4b96-9d3b-df1280061469.png)

1. 서버가 응답하지 않는다고 생각하고 클라이언트는 재요청한다.
2. 서버는 이미 연결된 상태라 생각하여 클라이언트의 연결요청을 잊어버린다.

### 3-way handshake

![3way](https://user-images.githubusercontent.com/48989903/138279381-93c50dca-75a1-45e7-ae47-07691cd31c63.png)

* 2-way handshake 와 다르게 서버와 클라이언트의 state 가 3개이다.

#### closing connection

![3way_close](https://user-images.githubusercontent.com/48989903/138280415-522d3a93-7797-495a-b9aa-ed61c2c0181c.png)

* FIN bit 가 1 이면 close 의 뜻이다.
* 클라이언트가 close 요청을 해도 서버에서 데이터를 보내는 중 일 수 있다.
* 서버에서 데이터를 보낼 필요가 없는 상태라면 FIN bit = 1 을 보내서 close 를 알린다.
* 클라이언트는 기다리다가 FIN bit = 1 패킷을 받으면 종료한다고 응답한다.

