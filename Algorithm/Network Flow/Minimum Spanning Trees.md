# Minimum Spanning Trees

* n 개의 스테이션이 연결된 네트워크를 고려해보자.
* 링크는 두개의 스테이션 사이에 cost 를 가지고 존재한다.
* 모든 스테이션에 최소 비용으로 메세지를 보내는 방법을 고려하자.

### e.g., Central office

![mst_central](https://user-images.githubusercontent.com/48989903/143403821-4181ef01-7cd6-4071-a3e2-f6618849c626.png)

* 모든 링크를 독립적으로 이어야하므로 효율이 안좋다.
* 더 효과적인 방법으로 구현해보자.

## Introduction

* Input : connected, undirected graph G = (V, E), 각 edge 는 cost 를 가지고 있다.
* Output : acyclic subset T (사이클이 없는 egde 들의 모임 T)
  * T 의 노드들은 모두 연결되어 있다.
  * cost 의 합은 최솟값이다.

## Properties

* egdes : |V| - 1
* no cycles
* not unique

## Solution

* Kruskal's algorithm (다루지 않을 것임)
* <b>Prim's algorithm</b> (greedy)

## Generic MST algorithm

* egde 가 없는 집합 A 가 있다.
* A 에 egde 를 하나씩 추가하며 loop invariant 를 언제나 유지한다.
* loop invariant
  * A 는 MST 의 subset 을 만족한다.
  * A 가 MST 의 subset 이고 A U (u, v) 가 MST 의 subset 이라면 egde (u, v) 는 A 에 대해 safe 하다고 한다.
  * MST 는 언제나 safe egdes 만을 추가한다.

### Proof : loop invariant

증명 : A 는 MST 의 subset 이다.

* Initialization : empty set 은 loop invariant 를 만족한다.
* Maintenance : safe egdes 만을 A 에 추가하기 때문에, A 는 MST 의 subset 을 만족한다.
* Termination : A 에 추가된 모든 edge 들은 MST 이다. 따라서, A 는 MST 이다.

### safe edge 를 어떻게 찾는가?

* 전체집합 V 를 S, V-S 로 나눈다.
* edge (u, v) 가 각각 S, V-S 에 endpoint 를 가지고 있다면, (S, V-S) 를 cross 한다고 표현한다.
* A 집합의 어느 edge 도 cross 하지 않으면 A 집합의 edge 들은 cut 을 respect 한다고 한다.
* crossing edge 들 중 가장 cost 가 낮은 edge 를 light edge 라 한다.

![mst_ctc](https://user-images.githubusercontent.com/48989903/143415467-52a56895-8b17-4768-849b-ee24d340f8dc.png)

* S = {a, b, d, e}
* V - S = {h, i, g, c, f}
* edge (a, b), (c, i), (h, g), (c, f), (g, f) 모두 cross the cut 이 아니므로 repect 하다.

### 그래서?

* (S, V-S) 를 respect 하는 edge 가 A 에 있다.
* (u, v) 는 (S, V-S) 를 cross 하는 light edge 일 때 (u, v) 는 A 의 safe edge 이다.

![mst_ctc_ok](https://user-images.githubusercontent.com/48989903/143417195-7831ca86-1efe-49e4-99c4-d2c0cd65214c.png)

* 먼저 A 집합을 구성한다.
  * (a, b), (c, i), (h, g), (c, f), (g, f)
  * 이들은 모두 MST 를 만족하며 respect 하다.
* light edge 를 찾아서 연결한다.
  * cross the cut 이라면 safe edge 가 된다.

## Prim's algorithm

* generic algorithm 을 변형해서 사용한다.
* safe edge 를 찾는 특정 룰이 존재한다.
* Dijkstra's algorithm 과 유사한 면을 보인다.

### Properties

* 집합 A 는 언제나 single tree 이다. (사이클이 없다)
* 이 tree 는 루트 트리 r 에서 모든 노드를 span 할 때까지 자란다.
* 매 step 마다 tree A 에 cross the cut 하는 light edge 를 추가한다.
* 알고리즘이 종료되면 A 는 MST 가 된다.

### find light edge

* priority queue Q 를 이용한다.
  * queue 에는 edge 를 구성하지 않는 vertex 가 들어가있다.
  * vertex 의 (u, v) 중 가장 작은 cost 가 key 가 된다.
  * vertex.key 의 초기값은 inf 이고 root vertext.key 는 0 이다.
  * Q 는 min-priority queue 로 구성된다.

### Process

* 초기 Q = {0, inf, inf, inf, inf, inf, inf, inf, inf, inf}

![mst_prim](https://user-images.githubusercontent.com/48989903/143424219-23373809-5fc4-45b3-b1ad-a6f748b4e25d.png)

1. min-priority 이므로 root vertex 부터 인접 노드에 연결을 시작한다.

![mst_prim2](https://user-images.githubusercontent.com/48989903/143427508-92fe5906-c9ea-4723-9126-6830b053d379.png)

2. b.key = 4, h.key = 8 로 업데이트한다. (Q = {4, 8, inf, ...})

![mst_prim3](https://user-images.githubusercontent.com/48989903/143427519-f1ba40d5-c5e4-4853-874b-37d172ee2185.png)

3. b 노드가 선택되어 c.key = 8 로 업데이트한다. h.key 는 8이 더 작으므로 업데이트 하지 않는다. (Q = {8, 8, inf, ...})

![mst_prim4](https://user-images.githubusercontent.com/48989903/143427535-7c84f4fd-976d-4110-8637-d8a92c633437.png)

4. c, h 가 동일한 min key 이므로 c 를 선택하여 진행하겠다.
5. i.key = 2, f.key = 4, d.key = 7 로 업데이트한다. (Q = {2, 4, 7, 8, inf, inf})

![mst_prim5](https://user-images.githubusercontent.com/48989903/143427751-7847b38a-6f80-471d-9f31-decca8bc9c04.png)

6. i 노드가 선택되어 h.key = 7, g.key = 6 으로 업데이트한다. c 는 dequeue 되었으므로 업데이트 하지 않는다. (Q = {4, 6, 7, 7, inf})

![mst_prim6](https://user-images.githubusercontent.com/48989903/143427768-4ffaceee-9cd5-4fe1-a890-04f0cfa52278.png)

7. f 노드가 선택되어 g.key = 2, e.key = 10 으로 업데이트한다. d.key = 7 로 14 보다 작으므로 업데이트 하지 않는다. (Q = {2, 7, 7, 10})

![mst_prim7](https://user-images.githubusercontent.com/48989903/143427787-8e8b27c2-7d24-41b8-a0fc-6d036e69f628.png)

8. g 노드가 선택되어 h.key = 1 로 업데이트한다. (Q = {1, 10, 7})

![mst_prim8](https://user-images.githubusercontent.com/48989903/143427797-d8da31e9-0b81-4506-bb6b-deae7da86d63.png)

9. h 노드가 선택된다. (Q = {7, 10})

![mst_prim9](https://user-images.githubusercontent.com/48989903/143427810-c2a83a0c-0c20-4e38-bbba-754285c92c76.png)

10. d 노드가 선택되어 e.key = 9 로 업데이트한다. (Q = {9})

![mst_prim10](https://user-images.githubusercontent.com/48989903/143427827-93d0cefa-013a-4780-9686-9fd3e7fd8df5.png)

11. e 노드가 선택된다.
12. 큐가 비었으므로 알고리즘이 중지된다.

### Performance

* Q 를 채우는 과정 : O(nlogn)
* 내림차순 정렬 : O(logn)
* 탐색 과정 : O(nlogn) : dequeue(n) x 탐색(logn)
* 따라서, O(nlogn)

