# Connectionless Transport : UDP (User Datagram Protocol)

* 기본적인 인터넷 트랜스포트 프로토콜이다.
* "best effort" 이다.
   * 데이터 손실이 있을 수 있다.
   * 순서 보장이 없다.
* Connectionless
   * no handshaking
   * 각 UDP segment 는 독립적이다. (TCP 는 순서가 있기 때문에 연관이 있다)
* 신뢰성 있는 UDP ?
   * 애플리케이션 계층에 신뢰성을 추가한다.

## Segment header

![udp_header](https://user-images.githubusercontent.com/48989903/136927321-ac593c54-3be4-4284-88cd-2ed5159741d7.png)

* length : segment's size (byte)
* no connection sender-receiver
* small header size

### UDP checksum

에러를 감지하는 역할을 한다. (e.g., flipped bits : 비트 표현 에러)

* sender
   1. 16-bits 인 첫번째 수와 두번째 수를 더한다.
   2. 자릿수 올림으로 발생한 수를 맨 끝자리에 더한다.
   3. 1의 보수를 취한다. (1 -> 0, 0 -> 1)

* receiver
   1. 16-bits 인 첫번째 수와 두번째 수를 더한다.
   2. 자릿수 올림으로 발생한 수를 맨 끝자리에 더한다.
   3. sender 가 보낸 결과와 sum 하여 에러를 체크한다. (모두 1이면 YES)
