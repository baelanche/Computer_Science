## Introduction

## Context-free grammar

* recursive structure
  * must has terminating rules
  * cannot be specified regular expression
  
## Derivation

* terminal symbol : leaf
* non-terminal symbol : not leaf

parse-tree : 순서를 나타내지는 않음  
leftmost : 루트 - 왼쪽 - 오른쪽   / preorder - 파싱은 preorder 와 일치 (LL파싱)
rightmost : 루트 - 오른쪽 - 왼쪽 / postorder(왼쪽, 오른쪽, 루트) 의 역순 - 파싱은 postorder 와 일치

parse tree 는 하나만 존재함

두 예제 모두 left most 를 선택하여 왼쪽 심볼을 먼저 터미네이팅함  
파싱은 문제가 없음 -> grammar 가 잘못됨
