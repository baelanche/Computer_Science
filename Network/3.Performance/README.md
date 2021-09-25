# Performance

* delay
* loss
* throughput

## 손실과 지연은 어떻게 발생하는가?

패킷은 라우터 버퍼에 큐(queue)된다.  
패킷의 arrival rate 가 link capacity 를 초과하면 딜레이가 발생한다.

transmission delay, queueing delay / loss

four sources of packet delay

processing delay : 라우터 내에서 걸리는 시간, 비트 체크, link 결정

propagation delay : 링크를 통해 날아가는 시간 / 물리적 링크의 거리가 d 이고 전파의 속도가 s 일때 딜레이는 d/s

caravan analogy

열개의 차가 하나의 톨게이트를 통과한다. 차 한대가 톨게이트에서 걸리는 시간이 12초, 차의 주행속도는 100km

모든 차가 두번째 톨게이트를 통과하는데 걸리는 시간은?

톨게이트에서 걸리는 시간은 120초, 100키로의 거리를 100키로로 가면 1시간 걸림

첫번째 차가 첫번째 톨게이트를 통과하는 시점부터 마지막 차가 두번째 톨게이트를 통과하는 시점 : 62분

transmission delay + propagation delay

Queueing delay

L*A/R 이 0에 가깝다 : 큐잉 딜레이가 거의 없다
L*A/R 이 1에 가깝다 : 큐잉 딜레이가 크다
1보다 크다 : 일하는 속도보다 제공되는 속도가 빠르다, 무한대의 딜레이

인터넷에 적용해보자(프로그램 사용)

클라이언트에서 라우터들을 거치며 서버에 갈때

보통 세개의 패킷을 보냄 라우터에 왔다가는 시간 체크

packet loss

큐가 꽉차면 새로운 패킷은 버려진다

throughput(단위시간동안 교환된 데이터의 양)

네트워크의 퍼포먼스 : delay, loss, throughput

rate(bits/time) bandwidth 가 고정되어 있어도 throughput 은 고정되어 있지 않음

보통 에버리지값을 측정

서버에서 F bits 를 클라이언트에 보냄
첫번째 링크 : Rs : small capacity
두번째 링크 : Rc : big capacity

실제 보내는 throughput 은 작은 쪽으로 결정됨

이럴경우 평균은?

bottleneck link

capacity가 작은 쪽의 link를 bottleneck link라 함

이 문제를 해결하기 위해 TCP 가 도입됨
데이터 전송률을 그때 상황에 맞게 조절함


여러개의 서버, 클라이언트들이 bandwidth를 공유함
10개의 커넥션이 R을 쓰고 있다고 할때

각 Rc, Rs, ... 들을 10으로 나누고 가장 작은것이 throughput

일반적으로 중간에 bottleneck 이 생기지 않음 코어는 대역폭을 높게 설계함

