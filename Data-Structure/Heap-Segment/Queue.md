# Queue In Heap Segment
- 큐는 First In Fist Out (FIFO) 구조로 동작하는 자료구조이다.
- 힙에서 큐를 구현하는 방식은 선형 큐 방식이다.
- 큐를 구현하기 위해서는 먼저 용어들을 알아야 한다.


## 용어
- Wrptr(WP) : 자료를 저장할 공간을 지시자.
- Rdptr(RP) : 자료를 꺼낼 공간을 지시자.
- Front : 큐에서 데이터가 빠져나오는 부분(RP가 지시하는 곳)
- Rear : 큐에서 데이터가 들어오는 곳(WP가 지시하는 곳)


## 선형 큐(Linear Queue)
- Push와 Pop행위를 할때, WP와 RP가 어떻게 움직이는지 유심히 봐야 한다.

다음과 같은 그림을 생각해보자.

\----------------------------  
Front &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Rear  
\----------------------------  
RP &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  WP


다음과 같은 자료구조가 있다고 가정해보자.
```cpp

typedef struct _que
{
	int num;
	struct _que * next;
}QUEUE;

QUEUE * Wrptr = (QUEUE *)0;;
QUEUE * Rdptr = (QUEUE *)0;;

```


## Create
```cpp

int Inqueue(QUEUE * data)
{
  // 할당받은 메모리의 시작주소를 p에 저장한다.
	QUEUE * p = calloc(1, sizeof(QUEUE));

  // 할당받지 못하면 흐름 종료.
	if (!p) return -1;       

  // 할당 받은 메모리에 데이터를 주사한다.
	*p = *data;              

  // 새로 추가하는 노드는 반드시 NULL로 초기화 한다.
  // 왜냐하면 QUEUE의 마지막 데이터이기 때문에, 다음을 지시하는 데이터가 없기 때문이다.
	p->next = (QUEUE *) 0x0;  

  // QUEUE가 EMPTY 상태가 아니라면, 현재 WP가 지시하고 있는 노드에 새로 들어온 데이터를 링크로 걸어준다.
	if (Wrptr) Wrptr->next = p;

  // WP를 QUEUE에 새로 들어온 데이터로 지시방향을 바꾼다.
	Wrptr = p;

  // RP가 NULL이면, RP도 새로 들어온 노드로 업데이트 한다.
  // 이 경우는, EMPTY 상태에서 새로 노드가 들어오는 경우이다.
	if (Rdptr == NULL) Rdptr = p;
	return 1;
}
```

## Delete
```cpp
int Dequeue(QUEUE * p)
{
  // RP 가 지시하는 데이터를 벡업한다.
	QUEUE * tmp = Rdptr;

  // RP가 NULL이라면, 즉 EMPTY상태라면 흐름을 종료한다.
	if (Rdptr == NULL) return -1;

  // QUEUE에서 꺼낼 데이터는 RP가 지시하고 있는데,
  // 이 데이터를 *p에 담아준다.
	*p = *Rdptr;

  // RP를 다음 노드로 이동시킨다.
	Rdptr = Rdptr->next;

  // RP가 NULL상태라면, WP도 NULL로 만든다.
	if (Rdptr == NULL) Wrptr = NULL;

  // 이전에 벡업시켜놓았던 데이터,
  // 즉, 연결이 끊긴 데이터를 힙에서 해제시킨다.
	free(tmp);
	return 1;
}
```

## Print States
```cpp
void Print_Queue(void)
{
	QUEUE *b_rdptr = Rdptr;
	int index = 0;
	while (b_rdptr)
	{
		printf("[%3d] value : %3d / addr : %#.8x\n", index, b_rdptr->num, b_rdptr);
		b_rdptr = b_rdptr->next;
		index++;
	}
}
```

## Counting
```cpp
int Count_Full_Data_Queue(void)
{
	QUEUE *b_rdptr = Rdptr;
	int n = 0;
	while (b_rdptr)
	{
		b_rdptr = b_rdptr->next;
		n++;
	}
	return n;
}
```
