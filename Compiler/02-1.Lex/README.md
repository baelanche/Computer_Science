# Lex

* Lex compiler
* Lex language

[capture]

## Lex Specifications

```
format :


declarations
%%
translation rules
%%
auxiliary procedures
```

* declarations
  * variables
  * constants
  * regular definitions : 정규표현식의 이름 선언
* translations rules
  * p<sub>i</sub> { action-i }
* auxiliary procedures
  * 필요한 procedure 이면 무엇이든 추가할 수 있다.
  
## Regular Expressions in Lex

[capture]

* \ : \ 뒤의 문자는 문자 그대로 읽는다
* . : newline 을 제외한 모든 문자
* r{m,n} : m to n occurrences over r - e.g., the{1,5} = the, thethe, thethethe, ...
* r1/r2 : r1 뒤에 r2 가 존재하면 r1
* [m-n] : m to n

```
e.g., [-+] -> [\-+]

foo|bar* = foo or barrrrrrrrrr...  
foo|(bar)* = foo or barbarbarbar...
```

## Generated Lexical Analyzer

* lex.yy.c 는 yylex() 함수를 포함한다.
* yylex()
  * input file 인 yyin 의 token 을 스캔한다. (default : stdin)
  * EOF 나 return 할 때 까지 실행된다.
  * EOF 에 다다르면 0을 리턴한다.

### Mathces and Actions

* Type of matches
  * 한 개만 일치하는 경우 : 해당 action 을 수행한다.
  * 서로 다른 길이를 가진 두 가지 이상이 일치하는 경우 : 길이가 가장 긴 것을 적용한다.
  * 같은 길이를 가진 두 가지 이상이 일치하는 경우 : 더 앞에 위치한 rule 을 적용한다.
  * 일치하는 것이 없는 경우 : default rule (panic mode) 이 실행된다. (= output 에 다음 문자가 복사된다)

* Variables used in yylex()
  * yytext[] : 인식한 문자열을 가진다.
  * yyleng : token 의 길이를 가진다.
  * yyin : input file 의 FILE* 이다. (default : stdin)
  
* Actions
  * 각 패턴은 일치하는 action 이 존재한다.
  * C 언어 코드이다.
  * return 구문을 포함할 수 있다.
  * | : 다음 rule 을 실행하는 것과 같은 문법이다.

```
Word Count Examples

- return 이 없기 때문에 eof 를 만날 때까지 yylex() 가 반복적으로 실행됨
```

### Special Routines

* ECHO : yytext 를 output 으로 복사
* REJECT : 한번 더 가리킴
* input() : 다음 글자를 읽는다.
* output() : 글자를 output 에 쓴다.
* unput(c) : input stream 에 지난 c 개의 글자를 쓴다.
* yywarp() : yylex() 가 eof 를 만났을 때 실행된다. 그 다음 파일을 호출하는 역할을 한다.
* yymore() : 다음에 일치할 rule 을 yytext 에 쓴다.
* yyless(n) : n 글자 만큼을 다시 input stream 으로 되돌려서 출력함
