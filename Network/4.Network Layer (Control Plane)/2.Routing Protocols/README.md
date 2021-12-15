# Routing Protocols

* link state
* distance vector

### Graph

<img width="1005" alt="graph" src="https://user-images.githubusercontent.com/48989903/146171755-3ea7df0c-a5d9-4b26-943f-9b4b25320ea9.png">

* 간선의 숫자는 cost 이며 낮을수록 좋은 link 이다.
* bandwidth 가 높을수록 cost 는 낮다.
* congestion 이 높을수록 cost 는 높다.

## Routing algorithm

* global
  * 모든 라우터가 link cost, 연결 상태 등의 정보를 가지고 있다.
  * link state 알고리즘으로 분류한다.
* decentralized
  * 모든 라우터가 자기와 연결된 라우터에 한해 link cost 를 알고 있다.
  * 반복적 수행을 통해 정보를 주고 받는다.
  * distance vector 알고리즘으로 분류한다.

### link state

* 특정 시간마다 테이블을 업데이트한다.

#### Dijkstra's algorithm

* source node 로 부터 모든 node 로 가는 cost 를 계산한다.

<img width="1152" alt="dijkstra" src="https://user-images.githubusercontent.com/48989903/146173849-7ef36177-2d35-4c39-b5e1-c2711b18e455.png">

1. 노드 u 로부터의 거리를 구한다.
2. 해당 노드에 인접하였다면 cost 를, 인접하지 않았다면 INF 를 기록한다.
3. cost 중 w 가 가장 낮으므로 다음 노드로 w 를 선택한다.
4. u, w 에 인접한 노드들의 cost 정보를 기록한다.
5. cost 중 x 가 가장 낮으므로 다음 노드로 x 를 선택한다.
6. u, w, x 에 인접한 노드들의 cost 정보를 기록한다.
7. cost 중 v 가 가장 낮으므로 다음 노드로 v 를 선택한다.
8. u, w, x, v 에 인접한 노드들의 cost 정보를 기록한다.
9. cost 중 y 가 가장 낮으므로 다음 노드로 y 를 선택한다.
10. u, w, x, v, y 에 인접한 노드들의 cost 정보를 기록한다.
11. uwxvyz 가 기록된다.

> u 를 중심으로 tree 가 생성된다.  
> 모든 노드를 잇는 network 가 형성된다.  
> tie 가 발생하면 임의로 선택한다. (tree 가 복수개 형성될 수 있다)

* complexity
  * n 개의 노드
  * 매 루프마다 1번의 비교가 줄어든다 : n(n+1)/2 = O(n<sup>2</sup>)
  * 더 효과적으로 구현하면 O(nlogn) 으로 복잡도를 낮출 수 있다.
* oscillations : 전송량에 따라 cost 가 매번 바뀌어서 라우팅이 계속 변하는 현상

### distance vector

#### Bellman-Ford equation

* x 에서 y 로 가는 최소 비용의 link 를 찾는 알고리즘
* 인접 노드에게 cost 정보를 받으면 table 을 새로 업데이트한다.

<img width="1199" alt="distancevector" src="https://user-images.githubusercontent.com/48989903/146189915-5593fa2f-1cca-4b81-9a86-9b1c98084567.png">

1. 각 노드의 테이블에 인접노드에 대한 cost 를 기록한다.
2. 인접노드에게 가는 방법 중 cost 가 가장 적은 경우를 비교하여 기록한다.
3. 연산을 마치면 테이블을 대칭행렬의 모양이 된다.

#### cost 가 변경되었을 경우

* link 와 인접한 노드에서 table 을 업데이트 한 뒤 인접노드에게 알린다.
* 가까운 노드부터 table 을 업데이트 해나간다.
* cost 가 감소된 경우 빠르게 업데이트하고 cost 가 증가된 경우 천천히 업데이트한다.
* 루프가 생길 수 있다.
  * link cost 에 INF 를 대입하여 루프를 사전에 방지한다.

### link state(LS) vs distance vector(DV)

* complexity
  * LS : O(NE)
  * node 의 수가 많을수록 LS 가 불리하고 적을수록 DV 가 불리하다. DV 는 노드끼리 계속 메세지를 주고 받기 때문에 convergence time 이 성능에 영향을 준다.
* convergence
  * LS : O(N<sup>2</sup>)
  * DV : varies
* robustness
  * LS : 노드가 잘못된 link cost 를 알려줄 수 있다.
  * DV : 노드가 잘못된 path cost 를 알려줄 수 있다. 정보를 계속 전파해서 사용하므로 LS 에 비해 고장에 취약하다.

