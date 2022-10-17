# Automata

* 정규표현식과 밀접한 관계를 가진다.
* 모든 NFA 는 DFA 로 변환될 수 있다.
  
## Nondeterministic Finite Automata
  
* 구성요소
  * S : state 의 집합
  * Sigma : input symbol 의 집합
  * T : transition function
  * s<sub>0</sub> : start state
  * F : accepting state 의 집합 (accepting state : 오토마타가 모든 입력값을 처리했을 때의 상태 집합)
* final state(=accepting state) 로 가는 경로가 여러 개일 수 있다.
* symbol 이 하나 이상이거나 입실론인 경우 nondeterministic 이다.
  
## Deterministic Finite Automata

* 구성요소
  * S : state 의 집합
  * Sigma : input symbol 의 집합
  * T : transition function
  * s<sub>0</sub> : start state
  * F : accepting state 의 집합
* Epsilon 이 없다.
  
## NFA to DFA

[capture]

* Subset Construction
  * 한 state 에서 다른 state 로 갈 때 이동가능한 경로를 하나로 묶음
  
### Regular Expression to NFA

Optimizing DFA : 심볼이 a / b 일 때 같은 성질을 가진 것끼리 묶임

### DFA to Regular Expression

해당 부분은 다루지 않는다

ex 1 : (bb + b) -> (ab + b)
