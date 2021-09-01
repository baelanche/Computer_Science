```.c
int a = 1;
```

정수형 변수 a에 1을 저장하였다.

변수는 가변적인 수로 값을 더하거나 빼거나 하여 변화될 수 있는 수이다.

>변수는 RAM에 저장됨으로써 기억되게 된다.

RAM의 공간에 주소들은 0x00000001 과 같은 형태로 되어있는데 인간이 이러한 주소를 일일이 기억하는 것은 힘든 일이다.

그래서 사용자는 a, animal, number 와 같은 인간에게 의미를 가진 단어로 변수 이름을 선언하고 컴퓨터는 변수의 공간을 알아서 할당한다.

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
