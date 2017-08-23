# Stack
- 스택은 Last In Fist Out (LIFO) 구조로 동작하는 자료구조이다.
- 스택을 구현하기 위해서는 먼저 용어들을 알아야 한다.


## 용어
- Sptr(SP) : 스택 포인터. 배열에서 스택의 현재 위치를 나타낸다.
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

예제를 통해서 이해해 보자.
```cpp
#define MAX_STACK		100
#define STACK_EMPTY	MAX_STACK
#define STACK_FULL	0

typedef struct{
  int id;
  char name[20];
} Object;

int Pop_Stack(int *p);
int Print_Stack(void);

Object Stack[MAX_STACK];
int Sptr = STACK_EMPTY;



int Push_Stack(Object * data)
{
	if (Sptr == STACK_FULL) return -1;
	Stack[--Sptr] = *data;
	return 1;
}

int Pop_Stack(Object *p)
{
	if (Sptr == STACK_EMPTY) return -1;
	*p = Stack[Sptr++];
	return 1;
}

```
