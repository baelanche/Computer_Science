# Address Spaces

* address : 메모리의 위치

### Representation

* Physical address vs Logical address
* Absolute address vs Relative address

> 컴퓨터는 실체 칩의 위치인 physical address 로만 접근할 수 있다.  
> 반면 개발자는 '0x01' 등의 logical address(=virtual address) 를 통해 메모리에 접근한다.  
> 이는 컴퓨터의 Memory Management Unit (MMU) 가 logical address 를 physical address 로 translation 해줌으로써 가능하게 된다.

#### So, how can we place process address space on the physical memory address space?

## Fixed Partitions

![fixed](https://user-images.githubusercontent.com/48989903/145200492-2c53ba55-1eae-49a0-8259-948895d4c214.png)

메모리를 일정 크기로 쪼갠다. 프로세스가 메모리 할당을 요청하면 한 partition 을 할당해준다.  
이 과정에서 address mapping 은 MMU 가 수행하며, mapping 방식에 대한 정보는 어딘가에 담겨있다.  

> base register's address + logical address = physical address  
> base register 의 값은 스케줄러가 바꿔서 제공한다.

* 쉽게 구현 가능하다.
* context switch 가 빠르다.
* 파티션 사이즈가 적합하지 않을 수 있다.
  * 메모리를 많이 차지하는 프로세스를 기준으로 파티셔닝 하기 때문에 리소스 낭비가 발생할 수 있다.

### Internal Fragmentation 

파티션 공간이 남을 경우 다른 프로세스가 이 공간을 사용할 수 없다. (exclusive)

## Variable Partitions

![variable](https://user-images.githubusercontent.com/48989903/145207132-c4b95f4d-4dab-476e-879d-e35260b8dd31.png)

* 운영체제가 알맞은 크기만큼 파티셔닝하여 할당해준다.

> base register's address + logical address = physical address  
> limit register 에 주소의 제한 범위를 명시한다.
> limit register 를 초과하는 경우 운영체제는 다른 방식으로 처리한다. (후에 서술)

* context switch 할 때에 base register, limit register 를 바꿔줘야 한다.

### External Fragmentation 

![external](https://user-images.githubusercontent.com/48989903/145207420-fafcd7e1-d168-44c0-9b35-19250a560453.png)

* Process 2, Process 4 가 작업을 마치고 메모리를 반환하여 hole 이 생긴 경우이다.
* 스케줄링이 진행될수록 hole 은 많아질 수밖에 없는데, 이들은 합치면 크기가 무시할 수 없을 정도가 된다.
* 그러나 hole 들은 물리적으로 분리된 위치에 있어서 contiguous 한 주소를 가질 수 없게되며 이를 'External Fragmentation' 이라 한다.

### Allocation Strategies

![strategy](https://user-images.githubusercontent.com/48989903/145207939-8db0ae57-3243-4002-8ea0-d59b5c6297f5.png)

* 프로세스가 메모리를 요청하는 경우, 어느 hole 을 주어야 할까?
  * First fit : 크기가 충분한 hole 중 첫번째로 발견한 hole 에 할당한다. (internal fragmentation 발생 가능)
  * Best fit : 크기가 충분한 hole 중 가장 낭비가 적은 hole 에 할당한다. (딱 맞지 않고 약간이라도 남으면 hole 이 생기기 때문에 external fragmentation 이 발생한다)
  * Worst fit : 가장 크기가 큰 hole 에 할당한다. (best fit 에 비해 external fragmentation 측면에서 유리하다)

<br/>
<hr>

프로세스 별로 하나의 파티션을 주는 것은 관리, 크기의 가변, 보안 측면에서 구현하기 어렵다.  
code, data, heap, stack 영역을 각각 따로 할당하고 아직 비어있는 동적 메모리 공간은 나중에 할당하는 것은 어떨까?  
이런 방식을 Sparse address space 라고 한다. (꼭 위의 영역별로 나누는 것은 아니다)  
이 이론을 활용하여 섹션 별 파티션을 할당해주는 방식인 Segmentation 이 등장한다.

<hr>
<br/>

## Segmentation

* variable partition 의 확장이다.

![segmentation](https://user-images.githubusercontent.com/48989903/145210483-0b98f363-7c56-47c4-b931-cf24949ce63b.png)

* 각 세그먼트는 base register, limit register 를 통해 물리적 주소 범위를 가진다. (위 그림에서 limit 은 길이의 개념으로 사용되었다)
* Direction : 주소가 증가하는 방향
* Protection : R(read), W(write)
* e.g., virtual address (0x0362) + base register (0xa362) 는 Segment1 의 주소 범위를 초과하였고, 이는 우리가 흔히 아는 Segmentation falut 에러를 발생시킨다.
* Segment ID
  * Explicit : <segment ID, offset>
    * e.g., <0x01, 0x2a31>
  * Implicit : n-MSB
    * e.g., 0x<b>01</b>2a31 - 01 : Segment ID
* 메모리 어딘가에 위의 Segment Table 을 저장하고, MMU 는 translation 할 때 Segement Table Base Register (STBR) 에 써있는 ST 를 읽어서 연산한다.
  * Segment Table 을 register 에 저장하는것은 context switch 할 때에 overhead 가 크기 때문에 메모리에 저장하는 방식으로 구현되어있다.
* Sparse address space 를 구현하는데에 유리한 구조이다.
* Segment 를 통째로 옮기는데에 효율적이다. (테이블만 수정하면 된다 / variable partition 의 경우 process 단위이기 때문에 옮기기 쉽지 않다)
* External fragmentation 의 발생 가능성은 여전하다.

<br/>
<hr>

Segmentation 도 약점이 분명 존재한다. 그래서 더 작은 사이즈로 쪼개어서 사용하면 어떨까하는 이론이 생기기 시작한다.  
small and fixed size 로 나누어서 할당하는 방식을 도입하게 되었고, 이것이 다음에 공부할 Paging 이다.  
Paging 기법은 현존하는 아키텍처에서 채택하고 있다.
