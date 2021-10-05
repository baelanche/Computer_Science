# Web and HTTP

HTTP : hypertext transfer protocol

### TCP 를 사용한다
* 클라이언트는 소켓을 만듦으로써 서버에 TCP 연결을 시작한다.
* 서버는 TCP 연결을 받아들인다.
* 클라이언트와 서버는 HTTP 메세지를 주고 받는다.

### Stateless

* 서버는 클라이언트의 request 에 대한 정보를 기억하지 않는다.

## HTTP Connections

1. non-persistent HTTP
  * TCP 연결을 통해 한번에 하나의 오브젝트만 전송한다.

2. persistent HTTP
  * TCP 연결을 통해 한번에 여러개의 오브젝트를 전송한다.

### Non-persistent HTTP

<br/>

![non-persistent1](https://user-images.githubusercontent.com/48989903/135988021-1de68b05-d253-4a74-9291-bfd6cf299451.png)

![non-persistent2](https://user-images.githubusercontent.com/48989903/135987169-28de14ec-35e3-459f-9838-2938fbcbd9a7.png)

<br/>

### Non-persistent HTTP : response time

RTT(Round Trip Time) : 클라이언트에서 서버로 패킷을 전송한 후 다시 돌아오기 까지의 시간

![non-persistent_restime](https://user-images.githubusercontent.com/48989903/135988935-354c8f48-0bba-4c66-873f-4cfdf211e7e0.png)

이 경우에 response time 은 2RTT + file transmission time 이다.

각 오브젝트마다 2RTT 가 걸리게 되는데 이는 OS 의 오버헤드를 야기할 수 있다.  
브라우저는 parallel TCP connection 등의 방법을 사용하기도 한다.

### Persistent HTTP

* 서버는 response 후에도 연결 상태를 유지한다.
* 각 오브젝트는 적어도 1RTT 의 시간을 절약할 수 있다.

## HTTP request message

* 아스키 코드로 되어있다.

![http_format](https://user-images.githubusercontent.com/48989903/135990946-bbc59ad8-192f-4f83-ab42-eb16396fb75d.png)


### POST

* 웹페이지가 form 을 포함하는 경우이다.
* request 의 내용이 entity body 에 들어 있다. (body)

### URL

* GET 메소드를 사용한다.
* input 이 URL 에 업로드 된다. (header)

### Method types

* HTTP 1.0 : GET, POST, HEAD
* HTTP 1.1 : GET, POST, HEAD, PUT, DELETE

## HTTP response message

|status code|definition|description|
|---|---|---|
|200|OK|요청 성공|
|301|Moved Permanently|요청한 오브젝트가 이동되었을 때|
|400|Bad Request|서버가 이해할 수 없는 요청을 했을 때|
|404|Not found|서버에 존재하지 않는 요청을 했을 때|
|505|HTTP Version Not Supported||

## User-server state : cookies

![cookie](https://user-images.githubusercontent.com/48989903/136000007-6ddfa8fa-4ef9-4aba-81c3-b6996aa30c5e.png)


1. 클라이언트가 서버에 처음 접속함
2. 서버는 식별 ID 를 생성하여 이 유저에 대한 정보를 데이터베이스에 저장함
3. 클라이언트가 서버에 다시 접속함
4. 서버는 쿠키가 있음을 확인하고 데이터베이스에서 정보를 바로 가져옴
5. 일주일 후에 접속하여도 쿠키 정보가 남아있음 (쿠키의 기간을 서버에서 정할 수 있다)

HTTP 는 stateless 이므로 connection closed 됐을 때 기록을 모두 잃지만, 쿠키를 통해 정보를 기억할 수 있다.

## Web caches (proxy server)

![proxy_server](https://user-images.githubusercontent.com/48989903/136001687-3463ea00-e0d6-4583-a3f7-5d4dccc2bcf3.png)

클라이언트가 요청했을 때 굳이 서버까지 가지 않고 가까운 곳에 위치한 proxy server 에서 응답하게 한다.
요청한 데이터가 프록시서버에 없다면 프록시서버에서 기존 서버에 요청해서 받아온다.

* 보통 ISP 에 프록시 서버를 설치한다.

### why Web caching?

* response time 이 줄어든다.
* traffic 이 줄어든다.
* content provider 를 도와준다.

### example

![cache_prob1](https://user-images.githubusercontent.com/48989903/136007855-5b3061ef-a053-4c5f-835c-8fc316e80d8e.png)

가정
* object size : 100Kb
* request rate to origin servers : 15sec
* data rate to browsers : 1.5Mbps
* RTT from router to origin servers : 2sec
* access link rate : 1.54Mbps

결과
* LAN utilization : (1.54 / 1 x 1000) x 100 = 0.15%
* access link rate : (1.5Mbps / 1.54Mbps) x 100 = 99%
* total delay : Internet delay + access delay + LAN delay
  * Internet delay : 2sec
  * access delay : access link rate 가 99% 이므로 delay 가 엄청 클 것이다
  * LAN delay : LAN 의 사용률이 1% 도 안되므로 delay 역시 거의 없을 것이다

#### 해결 1

![cache_prob2](https://user-images.githubusercontent.com/48989903/136008000-37d68cbb-82fe-4691-a092-0e281e447c31.png)

* access link 의 속도가 너무 느리다. (bottleneck)
  * access link 의 속도를 올리면 해결된다. -> 비싸다
  * access delay 의 속도가 대폭 감소된다.



#### 해결 2

![cache_prob3](https://user-images.githubusercontent.com/48989903/136008099-d5f2336f-c463-4827-b5b7-2a241dfb36da.png)

* server 에 web cache 를 설치한다. -> 싸다

* cache hit rate 는 0.4 라고 하자.
  * 40% 는 cache 에 있고 60% 는 origin 에 있다.
* access link utilization : 60%
* data rate to browser : 0.6 x 1.5Mbps = 9Mbps
* total delay : 0.6 x (delay from origin) + 0.4 x (cache) = 0.6 x 2.01 + 0.4 x (작은 수) = 약 1.2secs
* cache 를 통해 Internet delay 를 0 에 가까이 줄여서 solution 1 보다 속도가 좋아졌다.

### Conditional GET

![conditional_get](https://user-images.githubusercontent.com/48989903/136008505-8ed1193f-628f-4152-9790-3e938f11dd59.png)

캐시가 최신버전이면 굳이 오브젝트를 전송하지 않아도 되지 않을까?
* cache : request 의 날짜를 복사한다.
* server : cache 의 날짜가 최신 상태라면 response 에 아무 객체도 전송하지 않는다.
