# Breath First Search

* Input : graph (directed or undirected), 시작 노드
* Output : 시작 노드에서 목적 노드까지의 최소 거리
* 일반적으로 queue 를 사용하여 구현한다.

### Process

1. 시작 노드의 인접 노드를 모두 queue 에 넣는다.
2. queue 의 top 을 dequeue 하며, top 의 인접 노드를 모두 queue 에 넣는다.
   * 한번 방문한 노드에 대해서는 다시 queue 에 넣지 않는다.
4. 2 번을 계속 반복하며 목적 노드에 도착할시 distance 를 계산한다.

### Performance

* enqueue : O(V)
* dequeue : O(E)
* running time : O(V + E)

