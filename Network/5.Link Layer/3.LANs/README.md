# LANs

* addressing, ARP
* Ehternet
* switches
* VLANS

## MAC address

MAC address : 물리적으로 연결되어 있는 주소, 기기를 만들때 주소를 만들어 붙인다.

> e.g.,
> MAC : 주민등록번호  
> IP : 집 주소

## ARP (address resolution protocol)

ARP Table : 각 IP 는 IP, MAC, TTL 을 담은 table 을 가지고 있다.

> TTL : TTL 에 따라 값을 갱신한다. (일반적으로 20분)

* A 는 B 에게 datagram 을 전송할 것이다. (A 의 ARP table 에는 B 의 MAC address 가 없다)
* A 는 B 의 IP 주소를 담아 ARP 패킷을 LAN 에 전파한다.
* B 는 ARP 패킷을 받고 A 에게 자신의 MAC address 를 담아 답장한다.
* A 는 ARP table 에 주소를 저장한다.
* `plug-and-play' : 관리자 없이 ARP table 을 생성한다.

<img width="1128" alt="addressing" src="https://user-images.githubusercontent.com/48989903/146528676-fd62237c-9846-48ca-9cdb-29b169b74800.png">

A 는 R 을 경유하여 B 에게 datagram 을 보낼 것이다. A 는 B 의 IP 주소를 아는 상태이고 R의 IP, MAC 을 알고 있다.

1. B 의 IP 주소, R 의 MAC 주소를 datagram 에 담아 전송한다. (B 의 MAC 은 모르므로)
2. R 은 frame 을 받는다.
3. R 은 MAC frame 을 모두 제거한 후 자신(src)의 MAC, B(dest) 의 MAC 주소를 담아 전송한다.

## Ethernet

과거보다 속도가 비약적으로 상승하였고 장거리도 가능하게 되었다.

* bus : 90년대에 사용, 한 번에 한개만 전송 가능하다. 그렇지 않을시 collision 이 발생한다.
* star : swtich 를 중앙에 둔 형태이다. collision 이 발생하지 않는다.
* connectionless : no handshaking
* unreliable : no acks or nacks
* use CSMA/CD with binary backoff

## switches

* link layer device : store, forward 하는 역할
* transparent : 호스트들은 스위치의 존재를 모른다.
* plug-and-play, self-learning : 스위치는 재구성 해줄 필요가 없다.
* switch 는 switch table 을 가지고 있다.
* sender, receiver 의 정보를 저장하여 self-learning 한다.

<img width="507" alt="switch" src="https://user-images.githubusercontent.com/48989903/146530967-35fe293b-5180-4386-89f5-2d42e2be8cee.png">

1. A 는 A' 에게 전송한다.
2. 스위치는 목적지를 모르므로 일단 flood 한다. (주변 기기에 전송한다/물어본다)
3. A' 의 정보를 받아 전송한다. (selective send)

### switches vs routers

* store-and-forward : network layer vs link layer
* forwarding table : routing algorithm vs flooding, learning (내부망이 크지 않기 때문에 flooding 이 가능하다)

## VLAN (Virtual Local Area Network)

* 다른 network 의 호스트들을 같은 switch 로 관리하는 것을 말한다. (port-based)

