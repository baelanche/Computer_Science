# Automata

## Introduction

* Finite Automata
* Two Types
  * Deterministic finite automata (DFA) vs Non-deterministic finite automata (NFA)
  * 모든 NFA 는 DFA 로 변환될 수 있다.
  
* Nondeterministic Finite Automata
  * final state 로 가는 경로가 여러 개일 수 있다.
  * symbol 이 하나 이상이거나 입실론인 경우 nondeterministic
  
* Deterministic Finite Automata
  * no Epsilon
  
### NFA to DFA

[capture]

* Subset Construction
  * 한 state 에서 다른 state 로 갈 때 이동가능한 경로를 하나로 묶음
  
### Simulation of NFA

### Regular Expression to NFA

Optimizing DFA : 심볼이 a / b 일 때 같은 성질을 가진 것끼리 묶임

### DFA to Regular Expression

다루지 않음

ex 1 : (bb + b) -> (ab + b)
