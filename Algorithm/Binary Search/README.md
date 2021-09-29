# Binary Search

A[1...n] 에서 찾고자 하는 x 를 찾는 알고리즘

Divide : A[1...mid], A[mid+1...n] 으로 나눈다.
Conquer : A[mid] = x, A[mid] < x, A[mid] > x 인 경우 각각의 이벤트가 발생한다.
Combine : 결과를 리턴한다.

key : 파티셔닝을 한 후 조건에 맞는 하나의 배열만 취한다.

## Performance

T(n) = 1T(n/2) + O(1) 
