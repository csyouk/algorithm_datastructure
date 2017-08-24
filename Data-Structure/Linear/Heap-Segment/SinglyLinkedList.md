# Singly Linked List In Heap

## 장점
- 노드를 생성할 때 동적으로 힙 공간에 메모리를 할당받아서 데이터를 넣기 때문에, 메모리를
효율적으로 생성할 수 있다.

## 단점
- 링크가 파손되면 끊어진 노드는 영원히 찾을 수 없다.



## Create
```cpp
int Insert_Node(SCORE * head, SCORE * d)
{
	while (1)
	{
		if (head->next == NULL || head->next->id > d->id)
		{
			// 저장 공간을 할당 받아서 노드를 저장한다. 노드를 1개 생성하기 때문에,
      // calloc 의 첫번째 인자는 1이다.
      // 2번째 인자는 SCORE 구조체의 사이즈를 지정한다.
			SCORE *p = calloc(1, sizeof(SCORE));
			if (p == NULL) return -1; // 저장공간이 부족할 수도 있으니, 예외처리를 한다.
			*p = *d; // 할당 받은 힙 공간에 데이터를 부어준다. 이제 p는 data처럼 사용이 가능하다.


			p->next = head->next; // 삽입할 노드의 next를 이전 head의 next로 치환한다.
			head->next = p;  // head next를 새로 삽입한 노드로 지정한다.
			return 1;
		}
		if (head->next->id == d->id) return -2;
		head = head->next;
	}
}
```

## Retrive
```cpp

SCORE * Search_Id_Node(SCORE * head, int id)
{
	if (head->next == (SCORE *)0x0) return (SCORE *)0x0;
	head = head->next;

	for (;;)
	{
		if (head->id == id) return head;
		if (head->next == (SCORE *)0x0) return (SCORE *)0x0;
		head = head->next;
	}
}

```

## Update
```cpp

int Modify_Node(SCORE * head, SCORE * modifier, int id)
{
  SCORE *p = Search_Id_Node(head, id);
  if(!p) return -1;
  *p = *modifier;
  return 1;
}

```

## Delete
```cpp
int Delete_Node(SCORE * head, int id)
{
	while (1)
	{
    // id와 일치하는 노드를 발견하지 못한 경우.
		if (head->next == NULL) return -1;

    // id와 일치하는 노드를 발견한 경우.
		if (head->next->id == id){

      // 일치하는 노드를 삭제하기 전, 매칭하는 노드의 주소값을 잠시 벡업한다.
			SCORE *tmp = head->next;

      // 일치하는 노드의 이전 노드의 next에, 매칭하는 노드의 next 값을 넣어준다.
			head->next = head->next->next;

      // 링크를 교환하는 행위가 종료되면, 링크가 끊긴 노드를 메모리에서 해제시킨다.
			free(tmp);
			return 1;
		}
		head = head->next;
	}
}

```


## Print All Nodes

```cpp
int Print_All_Node(SCORE * head)
{
	int n = 0;

	printf("Head.next = 0x%.8X\n", head->next);
	if (head->next == (SCORE *)0x0) return 0;
	head = head->next;

	for (;;)
	{
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", head, head->id, head->name, head->jumsu, head->next);
		n++;
		if (head->next == (SCORE *)0x0) return n;
		head = head->next;
	}
}
```

## Counting
```cpp
int Count_Node(SCORE * head)
{
	int n = 0;
	while (1) {
		if(head->next == NULL) return n;
		head = head->next;
		n++
	}
}

```

## Print Node
```cpp
int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);
	if(!p) return -1;
	printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	return 1;
}

```
