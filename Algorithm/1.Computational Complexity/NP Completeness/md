# NP Completeness

## NP Class of Problems

```
P : (deterministic) polynomial (P is a subset of NP)
NP : nondeterministic polynomial
```

* Nondeterministic Turing machine 에 대해 만약 guess 한 path 가 모두 right path 라고 가정한다면 solution 이 올바르다는 것을 검증한 셈이다.
* 그러므로 NP 문제를 보이는 것은, 이 solution 이 polynomial-time algorithm 에 대해 유효하다는 것을 보이는 것과 같다.
* Condition of NP Class
  * Decision Problem : solution 에 대해 예/아니오로 대답할 수 있는 문제
  * Certificate : solution 의 조건에 맞는 subset 을 보이는 것
  * verify a certificate
* P 에 속하지 않고 NP 에 속하는 문제가 있는지는 모른다.
* P = NP ? : 컴퓨터 과학 분야에서 아직 증명되지 않은 논제이다.

### e.g., LongPath

* Problem : LongPath(G,k) 에 대하여 graph G 는 최소 k 길이 이상의 path 를 가지고 있는가? 단, path 는 cycle 을 제외하여야 한다.
* Proposition : LongPath(G,k) 는 NP 문제이다.
* Proof
  * LongPath(G,k) 는 decision problem 이다. (O)
  * LongPath(G,k) 가 요구하는 조건에 맞는 certificate 가 존재한다. : 최소 k 길이 이상의 path 를 구성하는 list of vertices
  * certificate 를 증명할 알고리즘이 존재한다.
    * Algorithm for verifying a certificate :
    * Verify(G,k,C)
    * 1. 그래프를 읽고 인접행렬을 구성한다.
    * 2. certificate 를 담은 배열을 읽는다.
    * 3. certificate 의 길이가 k 보다 작으면 false 를 리턴한다.
    * 4. certificate 의 노드 사이에 edge 가 존재하지 않으면 false 를 리턴한다.
    * 5. certificate 의 노드 사이에 cycle 이 존재하면 false 를 리턴한다.
    * 6. true 를 리턴한다.

## NP-Completes Problems

* NP-Complete 는 NP 의 subset 이다.
* NP 문제 중 polynomially reduce 가 가능하면 NP Complete 문제이다.
* NP Complete 문제는 NP 문제 중 가장 어려운 문제이다. (NP Complete 문제를 해결하면 NP 문제도 해결할 수 있다)
* 모든 NP 문제는 polynomial time 안에 NP Complete 문제로 reduce 될 수 있다.
* 모든 NP Complete 문제는 polynomial time 안에 다른 NP Complete 문제로 reduce 될 수 있다.

<img width="222" alt="redu" src="https://user-images.githubusercontent.com/48989903/146932026-9cb9ea5f-ada7-41dc-9874-cb1e4ed7e0fe.png">

* 의미 : Q 는 polynomial time 안에 Q' 으로 reduce 할 수 있다.
* Q' 은 NP Complete 문제 중 가장 어려운 문제이다.

