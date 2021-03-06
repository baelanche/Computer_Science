## Hello world !

```.c
#include <stdio.h>
int main() {
  printf("Hello world\n");
  return 0;
}
```

처음 C언어를 시작하면 대충 이렇게 생긴 코드를 타이핑하게 된다.

<hr/>

```.c
#include <stdio.h>
```

단어의 시작이 #으로 시작한다면 전처리문을 뜻한다.  
대표적으로 #include, #define 이 있는데 전자는 파일처리, 후자는 정의하는 용도로 사용한다.  
include는 < > 안의 파일을 포함시키겠다는 의미다.  
stdio.h 파일은 Visual Studio를 설치할 때 함께 설치되어서 IDE가 기본적으로 가리키는 라이브러리 경로에 들어있다.  
따라서 저렇게 써주기만 해도 C드라이브 > Program files > VS > ... 로 접근해서 자동으로 include 해주게 된다.

<br/>

>stdio.h 는 Standard input output을 의미하는데, 말그대로 표준 입력 출력이다.  
>컴퓨터의 표준 입/출력은 키보드, 모니터로 위 코드를 실행하면 검은 화면에 'Hello world' 가 출력될텐데  
>표준 출력이 모니터로 설정되어 있기 때문이다.

<br/>

>include 하는 방식은 두가지가 있다.  
>#include <header.h> / #include "header.h" 이다.  
>쌍따옴표로 묶게 되면 현재 작업하는 디렉토리에서 파일을 찾게 된다.  
>파일이 없다면 라이브러리 폴더로 접근하므로 더 큰 개념이라고 볼 수 있다.  
>일반적으로 사용자가 만든 헤더파일을 쌍따옴표로 묶어서 사용한다.

<hr/>

```.c
int main()
```

함수 이름은 main이고 반환자가 int 형이라는 뜻이다.  
중괄호가 닫힐때까지의 영역을 갖는다.

<hr/>

```.c
printf("Hello world\n");
```

화면에 문구를 출력하는 함수이다. \n는 개행문자를 의미한다.

<hr/>

```.c
return 0;
```

이는 안써주어도 무방하다.  
프로그램이 에러없이 종료되었는지를 확인할 수 있다.  
return 한 숫자가 콘솔에 뜬다면 정상 종료된 것이다.
