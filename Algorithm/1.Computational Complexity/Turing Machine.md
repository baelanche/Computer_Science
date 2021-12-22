# Turing Machine

디지털 연산에 관해 가장 강력한 기능을 제공하는 머신이다.  
튜링 머신이 식별하지 못하는 언어는 다른 머신 또한 식별하지 못한다.

## Finite automaton

<img width="742" alt="finite1" src="https://user-images.githubusercontent.com/48989903/146756591-bf8382b0-2fa5-48b8-9409-0a9c6fd8c769.png">

* finite-state graph 가 주어진다.

<img width="312" alt="finite2" src="https://user-images.githubusercontent.com/48989903/146756854-d161579d-8140-409f-904a-36350fe7fe45.png">

* 또, string 으로 구성된 finite tape 이 주어진다.
* tape 은 state 에 의해 순서대로 읽혀진다. (단방향)
* finite state 는 input string 을 읽고 간선(transition)에 동일한 string 을 보유해야만 다음 state 로 전이할 수 있다.

### Process

1. input string 이 들어와 순서대로 읽는다.
2. 현재 state 는 q<sub>0</sub> 이며 input 의 현재 label 인 a 와 transition 인 a 가 일치하므로 q<sub>1</sub> 으로 전이한다.
3. 현재 state 는 q<sub>1</sub> 이며 input 의 현재 label 인 b 와 transition 인 b 가 일치하므로 q<sub>2</sub> 으로 전이한다.
4. 현재 state 는 q<sub>2</sub> 이며 input 의 현재 label 인 a 와 transition 인 a 가 일치하므로 q<sub>3</sub> 으로 전이한다.
5. input 의 현재 label a 가 존재하지만 q<sub>3</sub> state 에 transition 이 없으므로 a 를 읽을 수 없다. 

## Definition

* finite state automaton 을 기반으로 한다.
* transition 이 약간 다른 방식으로 구현되어있다.
* tape 은 추가 메모리를 가지고 있다.
* tpae head(pointer) 를 가지며 좌/우로 움직일 수 있고 읽고 쓸 수 있다.

## Process

1. input 으로 finit-length tape 이 주어진다.
2. tape head 는 언제나 tape 의 첫번째(가장 왼쪽)를 가리킨다.
3. 머신은 tape 을 읽으면 아래의 동작을 할 수 있다.
   * state 를 바꾼다.
   * tape 의 값(symbol)을 덮어 쓸 수 있다.
   * tape head 를 좌/우로 움직인다.

## Tape cells

tape 의 각 cell 에는 다음과 같은 symbol 이 올 수 있다.

* input alphabet
* tape alphabet (input alphabet 보다 super set 의 개념)
* blank (tape 의 끝을 알려주는 용도로도 쓰인다)

## Tuples

<img width="899" alt="tuples" src="https://user-images.githubusercontent.com/48989903/146762294-853db350-3a32-4ed2-9197-25b29dcacd68.png">

## transition function

머신은 tape 을 읽으면 3가지 동작을 할 수 있는데, 예시는 아래와 같다.

* state q 가 symbol X 를 읽었을 때
  * state p 로 움직인다.
  * X 에 Y 를 덮어쓴다.
  * tape head 를 D = {L/R} 움직인다.

<img width="956" alt="transition" src="https://user-images.githubusercontent.com/48989903/146762708-ea2f6a9a-e455-4ba0-a8f1-7f7bc79593fa.png">

<br/><br/>

### Example

<img width="733" alt="tf" src="https://user-images.githubusercontent.com/48989903/146772812-05aba9b1-3b79-41e8-afd7-4614e5bdc615.png">

Tuple 로 표현하면 아래와 같다.

![tf2](https://user-images.githubusercontent.com/48989903/146773223-e3cd1f97-773c-43e1-831a-fbfa60cd343e.jpg)

## Accepting a string

input string w 가 turing machine 에 의해 읽혀지고 final state 에 도달했다면 TM 이 input string 을 받아들였다고 한다.

## Crashing and Halting

### Halting

 * state q, symbol x 에 대한 델타함수가 정의되어 있지 않을 때 state q 는 symbol x 에 대해 halting 이라고 한다.
 * state q 가 모든 tape symbol 에 대해 정의되어 있지 않다면 state q 는 halting state 라고 한다.
 * 모든 final state 는 halting state 이다.
    * final state 는 모든 tape symbol 에 대해 transition 이 정의되어 있지 않기 때문이다.

튜링머신에 의해 accept 된 input string 이 fail 되는 경우를 두가지로 나눌 수 있다.

### Crashing

* symbol 에 대해서 transition function 이 정의되지 않고, 현재 state 가 halting state 가 아닌 경우를 말한다.
* tape 의 왼쪽/오른쪽 끝에서 왼쪽/오른쪽으로 이동하려는 경우

### Looping

어떤 input string 에 대해 튜링머신이 무한 루프에 빠진 경우를 말한다.

### Crashing vs looping

* crashing 의 경우 절대로 final state 에 도달할 수 없다. 따라서 튜링머신이 reject 했다고 할 수 있다.
* looping 의 경우 언젠가 final state 에 도달할지도 모르므로 튜링머신이 reject 했다고 단언할 수는 없다.

