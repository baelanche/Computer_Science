## Copy-on-Write

* fork() : child process 의 page table 생성 후 같은 frame 참조
* Copy-on-Write 를 위해 write 를 끄고 마킹을 한다. (별도의 변수 등의 방법)
* 수정 발생시 write 가 가능하기 때문에 새로운 frame 을 참조한다
* page fault 는 parent, child 모두에게 발생할 수 있다.
* p1, p2 가 서로 다른 frame 을 참조하고 있고, 이 두 frame 의 내용이 같다면 같은 곳을 참조하게 하고 하나의 frame 을 날리기도 한다.

### zero page

* malloc() 한 순간 메모리 할당이 일어나는 것이 아니고 해당 메모리를 예약(선점)하는 것에 가깝다.
* MMU 가 그 페이지에 대해 write 하면 page fault 가 발생하여 그 때 OS 에 의해 메모리 할당이 일어난다.
* MMU 가 그 페이지에 대해 wirte 없이 read 하면 0으로 채워진 zero page 로 연결시킨다.

### kernel address space

![kas](https://user-images.githubusercontent.com/48989903/145663978-a669cf40-8801-405d-b19a-70ab944819cf.png)

* 모든 프로세스의 일정부분은 kernel address space 가 점유한다.
* fork() 를 실행할 시 kernel address space 도 공유한다.
* intel 같은 경우, 접근제어를 위해 user space 에 대한 segment, kernel space 에 대한 segment 를 가지고 있다.

## Thrashing

* working set : 프로세스가 사용중인 set of pages
* working set 이 main memory 의 크기보다 커지면 cpu 사용률이 뚝 떨어지게 되며 이를 thrashing 이라한다.
* 프로세스를 죽이거나 메모리 크기를 늘리면 해결할 수 있다.

##  Prepaging

* paging 의 수준을 올린 것을 의미한다. (=prefetching)
* spatial locality 에 기반해서 demand paging 이 일어날 때 주변 frame 을 같이 올리고, 내려서 성능의 향상을 만들어낸다.

# Page Replacement

* main memory 가 꽉 찬 시점에 어떤 page 를 제거하는 것이 좋을까?
  * 앞으로 절대 참조가 되지 않을 page 를 제거한다.
  * page fault 가 가장 발생되지 않을 page 를 제거한다. (page fault 발생시 성능 저하가 심하기 때문에)

## OPT : Belady's Algorithm

* 제일 나중에 참조될 것 같은 page 를 찾는 알고리즘 = page fault rage 를 최소화하는 알고리즘
* 이후 계획을 알아야 한다는 제약이 있다.
* 실제로 잘 쓰이지는 않고 lower bound 를 검증하는 용도로 쓰인다.

### e.g., 3 page frames

* Reference string : 각 page 마다 참고하고 있는 frame
* M : miss (page fault) -> main memory 의 page 를 참조하지 못한 상황
* H : hit -> main memory 의 page 를 참조한 상황

![opt1](https://user-images.githubusercontent.com/48989903/145932606-3b17281c-db14-4841-be84-f6f7ef89c16b.png)

* 1, 2, 3 을 참조하는 경우 frame 이 비어있으므로 단순 참조한다.
* 4번을 참조하는 순간 한 칸을 비워야한다. 1, 2, 3 중 3 이 가장 나중에 참조되므로 3을 뺀다.
* 5번을 참조하는 순간 4를 뺀다. (따라서 1,2,5)
* 3번을 참조하는 순간 1 혹은 2를 뺀다 (3,2,5)
* 4번을 참조하는 순간 3 혹은 2를 뺀다 (4,2,5)
* PF rate : (miss/all pf) = 7/12

## FIFO

* 가장 먼저 들어온 frame 을 제거하는 방식
* 사용한지 오래된 frame 은 재사용이 될 가능성이 낮을거라는 가정에서 시작된 알고리즘이다.
* <b>더 많은 memory 를 사용하면 page fault rate 가 올라갈 가능성이 있다.</b>

### Belady's Anomaly

![fifo](https://user-images.githubusercontent.com/48989903/145961359-c882c3c2-375b-4df0-9d3a-cd0b49eb314b.png)

* 그래프와 같이 page frame 이 증가했을 때 fault rate 가 늘어나는 시점이 있다. (Belady's Anomaly)

## LRU : Least Recently Used

* 가장 과거에 참조된 page 를 제거한다.
* hit 되는 경우 최신 frame 이 된다. (제거 우선순위의 최하위가 된다)
* Belady's Anomaly 의 발생이 없다. (LRU 는 stack algorithm 이기 때문이다)

![lru](https://user-images.githubusercontent.com/48989903/145962827-ac420a2b-51ad-4f00-b809-faa5d793a3b0.png)

* 두 경우의 3번 frame 까지를 보면 동일하다. 이를 통해 stack algorithm 이라는 것을 확인할 수 있다.

### LRU Implementation 1 : using clocks or counters

* page 가 참조된 시점을 저장하는 방식
* 참조 될 때마다 해당 page 에 counter 를 갱신한다.
* counter 값을 적는 방식은 매우 단순하고 빠르다.
* page 의 수가 많으면 counter 값이 작은 page 를 찾는데에 시간이 꽤 걸린다. (= victim page 를 찾는데에 오래 걸린다)
* 각 page 마다 counter 를 두어야 하기 때문에 overflow 발생가능성이 항상 있다.
* 메모리 공간을 잡아먹는다는 단점도 존재한다.

### LRU Implementation 2 : using doubly linked list or stack

* page 가 참조되면 해당 노드를 제거하고 리스트에 head 에 새로 추가하는 방식
* victim page 는 리스트의 tail 노드가 된다.
* 각 page 별 리스트를 구하기위한 다른 변수들이 필요하다.
* 해당 노드가 제거 될때 앞 뒤의 노드가 서로를 가리키고, head 에 삽입된 후 그 뒤 노드와 연결해야한다. (대충 4개 포인터 정도의 값 수정이 이루어진다)

### LRU Approximation Algorithms

LRU 를 구현하여 이상적으로 동작하는 방식은 아직까지도 없다. 이에 따라 유사한 알고리즘을 만들어서 운영체제에 접목하였다.

![rb](https://user-images.githubusercontent.com/48989903/145967892-71b206af-0449-4bda-a3e4-bf670b553c1c.png)

* <b>Additional-Reference-Bits Algorithm</b>
  * 각 PTE 는 reference bit 를 갖는다.
  * MMU 는 reference bit 에 값을 set 한다. (참조 시 1, 참조 안할 시 : 0)
  * OS 는 주기적으로 값을 오른쪽으로 shift 한다.
  * 앞자리 일수록 최근 <-> 뒷자리 일수록 과거 인 bits 가 형성된다.
  * reference bit 의 값이 작을수록 가장 오랫동안 참조가 되지 않은 page 가 된다. (= victim page)
  * 비트의 크기는 한정적이므로 비트가 꽉 찼을 때 새로 값이 들어오면 가장 오른쪽 bit 는 버려진다.
  * 주기적으로 OS 가 scan 해야하는 단점이 있다.
* <b>Second-Chance Algorithm</b> : clock algorithm
  * 각 PTE 는 reference bit 를 갖는다.
  * 화살표는 임의의 page 를 가리키고 있다.
  * 새로운 page 가 참조되면 화살표가 가리키고 있는 page 의 reference bit 를 확인하여 0 이면 victim, 1 이면 bit = 0 을 set 하고 다음 page 를 확인한다. (second chance algorithm)
  * 한바퀴 돌 동안 second chance 를 받은 page 에 참조가 이루어졌다면 다시금 생존할 수 있는 기회를 갖게 된다.
    * Using Modify bit
    * page 속성에 write 가 있다면 값을 1로 set 한다.
    * page 가 victim page 가 되어서 원래 공간으로(file, swap, ...) 돌아갈 때 modify 된 적이 있다면 새로 써준다.

## Counting-based Page Replacement

* LFU (Least Frequently Used) : 가장 방문 주기가 낮은 page 를 제거하는 방식
* MFU (Most Frequently Used) : 가장 방문 주기가 높은 page 를 제거하는 방식
  * 구현이 어렵다.
  * OPT 에 적절하지 않다.

