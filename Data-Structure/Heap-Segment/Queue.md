# Queue In Heap Segment
- 큐는 First In Fist Out (FIFO) 구조로 동작하는 자료구조이다.
- 큐를 구현하는 방식은 2가지가 있다.
  - 선형 큐
  - 환형 큐
- 큐를 구현하기 위해서는 먼저 용어들을 알아야 한다.


## 용어
- Wrptr(WP) : 자료를 저장할 공간을 지시.
- Rdptr(RP) : 자료를 꺼낼 공간을 지시.
- Queue : 스택으로 사용할 버퍼.
- MAX_Q : 최대 데이터 수
- Q_EMPTY : 비어있을 경우
- Q_FULL : MAX_Q의 값과 일치.
- Front : 큐에서 데이터가 빠져나오는 부분(RP가 지시하는 곳)
- Rear : 큐에서 데이터가 들어오는 곳(WP가 지시하는 곳)


## 선형 큐(Linear Queue)
- 선형 큐는 버퍼가 선형적이라는 가정하에 구현된 자료구조이다.
- Push와 Pop행위를 할때, WP와 RP가 어떻게 움직이는지 유심히 봐야 한다.

다음과 같은 그림을 생각해보자.

\----------------------------  
Front &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Rear  
\----------------------------  
RP &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  WP


**RP < WP**  ==> 데이터가 있는 상태.  
**RP == WP** ==> 데이터가 비어있는 상태.
