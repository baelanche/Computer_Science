# Sorting
  * Input : a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, ..., a<sub>n</sub>
  * Output : a<sub>1</sub> <= a<sub>2</sub> <= a<sub>3</sub> <= ... <= a<sub>n</sub>

e.g.
```
Input : 8 2 4 9 3 6
Output : 2 3 4 6 8 9
```

## Insertion Sort (삽입 정렬)

* 예제코드(C)
```.c
#include <stdio.h>
int main() {
  int n = 6; //배열 크기
  int a[6] = {8,2,4,9,3,6};
  
  int i, key;
  for(int j=1; j<n; j++) {
    key = a[j];
    i = j - 1;
    while (i >= 0 && a[i] > key) {
      a[i+1] = a[i];
      i = i-1;
    }
    a[i+1] = key;
  }
}

```
