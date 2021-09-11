# Exercise 1

## Insertion sort

### 1. insertion sort(A, n) 알고리즘의 작동원리를 설명하세요.
   1. A[1] 왼쪽에는 어떤 원소도 가지고 있지 않기 때문에 A[2] 부터 탐색을 시작한다.
   2. A[j] 에는 `현재 위치`, A[i] 에는 현재 위치의 `이전 위치(A[j-1])`를 저장한다.
   3. (0 < i) 의 범위 내에서 루프를 돌며 A[i] 가 A[j] 보다 크다면(참) 값을 교환하고 `현재 위치`가 A[i], `이전 위치`가 A[i-1] 이 된다.
   4. 조건이 참이면 3번을 반복하고, 거짓이라면 루프를 종료한다.
   5. (j+1 <= n) 를 만족할 때 A[j+1] 이 다시 `현재 위치`가 되고 2~4번을 반복한다.

### 2. loop invariants를 사용하여 insertion sort(A, n)의 correctness를 증명하세요.
   1. Initialization(루프 돌기 전)
      * Q) 첫번째 루프를 돌기 전 배열은 정렬되어 있는가?
      * A) 크기 1인 배열은 이미 정렬되어 있다. `j=1` 일때 `A[0]`는 정렬된 상태이므로 언제나 정렬된 상태임을 알 수 있다.
   2. Maintenance(루프 중)
      * Q) 반복 중에 배열은 정렬되어 있는 상태라고 할 수 있는가?
      * A) 배열의 `j`번째 원소가 내부 루프에 들어갈 때 정렬되어있지 않은 상태라면, 루프 종료시 정렬된 상태가 된다.  
           외부 루프가 한번 돌 때 내부 루프는 종료 시점까지 돈다.
   3. Termination(종료)
      * Q) 루프가 종료되어도 정렬된 상태인가?
      * A) 루프는 `j = n + 1`에서 종료된다. `j = n` 시점에서 모든 `j`번째 원소들은 정렬된 상태이다

### 3. insertion sort(A, n)의 best case 런타임을 계산과정과 함께 보이세요.
   

### 4. insertion sort(A, n)의 worst case 런타임을 계산과정과 함께 보이세요.

### 5. insertion sort(A, n)을 응용하여, 새로운 알고리즘 insertion sort_desc(A, n)를 작성하고(pseudo code) 그 작동원리를 설명하세요. 
```
insertion sort_desc(A, n)의 input과 output은 다음과 같다.
   * Input : n개의 원소로 이루어진 숫자 배열 A
   * Output : 내림차순으로 정렬된 배열 A'
```

### 6. Insertion sort를 응용한 문제 (a variant of insertion sort)를 만들어보세요. 여러분이 문제 출제자라면 우리가 배운 insertion sort를 어떻게 변형하여 출제할 수 있을지 고민해보세요. 요구하는 input과 output을 명확하게 설명해주세요.
