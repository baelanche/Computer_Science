# Analysis

* Cost : 알고리즘에서 수행된 코드 라인의 비용을 나타내는 상수
* Times : 각 줄이 실행될 횟수
* Total cost :  time of algorithm = Cost * Times

### Kinds of analyses

* <b>Worst-case(usually)</b> : 크기 n의 입력에 대한 알고리즘의 최대 시간
* Average-case(sometimes) : 모든 입력값 n에 대한 알고리즘의 예상 시간
* Best-case : 알고리즘이 가장 빠르게 동작하게 인풋을 입력

### Machine-independent time

It depends on the speed of our computer
  * relative speed (on the same machine)
  * absolute speed (on different machine)

->

Ignore machine-dependent constants  
Look at growth of T(n) as n -> infinite

Asymptotic Analysis

Asymptotic?
  * Asymptotic describes the behavior of a function in the limit - for sufficiently large values of its parameter

Asymptotic Notation
* The order of growth of the running time of an algorithm is defined as the highest-order term of an expression that describes the running time of the algorithm
* We ignore the leading term's constant coefficient, as well as all of the lower order terms in the expression

e.g. an<sup>2</sup> + bn + c = simply n<sup>2</sup>

### Big O

Let's say that we have some function that represents the sum total of all the running-time costs of an algorithm

* For a cost algorithm, the running time is : f(n) = cn(logn) + cn
* We want to describe the running time of that sort algorithm in terms of another function, g(n), so that we can say f(n) = O(g(n)) : cn(logn) + cn = O(g(n))

big O : 상한선 : upper bound

### Proof : fn < O(g(n)) (TEST!)

1. c(c > 0)와 n<sub>0</sub>(n<sub>0</sub> >= 0) 가 존재함을 증명
  * e.g. f(n) = 7n - 2 / g(n) = n
  * condition : 7n - 2 <= cn
  * c = 7, n<sub>0</sub> = 1 일때 성립
