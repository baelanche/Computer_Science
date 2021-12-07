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

