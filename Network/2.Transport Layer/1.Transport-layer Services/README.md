# Transport Layer Services

### "end-to-end"

종단 간 연결을 하는 프로토콜이다.

* send side : 메세지를 segments 단위로 쪼개서 네트워크 계층으로 보낸다.
* receive side : segments 를 다시 메세지로 만들고 애플리케이션 계층으로 보낸다.

### Transport layer vs network layer

* network layer : host(IP address) 간의 논리적 통신
* transport layer : process(Port number) 간의 논리적 통신

## Internet transport layer protocol

* TCP : reliable, in-order
* UDP : unreliable, unordered
* delay guarantees, bandwidth guarantees : X

