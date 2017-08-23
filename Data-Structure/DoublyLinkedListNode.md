# Doubly Linked List Node

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


다음과 같은 구조체가 있다고 하자.
```cpp
#define MAX	20
typedef struct _node
{
	int id;
	struct _node  * next;
	struct _node  * prev;
}NODE;

NODE Head, Tail;
NODE nodes[MAX];

```

## Create
데이터를 생성하여 linked listd에 추가하는 함수를 작성해보자.
데이터를 삽입할 때 고려해야 하는 것들은 다음과 같다.
- 데이터 노드의 id는 오름차순으로 정렬시켜야 한다.
- 데이터 노드를 기존 링크드 리스트에 추가시킬 때,
  - 노드의 중간에 삽입하는 경우.
  - 노드의 종단지점에 삽입하는 경우.

```cpp

int Insert_Node(NODE * head, NODE * d)
{
  // return value
  // -1 : 저장공간이 부족할 경우.
  // -2 : 동일한 id가 존재할 시,
  //  i : 자료를 성공적으로 저장했을 시 요소 번호 저장.

  int i;
  if(nodes[MAX-1].id != 0) return -1;
  for (i = 0; i < MAX; i++) {
    if(head->next == NULL || head->next->id)
    {
      // 삽입할 노드의 링크를 우선적으로 걸어준다.
      d->next = head->next;
      d->prev = head;

      // 삽입할 데이터 노드가 노드의 종단점일 경우에
      // head->next는 NULL이다. 이 경우를 예외적으로 처리해줘야 한다.
      if(head->next) head->next->prev = d;
      head->next = d;
      return i;
    }
    if(head->next->id == d->id) return -2;
    head = head->next;
  }

  return -1;
}
```

위의 경우는 전체 노드의 갯수에 제한이 있기 때문에 for loop를 사용해서 작성했다.
전체 노드의 개수에 제한이 없는 경우, 무한 loop을 통해서 순차적으로 탐색가능하다.

```cpp
void Insert_Node(NODE * head, NODE * d)
{
  while (1) {
    if(head->next == NULL || head->next->id)
    {
      d->next = head->next;
      d->prev = head;
      if(head->next) head->next->prev = d;
      head->next = d;
      return;
    }
    head = head->next;
  }
  return ;
}

```


## Retrive
링크 노드에서 검색조건과 일치하는 노드를 반환하는 함수를 작성해보자.

```cpp

NODE * Search_By_Id(NODE * head, int id)
{
  // 검색 실패시 0
  // 검색 성공시 해당 노드의 주소를 반환.
  while (1) {
    if(head->next == NULL) return (NODE *)0x0;
    if(head->next->id == id) return head->next;
    // 노드 이동.
    head = head->next;
  }
}

```

## Update
링크 노드에서 검색 조건과 일치하는 노드를 찾아서 멤버의 값을 업데이트 하는 함수를 작성해보자.

```cpp

int Modify_Node(NODE * head, int id)
{
  // 수정 실패시 -1
  // 수정 성공시 요소 id출력
  NODE * p = Search_By_Id(head, id);
  if(!p) return -1;

  p 구조체에 id 이외의 멤버가 있으면, scanf로 값을 받아서 업데이트한다.
  scanf("%d", p->sth);
  return p->id
}
```

## Delete
링크 노드에서 검색 조건을 만족하는 노드를 찾아서 타겟 노드의 연결을 끊고,
기존 노드의 링크를 설정해주는 함수를 작성해보자.

```cpp

int Delete_Node(NODE * head, int id)
{
  // 삭제 실패시 -1
  // 삭제 성공시 1
  NODE * p = Search_By_Id(head, id);
  if (p == NULL) return -1;

  p->id = 0;

  // 검색한 노드가 링크의 종단점에 위치할 경우는 딱히 업데이트 할 필요가 없다.
  // 하지만, 그렇지 않다면, 업데이트 해줘야 한다.
  if(p->next) p->next->prev = p->prev;
  p->prev->next = p->next;

  return 1;
}


```
