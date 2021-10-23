# TCP Congestion Control

* sender 는 손실이 발생할 때 까지 전송률(window)을 점차 늘린다. (additive increase)
* 손실이 발생하면 window 크기를 절반으로 줄인다. (multiplicative decrease)

![tcp_congestion](https://user-images.githubusercontent.com/48989903/138532795-8f8f9d70-556b-4fc4-9d72-653cf9d4edad.png)

### TCP sending rate

![tcp_sending_rate](https://user-images.githubusercontent.com/48989903/138532964-3707593f-1c43-495d-a909-82adc51973aa.png)

## TCP Slow Start

* 연결이 시작되면 첫번째 손실이 발생할 때까지 전송률을 지수적으로 증가시킨다.
  * 초기 : 1개
  * 매 RTT 마다 2배로 늘린다.
  * ACK 를 정상적으로 받으면 계속해서 늘린다.

![tcp_slow_start](https://user-images.githubusercontent.com/48989903/138533168-7b68d421-8a43-4ea5-a73b-6a228ebe4b30.png)

## detecting, reacting to loss

* 타임아웃이 발생(loss)
  * cwnd = 1
  * 다시 지수적으로 증가시킨다. (slow start)
  * 한계점에 도달하면 선형적으로 증가시킨다. (congestion avoidance)
* 3개의 중복 ack 가 왔을 때(loss) : TCP Reno
  * cwnd 를 절반으로 줄이고 다시 선형적으로 증가시킨다.
* TCP Tahoe 는 언제나 cwnd 를 1로 만든다.

![tcp_slow_start_graph](https://user-images.githubusercontent.com/48989903/138533268-380ff7c0-df66-4912-9f84-d6dffd847231.png)

## TCP throughput

![tcp_throughput](https://user-images.githubusercontent.com/48989903/138533572-131722b3-fee3-4bd0-a533-5947634ad628.png)

* 평균 throughput : 3/4 x W
* avg TCP throughput : 3/4 x W / RTT bytes/sec


### Example

* 1500 byte segments
* 100ms RTT
* Goal : 10 Gbps throughput

* W = 83333

## TCP Fairness

* capacity R 인 라우터를 공유하고 있을때 각 connection 은 R/2 만큼의 대역폭을 받는가?

![tcp_fairness](https://user-images.githubusercontent.com/48989903/138534107-2038280e-7c97-429f-8fb9-be80ca8a409e.png)

* 이론적으로는 공평하다.
* 실제로는 RTT 가 빠른쪽이 유리하다.

### UDP Fairness ?

* 전혀 공평하지 않다.
* flow control, congestion control, ... 등등이 없다.

## Explicit Congestion Notification (ECN)

* 혼잡이 발생하면 receiver 는 sender 에게 ECE (ECN echo) 비트를 ACK 로 날려준다.
* sender 는 congestion avoidance 상태로 들어간다.
