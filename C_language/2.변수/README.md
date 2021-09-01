## Variable 

변수는 가변적인 수로 값을 더하거나 빼거나 하여 변화될 수 있는 수이다.

```.c
int a = 1;
```

정수형 변수 a에 1을 저장하였다.

>변수는 RAM에 저장됨으로써 기억되게 된다.

RAM의 공간에 주소들은 0x00000001 과 같은 형태로 되어있는데 인간이 이러한 주소를 일일이 기억하는 것은 힘든 일이다.

그래서 사용자는 animal, number 와 같은 인간에게 의미를 가진 단어로 변수 이름을 선언하고 컴퓨터는 변수의 공간을 알아서 할당한다.

<hr/>

```.c
int a = 100000000000;
```

라고 선언하고 콘솔에 출력해보면 원하는 수가 안나오는 것을 알 수 있다.

이는 int 형 변수가 담을 수 있는 수의 범위를 초과했기 때문인데, 이는 overflow라고 한다.

<table>
  <tr align="center">
    <th colspan="2">구분</th>
    <th>크기(byte)</th>
    <th>범위</th>
  </tr>
  <tr align="center">
    <td rowspan="5">정수형</td>
    <td>char</td>
    <td>1</td>
    <td>-128 ~ 127</td>
  </tr>
  <tr align="center">
    <td>short</td>
    <td>2</td>
    <td>-32768 ~ 32767</td>
  </tr>
  <tr align="center">
    <td>int</td>
    <td>4</td>
    <td>-2,147,483,648 ~ 2,147,483,647</td>
  </tr>
  <tr align="center">
    <td>long</td>
    <td>4</td>
    <td>-2,147,483,648 ~ 2,147,483,647</td>
  </tr>
  <tr align="center">
    <td>long long</td>
    <td>8</td>
    <td>-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807</td>
  </tr>
  <tr align="center">
    <td rowspan="3">실수형</td>
    <td>float</td>
    <td>4</td>
    <td>3.4 x 10^-37 ~ 3.4 x 10^38</td>
  </tr>
  <tr align="center">
    <td>double</td>
    <td>8</td>
    <td>1.7 x 10^-307 ~ 1.7 x 10^308</td>
  </tr>
  <tr align="center">
    <td>long double</td>
    <td>8 이상</td>
    <td>-</td>
  </tr>
</table>

정수형은 unsigned, signed 로 구분되며 부호의 유무를 나타낸다.

unsigned char 라고 선언했다면 이 변수는 양수에 한정해서 비트를 할당받기 때문에 0 ~ 255 의 범위의 수를 가질 수 있다.

<hr/>

```.c
int a = 1;
printf("%d\n", a);
```

일반적으로 변수의 출력은 이렇게 한다.

%d는 정수를 뜻하며 아래 서식문자 표가 있다.

|서식문자|자료형|출력형태|
|:---:|:---:|:---:|
|%d|int|부호 있는 10진수 정수|
|%u|unsigned int|부호 없는 10진수 정수|
|%ld|long|10진 정수|
|%lld|long long|10진 정수|
|%lu|unsigned long|부호 없는 10진 정수|
|%o|unsigned int|부호 없는 8진수 정수|
|%x, %X|unsigned int|부호 없는 16진수 정수|
|%f|float, double|10진수 방식의 부동소수점 실수|
|%e, %E|float, double|e 또는 E 방식의 부동소수점 실수|
|%g, %G|float, double|값에 따라 %f와 %e 사이에서 선택|
|%c|char|값에 대응하는 문자|
|%s|char *|문자열|
|%p|void *|포인터의 주소 값|

의외에도 더 있지만 자주 쓸일이 없어서 서술하지 않았다.

<hr/>

```.c
float pi = 3.1415f;
```

float 자료형에 값을 할당할때에는 뒤에 f를 붙여 float 타입이라는 것을 명시해준다.

그렇지 않으면 double 형으로 인식하게된다.

```.c
printf("%f", 1.0);
```

또 %f 로 실수를 출력할 때에는 1이 아닌 1.0과 같이 실수형으로 써주어야 한다.

<br/><br/>

1.
```.c
printf("%.2f", 3.141592);
# 소수점 둘째자리까지 출력하라는 의미이다. 이 상황에서는 3.14가 출력된다.
# 잘려질때 반올림이 발생한다.
```

2.
```.c
printf("%.10f", 3.141592);
# 소수점 여섯째자리까지 있는데 열번째까지 출력하라고 하면 어떻게 될까?
# 3.1415920000 와 같이 출력된다.
```

3.
```.c
printf("%5d", 123);
# '  123' 이 출력된다. 5자리를 맞추기위해 공백 2칸이 추가되는 것이다.
```

4.
```.c
printf("%5d", 123456);
# 그냥 123456이 출력된다.
```

5.
```.c
printf("%6.3f", 3.141592);
#   3.142
```
