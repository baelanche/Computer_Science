Internet?

PC, server, laptop, smartphone : billions of connected computing devices
host = end systems
running network apps

wireless links, wired links : communication links
fiber, copper / radio, satellite
transmission rate: bandwidth

router : packet switches: forward packets(chunks of data)
routers and swithces

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
