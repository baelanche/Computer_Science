# Solvable and Unsolvable

풀 수 있는 문제와 풀 수 없는 문제로 나누어 볼 수 있다.

* Unsolvable problems
* Solvable problems
  * Provably intractable (infeasible) problems : 문제를 해결하기 위한 효과적인(polynomial time) 알고리즘이 확실히 없는 문제
  * Probably intractable problems : 문제를 해결하기 위한 효과적인 알고리즘이 아마도 없는 문제
  * Tractable problems (feasible problems) : 문제를 해결하기 위한 효과적인 알고리즘이 있는 문제

## Unsolvable Problems

* halting problem

### Halting problem

어떤 problem 과 input 에 대해 이 problem 이 halt 인지 halt 가 아닌지 판별할 수 있는 머신이 존재하는지 살펴보는 문제를 말한다.

> halting problem is 'undecidable'  
> 명확한 답을 내릴 수 없다.  
> 판별 가능한 머신 H 가 있다고 하자.  
> H 에 halting problem 을 동작시켰다 -> halting problem 인것을 증명하였다 -> 증명이 가능하니 halting problem 이 아니다  
> H 에 halting problem 을 동작시켰다 -> halting problem 이 아니라고 판별하였다 -> H 는 제대로 판별하지 못했다  
> 판별 가능한 머신 H 가 존재한다는 가정이 모순임을 알 수 있다.

<img width="1102" alt="halting" src="https://user-images.githubusercontent.com/48989903/146874011-da808363-161d-4efa-9c1c-d257fd3d5707.png">

Q) 어떤 마을에 스스로 면도하지 않는 남자만을 면도하는 이발사가 있다. 이 이발사는 스스로 면도를 할 수 있는가?

A)
```
이 이발사는 스스로 면도할 수 있다.
스스로 면도하지 않는 남자를 면도한다고 하였으므로 모순된다.
이 이발사는 스스로 면도할 수 없다.
스스로 면도하지 않는 남자를 면도한다고 하였으므로 모순된다.
```

halting problem 은 어떤 답을 선택하든지 모순되는 결과를 낳는다.  
halt/not halt 를 판별하는 프로그램을 만들 수 없다.

## Solvable Problems

* Provably intractable (infeasible) problems
* Probably intractable problems
* Tractable problems (feasible problems)

### Provably intractable (infeasible) problems

문제를 풀 수 있는 polynomial-time algorithm 이 없다고 증명된 문제

* Generalized chess
  * n by n 크기의 체스판에서 이길 수 있는 전략을 구하는 문제 : exponential lower bound : Omega(k<sup>n</sup>), Omega(n!), Omega(n<sup>n</sup>), ...

### Tractable problems

문제를 풀 수 있는 polynomial-time algorithm 이 존재하는 문제

* P problems : O(n<sup>k</sup>) : deterministic Turing machine 에 의해 polynomial-time 에 풀리는 문제
  * sorting

### Probably intractable problems

문제를 풀 수 있는 polynomial-time algorithm 이 아마도 없는 문제

* NP problems : nondeterministic Turing machine 에 의해 polynomial-time 에 풀리는 문제
  * traveling salesman

### Polynomial time algorithms

standard (deterministic) Turing machine 을 통해 polynomial time 에 실행되는 알고리즘

### Deterministic Turing machine

* 튜링머신은 state, input 에 따라 동작한다.
* 튜링머신이 수행할 수 있는 동작의 경우가 1개인 경우 deterministic Turing machine 이라 한다.
  * non-deterministic :
  * delta(p, X) = (q, Y, L)
  * delta(p, X) = (q, X, R)
  * delta 함수가 2개이므로 non-deterministic 이다.

### Nondeterministic Turing machine

* left-hand part(transition function) 에 대해 하나 이상의 transition 을 가지고 있는 경우를 말한다.
* 같은 input 에 대해 다른 output 을 제공한다.
* accept 혹은 halt 의 결과가 나올 수 있다.
* deterministic 의 superset 이다.

### Nondeterminism

튜링머신은 path 가 accept 인지 아닌지 2가지 방법을 통해 찾는다.

* split : 여러 프로그램으로 분기하여 가능한 path 를 찾는다.
* guess : 가능한 path 를 추측하여 찾는다.

