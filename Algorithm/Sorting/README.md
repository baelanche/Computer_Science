# Insertion Sort (삽입 정렬)

  * Input : (sequence) a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, ..., a<sub>n</sub>
  * Output : (permutation) a<sub>1</sub> <= a<sub>2</sub> <= a<sub>3</sub> <= ... <= a<sub>n</sub>

## Process

```
Input : 8 2 4 9 3 6
Output : 2 3 4 6 8 9
```

첫번째 원소는 비교할 이전 원소가 없으므로 2번째 원소부터 체크한다.

<br/><br/>

![in1](../image/in1.png)

2는 8보다 작으므로 둘의 자리를 바꾼다.

<br/><br/>

![in2](../image/in2.png)

첫번째 비교를 해보니 4는 8보다 작음이 성립했다.  
일단 둘의 위치를 바꾼 후 그 전 원소인 2와도 비교를 한다. 2보다는 작지 않으므로 다음 원소로 넘어간다.

<br/><br/>

![in3](../image/in3.png)

9는 8보다 크므로 아무 변화가 없다.

<br/><br/>

![in4](../image/in4.png)

1. 9와 비교하여 참을 보였다.(더 작다)
2. 8과 비교하여 참을 보였다.
3. 4와 비교하여 참을 보였다.
4. 2와 비교하여 거짓을 보였다.
5. 따라서 2의 다음 위치로 이동하며 4, 8, 9는 한칸씩 밀린 형태가 된다.

<br/><br/>

![in5](../image/in5.png)

6도 같은 알고리즘을 적용하면 위와 같은 결과가 나온다.

<br/><br/>

### Code

```.c
#include <stdio.h>
int main() {
  int n = 6; //배열 크기
  int a[6] = {8,2,4,9,3,6};
  
  int i, key;
  for(int j=1; j<n; j++) {
    key = a[j];
    i = j - 1;
    while (i >= 0 && a[i] > key) {
      a[i+1] = a[i];
      i = i-1;
    }
    a[i+1] = key;
  }
}
```

## Proof : Loop invariants

바깥쪽 반복문에서 `j`번째의 루프 중 subarray `A[1..j-1]`는 이미 정렬된 배열이란 것을 알 수 있다.

이 것을 바탕으로 loop invariant에 대해 세가지 증명을 해야한다.
1. Initialization(루프 돌기 전)
  * Q) 첫번째 루프를 돌기 전 배열은 정렬되어 있는가?
  * A) 크기 1인 배열은 이미 정렬되어 있다. `j=1` 일때 `A[0]`는 정렬된 상태이므로 언제나 정렬된 상태임을 알 수 있다.
2. Maintenance(루프 중)
  * Q) 반복 중에 배열은 정렬되어 있는 상태라고 할 수 있는가?
  * A) 배열의 `j`번째 원소가 내부 루프에 들어갈 때 정렬되어있지 않은 상태라면, 루프 종료시 정렬된 상태가 된다.  
  외부 루프가 한번 돌 때 내부 루프는 종료 시점까지 돈다.
3. Termination(종료)
  * Q) 루프가 종료되어도 정렬된 상태인가?
  * A) 루프는 `j = n + 1`에서 종료된다. `j = n` 시점에서 모든 `j`번째 원소들은 정렬된 상태이다.

## Running time
각 라인은 상수시간이 걸린다고 가정하자.

#### 1. 루프가 없을 때  
1번째 줄은 c<sub>1</sub>의 시간, 2번째 줄은 c<sub>2</sub>의 시간, ..., n번째 줄은 c<sub>n</sub>의 시간이 걸린다.  
루프가 없다면 알고리즘의 실행시간은 c<sub>1</sub> + c<sub>2</sub> + ... + c<sub>n</sub>이 된다.  
상수시간 + 상수시간 + ... + 상수시간은 상수시간이다.  
따라서 루프가 없다면 실행시간은 상수시간이 된다.

#### 2. 루프가 있을 때  
* 루프의 횟수가 상수일 때

  루프의 횟수가 상수라면, 실행시간은 상수시간이다.

* 루프의 횟수가 상수가 아닐 때

  대부분 알고리즘은 인풋에 따라 실행시간이 정해진다.
    1. 인풋이 정렬되어 있다면 정렬에 소비되는 시간이 더 적다.
    2. 인풋의 길이가 긴 것 보다는 짧은 것이 더 빠르게 수행된다.
  
  일반적으로, 실행시간이 최악인 경우를 찾는다.
  
### Analysis

* Cost : 알고리즘에서 수행된 코드 라인의 비용을 나타내는 상수
* Times : 각 줄이 실행될 횟수
* Total cost :  time of algorithm = Cost * Times

### Kinds of analyses

* <b>Worst-case(usually)</b> : 크기 n의 입력에 대한 알고리즘의 최대 시간
* Average-case(sometimes) : 모든 입력값 n에 대한 알고리즘의 예상 시간
* Best-case : 알고리즘이 가장 빠르게 동작하게 인풋을 입력

case ascending sort algorithm :
  * Worst-case : descending : O(n<sup>2</sup>)
  * Best-case : ascending : O(n)

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
