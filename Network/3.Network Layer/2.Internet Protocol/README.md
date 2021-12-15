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

