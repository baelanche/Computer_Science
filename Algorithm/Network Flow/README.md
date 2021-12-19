# Network Flow

## Representations of Graphs

* G = (V, E)
  * G : graph
  * V : vertex (노드)
  * E : edge (간선)
* 그래프는 directed, undirected 가 있다.
* 그래프는 일반적으로 두가지 방법으로 표현한다.
  * 인접 리스트
  * 인접 행렬

### Adjacency list

<img width="907" alt="adjlist" src="https://user-images.githubusercontent.com/48989903/146671508-3de7b396-1ea4-43b2-a3a7-e29e987aeabf.png">

* 각 vertex 는 인접 노드에 대한 인접 리스트를 가지고 있다.
* 만약 edge 에 weight 가 있다면 리스트에 함께 넣어준다.

<img width="815" alt="adjlist2" src="https://user-images.githubusercontent.com/48989903/146671548-6a71728a-0962-4917-8982-3b4b78d3ca3e.png">

* directed graph 인 경우도 마찬가지로 구성한다.

### Adjacency matrix

<img width="1156" alt="adjmatrix" src="https://user-images.githubusercontent.com/48989903/146671628-0876e5f5-4172-4a9c-8d34-45bfcebd429b.png">

* 노드간에 연결되어 있으면 1, 연결되어 있지 않으면 0 으로 행렬을 채운다.

<img width="1133" alt="adjmatrix2" src="https://user-images.githubusercontent.com/48989903/146671651-40364bc9-dc9d-4d96-abc8-137aa0e518ec.png">

* directed graph 인 경우도 마찬가지로 구성한다.

## Problem

1. BFS & DFS
2. Minimum Spanning Tree (Prim's algorithms)
3. Maximum Flow (The Ford-Fulkerson method)
