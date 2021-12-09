# Page Tables

## Hierarchical Page Tables

### e.g., Two-level Page Tables

![outer](https://user-images.githubusercontent.com/48989903/145359197-ebc11923-ca7b-425a-9c47-adfb6a7cb445.png)

* page table 의 대부분은 할당이 안되어 비어있는 상태이다.
* page table 을 page 크기에 맞춰 쪼갠다.
* 빈 page 에 대해서는 page table 을 생성하지 않는다.
* 이 조각들을 가리키는 Outer page table 을 만든다.

### How can translate VPN to PFN?

* e.g., VPN 10 (0b1010)

![hi_trans](https://user-images.githubusercontent.com/48989903/145361875-4158bfb2-9f6a-4a10-a871-776ce3106cb3.png)

* leaf table 에서는 끝의 두자리가 모두 다르고 앞의 두자리는 모두 같다.
* outer table 에서는 앞의 두자리가 모두 다르다.
* 따라서, outer table 에서 앞의 두자리를 통해 leaf table 을 찾아간다.

![hi_trans2](https://user-images.githubusercontent.com/48989903/145373902-5e6db9a2-e260-4244-8b5f-49291b52b544.png)

* level 이 커져도 같은 방법으로 활용 가능하다.

![hi_trans3](https://user-images.githubusercontent.com/48989903/145374419-9a1987f6-8488-480c-aeab-878b42a90325.png)

* PTE size 가 2<sup>3</sup> 이어도 마찬가지이다.

### E.g.

#### 32-bit address space, 4KB pages, 4 bytes/PTE

![pte1](https://user-images.githubusercontent.com/48989903/145376362-aa0d2629-73cb-4c73-9420-6044062fb590.png)

* Outer page + Page : 20bits
* Page offset : 12bits
* the number of PTE : 4KB / 4bytes = 2<sup>10</sup>
  * 따라서 outer page(10bits), page(10bits)

#### 53-bit address space, 8KB pages, 8 bytes/PTE

* 8KB = 2<sup>3</sup> x 2<sup>10</sup> = 2<sup>13</sup>
  * Thus, offset part is 13bits
* the number of PTE : 8KB / 8bytes = 2<sup>10</sup>
* 10 + 10 + 10 + 10 + 13
* This system requires 4-level page table

### Pros and Cons

* linear page table 에 비해 메모리 효율이 좋다. (비어있는 공간에 대해 할당을 안한다)
* physical memory 를 다루기 쉽다.
* hardware 가 동작하기 쉽다.
* external fragmentation 이 없다.
* 복잡하다.

## Hashed Page Table

* Virtual Page Number 를 해쉬화하여 page table 에 넣는다.

## Inverted Page Table

* 거꾸로 매팽하는 방법이다. PFN -> <VPN, PID>
* page table 공간이 줄어든다.
* entry 를 찾을 때의 시간이 오래걸린다.

## Translation Look-aside Buffer : TLB

* 단계수 + 1(offset) 의 translation 이 일어나기 때문에 이를 줄이고자 하는 개념으로 도입되었다.
* 최근에 translation 이 발생한 주소를 buffer 에 저장하여 활용한다.

