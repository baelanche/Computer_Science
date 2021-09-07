# Switch

```.c
#include <stdio.h>
int main() {
  int a;
  scanf("%d", &a);
  
  switch (a) {
    case 1:
      printf("choose 1\n");
      break;
      
    case 2:
      printf("choose 2\n");
      break;
      
    case 3:
      printf("choose 3\n");
      break;
      
    case 4:
      printf("choose 4\n");
      break;
      
    default:
      printf("4보다 큰 정수이거나 정수가 아니에요\n");
  }
  return 0;
}
```

괄호안에는 변수가 들어가며 문법은 `switch(변수)` 이렇다.  
`case 값` 으로 분기하며 break문은 웬만해선 써준다.  
스위치문은 break를 통해 스위치를 빠져나가게 되어있다.

만약 case 1 의 break문을 없앤 채로 `a = 1` 을 입력한다면
```
choose 1
choose 2
```
가 출력된다.

또한 `case 값` 에서 값은 무조건 <b>상수</b>여야 한다는 점을 주의해야 한다.

default 는 if-else 문에서 else와 같은 역할을 한다. 사용자가 분기하지 않은 경우에 대해서 이벤트를 받는다.

<br/><br/>

```.c
#include <stdio.h>
int main() {
  char c;
  scanf("%c", &c);
  
  switch (c) {
    case 'a':
      printf("a\n");
      break;
      
    case 'b':
      printf("b\n");
      break;
      
    default:
      printf("uh huh...\n");
  }
  return 0;
}
```

이렇게도 쓸 수 있다.  
문자는 생긴것만 문자일뿐 사실은 아스키코드에서 정의한 상수이므로 스위치문에 적용시킬 수 있다.

# switch vs if

```.c
#include <stdio.h>
int main() {
  int a;
  scanf("%d", &a);
  
  if(a == 1) {
    printf("아\n");
  } else if(a == 2) {
    printf("아아\n");
  } else if(a == 3) {
    printf("아아아\n");
  } else {
    printf("아아아아\n");
  }
}
```

위 코드에서 최악의 경우 if문은 연산을 4번하게 된다.  
예를들어 `a = 7` 이라면 if를 거치고 else if를 두번 거치면서 else까지 총 4번의 연산이다.

반면 switch는 내부적으로 jump table 이란 것을 만들어서 동작한다.  
이 테이블에는 상수에 따른 내부 로직이 적혀 있다.

대충 이런 느낌일 것이다.
|a|logic|
|:---:|:---:|
|1|printf("아\n");|
|2|printf("아아\n");|
|3|printf("아아아\n");|
|-|printf("아아아아\n");|

switch는 이 테이블을 보고 상수와 인풋값을 비교하여 바로 점프하여 실행한다.  
따라서 분기문이 많아도 연산횟수는 늘어나지 않고 테이블의 크기만 커지는 것이다.

또 case '값' 에서 `값` 의 크기가 크지 않고, `값` 이 정렬되어 있고, `값` 끼리의 차이가 크지 않을수록 더 좋은 효율을 발휘한다.

## 더 알아보기

* ### case '상수' 만 되는 이유?
  * 현재 위치에서 index 만큼 jmp 하는 방식이기 때문에 index 는 당연히 정수만 된다. (주소는 정수이니까)

* ### 만약 case 1, case 3, case 4, case 10 과 같이 불규칙적인 값으로 분기하면 컴퓨터는 어떻게 처리할까?
  * if-else 가 동작하는 방식과 index 기반 jmp 방식을 적절히 섞어서 쓸 것이다.
  * 이분탐색 방식은 어떨까?
