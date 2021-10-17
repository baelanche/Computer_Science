## 1. 사이트의 IP 주소 확인하기

![1](https://user-images.githubusercontent.com/48989903/137625115-95e22d23-a5f0-4f8e-9aa1-ba5068de09c8.png)

* 첫번째 IP : DNS 서버
* 두번째 IP : 웹 서버

<br/><br/>

## 2. DNS 패킷 분석

![2](https://user-images.githubusercontent.com/48989903/137625151-8be7e941-f021-4c6f-8648-c2a4aff1ae54.png)

DNS 연결은 UDP 프로토콜을 사용하며 port number 는 53 이다.

<br/><br/>

## 3. TCP Connection

![3](https://user-images.githubusercontent.com/48989903/137625199-63aa2777-511b-4b5b-8b14-fd8a399a93cf.png)

3-way handshaking 을 통해 연결을 성립했다.
1. 클라이언트(내 PC) 에서 서버에 SYN 를 날린다.
2. 서버에서 연결을 허용한다는 의미로 SYN + ACK 로 응답한다.
3. 서버의 응답을 확인했다는 뜻으로 ACK 를 날린다.

<br/><br/>

## 4. HTTP request, response

![4](https://user-images.githubusercontent.com/48989903/137625282-9941d8aa-eecc-4b83-a157-9f88c6f2c240.png)

서버로 HTTP Request 를 보낸다.  
클라이언트가 보고자하는 주소를 렌더링하길 요청한다. GET 방식이다.

![5](https://user-images.githubusercontent.com/48989903/137625290-8ada4509-f280-4998-8c4b-74dcb943f08a.png)

서버는 요청을 성공적으로 response 했다. status 200 을 통해 확인할 수 있다.

<br/><br/>

## 5. HTTP 패킷 분석

![6](https://user-images.githubusercontent.com/48989903/137625343-5ad6c80a-777f-4c8d-ac04-1edfa0f9e25d.png)

HTTP request - Seq : 1, Ack : 1 이다.  
클라이언트가 전송하는 데이터의 sequence 는 1이고 길이는 826이다.  
서버에게 1번 데이터로 보내달라는 뜻으로 ack 1 로 보냈다.

![7](https://user-images.githubusercontent.com/48989903/137625362-79b704df-93b4-407f-9d20-f4cde74333d3.png)

클라이언트가 전송한 데이터의 sequence + length = ack 이다.  
클라이언트가 전송한 826 byte 의 데이터를 모두 잘 받았다는 것을 의미한다.

<br/><br/>

## 6. Connection

![8](https://user-images.githubusercontent.com/48989903/137625381-ea85c129-5cc8-4584-b057-63b26647cf83.png)

* Persistent : keep-alive
* Non-persistent : close

persistent-connection 임을 확인할 수 있었다.
