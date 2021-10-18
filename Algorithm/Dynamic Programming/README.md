# Dynamic Programming : 동적할당법

1. 문제를 해결하는데 들어가는 자원을 줄이기 위한 하나의 테크닉이다.
   * 작은 문제들을 해결하여 원 문제를 해결한다. (Divide-and-conquer)
   * 작은 문제들을 테이블에 저장한다. (Memoization)

2. 최적화 문제에 주로 사용된다.

3. 작은 문제들을 해결할 때 중복되는 계산과정이 있다면 divide-and-conquer 보다 dp 가 효과적이라는 것을 알 수 있다.

## VS Divide-and-Conquer

* Divide-and-Conquer : 작은 문제들로 반복적으로 쪼개며 독립적으로 해결한 후 원 문제로 합쳐서 해결한다.
* Dynamic Programming : 작은 문제들로 반복적으로 쪼개며 해결한 값들을 테이블에 저장하여 원 문제에 활용하여 해결한다.

## Proof : cut and paste

올바른 optimal solution 을 세웠는지 증명한다.

* subproblem solution 이 not optimal 이라고 가정한다.
* non-optimal 을 제거하고 optimal solution 을 붙이면 더 좋은 결과를 얻는다.
* 따라서, 이전의 optimal solution 은 optimal solution 일 수 없다.

optimal solution 을 가진다는 것은 optimal subproblem solution 으로 구성되었다는 것을 활용한 증명방식이다.

## Problem

Dynamic programming 기법은 다양한 문제 해결에 적용할 수 있다. 그 중 유명한 문제 몇가지에 적용시켜 보고자 한다.

1. [The longest common subsequence](https://github.com/baelanche/Computer_Science/blob/master/Algorithm/Dynamic%20Programming/LSC.md)  
2. [Knapsack](https://github.com/baelanche/Computer_Science/blob/master/Algorithm/Dynamic%20Programming/Knapsack.md)  
3. [Rod cutting](https://github.com/baelanche/Computer_Science/blob/master/Algorithm/Dynamic%20Programming/Rod%20cutting.md)
