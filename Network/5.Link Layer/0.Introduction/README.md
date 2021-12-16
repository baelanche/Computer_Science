# Introduction : Link Layer

* error detection
* multiple access
* link layer addressing
* LAN : Ethernet, VLAN
* link layer 의 packet : frame
* 노드 사이의 link 에서 신뢰성 보장이 어떻게 이루어지는가? <-> TCP 의 end-to-end 신뢰성 : router, switch 등의 신뢰성

### Service

* framing, link access
  * 데이터에 header, trailer 를 붙여 frame 단위로 캡슐화한다. (frame = data + header + trailer)
  * channel 은 여러 사용자가 접근한다.
* reliable delivery between adjacent nodes : link 에서는 에러가 더 쉽게 발생할 수 있다.
* flow control
* error detection
* error correction : 재전송이 아닌 correction 하는 방법을 제공한다.
* half-duplex and full-duplex : 단방향 전송, 양방향 전송

