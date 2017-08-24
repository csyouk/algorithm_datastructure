# Doubly Linked List In Heap
## 장점
- sequence list 기반의 자료구조(array)에 비해서 자료의 이동이 적다.
- 메모리를 원하는 만큼만 사용한다.
- 하나의 link가 파손된 경우 다른 링크를 사용하는 코드를 작성해서 링크 복구가 가능하다.
- 제일 끝 노드를 Tail 구조체로 관리하면 오름차순, 내림차순 인쇄가 쉽다.

## 단점
- 제어가 sequence list 기반 자료구조보다 복잡하다.
- node의 next를 잘못 지정하면, 데이터가 유실 되기도 한다.

## 용어
- **Node** : 자료 그 자체를 나타냄.
- **Next** : 다음 노드를 나타내는 연결 주소.
- **Prev** : 이전 노드를 나타내는 연결 주소.
- **Head** : Linked list node의 시작 node를 가리키는 여분의 node이다.
- **Tail** : Linked list node의 마지막 node를 가리키는 여분의 node이다.


Doubly Linked List Node의 CRUD 행위를 구현해보자.


## Create
```cpp
int Insert_Node(SCORE * head, SCORE * d)
{
	while (1)
	{
		if (head->next == NULL || head->next->id > d->id)
		{
			SCORE *p = calloc(1, sizeof(SCORE));
			*p = *d;
			p->next = head->next;
			p->prev = head;
			if(head->next) head->next->prev = p;
			head->next = p;
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
	for (;;)
	{
		if (head->next == (SCORE *)0x0) return (SCORE *)0x0;
		if (head->next->id == id) return head->next;
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
	SCORE *p = Search_Id_Node(head, id);
	if (!p) return -1;

	p->prev->next = p->next;
	if (p->next)p->next->prev = p->prev;
	free(p);
	return 1;
}

```
