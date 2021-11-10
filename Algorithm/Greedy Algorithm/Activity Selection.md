# Activity Selection

각 활동의 시작 시간, 종료 시간이 주어지며 이 자원들을 스케줄링한다.  
활동들이 겹치지 않도록 하여 가장 많은 활동을 가능하게 자원들을 선택한다.

* Activities : S = [a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>]
* object a<sub>i</sub> has {s<sub>i</sub>, f<sub>i</sub>} : start time, finish time
* a<sub>i</sub> 는 [<sub>i</sub>, f<sub>i</sub>) 만큼의 기간을 가져야 한다. (겹치지 않으므로 최적의 경우가 될 수 있다)

![activity1](https://user-images.githubusercontent.com/48989903/138980286-05e6e86b-1e03-43a2-a9fa-397666cc8ab3.png)

## Greedy Approach

* finish time 을 오름차순으로 정렬한다.
* 구한 값이 unique 한 것은 아니다.


## by Dynamic Programming

![by_dp](https://user-images.githubusercontent.com/48989903/141130541-b3699d5b-2218-4cf0-b9dc-0cd9e95101ee.png)

* subproblem 인 a<sub>k</sub> 를 찾는다.
* 좌측의 A<sub>ik</sub>, A<sub>kj</sub> 또한 optimal solution 이다.
* c[i, j] : S<sub>ij</sub> 의 optimal solution 의 크기
* c[i, j] = c[i, k] + 1(a<sub>k</sub>를 선택했으므로 + 1 이다) + c[k, j]

![by_dp_s](https://user-images.githubusercontent.com/48989903/141131193-5ed8e5bb-f17f-4180-b42d-8050bb66e4e6.png)

점화식으로 나타내면 위와 같다.  
이 식으로 테이블에 모든 경우의 수를 담게 되며 이는 greedy algorithm 보다 효율적이라 보기는 힘들다.

### Proof : In order of finishi time

명제 : S<sub>k</sub> 가 nonempty 이며 S<sub>k</sub> 의 원소 a<sub>m</sub> 가 가장 빨리 종료되는 activity 일 때, a<sub>m</sub> 은 optimal solution 에 포함된다.

* A<sub>k</sub> 는 S<sub>k</sub> 의 optimal solution 이라 하자.
* a<sub>j</sub> 는 선택된 A<sub>k</sub> 중 가장 빨리 끝나는 activity 라 하자.
* 만약 a<sub>j</sub> = a<sub>m</sub> 이면 a<sub>m</sub> 은 optimal solution 에 포함된다.
* 만약 a<sub>j</sub> != a<sub>m</sub> 이면 A<sub>k</sub>' = A<sub>k</sub> - {a<sub>j</sub>} + {a<sub>m</sub>} 이다. A<sub>k</sub>' 는 a<sub>m</sub> 을 포함한 optimal solution 이다.

### Recursive solution

* Original problem : S = S<sub>0</sub>
* choose a<sub>m1</sub>
* next subproblem : S<sub>m1</sub>
* ...

### Pseudo code

