# Multiple Access Protocols

* broadcast (shared wire)
* 노드들이 channel 을 어떻게 공유할 것인가
* channel partitioning : divide channel into pieces (TDMA, FDMA, CDMA)
* random access
* taking turns : 노드들은 번갈아 차례를 가진다. 그러나 효율이 가장 좋은 방식은 아니다.

## Channel partitioning protocols

### TDMA

time division multiple access

<img width="871" alt="tdma" src="https://user-images.githubusercontent.com/48989903/146510386-7c2e73ae-89f5-4415-b91c-cc4ee1da1a11.png">

* slot 별 어떤 사용자가 사용할 수 있는지 할당한다.
* slot 은 제한되어있기 때문에 동시에 사용할 수 있는 사용자가 제한된다.
* 자원을 sparse 하게 할당한다.

### FDMA

frequency division multiple access

<img width="1051" alt="fdma" src="https://user-images.githubusercontent.com/48989903/146510913-1601ea51-86b1-457a-822c-4ede6819dee7.png">

* 주파수 별 사용자를 할당해서 할당하는 방식
* 주파수에 따라 동시에 할당할 수 있는 사용자의 수가 정해진다.
* 자원을 사용자에게 계속 주어야한다.

## Random access protocols

* 어떤 자원을 사용할 지 모르는 경우 random 하게 자원을 할당한다.
* 둘 이상의 사용자가 동시에 같은 자원을 사용할 경우 collision 이 발생한다.
* random access MAC protocol : detect collision, recover from collision
  * slotted ALOHA
  * ALOHA
  * CSMA, CSMA/CD, CSMA/CA

### Slotted ALOHA

collision 발생시 확률을 통해 재전송을 결정한다.

<img width="842" alt="slotted" src="https://user-images.githubusercontent.com/48989903/146513462-9bc115ce-3bb4-4037-86d7-5f96fb5c2448.png">

1. C : 3개의 노드가 동시에 frame 을 전송했다. (collision)
2. E : 3개의 노드가 확률적으로 모두 전송하지 않았다.
3. C : 2개의 노드가 동시에 frame 을 전송했다. (collision)
4. S : 노드 2가 전송했다.
5. 최선의 경우 3개의 slot 으로 해결할 것을 9개의 slot 으로 해결하였다.

장단점

* decentralized
* simple
* collision, wasting slots
* idle slots

#### efficiency

* N nodes, probability p
* slot 의 결과가 success 일 확률 : p(p-1)<sup>n-1</sup>
* n 개 slot 으로 success 할 확률 : Np(p-1)<sup>n-1</sup>
* max efficiency : 1/e (약 37%, 미분을 통해 구할 수 있다)

### ALOHA

no synchronization

<img width="887" alt="aloha" src="https://user-images.githubusercontent.com/48989903/146517992-63fe5c2e-9705-44c1-b822-57f4944ba8d2.png">

* slot 이 나누어져 있지 않다.
* frame 이 겹치면 collision 이다.

#### efficiency

<img width="1001" alt="aloha2" src="https://user-images.githubusercontent.com/48989903/146518242-8a9f974b-8c3b-45dc-82d2-1a9c503852f8.png">

* max efficiency : 1/2e (약 18%)

### CSMA (carrier sense multiple access)

전송하기 전에 채널의 상태를 파악한다.

* idle channel : 전송
* busy channel : 연기

<img width="290" alt="csma0" src="https://user-images.githubusercontent.com/48989903/146519244-01b5a2b5-7f41-49a6-a3a2-f16f6820d53c.png">

* channel 의 상태가 idle 인 것을 확인하고 두개의 노드가 서로 다른 시점에 전송을 시작했다.
* 특정 지점에 collision 이 발생한다.

### CSMA/CD (collision detection)

* collision 발생 시 전송을 취소한다.
* LAN 에서 사용하기 좋다.
* wireless LAN 에서 사용하기 어렵다. (전송의 힘이 수신의 힘보다 크다)

<img width="633" alt="csma" src="https://user-images.githubusercontent.com/48989903/146518770-520a7504-4e21-47a1-89b8-bf93cdc91824.png">

1. NIC 는 frame 을 만든다.
2. 채널이 idle 하면 전송하고 busy 하면 기다린다.
3. 다른 detection, transmission 이 없다면 NIC 는 전체 frame 을 전송한다.
4. 다른 detection, transmission 이 있다면 NIC 는 전송을 취소하고 jam 신호를 보낸다.
5. 전송 취소 후 binary (exponential) backoff 방식을 통해 언제 전송할지 결정한다.
   * 0 ~ 3 의 숫자를 뽑아 더 낮은 수를 뽑은 frame 이 먼저 전송한다.
   * 0 ~ 7 의 숫자를 뽑아 더 낮은 수를 뽑은 frame 이 먼저 전송한다.
   * 0 ~ 2<sup>m</sup>-1 의 숫자를 뽑아 더 낮은 수를 뽑은 frame 이 먼저 전송한다. (m <= 10)
   * m = 10 인 경우까지 실행하여도 전송에 실패하면 전송을 취소한다.

## Taking turns Protocols

### polling

<img width="440" alt="tt1" src="https://user-images.githubusercontent.com/48989903/146521485-67e58440-0724-4df1-b146-a266692172cf.png">

* master node 가 어떤 node 가 보낼지 투표로 선정하는 방식

### token passing

<img width="519" alt="tt2" src="https://user-images.githubusercontent.com/48989903/146521498-0ad5a272-fb22-41f7-9220-88eae289e5ea.png">

* control token 을 넘겨주며 전송 권한을 주는 방식

## Cable access network

* Internet, TV 는 다른 주파수로 down/up stream 한다.
  * downstream : 40Mbps
  * upstream : 30Mbps
  * upstream 시에 모든 유저가 채널에서 경쟁하므로 collision 이 발생할 수 있다.

