# Casting

```.c
#include <stdio.h>
int main() {
  int a;
  float b = 1.1;
  
  a = b;
  printf("%d", a);
}
```

int형 변수에 float를 대입하고 출력하면 어떻게 될까?

```.bash
1
```

소수점이 짤린채로 컴파일은 완료되지만 경고를 발생시켰다.  
%f 로 출력하지 않아서 소수점이 짤린게 분명하다.


printf("%f", a); 로 고쳐주었다.

```.bash
0.00000
```

더 괴상한 수가 나온다.

이는 변수 타입별로 메모리 상에 다르게 저장되기 때문이다.

<br/><br/>

## 부동소수점

실수타입은 부동소수점 방식을 사용하여 메모리에 값을 저장한다.  
부동이란 떠다닌다는 뜻인데 float 가 여기서 유래되었다.  
실수를 저장하는 다른 방법으로 고정소수점이 있으나 더 넓은 범위의 수를 표현할 수 있는 부동소수점 방식을 절대 다수의 컴퓨터에서 사용한다.

자료형 중 float는 부호에 1비트, 지수부에 8비트, 가수부에 23비트를 사용한다.  
이를 고정소수점 방식으로 구현했다면 2<sup>8</sup>보다 큰 수는 표현할 수 없을 것이다.  
반대로 부동소수점에서는 정규화라는 방식을 취하는데, 식은 아래와 같다.

(1.가수부) x 2<sup>지수부-127</sup>

한번에 와닿는 식은 아닌 것 같다.  
예를 들어 1111101011.101 이런 수가 있다면 1.111101011101 × 2<sup>9</sup> 이렇게 나타내어 32비트 내로 구현할 수 있다는 것이다.

자세히 알아보자.

* <b>2진법 소수 -> 10진법 소수</b>

10010.1111<sub>(2)</sub> = 2<sup>4</sup> + 2<sup>1</sup> + 2<sup>-1</sup> + 2<sup>-2</sup> + 2<sup>-3</sup> + 2<sup>-4</sup>

2진법으로 표현된 모든 소수는 10진법으로 변환이 가능하다.

* <b>10진법 소수 -> 2진법 소수</b>

-118.625 = -1110110<sub>(2)</sub> - 2<sup>-1</sup> - 2<sup>-3</sup> = -1110110.101<sub>(2)</sub>
  
잘 바뀐다.  
하지만 0.5, 0.25, 0.125 와 같은 수 말고 0.1, 0.01 도 바꿀 수 있을까?

0.1 = 2<sup>-4</sup> + 2<sup>-5</sup> + 2<sup>-8</sup> + 2<sup>-9</sup> + ... = 0.0001100110011...<sub>(2)</sub>

무한 소수가 나타난다.  
컴퓨터는 이런 무한 소수를 메모리에 다 담아낼 수 없기 때문에 필연적으로 오차가 발생하게 된다.

## IEEE 754

IEEE 754는 IEEE에서 개발한 컴퓨터에서 부동소수점을 표현하는 가장 널리 쓰이는 표준이다.

먼저 부호 비트에는 양수는 0, 음수는 1 이 할당된다.

두번째로 정규화 과정을 거친다. 정규화를 통해 `1.xxx` 꼴로 수를 표현한다. 이 때 몇번의 시프트가 일어났는지 계산하여  
시프트 연산의 횟수를 지수에 할당한다.

무한 소수의 경우 반올림 처리를 한다. float 를 예로들면 가수부가 23bit 이므로 24번째 bit에서 반올림한다.  
따라서 컴퓨터에는 소수점 이하 23자리가 저장된다.

마지막으로 계산한 지수에 바이어스 처리를 해준다. 이 과정은 지수에 2<sup>e-1</sup> - 1 을 더하는 과정이다.  
여기서 `e` 는 지수 부분의 비트수이다. float 이면 8, double 이면 11 이 된다.

왜 바이어스 처리를 하는 걸까?  
정규화 과정을 거쳤을 때 왼쪽으로 시프트 되는 경우가 있기 때문이다.  
왼쪽 시프트가 1번 일어났다고 하면 지수가 `-1` 이 되는데, 이것을 양수로 바꿔주는 것이 컴퓨터 입장에서 연산이 편하다.

이 과정까지 거치면 float 의 경우 지수의 값이 1 ~ 254 가 된다.  
원래 float 의 범위가 0 ~ 255 를 나타내지만 IEEE 754 에서는 0과 255를 다르게 처리한다.

|종류|지수부|가수부|
|:---:|:---:|:---:|
|비정상 수|0|0이 아님|
|무한대|2<sup>e-1</sup>|0|
|수가 아님(NaN)|2<sup>e-1</sup>|0이 아님|

### 비정상 수

바이어스 처리를 해도 1 이상이 되지 않는 수를 말한다.

### 무한대

부호 비트 덕분에 양/음의 무한대를 모두 표현할 수 있다.  
연산 과정에서 표현할 수 있는 가장 큰 수 보다 더 큰 값이 들어가면 발생한다.

### 수가 아님(NaN)

정확히 값을 정할 수 없는 경우를 말한다.  
무한대 - 무한대, 0 x 무한대, 0 / 0 등이 있다.

## 형변환

```.c
#include <stdio.h>
int main() {
  int a = 5, b = 3;
  float c, d;
  
  c = a / b;
  d = (float)a / b;
  
  printf("%f %f", c, d);
  
  return 0;
}
```

Output
```
1.000000 1.666667
```

a 와 b 중 어느 하나가 실수형 변수라면 컴퓨터는 사람과 같은 나눗셈을 수행한다.  
그러나 둘다 정수라면 몫을 계산한다.
