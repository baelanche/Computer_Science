# Back Tracking

## N Queens Problem

* Input : n x n array, n queens
* Output : distinct queens (서로 공격할 수 없는 위치)
* queen can move

```
Q x x
x x o
x o x
```

* 4 by 4 배열에 4개의 퀸을 놓을 수 있는 수 : 16 * 15 * 14 * 13

### Process

1. 첫번째 퀸은 아무 위치에나 놓는다.
2. 두번째 퀸부터 안전한 위치에 놓는다.
3. 2번 과정에서 안전한 위치를 찾을 수 없다면 이전에 놓은 퀸의 위치를 바꾼다. (back tracking)
4. 모든 퀸을 두었을 때 로직을 종료한다.

### Performance

* loop : n
  * find safe place : O(N)
  * recursive : T(n-1)
* running time : O(n<sup>2</sup>) + N * T(n-1) = O(n!)
* back tracking 을 실제로 적용하였을 때 최악의 경우가 잘 안나오므로 시간복잡도에 비해서 효율적이다.

