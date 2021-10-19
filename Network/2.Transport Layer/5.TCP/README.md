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

