# Wireless LAN

<img width="601" alt="wifi" src="https://user-images.githubusercontent.com/48989903/146539778-5eb60014-261a-4a2e-bf93-0ec829a6f8e8.png">

* AP (access point) : wifi 와 같은 무선 공유기 (NAT 를 통해 IP 주소를 할당 받음)
* BSS (basic service set) : AP 로 인해 형성된 네트워크
* host 는 반드시 AP 에 접근하여야 IP 주소를 받을 수 있다. (DHCP)
* 무선기기는 유동적이므로 고정 IP 를 할당하지 않는다.

### scanning

* passive scanning : 자동으로 wifi 를 찾는 것과 유사한 스캔 방법
* active scanning  직접 wife 를 찾는 방법

### CSMA/CA (Collision Avoidance)

<img width="436" alt="csmaca" src="https://user-images.githubusercontent.com/48989903/146540869-0d45f023-37c1-4424-af72-ca7137428085.png">

1. channel
   * idle : 보낸다.
   * busy : random backoff timer 를 돌려서 idle 이 될때까지 기다린다. ACk 가 오지 않으면(collision) increase backoff 를 하여 다시 timer 를 돌린다. 
2. SIFS 를 보낸 후 ACK 를 보낸다.

#### RTS-CTS exchange

<img width="1179" alt="rtscts" src="https://user-images.githubusercontent.com/48989903/146541110-3e576437-5e18-4f88-9de0-44a41a6a5f11.png">

1. rts 를 서로 동시에 보내서 collision 이 발생하였다.
2. rts 를 A 만 전송했다.
3. AP 가 cts 를 A, B 에 전송한다.
4. B 는 누군가가 rts 를 보낸것을 알고 cts 에 기재된 시간만큼 freeze 한다.
5. A 는 data 를 보낸다.
6. AP 는 ack 를 A, B 에 전송한다.

