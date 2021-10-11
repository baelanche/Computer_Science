# Electronic mail : Email

![components](https://user-images.githubusercontent.com/48989903/136718597-d0891977-e308-4c53-8f65-50dbeca33d4b.png)

### Components
* user agents
* mail servers
* SMTP

#### User agents
* 메일을 읽고 쓴다.

#### Mail servers
* 도착한 메일을 mailbox 에 보관한다.
* 보낼 메일을 message queue 에 보관한다.

#### SMTP
* mail servers 사이에 존재
* 클라이언트 : 메세지를 전송한다
* 서버 : 메세지를 받는다

## SMTP
* TCP
* 3개의 과정을 통해 전송한다.
  * handshaking
  * 메세지 전송
  * 닫음
* HTTP 와 같이 command/response 방식이다.
  * command : ASCII
  * response : status code, phrase
* message : 7-bit ASCII
* persistent 연결이다.

### Process

![smtp_process](https://user-images.githubusercontent.com/48989903/136719006-84530b9a-77d9-454a-9d24-f21b31a58176.png)

1. 클라이언트인 Alice 는 메일을 작성한다.
2. Alice 의 메일 서버로 전송되며 message queue 에 저장된다.
3. SMTP 는 bob 의 메일 서버에 TCP 를 연결한다.
4. TCP 연결을 통해 Alice 의 메세지를 전송한다.
5. Bob 의 메일 서버는 Bob 의 mailbox 에 메일을 저장한다.
6. Bob 은 메일을 수령한다.

### SMTP vs HTTP
* HTTP : pull (서버의 내용을 가져옴)
* SMTP : push (서버에 내용을 보냄)
* 둘다 ASCII 형태의 command/response, status codes
* HTTP : 각 오브젝트 별로 메세지 내에서 캡슐화 되어있다.
* SMTP : 여러 오브젝트를 여러 부분으로 나눠서 보낸다.

### Mail message format

* header : To, From, Subject
* body : message

### Mail access protocol

User agent 가 mail server 로 부터 메일을 받아올 때 사용하는 프로토콜을 말한다.

* POP : 증명에 성공하면 메일을 다운받을 수 있다
* IMAP : 메일서버에서 메세지들을 관리할 수 있다
* HTTP : 웹에서 메일을 확인한다

## POP3

#### authorization
* client : user, pass
* server : +OK, -ERR

#### transaction : client
* list : 리스트 형태로 출력
* retr : 인덱스를 통해 메일 받아옴
* dele : 삭제
* quit

* 메일을 삭제하면 다시 복구할 수 없다.
* 메일을 PC에 받아서 보는 'download-and-keep' 이다.
* stateless

## IMAP

* 메일은 서버에 저장하며 유저는 그것을 읽는다.
* 유저가 메세지들을 조직하고 분류할 수 있다.
* stateful : 폴더의 이름, 메세지 ID 등
