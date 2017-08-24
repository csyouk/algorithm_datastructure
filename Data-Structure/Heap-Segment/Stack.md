# Stack In Heap Segment
- 스택은 Last In Fist Out (LIFO) 구조로 동작하는 자료구조이다.
- 스택을 구현하기 위해서는 먼저 용어들을 알아야 한다.
- 힙에 저장을 한다는 말은 메모리의 구조가 비선형적이라는 뜻이다.
- 그렇기 때문에, 내부적으로 linked list node를 활용해야 한다.
- 구현은 linked list 이지만, 운영을 스택처럼만 한다.
- 기존의 배열기반 스택은 배열의 요소를 기반으로 스택에 데이터를 IO시키지만,
힙기반 스택은 주소를 기반으로 스택에 데이터를 IO한다.

## 용어
- Sptr(SP) : 스택 포인터. 힙 공간에서 스택의 현재 위치를 나타낸다. Push, Pop을 할 대상을 지시하는 지시자이다. (Read/Write)
- Stack : 스택으로 사용할 버퍼.


- Push : 스택에 데이터를 밀어 넣는 동작이다. 이때 동작은 다음과 같은 순으로 이루어져야 한다.
  - calloc을 통해서 힙에서 메모리를 얻어온다.
  - calloc을 통해 받은 메모리에 들어갈 데이터를 할당한다.
  - SP가 지시하는 주소를 스택에 들어온 데이터의 링크 주소에 복사한다.
  - SP에 노드의 주소를 할당한다.
- Pop : 스택에서 데이터를 빼내는 동작이다. 이때 동작은 다음과 같은 순으로 이루어져야 한다.
  - 먼저 스택이 비어있는지 체크한다.
  - 스택이 비어있지 않으면, 현재 SP가 지시하는 주소값을 임시 변수에 벡업한다.
  - pop의 결과물을 저장할 구조체 변수에 스택포인터가 지시하는 값을 복사한다.
  - SP에 현재 pop의 결과물에 연결된 다음 노드의 주소를 할당한다.
  - 스택 최상단의 노드는 이제 연결이 끊겼다. 그러므로 힙에서 메모리를 해제한다.

- 스택에서는 Create, Delete 동작만 있다.


- 다음과 같은 메모리 구조가 있다고 하자.
```cpp
typedef struct _stk
{
	int num;
	struct _stk * prev;
}STACK;

STACK * Sptr = (STACK *)0;
```


## Create
```cpp
int Push_Stack(STACK *data)
{
  // 스택에 넣은 메모리 공간을 OS로부터 할당받는다.
	STACK *p = calloc(1, sizeof(STACK));
	if (!p) return  -1;

  // 할당받은 메모리 공간에 데이터를 부어넣는다.
	*p = *data;

  // 스택의 최상단에 들어갈 노드의 다음 주소를(next) 혹은 스택의 이전(prev) 의 주소로
  // 현재 스택 포인터가 지시하는 값을 넣는다.
	p->prev = Sptr;

  // 스택 포인터는 스택의 최상단의 주소를 가리켜야 한다.
	Sptr = p;
	return 1;
}
```


## Delete
```cpp
int Pop_Stack(STACK *p)
{
  // 만약 스택에 아무런 값도 없다면 함수 호출을 종료 시킨다.
	if (Sptr == NULL) return -1;

  // 연결을 끊을 노드의 메모리 공간을 해제시켜야 하기 때문에,
  // 그 이전에 현재 스택포인터가 지시하는 노드의 주소를 임시 변수에 벡업한다.
	STACK *tmp = Sptr;

  // pop의 결과물을 저장시킬 메모리 공간에 현재 스택포인터가 가리키는 값을 저장한다.
	*p = *Sptr;

  // 스택 포인터는 스택 최상단 노드의 이전 주소값으로 업데이트 해줘야 한다.
	Sptr = p->prev;

  // SP 이동이 끝났다면, 연결이 끊긴 최상단 노드의 메모리 공간을 해제시킨다.
	free(tmp);
	return 1;
}
```

## Print All Stack
```cpp
void Print_Stack(void)
{
	STACK *b_sptr = Sptr;
	int n = 1;
	while (b_sptr)
	{
		printf("[%d] addr=0x%.8x, num=%d, next=0x%.8x\n", n, b_sptr, b_sptr->num, b_sptr->prev);
		b_sptr = b_sptr->prev;
		n++;
	}
}

```


## Count All Nodes in Stack
```cpp
int Count_Full_Data_Stack(void)
{
	STACK *b_sptr = Sptr;
	int n = 0;
	while (b_sptr)
	{
		b_sptr = b_sptr->prev;
		n++;
	}
}

```
