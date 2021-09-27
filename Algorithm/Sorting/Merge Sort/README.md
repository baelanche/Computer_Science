# Merge Sort (병합정렬 / 합병정렬)

Recursion 에 기반한 divide-and-conquer 알고리즘을 사용한다.

## Divide-and-conquer

* Divide : 문제를 여러 개의 작은 문제들로 접근한다.
* Conquer : 작은 문제들을 재귀적으로 해결해나간다. 
* Combine : 작은 문제들로부터 답을 찾아 본 문제를 해결한다.

### Divide-and-conquer in Merge sort

* Divide : n 크기의 배열은 n/2 크기의 배열로 나뉜다.
* Conquer : 나뉜 배열들을 재귀적으로 정렬해나간다. 배열의 크기가 1일때 종료한다.
* Conbine : 두개의 나뉜 배열들을 병합하여 정렬시킨다.

## Process

![merge_flow](../../image/merge_flow.png)

합병정렬은 재귀로 구성되어 있다. 재귀가 멈추는 순간은 작은 배열의 크기가 1일때 이다.  
conbine 과정에서 `Merge` 알고리즘을 수행한다.

### Pseudo code(Merge-sort)
```
MERGE-SORT(A[1...n],p,r)
  1. If p < r
  2. q <- fall(p+r/2)
  3. MERGE-SORT(A, p, q)
  4. MERGE-SORT(A, q+1, r)
  5. MERGE(A, p, q, r)
```

### Merge function

Merge 할 배열들은 이미 정렬되어 있는 배열이다.

#### Initial setting (L = [1, 4, 7] R = [2, 3, 9])
![l](../../image/merge_l.png)
![r](../../image/merge_r.png)
  
`inf : 배열의 끝을 표시하기 위한 수(배열안의 원소 중 어떤 수보다도 커야한다)`

<br/><br/>

![merge1](../../image/merge1.png)

1. 양 배열의 첫번째 원소를 비교하여 작은 값을 내려쓴다.

<br/><br/>

![merge2](../../image/merge2.png)

2. 값을 내려쓴 쪽은 다음 원소를 가리키며 다시 비교하여 마찬가지로 작은 값을 내려쓴다.

<br/><br/>

![merge3](../../image/merge3.png)

3.

<br/><br/>

![merge4](../../image/merge4.png)

4.

<br/><br/>

![merge5](../../image/merge5.png)

5.

<br/><br/>

![merge6](../../image/merge6.png)

6. R 배열에서 9를 내려쓰고 inf 를 가리킬 것이다. 양 배열의 인덱스가 inf 를 가리키면 중단한다.

<br/><br/>

Merge 하는 과정에서 비교횟수는 (r - p) + 1 이다.
```
p = 배열의 가장 작은 인덱스
r = 배열의 가장 큰 인덱스
```

여기서 r = 6, p = 1 이므로 n = (r - p) + 1 = 6 이다.

### Code



## Proof : Loop invariants(merge)

1. Initialization : 루프를 시작하기 전에 배열은 정렬되어 있는가?
  * 루프에 들어가기 전에 key 값은 시작 인덱스인 p 이며 이는 sub-array 가 아직 비어있다는 것을 의미한다. 따라서 정렬되어 있다. L, R 배열도 합쳐지기 전 크기 1의 배열이므로 정렬 상태이다.
2. Maintenance : 루프 중에 배열은 정렬되어 있는가?
  * L 과 R 의 원소를 차례로 비교하여 가장 작은 원소를 배열 A 에 복사한다. 이 때 A 는 비어있는 상태이므로 값이 추가되어도 정렬되어 있음을 만족한다.
3. Termination : 루프 종료 후 배열은 정렬되어 있는가?
  * 종료되는 순간은 k = r + 1 일때이다. 이 때 sub-array A 는 A[p...k-1] 이며 A[p...r] 과 같으므로 merge 가 완료된 상태이다. sub-array 는 이미 정렬된 상태이므로 whole array 도 정렬 상태이다.
    
## Running Time

input size : n
T(n) : Running time
D(n) : divide  
C(n) : combine

if (n <= c) : n이 constant이다. 다루지 않음

Best case : n = 1
Divide : 
Conquer : 
Conbine : n

Divide step : 길이가 n 일때 트리 형태로 배열이 쪼개질 것이다. 이 때 스텝이 k 일때 배열의 갯수는 2<sup>k</sup> 이다.
height는 logn 이다.  
결과적으로 log<sub>2</sub>n + 1 의 단계 , total cost : cn(log<sub>2</sub>n + 1) -> 최고차항만 남긴다. hence, O(nlogn) 이다.

## Conclusions

* O(n<sup>2</sup>) 인 Insertion sort 보다 성능이 좋다.
* 실제로, n > 30 일때 Merge sort 가 Insertion sort 보다 빠르게 동작한다.
