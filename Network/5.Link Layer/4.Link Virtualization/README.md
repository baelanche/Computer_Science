# Link Virtualization

## MPLS (Multiprotocol Label Switching)

IP 주소 대신 fixed length label 을 통해 forwarding 하기 위해 만들어진 프로토콜

### MPLS capable routers

* label value 에 따라 forwarding (IP forwarding table 과는 별개)
* flexibility : MPLS forwarding 은 IP forwarding 과 다를 수 있다.

<img width="1011" alt="mpls" src="https://user-images.githubusercontent.com/48989903/146533690-d6ee991c-3a8c-4692-bff9-1c2a8cd5f20c.png">

* IP routing 의 경우 destination 에 따라 forwarding 이 결정된다.
* MPLS routing 의 경우 <source, destination> 에 따라 forwarding 이 결정된다.
* 두 routing 의 결과가 서로 다를 수 있다.

### MPLS signaling

<img width="862" alt="signal" src="https://user-images.githubusercontent.com/48989903/146533959-010633d4-7b23-47e0-9769-a5219f8f7b7f.png">

* flooding 을 통해 bandwidth 를 reserved 하고 MPLS router 는 RSVP-TE signal 을 통해 forwarding 한다.

#### e.g., MPLS table

<img width="902" alt="table_ex" src="https://user-images.githubusercontent.com/48989903/146534350-b22557d9-b247-4901-9952-fc8d39f984fd.png">

