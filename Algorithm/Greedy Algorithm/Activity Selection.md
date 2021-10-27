# Activity Selection

각 활동의 시작 시간, 종료 시간이 주어지며 이 자원들을 스케줄링한다.  
활동들이 겹치지 않도록 하여 가장 많은 활동을 가능하게 자원들을 선택한다.

* Activities : S = [a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>]
* object a<sub>i</sub> has {s<sub>i</sub>, f<sub>i</sub>} : start time, finish time
* a<sub>i</sub> 는 [<sub>i</sub>, f<sub>i</sub>) 만큼의 기간을 가져야 한다. (겹치지 않으므로 최적의 경우가 될 수 있다)

![activity1](https://user-images.githubusercontent.com/48989903/138980286-05e6e86b-1e03-43a2-a9fa-397666cc8ab3.png)

## Greedy Approach

* finish time 을 오름차순으로 정렬한다.


## by Dynamic Programming

