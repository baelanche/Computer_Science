# Binary Search

정렬된 A[1...n] 에서 x 의 위치를 찾는 알고리즘

* Divide : A[1...mid], A[mid+1...n] 으로 나눈다.
* Conquer : A[mid] = x, A[mid] < x, A[mid] > x 인 경우 각각의 이벤트가 발생한다.
* Combine : 결과를 리턴한다.

파티셔닝을 한 후 조건에 맞는 하나의 배열만 취한다.

## Performance

![binary_perf](https://user-images.githubusercontent.com/48989903/136659510-463e7e82-3f9a-4e0d-ba84-fae06d26f79c.png)

따라서, O(logn) (because, master theory case 2)
