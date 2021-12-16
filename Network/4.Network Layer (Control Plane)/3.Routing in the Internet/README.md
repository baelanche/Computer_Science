# Routing in the Internet

* 네트워크의 규모가 커감에 따라 역할 분담이 생겨나게 된다.
* admin router 는 자신의 네트워크의 router 를 관리하도록 한다.
* 개별의 네트워크를 autonomous sysmtes (AS) 로 명명하여 관리한다.

## intra-AS routing : IGP

* 동일한 AS 내의 host, router 를 routing 하는 방식이다.
* AS 내의 모든 router 는 똑같은 intra-domain protocol 을 사용한다.
* gateway router : 네트워크 외부와 연결되는 router

## inter-AS routing

* AS 간의 routing
* gateway 는 inter-domain routing, intra-domain routing 을 수행한다.

### inter-AS tasks

* AS 내의 임의 router 가 네트워크 외부로 보내지는 datagram 을 받았을 때 어느 네트워크로 보낼지 결정한다.

### Routing protocol : Open Shortest Path First

* link state algorithm 을 사용한다.
* router 는 AS 내의 모든 router 에게 정보를 보낸다.
* IS-IS routing protocol 과 유사하다.
* 모든 OSPF 메세지는 인증절차를 거쳐 보안한다.
* cost 가 같은 여러 path 도 허용한다.
* unicast, multicast(복수의 수신자) 를 지원한다.
* Hierarchical OSPF

#### Hierarchical OSPF

<img width="1056" alt="hiospf" src="https://user-images.githubusercontent.com/48989903/146195279-5909589a-574d-4b29-be51-48e17eef6763.png">

* two-level : local area, backbone
  * area 별로 link state algorithm 을 수행한다.
  * 각 노드는 자신이 속한 area 에 대한 정보만을 가진다.
* area border routers : 다른 area 로 가는 정보를 가진다.
* backbone routers : backbone 내에서만 OSPF routing 을 수행한다.
* boundary routers : 다른 AS 로 연결한다.

