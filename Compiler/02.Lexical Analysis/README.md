# Lexical Analysis

## The Role of Lexical Analyzer

* input character 를 읽는다.
* token 을 만든다.

![image](https://user-images.githubusercontent.com/48989903/189040379-9bbcf26d-6b4e-487f-9a46-2944f2a4ec6f.png)

* 실제 기능의 대부분은 parser 가 한다.

## Implementing the Lexical Analyzer

* Hand-written
  * source language 의 token 구조를 다이어그램으로 만든다.
  * 다이어그램을 프로그램화 한다.
* Pattern-directed
  * pattern-action language 를 사용한다.
  * pattern 을 정규표현식의 형태로 묘사한다.
  * e.g., lex

### Tokens

* 의미를 갖는 최소 unit 단위
* 일반적으로 parser 와 통신하는 단위로 쓰인다
* lexemes 을 카테고리 별로 분류한 것
* example
  * keywords : if, then, while, ...
  * operators : plus, minus, ...
  * symbols : comma, ...
  * identifiers, numbers, literal strings

### Lexemes

* input token 을 실제로 나열한 것
* example
  * if, <, position, 60.0, ...

### Patterns

* token 을 나타내는 rule
* 대표적으로 정규 표현식이 있다.
