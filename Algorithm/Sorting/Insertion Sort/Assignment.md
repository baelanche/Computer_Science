# Exercise 1

## Insertion sort

### 1. insertion sort(A, n) 알고리즘의 작동원리를 설명하세요.
손에 쥔 카드패를 정렬하는 방법과 유사하다.  
배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 적절한 위치에 삽입하여 정렬하는 알고리즘이다.

   1. A[1] 왼쪽에는 어떤 원소도 가지고 있지 않기 때문에 A[2] 부터 탐색을 시작한다.
   2. A[j] 에는 `현재 위치`, A[i] 에는 현재 위치의 `이전 위치(A[j-1])`를 저장한다.
   3. (0 < i) 의 범위 내에서 루프를 돌며 A[i] 가 A[j] 보다 크다면(참) 값을 교환하고 `현재 위치`가 A[i], `이전 위치`가 A[i-1] 이 된다.
   4. 조건이 참이면 3번을 반복하고, 거짓이라면 루프를 종료한다.
   5. j+1 이 배열의 인덱스를 벗어나지 않는다면 A[j+1] 이 다시 `현재 위치`가 되고 2~4번을 반복한다.

### 2. loop invariants를 사용하여 insertion sort(A, n)의 correctness를 증명하세요.
   1. Initialization(루프 돌기 전)
      * Q) 첫번째 루프를 돌기 전 배열은 정렬되어 있는가?
      * A) 크기 1인 배열은 이미 정렬되어 있다. `j=2` 일때 `A[1]`는 정렬된 상태이므로 언제나 정렬된 상태임을 알 수 있다.
   2. Maintenance(루프 중)
      * Q) 반복 중에 배열은 정렬되어 있는 상태라고 할 수 있는가?
      * A) 배열의 `j`번째 원소가 내부 루프에 들어갈 때 정렬되어있지 않은 상태라면, 루프 종료시 정렬된 상태가 된다.  
           외부 루프가 한번 돌 때 내부 루프는 종료 시점까지 돈다.
   3. Termination(종료)
      * Q) 루프가 종료되어도 정렬된 상태인가?
      * A) 루프는 `j = n + 1`에서 종료된다. `j = n` 시점에서 모든 `j`번째 원소들은 정렬된 상태이다

### 3. insertion sort(A, n)의 best case 런타임을 계산과정과 함께 보이세요.
오름차순 정렬 알고리즘일 때 input 배열이 오름차순인 경우 Best case 이다.
   1. `현재 위치`의 원소는 A[2] 이며 `이전 위치`의 원소와 비교한다.
   2. `현재 위치`의 원소가 항상 크므로 `1`번의 비교를 통해 내부 루프가 종료된다.
   3. 따라서 배열의 크기가 n일때 n-1 번의 연산으로 외부 루프가 종료된다.

최고차항만을 따졌을 때 시간복잡도는 O(n)으로 Best case 가 된다.
   

### 4. insertion sort(A, n)의 worst case 런타임을 계산과정과 함께 보이세요.
오름차순 정렬 알고리즘일 때 input 배열이 내림차순인 경우 Worst case 이다.
   1. `현재 위치`의 원소는 A[2] 이며 `이전 위치`의 원소와 비교한다.
   2. `현재 위치`의 원소가 항상 작으므로 `현재 위치의 인덱스 - 1`번 만큼의 연산을 통해 내부 루프가 종료된다.
   3. 따라서 배열의 크기가 n일때 (n-1)<sup>2</sup> 번의 연산으로 외부 루프가 종료된다.

최고차항만을 따졌을 때 시간복잡도는 O(n<sup>2</sup>)으로 Worst case 가 된다.

### 5. insertion sort(A, n)을 응용하여, 새로운 알고리즘 insertion sort_desc(A, n)를 작성하고(pseudo code) 그 작동원리를 설명하세요. 
```
insertion sort_desc(A, n)의 input과 output은 다음과 같다.
   * Input : n개의 원소로 이루어진 숫자 배열 A
   * Output : 내림차순으로 정렬된 배열 A'
```

```.r
INSERTION-SORT_DESC(A,n)
   for j <- 2 to n
      do key <- A[j]
         i <- j - 1
         while i > 0 and A[i] < key
            do A[i+1] <- A[i]
               i <- i - 1
         A[i+1] = key
```

   1. A[1] 왼쪽에는 어떤 원소도 가지고 있지 않기 때문에 A[2] 부터 탐색을 시작한다.
   2. A[j] 에는 `현재 위치`, A[i] 에는 현재 위치의 `이전 위치(A[j-1])`를 저장한다.
   3. (0 < i) 의 범위 내에서 루프를 돌며 A[i] 가 A[j] 보다 <b>작다면(참)</b> 값을 교환하고 `현재 위치`가 A[i], `이전 위치`가 A[i-1] 이 된다.
   4. 조건이 참이면 3번을 반복하고, 거짓이라면 루프를 종료한다.
   5. j+1 이 배열의 인덱스를 벗어나지 않는다면 A[j+1] 이 다시 `현재 위치`가 되고 2~4번을 반복한다.

### 6. Insertion sort를 응용한 문제 (a variant of insertion sort)를 만들어보세요. 여러분이 문제 출제자라면 우리가 배운 insertion sort를 어떻게 변형하여 출제할 수 있을지 고민해보세요. 요구하는 input과 output을 명확하게 설명해주세요.

Binary insertion sort는 insertion sort에 binary search 알고리즘을 적용한 정렬 알고리즘이다.  
이 알고리즘을 적용하면 키 값의 위치를 찾는데 걸리는 시간이 총 O(nlogn)으로 기존 알고리즘에 비해 빠르다.  

insertion sort(A,n) 의 input이
```
1 2 4 5 7 3
```
이고 현재 key가 `3` 일때

<b>1) insertion sort 일 때 값을 비교하는 원소를 차례로 쓰시오.</b>  
<b>2) binary insertion sort 일 때 값을 비교하는 원소를 차례로 쓰시오.</b> (아래 함수를 참고해서 해결한다)

* binary search
```.c
/*
이미 정렬되어있는 배열을 반으로 잘라 키 값과 배열의 중간값의 크기를 비교한다.  
키 값이 중간값보다 작으면 왼쪽 배열, 키 값이 중간값보다 크면 오른쪽 배열을 대상으로 재탐색한다.
동일한 방식으로 탐색하며 키 값의 적절한 위치를 찾을때까지 반복한다.
binary_search(int, int, int) { return int }
start : 현재 탐색중인 배열의 시작 인덱스
end : 현재 탐색중인 배열의 마지막 인덱스
key : 위치를 찾고싶은 수
mid : 현재 탐색중인 배열의 중간 인덱스
*/
int binary_search(int start, int end, int key) {
   int mid;
   while (start < end) {
      mid = (start + end) / 2;
      if (key >= a[mid])
         start = mid + 1;
      else
         end = mid;
   }
   return end;
}
```

* Answer
   1. 7 5 4
   2. 4 2
