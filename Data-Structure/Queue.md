# Queue
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

선형큐를 구현해보자.
```cpp

#define MAX_Q	100
#define Q_EMPTY 0
#define Q_FULL MAX_Q

typedef struct{
  int id;
  char name[20];
} Object;

int Inqueue(int data);
int Dequeue(int *p);


Object Queue[MAX_Q];
// 처음에는 WP와 RP의 위치가 같다.
int Wrptr = Q_EMPTY;
int Rdptr = Q_EMPTY;

큐에서 데이터를 꺼내는 행위와 넣는 행위를 구현해보자.

int Inqueue(Object *data)
{
  // 큐에 삽입 실패시 -1

  // WP가 큐의 마지막에 위치할 때는
  // 정말로 큐가 꽉차있는지 확인하고,
  // 그렇지 않다면, 버퍼 이동을 해줘야 한다.

  int i;

  if(Wrptr == Q_FULL)
  {
    // RP가 첫 지점을 가리키고 있는지 확인한다.
    if(Rdptr == Q_EMPTY)
    {
      return -1;
    }

    // 버퍼 이동을 한다.
    for (i = 0; i < (Wrptr - Rdptr)); i++) {
      Queue[i] = Queue[Rdptr + i];
    }

    // WP와 RP의 위치를 옮긴다.
    Wrptr -= Rdptr;
    Rdptr = Q_EMPTY;
  }

  // WP가 지시하는 곳에 데이터를 밀어넣는다.
  Queue[Wrptr++] = * data;
}

int Dequeue(Object *tmp)
{
  // WP와 RP의 위치가 같다면, 큐는 비어있다는 뜻이다.
  // pop 실패시, -1
  // pop 성공시, 1
  if(Wrptr == Rdptr) return -1;

  // 포인터 구조체 tmp 에 RP가 지시하는 데이터를 꺼내서 집어넣는다.
  *tmp = Queue[Rdptr++];
  return 1;
}

```


## 환형 큐(Circular Queue
- 장점 : 버퍼 이동이 일어나지 않기 때문에, 연산 속도가 상대적으로 빠르고 코드가 간결하다.
- 단점 : 어디가 시작이고 어디가 끝인지 모른다. 잘못 짜면 제대로 동작하지 않는 수가 있다.
- 환형 큐의 그림을 그려보면 다음과 같다.
![Circular Queue](https://raw.githubusercontent.com/csyouk/algorithm_datastructure/master/Data-Structure/img/circular-queue.jpg)
- 환형 큐의 아이디어는, 큐의 Front와 Read가 서로 이어져 있다는 전제하에 데이터의 입출입 행위를 진행한다는 것이다.
- 대신, 환형 큐를 사용하려면, 특별한 규칙이 추가로 필요하다.
  - RP 와 WP가 동일한 경우는 EMPTY상태라고만 정의해야 한다.
  - 하지만, 데이터 입출입을 하다보면, RP와 WP의 위치가 서로 역전될 수 있다.
  - 이러한 현상을 막기 위해서, **특별한 규칙** 을 추가로 정의하자.
  - **WP는 RP의 사이의 메모리 공간은 하나가 반드시 비어있어야 한다.**
  - 즉, RP-WP = 1 Q_FULL 상태로 간주한다.
  - RP == WP ==> Empty 상태로 간주.


코드로 표현해보자.
```cpp

#define MAX_Q	100
#define Q_EMPTY 0
#define Q_FULL MAX_Q

typedef struct{
  int id;
  char name[20];
} Object;

int Inqueue(int data);
int Dequeue(int *p);


Object Queue[MAX_Q];
// 처음에는 WP와 RP의 위치가 같다.
int Wrptr = Q_EMPTY;
int Rdptr = Q_EMPTY;


큐에서 데이터를 꺼내는 행위와 넣는 행위를 구현해보자.

int Inqueue(Object *data)
{
  // 큐에 삽입 실패시 -1
  int full = (Wrptr + 1) % MAX_Q == Rdptr;
  if(full) return -1;

  // data를 Queue에 넣은 후, WP를 증가시킨다.
  // WP가 Q_MAX에 도착하면 처음 위치로 보내준다.
  Queue[Wrptr++] = *data;
  Wrptr %= Q_MAX;
  return 1;
}

int Dequeue(Object *tmp)
{
  // 큐에서 데이터를 빼는 행위가 실패하면 -1
  // 성공하면 1

  // WP와 RP가 일치하면 EMPTY 상태로 간주한다.
  if(Wrptr == Rdptr) return -1;

 *tmp = Queue[Rdptr++];
 Rdptr %= Q_MAX;
 return 1;
}


```
