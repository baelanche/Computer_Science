# Quick Sort

* Divide : 원소 중 하나를 피벗으로 정한다. 피벗을 기준으로 배열을 두개로 쪼갠다.
* Conquer : 재귀적으로 두개의 sub-array 를 정렬한다.
* Combine : 붙인다.

## Process

![quick_process](https://user-images.githubusercontent.com/48989903/136646630-5c60b2dd-f896-4949-aeb3-fc5047552897.png)

위와 같이 첫번째 자리가 피벗인 배열이 있다.  
피벗은 원하는 대로 고를 수 있으며 피벗에 따라 시간복잡도가 변한다.

1. 피벗과 비교하여 작거나 같으면 왼쪽 배열에 둔다.
2. 피벗보다 크면 오른쪽 배열에 둔다.
3. 나뉘어진 두 배열에서 다시 피벗을 고르고 반복한다.

실제 코드에 적용하면 아래와 같이 동작한다.

전제 : 피벗보다 같거나 작은 sub-array, 피벗보다 큰 sub-array, 피벗 세가지로 이루어져 있다.
* p : 제일 작은 인덱스
* r : 제일 큰 인덱스
* i : 피벗보다 작거나 같은 수를 모은 sub-array 중 가장 큰 인덱스를 가리킴
* j : 피벗보다 큰 수를 모은 sub-array 중 가장 큰 인덱스를 가리킴

![quick1](https://user-images.githubusercontent.com/48989903/136656932-874b90f3-fc86-4bbb-a9b1-bbdf5ae2f2c0.png)

1. 피벗 값과 루프가 가리키는 첫번째 원소의 값과 비교한다.

![quick2](https://user-images.githubusercontent.com/48989903/136656968-404acf89-8111-4388-80b1-e4de1bf7b774.png)

2. 첫번째 원소가 더 작으므로 i 를 증가시킨다.

![quick3](https://user-images.githubusercontent.com/48989903/136657000-af6e79d0-ad38-4f21-9bc5-6e515b4d67d6.png)

3. 두번째 원소는 피벗보다 크므로 j 를 증가시킨다.

![quick4](https://user-images.githubusercontent.com/48989903/136657052-1070834c-88e5-4ea3-a24f-de1d6ba1b323.png)

4. 세번째 원소도 피벗보다 크므로 j 를 증가시킨다.

![quick6](https://user-images.githubusercontent.com/48989903/136657073-9c698fa9-2af9-46ae-8f90-ab0b141f97b8.png)

5. 네번째 원소는 피벗보다 작다. i 를 증가시키고 A[i] 와 A[j] 를 스왑한다.

![quick7](https://user-images.githubusercontent.com/48989903/136657131-ef8bd182-bb04-4293-93a4-f20c845a42ed.png)

6. 끝까지 진행하면 위와 같다.

![quick8](https://user-images.githubusercontent.com/48989903/136657155-ef67f42c-89cb-491b-a388-d4a30faba819.png)

7. 마지막으로 i 를 증가시키고 A[i] 와 피벗을 스왑한다.

나누어진 sub-array 들을 위 방법으로 재귀하면 퀵정렬이 완성된다.

## Proof : Loop invariants

피벗을 배열의 가장 끝 값으로 하고 partition 을 진행할 시
* A[p...i] 의 모든 원소는 피벗보다 작거나 같다
* A[i+1...j-1] 의 모든 원소는 피벗보다 크다
* A[r] 은 피벗이다
이를 증명하고 싶다.

전제 : 피벗보다 같거나 작은 sub-array, 피벗보다 큰 sub-array, 피벗 세가지로 이루어져 있다.
* p : 제일 작은 인덱스
* r : 제일 큰 인덱스
* i : 피벗보다 작거나 같은 수를 모은 sub-array 중 가장 큰 인덱스를 가리킴
* j : 피벗보다 큰 수를 모은 sub-array 중 가장 큰 인덱스를 가리킴

전제는 이전과 같다.

1. Initialization : 루프를 시작하기 전에, A[r] 은 피벗이고 A[p...i], A[i+1...j-1] 은 빈 배열이다.
2. Maintenance : 루프가 진행중일 때, A[j] 가 피벗보다 작거나 같다면 A[i+1] 과 A[j] 를 스왑하므로 전제를 만족한다. A[j] 가 피벗보다 클때는 j 만 증가시키면 되므로 만족한다.
3. Termination : 루프가 종료되었을 때, j = r 이다. 따라서 피벗보다 작거나 같은 sub-array, 피벗보다 큰 sub-array, 피벗으로 partitioning 된다.

## Running Time

Partition : O(n) -> 파티션을 통해 피벗의 인덱스를 찾아내고, 양 쪽 sub-array 를 퀵소트(재귀) 한다.

파티셔닝에 따라(피벗에 따라) running time 이 크게 달라진다.
* balanced : 피벗을 통해 양 sub-array 가 비슷한 크기로 분리될 때 (merge sort 와 같은 퍼포먼스를 보여줌)
* unbalanced : 피벗을 통해 값의 분리가 일어나지 않아서 sub-array 가 하나만 만들어질 때 (insertion sort 와 같은 퍼포먼스를 보여줌)

### Best case

* balanced
* sub-array 가 대략 n/2 정도의 크기

```
T(n) = 2T(n/2) + O(n) = O(nlogn) // O(n) : partitioning
```

### Worst case
* unbalanced 
* 크기가 0 & n-1 로 분리되었을 경우

T(n) = T(n-1) + T(0) + O(n)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;= T(n-1) + O(n)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;= O(n<sup>2</sup>)

#### telescoping

T(n) = T(n-1) + n  
T(n-1) = T(n-2) + n-1, T(n) 에 대입  
T(n) = T(n-2) + n-1 + n  
T(n) = T(n-3) + n-2 + n-1 + n
...
