# Knapsack

* n 개의 아이템과 knapsack(배낭) 을 받는다.
* 아이템은 각각의 무게와 가치가 부여된다.
* 배낭은 한계가 존재한다.
* Goal : 배낭이 최대 가치를 지닐 수 있도록 아이템을 채운다.

## Naive approach

* all combination : 2<sup>n</sup>

## Four-step method

### 1. Optimal substructure

![knapsack_opt](https://user-images.githubusercontent.com/48989903/137667367-c559ad1f-7587-4066-b6eb-c83b6686409f.png)

* i : item index
* w<sub>i</sub> : item weight
* W : knapsack capacity
* opt(i, w) : w = 1 ~ W
  * not select : w 에 지장을 주지 않는다.
  * select : w = w - w<sub>i</sub>

### 2. Recurrence for knapsack

![knapsack_recur](https://user-images.githubusercontent.com/48989903/137666956-cf9b4ac8-3778-4f3b-91a5-5a990ebcac54.png)

* Base case : opt(0, w) = 0
* recursive step
  * can't select : if w<sub>i</sub> > w : opt(i, w) = opt(i-1, w)
  * don't select or select : opt(i, w) = max(opt(i-1, w), v<sub>i</sub> + opt(i-1, w-w<sub>i</sub>))

### 3. Fill up table

#### Pseudocode

![knapsack_table](https://user-images.githubusercontent.com/48989903/137668012-861ee4e0-8a2a-448a-91e1-19c901977e66.png)

<br/>

#### Example : input

![knapsack_exam](https://user-images.githubusercontent.com/48989903/137668281-cd438b44-f863-44f7-893b-0c88f6fc1f5f.png)

<br/>

#### Example : table

![knapsack_exam_table](https://user-images.githubusercontent.com/48989903/137668343-f266cea6-1ba6-465e-8aa9-e72b6382d638.png)

## Performance

* fill table : O(nm)
* tracing the solution : O(n)
