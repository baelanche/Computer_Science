# Network core
* packet switching
* circuit switching
* network structure

<br/><br/>

## Packet-switching

shared / bandwidth 공유

호스트가 작은 조각인 패킷으로 데이터를 전송하며 데이터를 전송하는 동안만 자원을 사용하도록 하는 방법

[pic] 패킷별 L bits , link의 bandwidth : R , L/R 초가 걸림

store and forward : 데이터가 라우터에 store됨 L bits에 대해서, 그리고 전송함

end-end delay : 2L/R 두번 링크를 타니까

one-hop numerical e.g. (hop : link) 위 그림은 two-hop

### Queueing delay, loss

[pic] 다수의 사용자들이 bandwidth를 공유하기 때문에 패킷스위칭이 단순하게 이루어지지는 않음.

a, b가 동시에 데이터를 보낸다. 데이터가 섞여져서 전송됨. 데이터가 몰리면 날아가는 패킷보다 쌓이는 패킷이 많아짐. 이것을 큐잉된다고 함.

그러면 대기시간이 생기게 되는데 이것은 큐잉 딜레이. arrival rate 가 transmission rate를 넘어서게 되면 큐잉이 생긴다.

트래픽이 몰리면 인터넷이 느려지는 이유가 이것이다. 큐의 길이는 무한정이 아님. 길이를 넘어서게 되면 초과된 데이터는 버려지게됨. (loss)

메모리를 더 할당해 큐의 길이를 늘인다? 큐잉딜레이가 엄청 길어지면 ...

데이터를 보내는 transmission delay 뿐만 아니라 queueing delay 가 존재한다.

Two key network-core functions

routing : 데이터가 라우터에 오면 나가는 경로가 어디인지 결정하는 알고리즘. 데이터가 주소가 쓰여있음. header의 정보.
forwarding : 라우터의 입구에서 출구로 패킷을 옮기는 알고리즘

### Circuit-switching

dedicated

[pic] 시작지, 도착지 주소 자원을 할당함, bandwidth를 사용자별로 나눌 필요가 없음. -> 큐잉딜레이 안생김. 패킷손실 없음.

사용률이 떨어지면 대역폭 낭비. 전화에 적합함. 전화 걸면 한개의 서킷 할당.

서킷의 개수. bandwidth가 있고 bps가 있음. 총 몇명이 전화를 할 수 있나? 동시에 통화할 수 있는 사용자 수가 보통 제한되어있음.

대역폭이 꽉차면 통화를 못하게됨 -> 통화중으로 표시

FDM vs TDM

다중화 기법

Frequency Division Multiplexing

Time Division Multiplexing

[pic] 주파수를 쪼개서 사용자별로 분배. 아날로그 방식

[pic] 시간별로 유저에게 주파수 할당. 아날로그 방식으로는 불가능. 디지털 방식


### Packet swi vs Circuit swi

사용자를 더 많이 받아들일 수 있는 것? 패킷스위칭

예)

bps : 1 Mbps link
users : 100 kb/s, active 10% of time

서킷스위칭 : 10명
패킷스위칭 : 35명. 35명 중 10명이 동시에 패킷을 보낼 확률을 계산해보니 0.0004 

패킷스위칭이 더 좋은가? 인터넷의 대부분이 패킷스위칭 방식임

일반적으로 유저들은 가끔씩, 한번에 ~~ 활동하는데 이런 방식엔 패킷스위칭이 좋음. 패턴이 없음.
-> 리소스를 공유하는게 효과적, 그냥 보내면 라우터들이 경로를 설정해주므로 단순함에 있어서 좋음.

혼잡한 상황이 생길수는 있음. 예상치 못한 인원이 몰렸을 때. 

서킷-like 한 동작은 어떻게 제공하는가?
인터넷에 이러한 솔루션은 잘 적용되지 않는다. -> 대역폭이 충분하기 때문임.
Skype(VoIP) 와 같은 음성데이터를 송/수신할때 패킷스위칭을 사용하는데에 일반적으로 잘 동작하는 것이 증거임.
물론 트래픽이 몰리면 끊김이 생기게 됨. 여전히 해결되지 않은 문제임.

internet structure : network of networks

엔드 시스템은 ISP를 통해 인터넷에 접속한다. ISP가 노드들을 연결해주는데 어떤식으로 연결해주는가?