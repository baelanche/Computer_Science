# Summary

<img width="1186" alt="s1" src="https://user-images.githubusercontent.com/48989903/146535520-1a74519c-c183-450a-96e4-45061db9f6b4.png">

컴퓨터로 www.google.com 에 접근하는 과정을 정리해보자.

<img width="592" alt="s2" src="https://user-images.githubusercontent.com/48989903/146535676-32ecdcbb-fa19-482b-a421-f08083c7f235.png">

1. DHCP 를 활용하여 IP, router, DNS server 등의 주소를 얻는다. (IP 동적 할당 프로토콜)
2. DHCP 는 UDP, IP, Ethernet 을 캡슐화한다.
3. Ethernet 은 broadcast 하고 DHCP 는 그 메세지를 받는다.
4. Ethernet 은 IP, UDP 를 DHCP 에 올린다.
5. DHCP server 는 client IP, router address, DNS server address 등을 담은 DHCP ACK 를 생성한다.
7. swtich learning
8. DCHP client 는 DHCP ACK 를 받는다.

<img width="597" alt="s3" src="https://user-images.githubusercontent.com/48989903/146537236-270f8035-1e6f-46c0-b192-ba2e2659fe84.png">

1. www.google.com 의 IP 주소를 알기 위해 DNS 쿼리를 만든다.
2. ARP 를 통해 router 의 MAC 주소를 얻는다.

<img width="1176" alt="s4" src="https://user-images.githubusercontent.com/48989903/146537787-79f84ff1-a777-4495-97f6-5d6a97f823d4.png">

1. DNS 쿼리는 router 에 도착했다.
2. 여러 routing algorithm 을 통해 Comcast network 의 router 에 도착 후 DNS server 에 도착한다.
3. DNS server 는 www.google.com 의 IP address 를 담아서 응답한다.

<img width="633" alt="s5" src="https://user-images.githubusercontent.com/48989903/146537859-61a4f025-e22b-4dbc-b3fc-6667895ab933.png">

1. HTTP request 를 보내기 위해 TCP 를 open 한다.
2. SYN segement 를 보낸다.
3. SYNACK segment 를 응답 받는다.
4. TCP connection 이 완성된다.

<img width="600" alt="s6" src="https://user-images.githubusercontent.com/48989903/146538112-605b8105-596e-4feb-8535-b7517e3c0534.png">

1. HTTP requet 를 전송한다.
2. web server 는 HTTP reply 를 보내 응답한다.
3. HTTP reply 를 client 가 받는다.

