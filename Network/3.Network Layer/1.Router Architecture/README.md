# Router Architecture

![router_arc](https://user-images.githubusercontent.com/48989903/141787159-aa5157dc-9a35-42f6-ac9a-02d994ccbcce.png)

* data plane : hardware
* control plane : software

## Input port functions

![router_arc_detail](https://user-images.githubusercontent.com/48989903/141787832-ce9f6801-2ed7-410c-8d40-d8ee89654610.png)

* line termination : physical layer
* link layer protocol : data link layer
* queueing : transport layer
  * decentralized switching : 헤더를 읽고 테이블에서 output port 를 찾음
    * destination-based forwarding (일반적) : IP 주소에 따라 포워딩
    * generalized forwarding : 헤더 필드 값에 따라 포워딩

## Destination-based forwarding

![forwarding_table](https://user-images.githubusercontent.com/48989903/141788854-6595de90-1a5c-4f1c-b998-4ffa026f17fd.png)

* 해당 주소 범위 내의 IP 를 특정 인터페이스로 보내게 하는 방식
* 라우팅 알고리즘을 통해서 범위를 정한다.

### Longest prefix matching

![longest_prefix_matching](https://user-images.githubusercontent.com/48989903/141789625-5781eb9f-b27c-40a2-b35d-2a687cfc2819.png)

* 주소의 prefix 가 어떤 entry 와 일치하느냐에 따라 인터페이스를 분기하는 방식이다.
* e.g.
  * <b>11001000 00010111 00010</b>110 10100001 : link 0
  * <b>11001000 00010111 00011000</b> 10101010 : link 1

## Switching fabrics

* input buffer 에서 output buffer 로 전송하는 역할
* memory / bus / crossbar 형태로 구현한다.

### memory

![via_memory](https://user-images.githubusercontent.com/48989903/141791799-bbaf71b0-3ac3-4828-87e6-c641ea71ab34.png)

* input port -> memory -> output port
* 패킷을 메모리에 복사하여 이동시킨다.
* memory bandwidth 에 의해 속도가 결정된다.

