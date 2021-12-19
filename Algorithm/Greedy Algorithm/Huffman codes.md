# Huffman codes

* 데이터 압축에 이용하는 알고리즘이다.
* 어떤 character 를 binary character code 로 인코딩한다. (e.g., a = 000) 이를 codeword 라 한다.
* 인코딩은 단순한 방식으로 한다.

## Let's think

* 한 파일에 100,000 개의 character 가 있고 이들은 모두 a ~ f 의 character 이다.
* character 의 빈도수는 서로 다르다.

### 1. Fixed-length code

* 모든 character bits length 는 같다. (e.g., a = 000, b = 001, ..., f = 101)
* codeword 를 이어붙여서 표현한다.
* 300,000 bits 면 파일을 저장할 수 있다.

### 2. Variable-length code (= Huffman code)

* frequency 에 따라서 length 를 부여한다.
* 20% ~ 90% 까지 bit 수를 절약할 수 있다.

![huffman](https://user-images.githubusercontent.com/48989903/141266284-21899be5-abb4-4edc-9fea-876b35902973.png)

* 가장 많이 나오는 character 에 가장 짧은 길이의 code 를 부여한다.
* 가장 적게 나오는 character 에 가장 긴 길이의 code 를 부여한다.

### 핵심 : 그래서 인코딩은 어떤 방식으로 하나?

어떤 codeword 도 다른 codeword 의 prefix 가 아니면 이를 prefix-free code 라 한다.  
모든 codeword 가 prefix-free code 라면 huffman code 를 구성할 수 있다.

* a = 0, b = 110, c = 10, d = 111
* a 는 b, c, d 의 prefix 가 아니다.
* b 는 a, c, d 의 prefix 가 아니다.
* c 는 a, b, d 의 prefix 가 아니다.
* d 는 a, b, c 의 prefix 가 아니다.
* e.g., 01010 : acc

> 코드 사이에 marking 을 통해서 구분하는 방법도 있지만,  
> prefix-free code 로 ambiguity 를 없애서 코드를 만들면 공간을 더 절약할 수 있다.

## Building Huffman codes

optimal code 에 대응되는 트리를 만든다. 트리는 bottom-up 방식으로 merge 를 통해 완성한다.

* C : set of n characters
* f[c] : frequency
* T : tree
* merge process : min-priority queue (key : frequency)

1. 각 character 는 leaf node 가 된다.
2. priority queue 에 넣어서 frequency 가 낮은 노드가 우선순위가 된다.
3. queue is not empty 인 경우 아래 로직에 대해 루프한다.
   * queue 에서 두개의 노드를 dequeue 한다. (lowest frequency)
   * 두 노드를 merge 하여 parent 로 한다. (f[z] = f[x] + f[y])
   * 만들어진 노드를 queue 에 넣는다.
4. 마지막 노드가 root 노드가 된다.

### Process

<img width="700" alt="h1" src="https://user-images.githubusercontent.com/48989903/146671220-d726103e-97be-429c-900a-f1dba91a7223.png">

1. 초기 세팅

<img width="701" alt="h2" src="https://user-images.githubusercontent.com/48989903/146671226-42e1885b-3735-4ae5-843f-d68298f4ceed.png">

2. 가장 빈도수가 낮은 두 노드를 merge 한다. parent 노드는 빈도수의 합이 되며 왼쪽 노드가 항상 빈도수가 더 낮다. 가지 왼쪽에 0, 오른쪽에 1을 붙인다.

<img width="703" alt="h3" src="https://user-images.githubusercontent.com/48989903/146671246-78ecf069-aef1-4900-b196-3d50fb378137.png">

3. 그 다음으로 낮은 노드 12, 13 을 merge 한다.

<img width="696" alt="h4" src="https://user-images.githubusercontent.com/48989903/146671261-c27e1d08-d9e7-4f67-937f-9db516bdf945.png">

4. parent 노드도 queue 에 다시 들어가기 때문에 14, 16 을 merge 한다.

<img width="611" alt="h5" src="https://user-images.githubusercontent.com/48989903/146671280-03eb4d19-1e26-4efe-ba4b-9b5b21945fe1.png">

5. 25, 30 을 merge 한다.

<img width="528" alt="h6" src="https://user-images.githubusercontent.com/48989903/146671289-84fc3199-409e-48d4-b8d6-33c4e61a7c55.png">

6. 45, 55 를 merge 한다.
7. huffman code 를 구한다.
   * a : 0
   * b : 101
   * c : 100
   * d : 111
   * e : 1101
   * f : 1100
8. 모든 code 가 prefix-free code 인지 검증한다. 

### Performance

* Build min-heap : O(n)
* loop : n-1
* Extract/Insert priority queue : O(logn)
* running time : O(nlogn)

## Greediness

* 가장 빈도수가 낮은 character 에 대해 가장 긴 path 를 부여한다.
* 모든 subtree 에 대해 빈도수가 가장 낮은 노드가 가장 긴 path 를 가지고 있다.
