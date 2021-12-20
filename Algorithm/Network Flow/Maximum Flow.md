# Maximum Flow

* directed graph : flow network
* 각 edge (u, v) 는 capacity, flow 를 가진다.
  * capacity : 최대 수용능력
  * flow : 실제 수용능력
  * 양방향 edge 는 존재하지 않는다.
* source vertex (시작노드), sink/target vertex (도착노드) 가 존재한다.

## Flow network

* Capacity constraint : 0 <= f(u,v) <= c(u,v)
* <b>Flow conservation</b> : u 로 들어오는 flow 의 합은 u 에서 나가는 flow 의 합은 같다.

<img width="903" alt="flow" src="https://user-images.githubusercontent.com/48989903/146674877-fe67e921-d2a9-4cd7-91a7-58dea72415db.png">

* flow/capacity 로 표현한다.
* value of a flow : (Sum of flow out of s) - (Sum of flow into s)
  * Sum of flow out of s : 1 + 2 = 3
  * Sum of flow into s : 0

### Cuts

* cut(S,T) : graph 를 S 와 T(= V-S) 로 나눈다.
  * <b>여기서 S 는 source, T 는 target 을 반드시 포함해야 한다.</b>
* net flow : across cut(S,T) : S 에서 T 로 나가는 flow 의 합 - T 에서 S 로 들어오는 flow 의 합
* capacity of cut(S,T) : S 에서 T 로 나가는 capacity 의 합
* minimum cut of G : 모든 cut 중에 가장 capacity 가 작은 cut

#### Exercise

<img width="865" alt="cut1" src="https://user-images.githubusercontent.com/48989903/146675487-e1ba6040-51ca-44c3-989d-03c3f74b6523.png">

net flow : f(S,T) = 2 + 2 - 1 = 3

<img width="878" alt="cut2" src="https://user-images.githubusercontent.com/48989903/146675502-c1c2878a-aa86-41d4-8998-9258781576d4.png">

net flow : f(S,T) = 2 + 1 + 2 - 1 - 1 = 3

<img width="883" alt="cut3" src="https://user-images.githubusercontent.com/48989903/146675515-30962c63-e837-4849-903d-ba78a1c2fbf4.png">

capacity of cut : c(S,T) = 2 + 3 = 5

<img width="867" alt="cut4" src="https://user-images.githubusercontent.com/48989903/146675528-76f147e1-c4c9-4a99-ae9c-b531cba90d5a.png">

net flow : f(S,T) = 2 + 2 - 1 = 3

<img width="872" alt="cut5" src="https://user-images.githubusercontent.com/48989903/146675532-51e44828-20fd-4e4c-9142-3208cac831b7.png">

capacity of cut : c(S,T) = 3 + 3 = 6

<br/>
<b>어떤 cut 이 주어지던지 net flow 는 항상 같다</b>

#### value of a flow = net flow

Proof : flow conversation  
  
생략

## The Ford-Fulkerson method

* maximum-flow problem 을 해결하는 알고리즘 중 하나이다.
  * Input : flow network G, source s, target t, capacity c
  * Output : maximum value of a flow
* Residual networks 를 사용한다.
  * augmenting path 를 찾음으로써 flow 를 늘려가면서 residual networks 를 구성할 수 있다.

### Residual networks

* edge 에 얼마만의 flow 를 보낼 수 있는지 알려주는 network 이다.
* 양방향 간선이 존재 할 수 있다.
* 각 방향별로 capacity 를 구한 것이 residual capacity 이다.

#### Residual capacity

<img width="889" alt="residualcapa" src="https://user-images.githubusercontent.com/48989903/146676498-475c29d0-809d-46a8-b3f8-37287792b856.png">

<img width="434" alt="rc1" src="https://user-images.githubusercontent.com/48989903/146676828-e336cc71-c349-42d0-89d0-daa0babc4828.png">

flow network 가 주어져 있다.

<img width="428" alt="rc2" src="https://user-images.githubusercontent.com/48989903/146676852-1b8e73bf-3864-4f5f-ae83-c10bd205f924.png">

residual capacity 를 알아보기 위해 양방향 간선을 그린다.

<img width="552" alt="rc3" src="https://user-images.githubusercontent.com/48989903/146676879-c19d4407-f757-4d1b-b534-32bd94e6ab57.png">

* s -> v<sub>1</sub> : flow network 에 s -> v<sub>1</sub> 의 간선이 존재하였으므로 식의 첫번째 조건에 의해 c - f = 16 - 11 = 5 이다.
* v<sub>1</sub> -> s : flow network 에 v<sub>1</sub> -> s 의 간선이 존재하지 않았으므로 식의 두번째 조건에 의해 capacity 를 그대로 써서 11 이다.

#### Example

#### Q) 위 flow network 의 residual network 를 그리시오.

<img width="610" alt="rc4" src="https://user-images.githubusercontent.com/48989903/146676952-11b378e9-dfeb-43bc-9b0d-cced3fec5632.png">

<br/><br/><br/>

#### A)

<img width="608" alt="rc5" src="https://user-images.githubusercontent.com/48989903/146677044-31f94066-f47c-4c8b-8916-bdf21e80aeb5.png">

capacity 가 0 일 경우 생략하여 그리기도 한다.  
양방향 간선이 존재하므로 |residual network| <= 2|E| 이다.  
residual network 를 통해 얼마만큼의 flow 를 더 보낼 수 있는지 판단할 수 있다.

#### Augmenting path

* residual network 를 먼저 그린 후 찾아야한다. (flow network X)
* flow 를 증가시킬 수 있다.
* 얼마만큼의 flow 를 더 보낼 수 있는지 찾는 것이 관건이다.
* 선택한 path 에서 minimum-capacity 를 찾는다.

#### Ford-Fulkerson method

<img width="540" alt="aug1" src="https://user-images.githubusercontent.com/48989903/146724786-557bb509-0032-47b7-9d67-022ffd7652f0.png">

* 위 그림은 차례로 flow network, residual network 이다.
* residual network 에서 하나의 augmenting path 를 선택했다.
* augmenting path 의 capacity 는 5, 4, 5 이므로 minimum-capacity 4 를 선택한다.

<img width="459" alt="aug2" src="https://user-images.githubusercontent.com/48989903/146725072-04a6a63a-d7a3-49ea-a768-a9d370961ffa.png">

* t -> s 방향(반대 방향)으로 augmenting path 값인 4 를 흘려보낸다.
* 따라서 s -> t 방향으로의 capacity 는 4 씩 줄어든다.

<img width="1122" alt="aug3" src="https://user-images.githubusercontent.com/48989903/146725728-7742fde9-740f-4b86-a4d6-5f140e9cf478.png">

* 이를 통해서 만들어진 residual network 는 다시 flow network 로도 표현할 수 있다.
* 더 이상의 augmenting path(s -> t) 를 찾을 수 없다.
* value of a flow
  * 기존 : 11 + 8 = 19
  * ford-fulkerson method 적용 : 11 + 12 = 23

### Example



### Performance

* finding augmenting path : O(V + 2E) = O(E)
* maximum flow : f
* running time : O(Ef)

