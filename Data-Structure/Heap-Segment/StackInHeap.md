# Stack In Heap Segment
- 스택은 Last In Fist Out (LIFO) 구조로 동작하는 자료구조이다.
- 스택을 구현하기 위해서는 먼저 용어들을 알아야 한다.


## 용어
- Sptr(SP) : 스택 포인터. 배열에서 스택의 현재 위치를 나타낸다. Push, Pop을 할 대상을 지시하는 지시자이다. (Read/Write)
- Stack : 스택으로 사용할 버퍼.
- MAX_STACK : 최대 데이터 수
- STACK_EMPTY : 비어있을 경우
- STACK_FULL : 스택이 꽉 찼을 경우의 Sptr의 값.


- Push : 스택에 데이터를 밀어 넣는 동작이다. 이때 동작은 다음과 같은 순으로 이루어져야 한다.
  - SP가 STACK_FULL 과 같은 상태인지 체크한다. 만약 같다면, 스택에 데이터를 넣을 수 없다.
  - SP값을 감소한다.
  - SP가 지시하는 곳에 Stack에 값을 push한다.
- Pop : 스택에서 데이터를 빼내는 동작이다. 이때 동작은 다음과 같은 순으로 이루어져야 한다.
  - SP가 STACK_EMPTY를 가리키고 있는지 체크한다. 만약 같다면, 스택에서 데이터를 더 이상 추출할 수 없다.
  - SP가 가리키는 곳에 있는 값을 꺼낸다.
  - SP 값을 증가시킨다.

- 스택에서는 Create, Delete 동작만 있다.
