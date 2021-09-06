# Internet?

### "Network of networks"

PC, server, laptop, smartphone 등 수백만개의 디바이스가 컴퓨터 네트워크에 연결되어 있다. 이러한 환경을 인터넷이라 한다.  
또 각 디바이스를 <b>host</b> 또는 <b>end systems</b> 라고 부른다.

디바이스들이 소통하기 위해선 이들을 연결해줄 communication links 가 필요하다. 이 link 는 선의 존재 유무로 나뉜다.
* wireless links : radio spectrum, satellite
* wired links : fiber, cooper

서로 다른 재질들로 된 link 들은 각각 다른 전송 rate 를 가지고 있는데, 이를 transmission rate 라고 한다.

네트워크를 통해 데이터(chunks of data)를 보낼 때 packet 이라는 가공된 형태로 보낸다.  
이 때 communication link 가 서로 다르다면 <b>router</b> 를 통하여 보낸다. 이러한 역할을 하는 router 를 packet switch 라고도 한다.

node : all entities

Internet : network of networks
Interconnected ISPs
infrastructure that provides services to applications
provides programming interface to apps


Protocol control sending, receiving of messages
TCP, IP, HTTP, Skype

Internet standards
RFC : Request for comments
IETF : Internet Engineering Task Force

ietf.org
internet standard - RFCs : search Internet Protocol : RFC 791

IP Header

What's a protocol?

protocol define format, order of messages sent and received among network entities, and actions token on message transmission, receipt

Network edge?

network edge: hosts: clients and servers, servers often in data centers

network core: interconnected routers, network of networks

How to connect end systems to edge router?
* residential access nets
* institutional access networks(school, company)
* mobile access networks

bandwidth(bits for second) -> shared or dedicated?

Access network: digital subscriber line(DSL)
voice, data transmitted at different frequencies over dedicated line to central office
use existing telephone line to central office DSLAM
  * data over DSL phone line goes to Internet
  * voice over DSL phone line goes to telephone net
< 2.5 Mbps upstream transmission rate(typically < 1 Mbps)
< 24 Mbps downstream transmission rate(typically < 10 Mbps)

Access network: cable network

frequency division multiplexing: different channels transmitted in different frequency bands
HFC : hybird fiber coax
  * asymmetric : up to 30Mbps downstream transmission rate, 2 Mbps upstream transmission rate
network of cable, fiber attaches homes to ISP router
  * homes share access network to cable headend
  * unlike DSL, which has dedicated access to central office

주파수가 섞여서 날아가도 수신측에서 주파수를 분리해낼 수 있다.

Channels : 주파수 별로 분리해낸 것

Access network: home network

Ethernet(Enterprise access networks) 
typically used in companies, universities, etc.
10Mbps, 100Mbps, 1Gbps, 10Gbps transmission rates
today, end systems typically connect into Ethernet switch
속도가 워낙 좋아져서 집단에서 많이 쓰임

Wireless access networks
shared wireless access network connects end system to router
wireless LAN: within building
wide-area wireless access: provided by telco operation, 3G, 4G:LTE
(공유기 부터 와이파이)

Hosts: sends packets of data
host sending function:
  * take application message
  * breaks into smaller chunks, known as packets, of length L bits
  * transmits packet into access network at transmission rate R
  * link transmission rate, aka link capacity, aka link bandwidth

Physical media

bit: propagates between transmitter/receiver pairs
physical link: what lies between transmitter & receiver
guided media: 유선
unguided media: 무선
twisted pair(TP): two insulated copper wires
coaxial cable: two concentric copper conductors(집)
fiber optic cable: 광케이블, 전송률 높음, glass fiber carrying light pulse, each pulse a bit(장거리)
radio: no wire / type: terrestrial microwave, LAN, wide-area, satellite
