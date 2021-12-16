# Routing among the ISPs

## inter-AS Routing : BGP (Border Gateway Protocol)

<img width="1117" alt="bgp" src="https://user-images.githubusercontent.com/48989903/146342843-03151be7-742a-422b-85f9-a288a5cfe49d.png">

* 각 AS 에 제공된다.
  * eBGP : subnet 은 이웃 AS 의 도달가능성에 대한 정보를 얻는다.
  * iBGP : AS 내부의 router 들의 도달가능성에 대한 정보를 얻는다.
* BGP sesseion : 두개의 BGP 라우터들이 BGP 메세지에 대한 정보를 주고 받는 것
* AS-PATH : AS 의 리스트
* NEXT-HOP : inter-AS router 의 next-hop AS
* Policy-based routing

<img width="1143" alt="bgp1" src="https://user-images.githubusercontent.com/48989903/146344317-e49b0a0e-7149-4d48-8e81-f5a1a96be124.png">

1. AS3 에 X 네트워크가 가입했다.
2. AS3 의 3a 가 AS2 의 2c 에게 path 정보를 제공한다.
3. AS2 정책에 따라, 2c 는 정보를 받아들이고 AS2 의 라우터들에게 전파한다.
4. AS2 정책에 따라, 2a 를 통해 AS1 의 1c 에게 알린다.

<img width="1150" alt="bgp2" src="https://user-images.githubusercontent.com/48989903/146344522-0c124a1e-544f-4042-8bac-632ce0759cd6.png">

1. AS1 은 2a 를 통해 path 정보를 받았다.
2. AS1 은 3a 를 통해 path 정보를 받았다.
3. AS1 정책에 따라 메세지를 보낼 때 적당한 path 를 선택하여 보낸다.

### BGP messages

* OPEN : BGP peer 에 open TCP connection 
* UPDATE : 새로운 path 를 알림
* KEEPALIVE : connection 상태를 주기적으로 알림
* NOTIFICATION

### BGP route selection

* policy
* shortest AS-PATH
* closest NEXT-HOP router (hot potato routing)
* 부가적인 기준

### Hot Potato Routing

해당 라우터에서 최단시간에 보낼 수 있는 경로를 선택한다.

<img width="1147" alt="hot" src="https://user-images.githubusercontent.com/48989903/146345652-c1df63f3-aa98-475c-9c06-9216907c8c03.png">

* 2d 는 2a 나 2c 를 통해 X 로 가는 경로를 배웠다.
* cost 가 낮은 2a 를 선택한다.

#### different

* intra-AS : performance 중시, single admin 이므로 policy 가 필요 없다
* inter-AS : policy 중시

