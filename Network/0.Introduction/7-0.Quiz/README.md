# Quiz

원본 : [lychee](https://velog.io/@lychee/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-1.5)

### (a) Akamai에서 운영하는 CDN(Content Distribution/Delivery Network)에는 한개의 컨텐츠 회사 데이터만 지나다닌다.

⇒ F. akamai같은 CDN에는 한 회사의 트래픽만 지나다닐 수 없음. (수업 시간에 Akamai는 Thire Party Content "Provider" Network 회사라고 했는데 CDN과 CPN을 공용으로 써도 되는 건가요? 네. 공용해서 사용함

### (b) Throughput을 결정하는 bottlenext link는 source와 destination 사이 링크들 중 Transmission rate 값이 가장 큰 링크이다.

⇒ F. source와 destination 사이의 end-to-end path 중에 transmission rate이 가장 작은 링크

→ Transmission rate이 가장 적은 링크이거나 아주 높은 링크의 다음 링크” 라고 보조설명을 한답변이 있었는데 약간 불안합니다. 지금은 이론적인 상황만을 설명하고 있으므로 source와 destination 사이의 end-to-end path 중에 transmission rate이 가장 작은 링크가 맞습니다. 아주 높은 링크의 다음 링크는 e2e path에 속한 링크가 딱 2개인 경우를 설명하는 것 같네요..

### (c) 2계층 PDU 이름은 segment 이고 4계층 PDU 이름은 frame 이다.

⇒ F. 5계층:메시지, 4계층: 세그먼트, 3계층: 패킷 or datagram, 2계층: 프레임

### (d) 두 사용자가 Point-to-point로 연결된 네트워크에서 제3의 해커가 sniffing할 수 있다.

⇒ F. 사이에 제 3의 해커가 위치해야 sniffing 할 수 있음

### (e) 사용자의 실행 없이도 자가복제가 가능하며, 주로 네트워크 링크 혹은 서버를 공격하는 malware를 worm이라고 한다.

⇒ T.

### (f) ALOHA 네트워크는 ARPANET 이전에 등장했다.

⇒ F. ARPAnet은 60년대 등장한 인터넷의 어머니

### (g) 1970년대에는 DECnet, XNA등 다양한 네트워크가 등장했다.

⇒ T,

### (1) Throughput을 정의하시오.

⇒ end host와 end host 사이 혹은 sender와 receiver, source와 destination 사이 단위시간당 전송되는 비트수 혹은 초당 전송되는 비트 수

### (2) 최초의 인터넷 서비스는?

⇒ E-mail

### (3) best-effort 서비스의 의미는?

⇒ throughput, delay, loss 등의 서비스 품질을 보장하지 않으며 그때 그때 망 상황에 따라 품질이 결정되는 서비스

### (4) Vint Cerf가 설립한 internetworking의 4가지 원칙은?

* 각 ISP의 자치권 보장 (즉, 최소한의 변경으로 ISP 망 연결)
* end-host들에게 서비스 품질을 보장하지 않는 best-effort 서비스
* 라우터들이 지나간 연결에 관한 정보를 유지하지 않는다.
* 하나의 관리자가 제어하지 않는다
