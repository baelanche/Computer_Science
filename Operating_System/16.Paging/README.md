# Paging

![paging](https://user-images.githubusercontent.com/48989903/145344114-e08047fd-851e-44cc-867b-77dda4049319.png)

* virtual address 는 작은 크기(4KB)의 page 로 쪼갠다.
  * page 의 크기가 작으면 internal fragmentation 이 발생하는 크기가 줄어들지만 page entry 가 많아진다.
  * page 의 크기가 크면 internal fragmentation 이 발생하는 크기가 커지지만 page entry 가 줄어든다.
    * 1Gbyte 정도의 huge page 를 제공하는 아키텍처도 있다.
* physical address 는 그와 같은 작은 크기의 frame 으로 쪼갠다.
* fixed size 이기 때문에 internal fragmentation 이 발생할 수 있다.
  * 한 프로세스 당 절반 정도(2KB) 가 internal fragmentation 이 발생한다고 했을 때, 1000 개의 프로세스면 2MB 가 된다. 전체 메모리 용량에 비하면 크지 않기 때문에 꽤나 무시할 만 한 정도이다.
* external fragmentation 은 발생하지 않는다.

## Page Tables

* 각 프로세스는 자신의 고유한 page table 을 가진다.
* Page table base register 는 프로세스의 page table 을 가리키며, context switch 가 일어나면 PTBR 이 가리키는 주소가 바뀐다.
* VPN(virtual page number) to PFN(physical frame number)
  * Virtual address = <VPN, offset>
  * Physical address = <PFN, offset>
* 운영체제가 관리(alloc PF, update PT)하며, MMU 가 access 한다.

### Summary : Address Translation

![trans](https://user-images.githubusercontent.com/48989903/145346587-44ddd34b-fef9-4c23-80af-1188b9313f09.png)

### e.g., address translation

![trans_eg](https://user-images.githubusercontent.com/48989903/145347500-1625d6b6-c8de-473e-a158-5128e3828317.png)

* Virtual address : 32bits = 4GB
* Physical address : 20bits = 1MB
* Page size : 4KB
* Offset : 12bits
* VPN : 32 - 12 = 20bits
* Page table entries : 2<sup>20</sup>
* PFN : 20 - 12 = 8bits
* One of page table entry : 8bits
* Page table entry size : 2<sup>20</sup> * 8bits = 2<sup>20</sup>bytes = 1MB

### Page Table Entry (PTE)

![pte](https://user-images.githubusercontent.com/48989903/145347666-59010c47-4424-450f-af91-91c90fb4dcde.png)

* Valid bit : PTE 가 유효한지
* Reference bit
* Modify bit
* Protection bit : read, write, execute

## Buddy System Allocator

* Physically contiguous 한 메모리를 할당받아야 하는 경우가 있다. (e.g., I/O buffers)
* 이런 경우 피치 못하게 variable 한 메모리를 할당해 주어야하고 이는 external fragmentation 을 발생시킬 수 있다.
* external fragmentation 을 줄이기 위해 buddy system allocator 를 이용한다.
* buddy system 에서는 page 의 크기가 2<sup>n</sup> 이다.
* 13 pages 를 요구했을 때는 16 pages 를 할당해 주어야 하므로 internal fragmentation 이 발생한다.

### Allocation

![buddy](https://user-images.githubusercontent.com/48989903/145351685-e9cd7d55-720d-4293-8b6a-27be6511463e.png)

* size 2 인 page 를 요구했을 때 먼저 적당한 page 가 있는지 확인하고, 없다면 더 큰 page 를 반으로 나눈다.
* 반으로 나뉘어진 두 page 는 buddy 관계라고 한다. 둘 중 하나의 page 를 선택한다.
* size 2 보다 크므로 계속해서 나눈다.
* pages 2 를 할당한다.

![buddy2](https://user-images.githubusercontent.com/48989903/145352032-4f462cea-e9e4-4eba-b98f-b39a16e7eb2d.png)

* 이 상황에서 size 4 인 page 를 요구한다면 바로 할당해주면 된다.

![buddy3](https://user-images.githubusercontent.com/48989903/145352107-a9d9a18e-789e-4b28-97fb-41ccfe6ca2e5.png)

* size 4 인 page 를 요구했을 때 적절한 것이 없으므로 pages 8 을 반으로 쪼개어 하나를 준다.

![buddy4](https://user-images.githubusercontent.com/48989903/145352217-367e4041-2187-4f11-9ade-05c06afb91fc.png)

* size 1 인 page 를 요구했을 때 free chunks 중 가장 작은 pages 2 를 반으로 쪼개어 하나를 준다.

### Free

![buddy5](https://user-images.githubusercontent.com/48989903/145352979-0b971277-f784-4b20-8d25-ca598b95757d.png)

* free 를 해야할 때, 해당 chunk 를 먼저 free 하고 buddy 를 살핀다.
  * buddy 가 free 일 경우 : buddy 와 합친다.
  * buddy 가 free 가 아닐 경우 : 해당 chunk 는 free 라고 표시한 후 끝낸다.


