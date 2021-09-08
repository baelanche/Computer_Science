# Analysis

* Cost : 알고리즘에서 수행된 코드 라인의 비용을 나타내는 상수
* Times : 각 줄이 실행될 횟수
* Total cost :  time of algorithm = Cost * Times

### Kinds of analyses

* <b>Worst-case(usually)</b> : 크기 n의 입력에 대한 알고리즘의 최대 시간
* Average-case(sometimes) : 모든 입력값 n에 대한 알고리즘의 예상 시간
* Best-case : 크기 n의 입력에 대한 알고리즘의 최소 시간

### Machine-independent time

시간은 컴퓨터의 성능에 좌우된다.
  * relative speed (on the same machine)
  * absolute speed (on different machine)

컴퓨터에 좌우되지 않는 방법을 찾기 위해 n을 무한대로 보내 total cost 를 찾는 방법을 고안하였다.

<br/><br/>

# Asymptotic Analysis

Asymptotic?
  * 충분히 큰 입력값으로 함수의 한계 내 동작을 얻는 방법이다.

Asymptotic Notation
* 알고리즘의 실행 시간 증가 순서는 실행시간을 설명하는 식의 최고차수의 항으로 정의된다.
* 하위차수의 항과 상수는 무시한다.

`e.g.` an<sup>2</sup> + bn + c -> n<sup>2</sup>

<br/><br/>

## Big O

알고리즘의 모든 실행 시간 비용의 합계를 나타내는 함수가 있다고 하자.

* 비용함수 f(n) 의 실행 시간 f(n) = cn(logn) + cn
* 다른 함수의 관점에서 정렬 알고리즘의 실행 시간을 표현할 것이다.
  * f(n) = O(g(n)) 이 되는 g(n)을 만든다.
  * O(g(n)) = cn(logn) + cn 이 된다.
    * c : multiplicative constant
    * n<sub>0</sub> : threshold

### Proof

0 <= f(n) <= cg(n) 이 성립함을 보이자.  
위 식을 만족시키는 c(c > 0)와 n<sub>0</sub>(n<sub>0</sub> >= 0) 가 존재함을 증명할 것이다.

#### e.g.1) f(n) = 7n - 2
  * g(n) 은 f(n) 의 최고차수인 n을 받아 g(n) = n 이다.
  * 적당한 c 를 선택한다. 여기서는 c = 7 로 진행할 것이다.
  * n<sub>0</sub> 도 마찬가지로 대입해본다. n<sub>0</sub> = 1 을 대입해보니 성립한다.
  * n이 n<sub>0</sub> = 1 보다 같거나 클 때 f(n)이 cg(n) 보다 항상 작으므로 전제가 성립한다.
  * 따라서 f(n) = O(g(n)) 이다.

![threshold](../image/threshold.png)

  * n<sup>0</sup> 를 기준으로 전제조건이 항상 성립한다.(n<sup>0</sup> : threshold)
  * g(n) 은 f(n) 의 점진적 상한선이다.

#### e.g.2) f(n) = n<sup>3</sup> + 100n<sup>2</sup>, g(n) = n<sup>3</sup>
  * f(n) = O(g(n)) 증명
  * c = 1 
  * n<sub>0</sub> = 

  * g(n) = O(f(n)) 증명
