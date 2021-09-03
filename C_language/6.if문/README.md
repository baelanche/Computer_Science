# if

사용자가 제시한 조건에 따라 코드를 수행할지의 여부를 정하는 제어문의 한 종류이다.

```.c
#include <stdio.h>
int main() {
  int a;
  printf("숫자를 입력하세요 ");
  scanf("%d", &a);
  
  if(a == 1) {
    printf("당신의 숫자는 1입니다");
  }
  
  return 0;
}
```

1을 입력했을 때에만 '당신의 숫자는 1입니다' 라는 문구가 출력된다.  
if문은 마치 함수처럼 자신의 영역을 가지고 조건을 만족했을 때 코드가 동작한다.  

숫자 1을 입력한다면 `if(a == 1)`은 `if(1 == 1)`이 될 것이다.  
괄호안에서는 값을 비교하여 true/false를 리턴하게 되는데 이 경우는 참이므로 `if(true)`가 되어 동작을 수행하는 것이다.  
C언어에서는 `if(true)`와 `if(1)`이 같은 동작을 하고 `if(false)`와 `if(0)`가 같은 동작을 한다.
> 자바에서는 `if(1)` 이라고 쓰면 문법적 오류이다.

# if-else

```.c
#include <stdio.h>
int main() {
  int a;
  printf("숫자를 입력하세요 ");
  scanf("%d", &a);
  
  if(a > 10) {
    printf("당신의 숫자는 10보다 큽니다");
  } else {
    printf("당신의 숫자는 10과 같거나 작습니다");
  }
  
  return 0;
}
```

if-else 문을 이용하면 if의 조건에 들어가지 않는 경우를 처리해줄 수 있다.

# 중첩 if-else

```.c
#include <stdio.h>
int main() {
  int a;
  printf("숫자를 입력하세요 ");
  scanf("%d", &a);
  
  if(a > 10) {
    printf("당신의 숫자는 10보다 큽니다");
  } else if(a < 5) {
    printf("당신의 숫자는 5보다 작습니다");
  } else {
    printf("당신의 숫자는 10보다 작거나 같으면서 5보다 크거나 같습니다");
  }
  
  return 0;
}
```

중첩 if-else 문을 이용하면 조건에 따른 여러 경우들을 처리할 수 있다.


### short-coding

```.c
if(a > 10)
    printf("당신의 숫자는 10보다 큽니다");
else if(a < 5)
    printf("당신의 숫자는 5보다 작습니다");
else
    printf("당신의 숫자는 10보다 작거나 같으면서 5보다 크거나 같습니다");
```

조건문안에 수행할 코드가 1줄이면 중괄호를 생략해도 된다.
