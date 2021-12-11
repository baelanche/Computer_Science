## Copy-on-Write

* fork() : child process 의 page table 생성 후 같은 frame 참조
* Copy-on-Write 를 위해 write 를 끄고 마킹을 한다.
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

