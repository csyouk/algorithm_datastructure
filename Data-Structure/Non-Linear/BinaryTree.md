# Tree
- Tree는 Graph형 자료구조의 한 갈래이다.
- 그러므로, Graph 자료구조에서의 용어를 조금 알아야 한다.
- 먼저, Graph형 자료구조에서 사용하는 용어를 먼저 체크해보자.
  - Node : 꼭지점, 마디.
  - Edge : 간선, 변.

- 다음은 Tree구조에서 사용하는 용어이다.
  - Root : 근(根, 뿌리근)노드
  - Parent Node : 부모 노드
  - Children Node : 자식 노드
  - Edge : 간선.
  - Depth : 깊이.

- 다양한 트리가 있지만, 이 문서에서는 이진 트리를 다룬다.

## 장점
- 탐색이 Linked List보다 빠르다.

## 단점
- 설계나 분석이 어렵다.

## 탐색 방법
- 다음 그림을 바탕으로 트리 구조의 탐색 방법을 알아보자.
![Tree](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Binary_tree.svg/220px-Binary_tree.svg.png)

- 탐색 방법에는 다음 3가지가 있다.
  - **Inorder Traverse(중위 탐색)** : 트리의 좌측 하단부터 탐색을 시작한다.  
    - **2 -> 7 -> 5 -> 6 -> 11 -> 2 -> 5 -> 9 -> 4**
  - **Preorder Traverse(전위 탐색)** : root 부터 좌측을 우선적으로 탐색한다.  
    - **2 -> 7 -> 2 -> 6 -> 5 -> 11 -> 5 -> 9 -> 4**
  - **Postorder Traverse(후위 탐색)** : 트리의 좌측 하단부터 연결된 부모노드의 우측 하단을 우선적으로 탐색 하는 방법. root를 가장 나중에 탐색한다.  
    - **2 -> 5 -> 11 -> 6 -> 7 -> 4 -> 9 -> 5 -> 2**

- 위의 탐색 방법을 통해서 수식을 트리구조로 나타내는 방법을 알아보자.
  - (1 + 2) * (3 + 4) 와 같은 수식이 있다고 해보자.
  - **수식을 분해** 해서 트리구조로 나타내면, **Inorder방식** 으로 표기가 가능하다.
  - Inorder방식으로 표기된 트리는 **Postorder방식** 으로 **데이터처리** 를 할 수 있다.
  - Postorder방식으로 데이터를 처리할 때, Stack에 값을 저장하며 처리할 수 있다.


다음 코드를 보면서 위의 3가지 방식의 작동방식의 코드를 살펴보자. 다음과 같은 구조체가 선언되어 있다고 해보자.
```cpp
typedef struct _node
{
	char *name;
	struct _node *left;
	struct _node *right;
} Node;

Node root, n1, n2, n3, n4, n5, n6;
```

- 먼저 트리구조 데이터를 만들어보자.
```cpp
void Init_Tree(void)
{
	root.left = &n1;
	root.right = &n2;
	root.name = "ROOT";

	n1.left = &n3;
	n1.right = &n4;
	n1.name = "N1";

	n2.left = &n5;
	n2.right = &n6;
	n2.name = "N2";

	n3.left = n3.right = n4.left = n4.right = n5.left = n5.right = n6.left = n6.right = NULL;
	n3.name = "N3";
	n4.name = "N4";
	n5.name = "N5";
	n6.name = "N6";
}


int main(void)
{
	Init_Tree();

	printf("Inorder Traverse :");
	Inorder_Traverse(&root);
	printf("\n");

	printf("Preorder Traverse :");
	Preorder_Traverse(&root);
	printf("\n");

	printf("Postorder Traverse :");
	Postorder_Traverse(&root);
	printf("\n");
	return 0;
}
```

- **Inorder Traverse**
  - 중위 탐색의 경우 트리의 좌측 하단부터 탐색을 시작한다.
  - 좌측 하단의 탐색이 종료되면 스택이 해제되면서 부모 노드를 훑는다.
  - 탐색이 전부 종료되면 우측 하단을 찾는다.
  - 아래 코드의 인쇄 결과는 다음과 같다.
  - Inorder Traver : N3 N1 N4 Root N5 N2 N6
```cpp
void Inorder_Traverse(Node *p)
{
	if (p->left) Inorder_Traverse(p->left);
	printf(" %s", p->name);
	if (p->right) Inorder_Traverse(p->right);
}
```

- **Preorder Traverse**
  - 전위 탐색의 경우 트리의 루트부터 좌측 하단을 우선적으로 탐색을 시작한다.
  - 좌측 하단의 탐색이 종료되면 스택이 해제되면서 right edge를 탐색한다.
  - 아래 코드의 인쇄 결과는 다음과 같다.
  - Preorder Traver : Root N1 N3 N4 N2 N5 N6
```cpp
void Preorder_Traverse(Node *p)
{
	printf(" %s", p->name);
	if (p->left) Preorder_Traverse(p->left);
	if (p->right) Preorder_Traverse(p->right);
}
```

- **Postorder Traverse**
  - 후위 탐색의 경우 트리의 좌측 하단과 우측 하단부터 우선적으로 탐색을 시작한다.
  - 아래 코드의 인쇄 결과는 다음과 같다.
  - Postorder Traver : N3 N4 N1 N5 N6 N2 Root
```cpp
void Postorder_Traverse(Node *p)
{
	if (p->left) Postorder_Traverse(p->left);
	if (p->right) Postorder_Traverse(p->right);
	printf(" %s", p->name);
}
```
