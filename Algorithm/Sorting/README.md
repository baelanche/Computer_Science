# Sorting
  * Input : (sequence) a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, ..., a<sub>n</sub>
  * Output : (permutation) a<sub>1</sub> <= a<sub>2</sub> <= a<sub>3</sub> <= ... <= a<sub>n</sub>

## Insertion Sort (삽입 정렬)

* 예제코드(C)
```
Input : 8 2 4 9 3 6
Output : 2 3 4 6 8 9
```
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

### Proof

Loop invariants
* Note that, as we go through the outer loop(the for loop), we are guaranteed that the part of the array from element #1 up through element j - 1 is sorted order. We can stats this as a formal loop invariant.
* "At the start of each iteration of the for loop of lines 1-8, the subarray A[1..j-1] consists of the elements originally in A[1..j-1] but in sorted order"

We must show three things about a loop invariant
* Initialization : It is true prior to the first iteration of the loop
  * Is the array sorted prior to the first iteration of the loop?
  * The first iteration begins by assuming that a list of size 1 is already in sorted order, and starts off by assigning j a value of 2. A list of size 1 is always in sorted order.
* Maintenance : If it is true before an iteration of the loop, it remains true before the next iteration
  * If the array is sorted prior to an iteration of the loop, will that iteration preserve its sorted status?
  * Our examination of the behavior of the inner loop shows that if the j th element of the array is out of order when entering the inner loop, then it will be in the correct order when exiting the loop.
  * The inner loop is basically all that the outer loop does during one iteration.
* Termination : When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct
  * What happens when the loop terminates? Does that preserve the sorted order?
  * The loop terminates when j = n + 1. Just prior to that point, while j = n, all j (and thus all n) of the elements of the array are in sorted order.
  * So, yes, the termination condition of the loop preserves the sorted order of the array.

Running time
* Assume that we write our algorithm in such a way that it has i lines(or steps), each of which takes a constant amount of time to execute on our RAM.
* So, c1 is the time it takes to execute line 1, c2 is the time it takes to execute line 2, etc.
* If there are no loops in our algorithm: c1 + c2 + ... + ci.
* A constant plus a constant plus a constant ... equals a constant.
* So the running time of any algorithm with no loops is a constant.

* What if the algorithm has loops?
* If the number of times the algorithm executes the loop is constant, then the running time of the algorithm is still a constant.
* However, the running time of most algorithms will depend upon the input.
* If the number of times the algorithm executes the loop is proportional to the input, then the running time will not be a constant.
* The running time depends on the input: an already sorted sequence is easier to sort.
* Parameterize the running time by the size of the input, since short sequences are easier to sort than long ones.
* Generally, we seek upper bounds on the running time, because everybody like a guarantee.
