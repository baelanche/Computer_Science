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

### bus

![bus](https://user-images.githubusercontent.com/48989903/142761884-08b5e83f-b722-4f50-96e6-89e300eb940a.png)

* bus bandwidth 에 따라 speed 가 결정된다.

### cross bar

![crossbar](https://user-images.githubusercontent.com/48989903/142761969-8d1cbf91-92b4-4098-ab95-dce603feba0a.png)

* bus bandwidth 의 한계를 극복하였음
* 여러 interconnection network 가 연결되어있다.

## Input port

* Head-of-the-Line blocking : 큐의 앞 데이터그램이 블록되면 뒤의 큐들이 앞으로 나아갈 수 없는 현상을 말한다. (queuing)

## Output port

![output_port](https://user-images.githubusercontent.com/48989903/142762180-937d5759-411b-4703-a448-1acc834bd037.png)

* input 속도가 더 빠르면 output port 에서 버퍼링이 일어난다. (queuing)
* L3, L2, L1 순으로 이동한다.
* '스케줄링' 에 따라 큐들이 처리된다.

## Buffering

* Q) 버퍼링을 크게하여 손실이 없게하면 안될까?
* A) 버퍼링이 과도하게 크다면 큐잉현상이 더욱 지속될 것이다. 큐잉이 일어난 패킷의 손실을 발생시키고 새로운 패킷을 받는것이 처리속도가 더 빠를 가능성이 크다.
* 위 이론에 따라 적절한 크기의 버퍼링을 구하는 식이 세워졌다.

![buffering](https://user-images.githubusercontent.com/48989903/142762342-d16b0edf-d9ab-4a0d-b41e-167b105a69e9.png)

* RTT : Round trip time
* C : link capacity
* N : flows

## Scheduling

### FIFO

* 먼저 온 패킷을 먼저 처리한다.
* 큐가 꽉차면 어떻게 처리하는가?
  * tail drop : 가장 마지막의 패킷 drop
  * priority : 우선순위에 따라서 패킷 drop
  * random : 무작위 패킷 drop (random drop 이 일반적이다 -> fairness)

### Priority

* highest priority 패킷을 먼저 보낸다.
* priority 가 적용된 queue 를 multiple 로 사용하기도 한다.

### Round Robin

* multiple class
* 각 클래스별로 한개의 패킷씩을 순차적으로 처리

### Weighted Fair Queuing

* round rotin 기반이다.
* 각 클래스는 얻은 가중치에 따라 처리된다.

