# P2P

* 상시 서버가 없다.
* peer 들이 동등한 관계로 서로 연결한다.

## client-server vs P2P

* 크기가 F 인 파일을 한 서버로부터 N 개의 peer 에 배포하는데 얼마나 걸리는가?

### client-server

클라이언트가 파일을 요청할 때마다 서버가 보내주어야 한다.

#### server

* 서버가 한번 전송하는 시간 : F/u<sub>s</sub>
* 서버가 N 번 전송하는 시간 : NF/u<sub>s</sub>

#### client

* 가장 느린 클라이언트의 다운률 : d<sub>min</sub>
* 가장 느린 클라이언트의 다운 시간 : F/d<sub>min</sub>

#### D(c-s) = max{NF/u<sub>s</sub>, F/d<sub>min</sub>}

통상적으로 서버의 속도가 빠르기 때문에 클라이언트 측에서 bottleneck 이 걸릴 확률이 훨씬 높지만,  
N 이 과도하게 커지면 서버에 bottleneck 이 생길 수 있다.

### P2P

* 서버가 한번 전송하는 시간 : F/u<sub>s</sub>
* 가장 느린 클라이언트의 다운 시간 : F/d<sub>min</sub>
* 모든 클라이언트가 NF bits 를 다운받는 시간 : NF/(u<sub>s</sub> + Sigma(U<sub>i</sub>))
  * 클라이언트는 나중에 업로드 해주는 역할을 한다.

#### D(P2P) = max{NF/u<sub>s</sub>, F/d<sub>min</sub>, NF/(u<sub>s</sub> + Sigma(U<sub>i</sub>))}

NF/(u<sub>s</sub> + Sigma(U<sub>i</sub>)) 에서 N 이 커짐에 따라 분자, 분모가 모두 커진다.

#### example

![cs_vs_p2p](https://user-images.githubusercontent.com/48989903/136769044-1525887f-6b9d-40aa-b453-b8225dfde2b7.png)

client upload rate = u, F/u = 1hour, u<sub>s</sub> = 10u, d<sub>min</sub>>=u<sub>s</sub>

## BitTorrent

* 파일을 256kb 로 나눈다.
* 토렌트의 peer 들이 file chunks 를 주고 받는다.

![bit_torrent](https://user-images.githubusercontent.com/48989903/136769794-121a2bcc-2ae3-481e-8753-06be47106615.png)

1. Alice 는 토렌트에 조인하기 위해 왔다.
2. tracker 로부터 피어의 리스트를 받는다.
3. 토렌트의 피어들과 file chunks 를 교환한다.

<br/>

* 다운로드 하면서 업로드할 수 있다.
* 토렌트 내의 피어는 바뀔 수 있다.
* 토렌트를 떠날 수도 다시 조인할 수도 있다.

<br/>

* request chunks
  * 다른 피어들이 서로 다른 chunks 를 가지고있다.
  * 주기적으로 각 피어들에게 그들이 가진 chunks 들을 요청한다.
  * 없는 chunks 를 피어에게 요청한다. (구하기 힘든 것부터)
* sending chunks : tit-for-tat
  * 자신에게 빠른 속도로 chunks 를 보내는 4명의 피어에게 chunk 를 보낸다. (10초마다 4명을 업데이트 한다)
  * 30초마다 다른 피어를 선택하여 chunks 를 보낸다.

