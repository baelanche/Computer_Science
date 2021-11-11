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
