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
* 일반적으로 parser 와 통신하는 단위로 쓰인다.
* lexemes 을 카테고리 별로 분류한 것
* <token name, attribute value> 의 쌍으로 구성된다.
* attribute 가 필요 없을 때는 <const, > 와 같이 value 를 빈 값으로 쓴다.
* example
  * keywords : if, then, while, ...
  * operators : plus, minus, ...
  * symbols : comma, ...
  * identifiers, numbers, literal strings
  
e.g.,

```
position = initial + rate * 60
<id, pointer to symbol table entry for position>
<assign_op, >
<id, pointer to symbol table entry for initial>
<add_op, >
<id, pointer to symbol table entry for rate>
<mult_op, >
<num, integer value 60>
```

### Lexemes

* input token 을 실제로 나열한 것
* example
  * if, <, position, 60.0, ...

### Patterns

* token 을 나타내는 rule
* 대표적으로 정규 표현식이 있다.

#### example

![image](https://user-images.githubusercontent.com/48989903/189618579-54867ecc-5fef-416e-abd7-f8d67e97c2a0.png)

## Lexical Errors

* input 이 어떤 token 과도 매칭되지 않는 경우
* syntax error 의 하나이다. (문법의 오류는 lexical error 가 아니라 syntax error 이다)
* Panic mode : input 을 연속적으로 지워가면서 가장 잘 표현된 token 을 찾는 방식이다.

## Specification of Tokens

* Operations on Languages
  * Union : L or M
  * Concatenation : L and M
  * Kleene Closure : zero or more concatenations of L
  * Closure : one or more concatenations of L
  
## Regular Expressions

* 정규표현식은 문자열의 패턴을 나타낸다.
* 정규표현식은 하나의 language 를 나타낸다.

![image](https://user-images.githubusercontent.com/48989903/189629518-f5654374-434d-43fa-a6b2-91e779752662.png)

* example

![image](https://user-images.githubusercontent.com/48989903/189630433-df5caf60-606d-467d-82f3-bb2c029b4a8c.png)

* Algebraic properties

![image](https://user-images.githubusercontent.com/48989903/189630742-57981c90-3bf5-4b31-87b0-d0f9e9b6931a.png)

대수학에서의 법칙들이 적용된다.

## Regular Definitions

![image](https://user-images.githubusercontent.com/48989903/189631363-f7c0290a-cda9-46ee-ba38-34a412d3e656.png)

## Notational Shorthands

![image](https://user-images.githubusercontent.com/48989903/189631521-d46f4cfd-ef10-4bef-9dcf-7bd53cac5054.png)

## Transition Diagrams

* states
* edges (or transitions)
* actions
  * goto
  * accept
  * retract
  * fail

![image](https://user-images.githubusercontent.com/48989903/189649181-e7f81f7d-4c21-4e0a-ab2a-5cdb975960bb.png)

* The principle of longest string : diagram 중 가장 긴 diagram 을 적용한다.
* 여러개의 transition diagram 을 두고 각각에 대해 token 을 검증한다.
  * 모든 transition diagram 에 대해 fail 이 발생한 경우 lexical error, error recovery 루틴이 발생한다.
* id 와 keyword 를 인식한다.
  * keyword 는 id 의 예외적 경우이다.
  * symbol table 에 id 가 저장되기 전, keyword 를 저장시킨다.
  
  ### Implementing Transition Diagrams
  
  * transition diagram 을 program 으로 변환한다.
  * 각 state 는 어떠한 code 로 변환된다.
  * Non-accepting state
    * 다음 input 에 대해 남아있는 edge 가 있다면 다음 state 로 간다.
    * 남아있는 edge 가 없다면 fail
  * Accepting state
    * retract 를 해야하는지 확인한다.
    * retract 가 필요없다면 token 을 return 한다.
  * fail
    * 다음 transition diagram 으로 이동한다.
    * 다음 transition diagram 이 존재하지 않는다면, error recovery 를 수행한다.
