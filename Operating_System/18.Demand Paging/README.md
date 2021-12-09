# Demand Paging

## Swapping : Paging

* 메모리가 부족할 때 프로세스를 통째로 저장소에 일시적으로 빼놓고 필요시 다시 메모리로 불러오는 방식
* 실제 메모리의 크기보다 더 많은 양의 메모리를 사용할 수 있다.
* 프로세스 전체를 in/out 하기 때문에 많은 시간이 걸린다.

## Demand Paging

* swapping 을 page-level 에서 하는 것을 말한다.

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

