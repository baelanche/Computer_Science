# Video streaming and content distribution networks

* Video traffic 이 대역폭의 상당부분을 차지하고 있다.
* 사용자가 PC, mobile, 2G, 3G 등 다양한 플랫폼을 사용하므로 대처가 필요하다.

## Video

* 이미지의 연속적인 집합
* 변화되는 이미지의 비트 정보 차이가 크지 않다면 바뀐 부분의 정보만을 보내는 알고리즘이 있다.
* CBR(constant bit rate), VBR(variable bit rate)
* MPEG 1, MPEG2, MPEG4, ...

## Streaming stored video

과거에 비해 스트리밍 서비스가 비약적으로 늘어났다.

### DASH

Dynamic, Adaptive, Streaming over HTTP

* server
  * 비디오를 chunks 로 조각낸다.
  * 각 chunks 를 저장하고 다른 rate 로 인코딩한다. (1080p, 720p, ...)
  * manifest file : 서로 다른 chunks 들에 대해 URL 을 제공한다.
* client
  * 주기적으로 server-to-client 대역폭을 측정한다.
  * manifest 에 chunks 를 한번에 요청한다.
* "intelligence" at client
  * when : 클라이언트는 chunks 를 요청할 수 있다.
  * what encoding rate : 클라이언트는 quality 를 정할 수 있다.
  * where : 클라이언트에게 가까운 서버에 chunks 를 요청할 수 있다.

## CDN

동시에 엄청 많은 사람들이 하나의 컨텐츠에 접근하면 어떻게 스트리밍 할 수 있을까?

1. 큰 규모의 단일 서버
   * 다운시 모든 사람이 이용할 수 없음
   * 네트워크 혼잡 유발
   * 거리에 따른 속도 차이

2. 분산된 CDN 노드에 비디오의 복사본을 저장한다.
   * enter deep : CDN 서버를 사용자 가까이에 둔다.

### CDN content access : a closer look

Bob 이 netcinema.com 에 비디오를 요청한다. (비디오는 KingCDN에 저장되어 있다)

![cdn_process](https://user-images.githubusercontent.com/48989903/136778271-ead219aa-44fd-47de-8046-c9c453d2b2bc.png)

1. Bob 은 웹페이지에서 netcinema 의 URL 을 얻는다.
2. Bob 의 local DNS server 를 통해 netcinema.com DNS server 에 연결한다.
3. netcinema 의 DNS 에서 KingCDN.com URL 을 돌려준다.
4. KingCDN DNS 를 통해 KingCDN 의 IP 와 비디오 데이터를 받는다.
5. Bob 에게 전달한다.
6. Bob 은 KingCDN.com 에 직접 요청하여 HTTP 를 통해 스트리밍한다.

### Case : Netflix

![netflix](https://user-images.githubusercontent.com/48989903/136778468-ebe4bc11-15dc-475e-8e6b-e7fdec64fb06.png)
