# Rod cutting

* 길이가 n 인 막대가 주어진다.
* 조각별 가격이 주어진다.
* 막대를 어떻게 잘라야 가장 큰 이득을 얻을 수 있을지 구한다.

## Preprocessing

* r<sub>n</sub> : 최대 이득
* p<sub>n</sub> : 자르지 않았을 때의 값
* r<sub>1</sub> + r<sub>n-1</sub> : 길이 1 의 값 + 길이 n-1 의 값
* ...
* r<sub>n-1</sub> + r<sub>1</sub> : 길이 n-1 의 값 + 길이 1 의 값
* max value : max(p<sub>n</sub>, r<sub>1</sub> + r<sub>n-1</sub>, ..., r<sub>n-1</sub> + r<sub>1</sub>)

## 1. Optimal substructure

![rod_overview](https://user-images.githubusercontent.com/48989903/137673191-23a2b71e-efa0-41dc-9b68-81bb9e2e9a9f.png)

## 2. Recursive structure

* 막대를 나눈다.
* 나눠진 막대 중 오른쪽 막대를 이용하여 subproblem 을 푼다.
* max(p<sub>i</sub> + r<sub>n-i</sub>)

#### Pseudocode

```.c
Cut-rod(p, n)
  if n == 0
    return 0
  q = -INF
  for i = 1 to n
    q = max(q, p[i] + Cut-rod(p, n-i))
  return q
```

* T(n) = 2<sup>n</sup>

## 3. Dynamic programming : bottom-up

```.c
Cut-rod(p, n)
  r[n]
  r[0] = 0
  for j = 1 to n
    q = -INF
    for i = 1 to j
      q = max(q, p[i] + r[j - i])
    r[j] = q
  return r[n]
```

## Performance

* O(n<sup>2</sup>) (table : n x n)

## Reconstructing a solution

* optimal choices 를 저장한 테이블을 생성한다.

```.c
Cut-rod(p, n)
  r[n], s[n]
  r[0] = 0
  for j = 1 to n
    q = -INF
    for i = 1 to j
      if q < p[i] + r[j-i]
        q = p[i] + r[j-i]
        s[j] = i
    r[j] = q
  return r, s
  
print(p, n)
  r, s = Cut-rod(p, n)
  while n > 0
    print s[n]
    n = n - s[n]
```

#### Print Cut-rod

![rod_print](https://user-images.githubusercontent.com/48989903/137679861-354a1686-261e-44c4-8776-226fc55e5992.png)

* print s[8] = 2
* n = n - s[8] = 8 - 2 = 6
* print s[2] = 6
* n = n - s[2] = 6 - 6 = 0
