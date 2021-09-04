# for문
```.c
#include <stdio.h>
int main() {
  int i;
  for(i=0; i<10; i++) {
    printf("%d\n", i);
  }
  return 0;
}
```

for문은 다음과 같은 구조를 가지고 있다.
```
for(초기식;조건식;증감식) {

}
```

# break 문
```.c
#include <stdio.h>
int main() {
  int a;
  for(;;) {
    scanf("%d", &a);
    if(a == 1) {
      printf("1을 입력하였습니다.\n");
      break;
    }
    printf("%d\n", a);
  }
}
```

위처럼 for문 안에 조건식이 없다면 무한루프를 돌게된다.  
break를 통해 for문 내부에서 반복문을 멈출 수 있다.

# continue 문
```.c
#include <stdio.h>
int main() {
  for(int i=0; i<10; i++) {
    if(i%2 == 0)
      continue;
    printf("%d\n", i);
  }
  return 0;
}
```

continue는 스킵해 버리는 기능을 가지고 있다.  
위 코드에서는 i가 2의 배수일 때 그 반복문 케이스를 스킵해버린다.

# while 문
```.c
#include <stdio.h>
int main() {
  int i = 0;
  while(i < 10) {
    printf("%d\n", i);
    i++;
  }
  return 0;
}
```

for문과 마찬가지로 반복문의 기능을 가지고 있다.
while(조건식) 으로 구성되며 초기식과 증감식은 내/외부에 따로 써주어야한다.

# do-while 문
```c
#include <stdio.h>
int main() {
  int i=0;
  do {
    i++;
  } while(i<1);
  
  printf("%d\n", i);
  
  return 0;
}
```

조건식을 먼저 검사하는 while문과 다르게 do-while은 내부 코드를 먼저 실행한 후 조건식을 검사한다.  
위 코드에서는 먼저 i가 1증가하였고 while의 조건에서 false를 리턴하여 바로 중지되었다.
