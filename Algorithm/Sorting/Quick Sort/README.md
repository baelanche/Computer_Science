# Quick Sort

* Divide : 원소 중 하나를 피벗으로 정한다. 피벗을 기준으로 배열을 두개로 쪼갠다.
* Conquer : 재귀적으로 두개의 sub-array 를 정렬한다.
* Combine : 붙인다.

## Process

피벗을 기준으로 배열을 쪼갠다.

i : 피벗보다 작거나 같은 값의 경계
j : 피벗보다 큰 값의 경계
루프가 끝나면 i + 1 과 피벗을 스왑

## Proof : Loop invariants

전제 : 피벗보다 같거나 작은 sub-array, 피벗보다 큰 sub-array, 피벗 세가지로 이루어져 있다.
* p : 제일 작은 인덱스
* r : 제일 큰 인덱스
* i : 피벗보다 작거나 같은 수를 모은 sub-array 중 가장 큰 인덱스를 가리킴
* j : 피벗보다 큰 수를 모은 sub-array 중 가장 큰 인덱스를 가리킴

1. Initialization : 
2. Maintenance :
3. Termination :

## Running Time

Partition : O(n)
파티션을 통해 피벗의 인덱스를 찾아내고, 양 쪽 sub-array 를 퀵소트 한다.

파티셔닝에 따라 running time 이 크게 달라진다.

balanced : 피벗을 통해 양 sub-array 가 비슷한 크기로 분리될 때 (merge sort 와 같은 퍼포먼스를 보여줌)
unbalanced : 피벗을 통해 값의 분리가 일어나지 않아서 sub-array 가 하나만 만들어질 때 (insertion sort 와 같은 퍼포먼스를 보여줌)

Best case : balanced / sub-array 가 대략 n/2 정도의 크기
T(n) = 2T(n/2) + O(n) = O(nlogn) ( O(n) : partitioning)

Worst case : unbalanced / 크기가 0, n-1 로 분리되었을 경우
T(n) = T(n-1) + T(0) + O(n)
     = T(n-1) + O(n)
     = O(n^2) // telescoping 으로 풀어내면 n + n + ... + n 이 n 개 이므로 n^2
