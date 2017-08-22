# Singly Linked List Node

## 장점
- sequence list 기반의 자료구조(array)에 비해서 자료의 이동이 적다.
- 메모리를 원하는 만큼만 사용한다.

## 단점
- 제어가 sequence list 기반 자료구조보다 복잡하다.
- node의 next를 잘못 지정하면, 데이터가 유실 되기도 한다.


## 용어
- **Node** : 자료 그 자체를 나타냄.
- **Link** : 연결 주소.
- **Head** : Linked list node의 시작 node를 가리키는 여분의 node이다.

## 특이점
- linked list node 계열은 기본적으로 모든 자료를 struct 형태로 관리한다.
- struct에 next 라는 멤버를 가지고 있음으로써, 다음 node에 접근할 수 있다.
- next 멤버는 자신과 동일한 타입을 가진 데이터만 지시할 수 있다.
- 자기 참조 구조체의 형식을 띌 수 밖에 없다.

코드로 나타내면 다음과 같은 형태를 띈다.
```cpp

typedef struct node{
  int id;
  Node * next;
} Node;

Node Head; // Head 구조체는 linked list node의 첫 번째 요소를 가리키고 있다.

노드를 생성시킨 후 추가하는 방법은 다음과 같다.

void Insert_Node(Node * head, Node * node)
{
  첫 노드 혹은 마지막 노드에 추가시키기 위해서는 분명, head의 next가 NULL값 이어야 한다.
  if(head->next == NULL)
  {
    d->next = head->next;
    head->next = d;
    return;
  }

  node의 id조건을 통해서, 기존에 동일한 데이터가 있다면, 추가하지 않는다.
  if(head->next->id == node->id) return;

  노드의 중간에 node를 삽입시켜서 연결하기 위해서는, 기존에 연결되어 있던 link를 끊어야 하는데,
  순서가 있다.
  순서를 지키지 않으면, 데이터가 유실될 위험이 있다.
  노드를 추가시키는 규칙은, 새로운 데이터인 node의 id멤버를 기존의 linked list node를 순차적으로
  탐색하며, head의 id가 node의 id보다 큰 지점이 생기면, 그곳에 link를 끊고 연결해준다.

  반복적으로 head를 갱신시켜주며, 순차적으로 탐색한다.
  head 노드의 next 멤버가 가리키는 노드의 id값이 node(인자로 넘어온 변수) 노드의 id값 보다 큰 순간,
  반복이 멈춘다. 이때, head의 위치는, 인자로 넘어온 node의 바로 이전이다.
  while (head->next->id < node->id) {
    head = head->next;
    첫 노드 혹은 마지막 노드에 추가시키기 위해서는 분명, head의 next가 NULL값 이어야 한다.
    if(head->next == NULL)
    {
      d->next = head->next;
      head->next = d;
      return;
    }
  }

  d->next = head->next;
  head->next = d;
  return;
}


위의 코드를 다음과 같이 바꿀 수 있다.

int Insert_Node(SCORE * head, SCORE * d)
{
	int i;

	for (i = 0; i<MAX_ST; i++)
	{
    // 첫 노드를 추가하거나, 마지막 노드를 추가할때의 조건을 한 곳에 통합 시켰다.
		if ((head->next == NULL) || (d->id < head->next->id))
		{
			d->next = head->next;
			head->next = d;
			return 1;
		}

		if (d->id == head->next->id) return -2;

		head = head->next;
	}

	return -1;
}


물론 재귀함수로도 구현이 가능하다.
void Insert_Node_Recursively(Node * head, Node *node)
{
	static int cnt = 0;

	// 노드를 처음 추가하거나, linked list node의 마지막에 추가할 때,
	if (head->next == NULL){
		d->next = head->next;
		head->next = d;
		return;
	}

	//  node를 linked list node의 중간에 삽입할 때.
	if (head->next->id > d->id){
		d->next = head->next;
		head->next = d;
		return;
	}
	// 이미 동일한 값이 존재할 경우. 추가할 필요가 없다.
	if (head->next->id == d->id) return;

	// 노드 이동
	return Insert_Node_Recursively(head->next, d);
}


위 함수를 더 축약하면 다음과 같이 바꿀 수 있다.
void Insert_Node_Recursively(Node * head, Node *node)
{
  노드를 처음 추가하거나, linked list node의 마지막에 추가할 때,
	node를 linked list nodes의 중간에 삽입할 때.
	2가지 행위를 하나의 코드로 합쳤다.
	주의할 점은 head->next가 NULL인지를 우선적으로 체크해야 한다는 점이다.
	short circuit을 사용할 때, 참일 확률이 높은 조건을 우선적으로 배치한다.

	if (head->next == NULL || head->next->id > d->id){
		d->next = head->next;
		head->next = d;
		return;
	}

	// 이미 동일한 데이터가 존재할 경우.
	if (head->next->id == d->id) return;

	// 노드 이동
	return Insert_Node_Recursively(head->next, d);
}

```
