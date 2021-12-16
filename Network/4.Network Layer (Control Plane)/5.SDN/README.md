# SDN (Software Defined Networking)

* 배경 : monolithic router 의 형성
* logically centralized control plane 로의 변화
* distributed -> centralized
* table-based forwarding

### Traffic engineering

* 기존의 라우팅 알고리즘(ls, dv)이 아닌 다른 path 로 전송하고자 할 때 바꿀 수 없다.
* 새로운 라우팅 알고리즘을 추가해주어야 가능한데, 이를 개선하고자 SDN 을 도입하였다.

## SDN perspective

* generalized forwarding
* control/data plane 분리
* 프로그래밍 가능한 routing

### 1. Data plane switches

* generalized data plane forwarding 을 통해 빠르고 간편하게 switch 세팅
* switch flow table 은 controller 에 의해 계산, 설치 된다.
* protocol 은 controller 에 정의되어 있다.

### 2. SDN Controller : Network OS

* 네트워크의 state 유지보수
* data plane, control plane 사이에 위치하여 상호작용한다.

### 3. Control applications

* 하드웨어와 완전히 분리되어있다.
* routing, access control, load balance 등을 수행한다.

## Components of SDN controller

<img width="715" alt="sdn" src="https://user-images.githubusercontent.com/48989903/146351607-5076ec3f-990b-44ca-b5e2-fd68e7e5c56f.png">

### OpenFlow protocol

* TCP 사용
* controller <-> switch

### interaction example

<img width="596" alt="controller" src="https://user-images.githubusercontent.com/48989903/146353319-0198b8b5-83dc-4d23-9f72-4723501c566a.png">

1. s1 은 OpenFlow 를 통해서 controller 에 메세지를 보낸다.
2. controller 는 OpenFlow 메세지를 받고 link-status info 를 업데이트한다.
3. Dijkstra's algorithm application 은 이 정보를 등록한다.
4. Dijkstra's algorithm application 은 새로운 계산 결과를 계산하여 보낸다.
5. link status info 는 flow table 과 상호작용한다.
6. controller 는 OpenFlow 를 통해 switch 에 업데이트된 새로운 table 을 설치한다.

### Challenge

* dependable, realiable, performance-scalable, secure

