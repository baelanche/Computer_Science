# Internet Protocol

* IPv4 : 32bit
* IPv6 : 128bit
* IP header : 20bytes
* TCP header : 20bytes
* IOT 에서는 40bytes 를 차지하는 TCP/IP 프로토콜을 잘 사용하지 않는다.

### IP fragmentation, reassembly

* large IP datagram 은 쪼개지고 재조합되어 목적지에 도달한다.

### e.g.,

* 4000 byte datagram
* MTU = 1500 bytes

<img width="645" alt="fragmentation" src="https://user-images.githubusercontent.com/48989903/146160449-d5615223-974e-49e5-9a68-9651ced7920a.png">

* 4000 byte 를 3개로 쪼갠다.
* fragflag : 1 (쪼갠 조각이 더 있음)
* header : 40 bytes (IP header x 2)

## IP addressing

<img width="717" alt="addressing" src="https://user-images.githubusercontent.com/48989903/146156468-ebc00344-7b5f-407a-b729-1fa3faffe9e4.png">

* 네트워크의 관리 용이를 위해 앞자리(상위 비트)는 동일하게 구성된다.
* Router : 네트워크 끼리 연결 (L3)
* Switch : 네트워크 내를 연결 (L2)

## Subnets

* subnet parts : high order bits
* host parts : low order bits
* subnet mark : /subnet parts 로 표현
  * e.g., 223.1.1.0/24 : 24 bits 로 subnet 을 구성함 -> 32-24 = 8, 따라서 호스트는 2<sup>8</sup> 개의 IP 주소를 가질 수 있음

### IP addressing : CIDR (Classless InterDomain Routing)

<img width="858" alt="cidr" src="https://user-images.githubusercontent.com/48989903/146157862-a84db314-c2d2-4953-8ef5-d0079307aeba.png">

* address format : a.b.c.d/x

## How does a host get IP address?

### DHCP

* 동적으로 주소를 할당받는 방법
* IP 주소가 모자라기 때문에 client 들에게는 network 에 연결시 주소를 할당하는 방법을 이용하였다.
* 지금 잘 사용되지 않는다.

#### Scenario

<img width="860" alt="dhcp" src="https://user-images.githubusercontent.com/48989903/146158830-9df8aa98-0c18-4668-a9ea-010084959c91.png">

1. client 는 DHCP server 에 IP 를 요청한다.
2. server 는 IP 를 제공한다.
3. client 는 할당받은 IP 로 접속을 요청한다.
4. server 는 ACK 를 전송한다.

### subnet addressing

<img width="1106" alt="addressing2" src="https://user-images.githubusercontent.com/48989903/146160075-1ddcb15a-813d-4da4-ac16-4d01be182238.png">

* ISP 는 특정 범위의 IP 주소를 할당한다.
* 조직별로 subnet parts 의 bit 크기를 늘려서 나눠갖는다.
* 앞의 20 bits 는 ISP block 이고 그 뒤의 3 bits 는 org block 이 된다.
* org 별 org block 의 숫자는 모두 다르다. (8개 조직이므로 3bits (2<sup>3</sup>))
* ISP 는 ICANN 이라는 기관에서 IP 주소를 받아온다.

## NAT : network address translation

IPv4 의 IP 주소로는 host 에 주소를 할당하기에는 턱없이 부족하다.  
IPv6 가 등장한지 20년이 넘었지만 적극적으로 사용하고 있지는 않는 추세이다.  
IP 주소의 상당 부분을 보유하는 미국에서는 당장 IP 주소가 부족하지 않기 때문이다.  
이 NAT 라는 기술이 도입되면서 IPv4 를 사용하여도 충분히 감당할 수 있는 상황이 되었다.

<img width="1186" alt="nat" src="https://user-images.githubusercontent.com/48989903/146161879-d2172a41-ed3b-4f96-80de-ce9821141862.png">

* 138.76.29.7 이라는 주소를 할당받았다. 하지만 우측의 내부망에 여러 host 에게 주소를 주어야 하는 상황이다.
* 망내에서만 사용하는 임의의 port number(10.0.0.1~3)를 부여하고 망외부에서는 138.76.29.7 주소로 접근하게한다.
* translation
  * datagram 을 내보낼 때 : (source IP address, port number) -> (NAT IP address, new port number)
  * table 에 위 두 쌍을 모두 저장한다.
  * datagram 을 받을 때 : (NAT IP address, new port number) 를 table 에서 찾아 (source IP address, port number) 로 translation 한다.
* 16 bit port number field : 60000 개 정도의 IP 를 확보할 수 있다.
* 논쟁
  * 오직 layer 3 에서만 처리할 수 있다.
  * end-to-end 규약에 어긋난다.
  * P2P 에는 적용되지 않는다.

## IPv6

* bit 를 늘림과 동시에 쓸모없는 header 를 정리하는 작업을 거쳤다.
* 전세계 10~20% 정도가 IPv6 로 되어있다.
* header : 40bytes
* tunneling : IPv6 를 읽을 수 없는 라우터를 위해 IPv4 datagram 내에 IPv6 datagram 을 넣고 IPv4 방식으로 처리하는 방법

<img width="1061" alt="tunneling" src="https://user-images.githubusercontent.com/48989903/146168133-867a216e-fe79-4e01-bad3-99bf79537d02.png">

* C, D 는 IPv6 지원이 안된다.
* C, D 를 지날 때에는 IPv4 헤더를 붙여서 지나게 한다.

## Generalized Forwarding and SDN

* control plane 을 소프트웨어화 시킨것이 SDN 이다.

### OpenFlow

* match + action : 패킷의 패턴을 찾고 해당되는 패킷에 대해 다양한 action 을 취한다.

