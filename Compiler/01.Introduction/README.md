# Introduction to Compiler

* Language Process
* Programs Releated to Compilers
* The Structure of a Compiler
* Major Data Structures in a Compiler

## Language Process

### Compilers

* 컴파일러는 하나의 언어를 다른 언어로 바꾸는 컴퓨터 프로그램이다.
* source language 와 target language 라고 명명한다.

![image](https://user-images.githubusercontent.com/48989903/188639802-94ad8a55-6cf2-457b-a20a-ea2e6ba3f337.png)

* 다양한 source language, target language, compiler 가 존재한다.

### Interpreters

* 인터프리터는 source programs, input 을 읽고 기계어로 번역하지 않고 즉시 실행한다.
* 인터프리터는 주로 다음과 같은 역할들을 한다.
  * interactive execution
  * dynamic typing
  * better error diagnotics, 기계어로된 프로그램보다는 느리다.
  
### Hybrid Approaches

* 컴파일과 인터프리트가 결합된 형태이다.

![image](https://user-images.githubusercontent.com/48989903/188641970-9e67d453-21e9-4d1f-8f5d-a8caf4e04eef.png)

* Intermediate representation(e.g., java bytecode) 는 다른 가상머신(e.g., jvm) 에 의해 인터프리트될 수 있다.
* 느린 실행속도의 보완이 가능하다.

## Programs Releated to Compilers

* assemblers
* linkers
* loaders
* processors
* debuggers
* ...

## The Logical Structure of a Compiler

![image](https://user-images.githubusercontent.com/48989903/188642880-a47a55d8-c3c3-4267-940e-3246fb35dec8.png)

### Lexical Analysis

* Lexical Analyzer 는 input 값들을 의미있는 가장 작은 유닛으로 쪼갠다. 쪼개진 token 은 <name, attribute> 의 형태를 띈다.
* example

![image](https://user-images.githubusercontent.com/48989903/188868336-7796778e-1b3d-481c-91b8-6224b53da33c.png)

* symbol table 과 literal table 을 이용하여 동작한다.

### Syntax Analysis

* Syntax analyzer or parser performs syntax analysis
  * token 을 그룹핑한다.
  * parse tree 나 syntax tree 를 만든다.
* Context Free Grammar (statement, expression)
  * describe recursive rules
  * expression

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
