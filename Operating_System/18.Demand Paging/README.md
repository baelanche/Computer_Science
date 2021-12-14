# Demand Paging

## Swapping : Paging

* 메모리가 부족할 때 프로세스를 통째로 저장소에 일시적으로 빼놓고 필요시 다시 메모리로 불러오는 방식
* 실제 메모리의 크기보다 더 많은 양의 메모리를 사용할 수 있다.
* 프로세스 전체를 in/out 하기 때문에 많은 시간이 걸린다.

## Demand Paging

* swapping 을 page-level 에서 하는 것을 말한다.
* 하드웨어는 page table 의 valid/invalid bit 를 통해 이 과정을 도와준다.
* 저장소가 필요하다. (linux 에서 swap 공간을 지정하는 것이 이 저장소를 의미한다)
* page fault 가 발생하면 instruction 을 재시작한다.

#### e.g.,

![demand1](https://user-images.githubusercontent.com/48989903/145384366-d83ed3f4-fdca-418f-9924-59f29ce53859.png)

* 프로세스에게 메모리 할당을 모두 해주어서 main memory 가 꽉 찬 상태이다.

![demand2](https://user-images.githubusercontent.com/48989903/145384501-ac94d4de-c386-4955-a133-f355aa0981b6.png)

* 운영체제는 victim page 를 지정하여 디스크에 쓴다.

![demand3](https://user-images.githubusercontent.com/48989903/145387312-3238ecbc-59d0-4238-aebf-cf1f50aa313a.png)

* PTE 에서 swap file 을 가리키게 하고 메모리에서 victim page 를 제거한다.

![demand4](https://user-images.githubusercontent.com/48989903/145387584-99f9b9dd-01a2-4ef9-abfd-0ae655a45b97.png)

* P0 를 할당한다.
* 이후 context switch 가 일어나 P0 가 디스크의 paging file 을 가리키게 되었다.
* 이 때 MMU 는 디스크에 접근하지 못하므로 운영체제에게 알린다.
* 운영체제는 main memory 의 공간을 비워 디스크의 paging file 을 가져온다.
* PTE 를 재조정한다.
* MMU 가 재동작한다.

### Handling a Page Fault

* OS 는 page table 을 생성한다.
* MMU 는 page table 에 접근하여 알아서 translation 한다.
* MMU 가 page table 에 접근했을 때 page fault(translation 과정에서의 문제) 가 발생한다면 이 상황을 OS 가 처리한다.
* 이후 MMU 가 다시 동작한다.

### Demand Paging in real OS

* 시스템이 켜졌을 때 프로세스를 메모리에 올려서 동작하는 것이 아니라, 그때 그때 필요한 프로세스를 메모리에 올려서 동작한다.
* The principle of locality
  * Temporal locality : 최근에 읽힌 메모리/페이지가 곧 다시 읽힐 가능성이 높다.
  * Spatial locality : 최근에 읽힌 메모리/페이지의 주변 영역이 곧 다시 읽힐 가능성이 높다.

### Shared Memory

![shared](https://user-images.githubusercontent.com/48989903/145528232-18b506fb-f859-4bd3-b65c-7a40845251cd.png)

* PA, PB 의 page table 이 같은 프레임을 가리키는 경우이다.
* 이럴 때에 page frame 을 sharing 한다고 말한다.
* Ref count : frame 을 참조하는 process 의 수

## Copy-on-Write

* fork() : child process 의 page table 생성 후 같은 frame 참조 (sharing)
* Copy-on-Write 를 위해 write 를 끄고 마킹을 한다. (별도의 변수 등의 방법)
* 수정 발생시 write 가 가능하기 때문에 새로운 frame 을 참조한다
* page fault 는 parent, child 모두에게 발생할 수 있다.
* p1, p2 가 서로 다른 frame 을 참조하고 있고, 이 두 frame 의 내용이 같다면 같은 곳을 참조하게 하고 하나의 frame 을 날리기도 한다.

![cow](https://user-images.githubusercontent.com/48989903/145528652-457503a8-0b3d-410a-8624-8a59c1141286.png)

* process A 의 pt 가 위와 같을 때 A 에 대해 fork() 를 실행하였다.
* process B 는 메모리를 copy 하는 일 없이 page table 을 통해 참조시켜서 fork() 를 마친다.

![cow2](https://user-images.githubusercontent.com/48989903/145528977-d7b5ece8-4284-4d16-9ced-4c95ae9696c8.png)

* 단 fork() 를 하고난 후 변경되는 사항에 대해서는 공유하지 않기 때문에 수정이 발생하면 다른 frame 에 새로 쓴다.

![cow3](https://user-images.githubusercontent.com/48989903/145529090-73e63ea5-8a31-41d7-b135-9fed14ae2c24.png)

* process A 에서 새로 write 하였을 때도 마찬가지로 다른 frame 에 새로 쓴다.

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
