# Breath First Search

* Input : graph (directed or undirected), 시작 노드
* Output : 시작 노드에서 목적 노드까지의 최소 거리
* 일반적으로 queue 를 이용하여 구현한다.
* 한번 방문한 노드는 다시 방문하지 않는다.

### Process

1. 시작 노드의 인접 노드를 모두 queue 에 넣는다.
2. queue 의 top 을 dequeue 하며, top 의 인접 노드를 모두 queue 에 넣는다.
3. 2 번을 계속 반복하며 목적 노드에 도착할시 distance 를 계산한다.

### Performance

* enqueue : O(V)
* dequeue : O(E)
* running time : O(V + E)

# Death First Search

* Input : graph (directed or undirected)
* Output
  * 탐색을 시작한 시간
  * 탐색을 마친 시간
* 한번 방문한 노드는 다시 방문하지 않는다.
* 일반적으로 재귀를 이용하여 구현한다.

### Process

1. 시작 노드를 정한다.
2. 인접 노드 중 하나를 선택하여 목적 노드 혹은 더 이상 탐색할 수 없는 지점까지 탐색한다.
3. 2번을 반복하여 원하는 output 을 출력한다.

### Performance

* running time : O(V + E)

