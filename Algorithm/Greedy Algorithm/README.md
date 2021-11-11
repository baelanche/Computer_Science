# Greedy Algorithm

주어진 상황에서 매 순간 최선을 선택하는 알고리즘이다.  
이 알고리즘은 항상 <b>최적의 해를 보장해 주지는 않는다.</b>  
dp, divde and conquer 와 달리 문제를 쪼개서 풀어내는 알고리즘이 아니다.  
한번 해를 선택하면 이후에 선택을 바꾸는 경우가 없다.

* Selection procedure : 주어진 상황에서 최적의 해를 선택한다. (locally optimal)
* Feasibility check : 특정 해를 고르는 것이 가능한 상황인지 판단한다.
* Solution check : 해의 집합이 최적의 해인지 판단한다.

## Elements

* locally optimal choice : 매 step 최고의 효율을 가진 해를 선택한다.
* globally optimal choice 가 옳은지 검사해야한다.

## VS Dynamic Programming

* DP
  * 모든 경우를 고려하여 최적의 해를 구한다.
  * subproblem 을 재귀적으로 해결하여 original problem 을 해결한다.
  * bottom-up (also top-down)
* Greedy
  * 매 step 마다 최적의 해를 구한다.
  * 하나의 solution 을 선택하고 subproblem 을 해결한다.
  * top-down

### Knapsack

Knapsack problem 은 greedy algorithm 으로 풀리지 않는 것은 자명하다. (간단한 예로 검증할 수 있다)  
Knapsack problem 은 매 순간 subproblem 의 solution 이 original problem 에 포함시켜도 되는지 검증해야 한다.  
그러나 greedy algotirhm 의 경우는 solution 을 먼저 포함시키기 때문에 문제 풀기에 알맞지 않다.

## Problem

1. [Activity Selection](https://github.com/baelanche/Computer_Science/blob/master/Algorithm/Greedy%20Algorithm/Activity%20Selection.md)
