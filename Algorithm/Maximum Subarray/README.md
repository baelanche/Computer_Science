# Maximum Subarray (최대 구간합)

* input : A[1...n] (양수 & 음수)
* output : 합이 가장 큰 연결된 부분 배열 A[i...j]

### Naive approach

1번 인덱스부터 n번 인덱스까지 더하면서 최댓값을 찾아본다.  
매 연산마다 최댓값을 갱신하는 과정을 거친다.  
모든 인덱스에서 끝까지 순회하므로 시간복잡도는 O(n<sup>2</sup>) 이다.

## Solving by divide-and-conquer

Time complexity : O(nlogn)
array : A[1...n]  
divide 0 : A[1...n] = A[low...high]

* Divide : mid 인덱스 기준으로 나누며 가능한 같은 크기의 subarray 로 나눈다.
* Conquer : 나뉘어진 subarray 에서 최대 구간합을 찾는다.
* Combine : mid 중심으로 나타날 수 있는 최대 구간합을 찾는다. (subarray 로 나뉘어지기 전 mid 부분에서 최대 부분합이 발생할 수 있기 때문이다) 왼쪽 subarray, 오른쪽 subarray, 중앙 subarray 중 가장 큰 값을 재귀과정에 사용한다.

### Combine : cross the midpoint

A[low...mid], A[mid+1...high] 로 나뉘어진 상황에서 중심에서 발생하는 최대 구간합을 찾아보자.

![midpoint](https://user-images.githubusercontent.com/48989903/135854280-cc89e722-0eb8-4435-9742-cf3f627587fd.png)


1. mid-subarray 의 범위는 A[i...mid], A[mid+1...j] 이다.
2. 두 배열에서 각각 최대 구간합을 구한다.
3. 두 수를 더한다.

## Process

