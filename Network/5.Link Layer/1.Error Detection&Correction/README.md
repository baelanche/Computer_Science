# Error Detection & Correction

<img width="790" alt="edc" src="https://user-images.githubusercontent.com/48989903/146362554-5482cd5e-6285-4129-9cd0-52ea132e3d2e.png">

* EDC : Error detection and correction bits
* D : data
* EDC 를 통해 에러 체크 후 EDC 에 변화가 있는지 살핀다.
* 100% 신뢰성 보장이 되는 것은 아니다.

## Parity checking

### single bit parity : detect single bit errors

<img width="399" alt="sparity" src="https://user-images.githubusercontent.com/48989903/146363109-26ab3a60-8a04-4e48-a418-6d94e32af05b.png">

* 앞의 데이터의 비트 수가 홀수 : 1
* 앞의 데이터의 비트 수가 짝수 : 0
* 홀수개의 에러에 대해서만 찾을 수 있다. 

### two-dimensional bit parity : detect and correct single bit errors

<img width="530" alt="tparity" src="https://user-images.githubusercontent.com/48989903/146363512-36b27488-2b65-4a0f-8e5b-9bd297c01e49.png">

* 데이터를 2차원 배열의 형태로 나열한다.
* single bit parity 방식으로 col, row 에 대한 에러를 체크한다. 
* 에러가 1개의 경우에만 동작한다.

## Cyclic redundancy check

<img width="636" alt="crc" src="https://user-images.githubusercontent.com/48989903/146375314-772bee71-fc3e-43b3-abf9-5e58aa3d7e7e.png">

### example

<img width="509" alt="crc2" src="https://user-images.githubusercontent.com/48989903/146375474-7e56a4fc-f2c1-4203-bd31-8ca735911cd1.png">

* D : 101110
* G : 1001 : r + 1 bits (주어진다)
* D 뒤에 r bits 만큼 0을 붙인다.
* 나눗셈 연산을 한다 (XOR)
* R 을 구했다면 D 뒤에 R 을 붙여서 전송한다.
* 101110011 / 1001 = 0 -> 오류가 없다.

