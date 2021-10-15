# The longest common subsequence

### Example

Q) subsequence X, Y 가 주어졌다. Z 는 X 와 Y 의 longest common subsequence 이다. Z 는 무엇인가?
* X = [A, B, C, B, D, A, B]
* Y = [B, D, C, A, B, A]

A) Z = [B, C, A, B], [B, D, A, B]

## Naive approach

X 에서 가능한 subsequence 를 모두 찾은 뒤 Y 를 스캔한다.
* |X| = m
* |Y| = n

X 의 subsequence 의 개수 : 2<sup>m</sup> - 1 (공집합은 제외)  
Time complexity : O(2<sup>m</sup>) x O(n) = O(n2<sup>m</sup>)

## Four-step method 

X = ABCDEF, Y = GBCDFE

### 1. Optimal substructure of LCS

Goal : 문제에 optimal substructure 가 있음을 보인다.

Z 는 X, Y 의 LCS 라고 하자.

1. X<sub>m</sub> = Y<sub>n</sub> 일때
   * Z 는 LCS 이므로 Z<sub>k</sub> = X<sub>m</sub> = Y<sub>n</sub> 이다. Z<sub>k-1</sub> 는 X<sub>m-1</sub> 과 Y<sub>n-1</sub> 의 LCS 일 것이다.
2. X<sub>m</sub> != Y<sub>n</sub> 일때
   * Z<sub>k</sub> != X<sub>m</sub> 이면 Z<sub>k</sub> 는 X<sub>m-1</sub> 과 Y<sub>n</sub> 의 LCS 일 것이다.
   * Z<sub>k</sub> != Y<sub>n</sub> 이면 Z<sub>k</sub> 는 X<sub>m</sub> 과 Y<sub>n-1</sub> 의 LCS 일 것이다.
   * 둘 중 LCS 의 길이가 큰 것으로 정한다.

### 2. Cost of optimal solution

Goal : optimal solution 을 재귀적으로 정의한다.

* common subsequence 의 길이가 곧 cost 이다.
* c[i, j] 를 sequence X, Y 의 LCS 의 길이라 하자.
* base case : c[i, j] = 0

![lcs_recurrence](https://user-images.githubusercontent.com/48989903/137073660-7ca876f9-b7bf-4aae-b62d-4b7ef93de466.png)

Optimal structure 에서 정의한 얘기를 바탕으로 식을 세우면 위와 같다.

> 재귀만으로 LCS 를 구현하면 O(2<sup>n+m</sup>) 이다.

### 3. Compute length of optimal solution

Goal : optimal solution 을 계산한다.

![lcs_table](https://user-images.githubusercontent.com/48989903/137075138-2eb17114-ad3d-424b-8f76-a84f1e17814c.png)

1. X[i], Y[j] 값이 같다면 +1
2. X[i], Y[j] 값이 다르다면
   * max(X[i-1], Y[j])
   * max(X[i], Y[j-1])

### 4. Coding

Goal : 계산된 결과를 통해 optimal solution 을 세운다.

## Print LCS

* 2-dimension array C : length of LCS of X and Y
* 2-dimension array B : pointers to optimal subproblem solutions
 
```.c
PRINT-LCS(b, X, i, j)
  if i == 0 or j == 0
    return
  if b[i, j] == ↖
    PRINT-LCS(b, X, i-1, j-1)
    print c[i, j]
  else if b[i, j] == ←
    PRINT-LCS(b, X, i-1, j)
  else PRINT-LCS(b, X, i, j-1)
```

재귀의 방향이 역순이므로 PRINT-LCS 는 정방향의 문자열이 출력된다.

Q) 왜 인풋으로 X 배열을 사용할까?

## Performance

* LCS compute time complexity : O(mn)
  * 이중 루프로 c[1...m, 1...n] 의 인덱스를 채우므로 O(mn) 이다.
* LCS print time complexity : O(m+n)
  * m, n 이 0 이 될때까지 이므로 O(m+n) 이다.
