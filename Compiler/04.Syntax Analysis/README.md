# Syntax Analysis

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

syntax tree : 토큰 실행 순서에 대해서는 추상화 되어 있음 

Regular Expression vs CFG(Context free grammar)

r.e. 는 CFG 로 바뀔 수 있다.

ambiguous parse tree 를 증명하려면 여러 개의 parse tree 를 만든다.

A -> a : rule  
A => a : A 의 derivation a

elimination recursion

S => Aa => Sda : non-immediate left recursion : 다른 방법으로 없애야 함

Parsing

* Top-down parsing : left-most derivation
* Bottom-up parsing : right-most derivation in reveerse

LL(1)

* 첫번째 L : scan input left to right
* 두번째 L : left-most derivation

### Top-down parsing

* backtracking : 2개 이상의 룰이 있을 때 올바른 token 을 찾지 못하면 되돌아가서 다른 룰을 선택함
* predictive : 유니크한 룰이 있는 경우

LL(1) : 룰의 교집합이 공집합이어야 함

