# Lex

* Lex compiler
* Lex language

## Lex Specifications

* declarations
  * variables
  * constants
  * regular definitions : 정규표현식의 이름 선언
* translations rules
  * p<sub>i</sub> { action-i }
  
## Regular Expressions in Lex

* \ : escape expressions
* . : newline 을 제외한 모든 문자
* r{m,n} : m to n occurrences over r - e.g., the{1,5} = the, thethe, thethethe, ...
* r1/r2 : r1 뒤에 r2 가 존재하면 r1
* [m-n] : m to n

e.g., [-+] -> [\-+]

foo or barrrrrrrrrr...  
foo or barbarbarbar...

* yylex() : yyin 에 FILE* 을 매개변수로 넘겨준다. (default : stdin)

* no match : default rule - panic mode
* yytext[] : pointer - lexemes
* yyleng : length of yytext[]

return 이 없으면 다음 token 을 계속 실행한다. return 하거나 eof 를 만날때 까지 실행함.

word count : return 이 없기 때문에 eof 를 만날 때까지 yylex() 가 반복적으로 실행됨

* ECHO : yytext 를 output 으로 복사
* REJECT : 한번 더 가리킴
* input() : 다음 글자를 읽는다.
* output() : 글자를 output 에 쓴다.
* unput(c) : input stream 에 지난 c 개의 글자를 쓴다.
* yywarp() : yylex() 가 eof 를 만났을 때 실행된다. 그 다음 파일을 호출하는 역할을 한다.
* yymore() : 
* yyless(n) : n 글자 만큼을 다시 input stream 으로 되돌려서 출력함
