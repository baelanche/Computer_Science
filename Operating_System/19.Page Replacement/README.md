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

### Counting-based Page Replacement

* LFU (Least Frequently Used) : 가장 방문 주기가 낮은 page 를 제거하는 방식
* MFU (Most Frequently Used) : 가장 방문 주기가 높은 page 를 제거하는 방식
  * 구현이 어렵다.
  * OPT 에 적절하지 않다.

## Global vs Local Page Replacement

* Global Replacement
  * all frames 에서 process 가 victime page 를 선택한다.
  * 전체적인 성능은 좋으나 실행 시간의 변화가 크다.
* Local Replacement
  * process 의 page frame 을 replace 한다.
  * 성능은 믿을만하나 메모리 사용률이 줄어든다.

### Page Pinning

* 몇몇 page 는 memory 에 항상 올려야 하는 경우가 있다. (e.g., I/O buffers)
  * 하드웨어와 정보를 주고 받는 buffer 들은 pinning 한다.

### Paging Virtual Memory

![vm](https://user-images.githubusercontent.com/48989903/145977826-7ce38a48-6594-4397-9b18-7b43e278fac2.png)

* code
  * read-only, sharable
  * 실행 파일의 뒤에 있다는 뜻으로 file-backed pages 라고도 한다.
  * victim page 가 될 때 단순히 버리기만 하면 된다.
* stack, heap (anonymous pages)
  * read, write
  * start zero page, copy-on-write
  * swap file 을 반드시 사용해야 한다.
* data
  * start file data, update 시에 copy-on-write
  * cow 가 일어나면 swap file 을 반드시 사용해야 한다.

