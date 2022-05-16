# DNS : domain name system

IP 주소에 'name' 을 매핑하는 시스템

## DNS services

* host name - IP address 사이의 변환을 제공
* host aliasing : 호스트 이름을 간단히 하여 제공함
* mail server aliasing
* load distribution : 다수의 IP 주소를 한개의 호스트 네임에 대응시킬 수 있다

### 왜 DNS 를 분산시켰는가?

* DNS 가 다운되면 접속이 불가능 해진다.
* 트래픽이 몰린다.
* 거리에 따른 차이가 발생한다.
* 유지보수의 불편함

### DNS hierarchy

![dns_hierarchy](https://user-images.githubusercontent.com/48989903/136731475-68d17676-80c8-4643-baea-993db4071442.png)

1. 클라이언트가 www.amazon.com 으로 이동하길 원한다.
2. 클라이언트는 com DNS server 를 찾기 위해 root server 에 쿼리를 날린다.
3. 클라이언트는 amazon.com 를 찾기 위해 com DNS server 에 쿼리를 날린다.
4. 클라이언트는 www.amazon.com 의 IP 주소를 찾기 위해 amazon.com 에 쿼리를 날린다.

### root name servers

전세계 곳곳에 root name server 를 분산 설치하여 관리한다. (400 여개 이상 설치됨)  
13개의 logical root name server 가 있다.

### TLD, authoritative servers

* TLD(top-level domain) servers : com, org, net, edu, ... (e.g., www.naver.com)
* authoritative servers : 기관의 DNS 서버 (e.g., kin.naver.com, cafe.naver.com)
  * 실제 개인 도메인과 IP 주소의 관계가 기록/저장/변경되는 서버. 그래서 권한의 의미인 Authoritative가 붙음. 일반적으로 도메인/호스팅 업체의 ‘네임서버’를 말하지만, 개인 DNS 서버 구축을 한 경우에도 여기에 해당함.

### Local DNS name servers

* ISP 가 소유하고 있다.
* 호스트가 DNS 쿼리를 만들면 이 서버에서 수신한다.
* 프록시 서버와 같은 역할을 한다.

### Example

![dns_process](https://user-images.githubusercontent.com/48989903/136735282-66a8758b-b52f-46c7-ad3b-3c371533ccac.png)

1. cis.poly.edu 에서 gaia.cs.umass.edu 에 접속하길 원한다.
2. local DNS server 인 dns.poly.edu 에 쿼리를 보낸다.
3. local DNS server 는 root DNS server 에 request 를 보낸다.
4. root DNS server 에서 IP 주소를 알려준다.
5. local DNS server 는 TLD DNS server 에 request 를 보낸다.
6. TLD DNS server 에서 응답한다.
7. local DNS server 는 authoritative DNS server 에 request 를 보낸다.
8. authoritative DNS server 에서 응답한다.
9. local DNS server 에서 호스트에게 전달한다.

### caching, updating records

위 방식은 절차가 비효율적이다. 반복적인 쿼리에 대해서는 캐시를 적용한다.

![dns_process_rec](https://user-images.githubusercontent.com/48989903/136736042-e35504de-1502-488f-ae5b-a23a07f95216.png)

* DNS 서버들은 한 번 받은 요청에 대해서는 cache 한다.
* cache 는 기한이 오래되면 폐기될 것이다. (보통 2일)

### DNS records

아래와 같은 형태로 자원을 보관하며 RR format 이라 부른다.
```
RR format : (name, value, type, ttl)
```

#### type = A

* name : hostname
* value : IP address

#### type = NS

* name : domain
* value : hostname of authoritative server

#### type = CNAME

* name : alias name
* value : canonical name

#### type = MX

* value : name of mailserver

