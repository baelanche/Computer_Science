# Principle of Congestion Control

* congestion : 너무 많은 데이터를 보내서 네트워크를 다루기 힘든 상태
* flow control != congestion control
* 라우터의 버퍼 오버플로우로 패킷 손실이 야기될 수 있다.
* 라우터의 버퍼 큐잉으로 큐잉 딜레이가 야기될 수 있다.

### 혼잡 예제 1

* 두명의 sender, 두명의 receiver
* 한개의 라우터, 버퍼는 무한대인 경우
* output link capacity : R
* 손실은 생기지 않는다.

![conge1](https://user-images.githubusercontent.com/48989903/138289851-b38b0b58-641e-4523-a9b9-470ced49b8a9.png)

![conge2](https://user-images.githubusercontent.com/48989903/138290091-fc7b98ed-bddd-42ec-828f-8eb4a62b56cf.png)

* 데이터 in/out 용량이 R/2 를 넘어서면 처리가 안된다. -> capacity 를 넘어서면 딜레이가 무한정 늘어난다.

### 혼잡 예제 2

* 두명의 sender, 두명의 receiver
* 한개의 라우터, 버퍼는 무한대가 아닌 경우
* output link capacity : R

![conge3](https://user-images.githubusercontent.com/48989903/138291723-4d44d503-90dd-4177-939b-5362d68eab19.png)

* sender 는 라우터 버퍼의 용량을 모른다.
* 버퍼가 꽉차면 라우터는 패킷을 버린다. -> sender 는 이것으로 혼잡상태임을 짐작할 수 있다.
* "costs" of congestion : 보낸 패킷 중 버려진 패킷들을 혼잡의 "cost" 라고 한다.
* 재전송이 늘어날수록 cost 가 커진다.

### 혼잡 예제 3

![conge_ex](https://user-images.githubusercontent.com/48989903/138292870-85c5b197-6a76-41e7-9685-438eaa728623.png)

* 4명의 sender
* 4개의 라우터, 버퍼는 무한대가 아닌 경우
* 모두 2번의 라우터를 거친다.
* output link capacity : C

![conge4](https://user-images.githubusercontent.com/48989903/138292931-04eeddbc-31fe-4902-9870-d0296017e5e8.png)

* 라우터를 통과하는 경로가 2개 이므로 throughput 은 예제 2 일때보다 당연히 떨어진다. (C/4 정도)
