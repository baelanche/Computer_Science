# Multiplexing and demultiplexing

![mux_demux](https://user-images.githubusercontent.com/48989903/136920389-94e36cc9-3713-4b51-844f-1998c921ddd0.png)

* sender : 여러개의 소켓으로 데이터를 다룬다.
* receiver : 각 세그먼트를 올바른 소켓에 전달한다. (Port number 로 소켓을 구분할 수 있다)

![segment_format](https://user-images.githubusercontent.com/48989903/136921814-e07c45d4-2fb9-47f4-985e-9f86aa07daa0.png)

* 호스트가 IP datagram 을 받았을 때
   * 각 datagram 은 source IP, destination IP 를 가지고 있다.
   * 각 datagram 은 transport-layer segment 를 운반한다.
   * 각 segment 는 source, destination port number 를 가지고 있다.
* 호스트는 IP addresses, port numbers 를 활용하여 적절한 소켓으로 연결한다.

## Connectionless demux

* 호스트가 UDP segment 를 받았을 때
   * segment 의 destination port 를 확인한다.
   * UDP segment 를 확인한 port 로 보낸다.

```
만약 IP datagram 이 같은 destination port number 를 가지고 있고, source IP address 혹은 source port number 는 서로 다르다면  
(-> 서로 다른 클라이언트들이 같은 포트로 데이터를 보냄)  
같은 소켓으로 전달될 것이다.
```

### Example

![connectionless](https://user-images.githubusercontent.com/48989903/136923976-d55c039f-00e4-4dba-857a-cb245de45eb8.png)

## Connection-orientd demux

* TCP 는 4가지 정보로 식별한다.
   * source IP address
   * source port number
   * dest IP address
   * dest port number
* 서버에서는 동시에 많은 TCP 를 지원할 수 있다.
* 웹서버에서는 클라이언트 별 다른 소켓을 만들어서 이용한다.
   * non-persistent HTTP 는 request 별 다른 소켓을 만들어서 이용한다.

### Example

![connection_oriented](https://user-images.githubusercontent.com/48989903/136925372-ac29bf88-6300-4e92-98ba-8b6a4fb963d9.png)

오른쪽 호스트는 connection 을 두개 이용하고 있다. (source port number 가 다르다)
