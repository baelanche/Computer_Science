# ICMP (Internet Control Message Protocol)

* route 의 이름, IP 주소 등을 담고있다.
* communicate network level (error report, request, reply, ...)
* IP 위에서 동작한다.

## Traceroute

* UDP 를 통해 전송
* 첫번째 전송 TTL = 1
* 두번째 전송 TTL = 2 ...
* 각 전송에 따라 ICMP 메세지를 통해 delay 등을 측정할 수 있다.
* destination 에 도달하면 멈춘다.

