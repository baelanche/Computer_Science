# The Logical Structure of Compiler

## Lexical Analysis

## Syntax Analysis

* Syntax analyzer or parser performs syntax analysis
* Context Free Grammar (statement, expression)
  * describe recursive rules

## Semantic Analysis

* Semantic analyzer 는 syntax tree 와 symbol table 을 이용하여 semantic consistency 를 검사한다.

## Intermediate Code Generator

* Intermediate code
  * 추상 기계의 프로그램 (기계어가 아님)
  * 변환하기 간단해야 한다.
* A variety of forms

## Code Optimization

* intermidiate code 를 향상시킨다. (folding)

## Code Generation

* assembly code 로 변환시킨다.
