# Overview of Network Layer

* forwarding : 라우터의 패킷을 어느 라우터로 보낼지 결정하는 기능
* routing : 어느 라우터를 타고 도착지로 갈지 결정하는 기능

## Data plane

라우터 입력 포트에 도착한 데이터그램이 라우터 출력 포트로 포워딩되는 방법을 결정한다.

## Control plane

데이터그램이 source host 에서 destination host 로 end-end path 를 따라 라우터들 사이에서 라우팅되는 방법을 결정한다.

### Per-router control plane

각각의 모든 라우터들이 control plane 내에서 개별적인 routing algorithm 을 통해 상호작용한다.

![control_plane](https://user-images.githubusercontent.com/48989903/140701949-fcf9ea62-01c2-4c55-8a21-e7aa45b83361.png)

### Locally centralized control plane

각 controller 가 local control agent (CAs) 를 통해 상호작용한다.

![control_plane_central](https://user-images.githubusercontent.com/48989903/140702267-f4ba8781-aeff-4b06-ac97-686361f0ae2a.png)
