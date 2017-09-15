
//[Data Structure] Linked List #1
#if 0
//Heap에 단일 링크 방식으로 자료를 관리하기 위하여 자료의 구조체를 다음과 같이 선언하고 HEAD 구조체를 만든다. HEAD 구조체는 항상 링크의 첫 자료를 가리키기 위한 용도로 사용되고 자료를 저장하지는 않는 구조체이다. 초기의 HEAD 구조체의 next 포인터는 NULL이며 next값이 NULL이면 마지막 자료임을 의미한다.
//
//
//struct st
//{
//	int id;
//	struct st * next;
//}HEAD = { 0, NULL };
//
//새로운 자료의 추가는 다음과 같은 절차에 의하여 링크가 구성이 된다.
//
//1. 초기에는 첫 자료를 지시하기 위한 HEAD 구조체가 하나 생성이 되어 있다. (그림 Ⓐ)
//2. 그림 Ⓑ처럼 5의 추가가 요청되는 경우 먼저 Heap에 구조체를 하나 할당 받은 후 id를 5를 저장한다.
//3. 이 구조체를 링크에 추가하게 되는데 HEAD의 next가 NULL이므로 바로 다음에 저장하고 링크를 수정한다.
//4. 그림 Ⓑ에서 15의 추가가 요청 되면Heap에 구조체를 만든 후 id 값이 오름차순으로 되도록 링크를 구성한다.
//5. 따라서 그림 Ⓑ에서 15, 10 순서로 자료 추가가 요청되면 그림 Ⓒ와 그림 Ⓓ와 같이 링크가 구성이 된다.
//6. 새 자료의 추가 요청이 오면 오름차순으로 추가될 위치를 찾은 후 다음과 같은 규칙으로 링크를 수정하면 된다.
//- 새 자료의 next = 이전 자료의 next, 이전 자료의 next = 새 자료의 주소
//7. 자료를 삭제할 경우는 해당 자료를 찾은 후 링크를 다음과 같이 정리하면 된다.
//- 이전 자료의 next = 삭제할 자료의 next
//8. 그림 Ⓓ에서 10, 15가 순서대로 삭제가 되면 그림 Ⓔ, Ⓕ와 같으며 그림 Ⓔ에서 5가 삭제되면 그림 Ⓖ와 같다.
//
//
//
//설계해야 하는 Insert 함수의 기능은 다음과 같다.
//
//prototype
//struct st * Insert(int d)
//	parameter
//d : 저장할 자료의 id 값
//	기능
//	Heap에 구조체를 하나 생성한 후 id에 d를 저장하고 링크 구성을 수정한다.
//	단, 이미 id가 d와 같은 자료가 링크에 존재하는 경우 오류(NULL)를 리턴한다.
//	리턴
//	새로 생성하여 링크에 추가시킨 구조체의 주소 리턴, 이미 d가 존재시는 NULL 리턴
//
//	설계해야 하는 Delete 함수의 기능은 다음과 같다.main 함수로 설계한 코드의 동작을 확인할 수가 있다.
//
//	prototype
//struct st * Delete(int d)
//	parameter
//d : 삭제할 자료의 id 값
//	기능
//	id가 d인 자료를 찾아서 삭제하고 링크 구성을 수정한다.만약 해당 자료가 없거나 자료가 하나도 없는 비어있는 상태라면 오류(NULL)을 리턴한다.
//	리턴
//	링크에서 삭제시킨 구조체의 주소 리턴, d가 없거나 자료가 비어있는 상태라면 NULL 리턴
//	주의사항
//	올바른 테스트 코드에서의 채점을 위하여 삭제하는 자료는 절대 free 시키지 말 것.또한, 삭제하는 자료의 기존 id값과 next 값은 전혀 변경해서는 안되고 링크에서만 제거하여야 한다.
#include <stdio.h>
#include <malloc.h>

struct st
{
	int id;
	struct st * next;
}HEAD = { -1, NULL };

struct st * Insert(int d)
{
	// 코드설계
	struct st * head = &HEAD;

	struct st * node = calloc(1, sizeof(struct st));
	if (!node) return NULL;
	node->id = d;
	node->next = NULL;

	while (1)
	{
		if (head->next == NULL || head->next->id > node->id)
		{
			node->next = head->next;
			head->next = node;
			return node;
		}
		if (head->next->id == node->id) return NULL;
		head = head->next;
	}
}

struct st * Delete(int d)
{
	// 코드설계
	struct st * head = &HEAD;
	while (1)
	{
		if (head->next == NULL) return NULL;
		if (head->next->id == d)
		{
			struct st * tmp = head->next;
			head->next = head->next->next;
			return tmp;
		}
		head = head->next;
	}
}

// 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지

int main(void)
{
#define R (void *)1
#define N (void *)NULL

	int i;
	int oper[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, };
	int data[] = { 7, 2, 1, 5, 4, 7, 9, 9, 8, 1, 9, 7, 7, 3, 2, };
	void * res[] = { N, R, R, R, R, R, R, N, R, R, R, R, N, R, R, };
	int next[] = { -1, -1, 2, -1, 5, -1, -1, -1, 9, 2, -1, 8, -1, 4, 3, };
	struct st * r, *t;

	for (i = 0; i<(sizeof(oper) / sizeof(oper[0])); i++)
	{
		printf("TEST VECTOR [%d]\n", i);

		if (oper[i] == 1)
		{
			r = Insert(data[i]);

			if (res[i] == NULL)
			{
				if (r != NULL)
				{
					printf(">>>>Fail: Expected return => 0x%.8X, Your return=> 0x%.8X\n", res[i], r);
					return 0;
				}

				else
				{
					printf("return => 0x%.8X\n", r);
				}
			}

			else
			{
				t = &HEAD;
				printf("LINK : ");

				for (;;)
				{
					if (t->next == NULL)
					{
						if (t->id == -1) printf("HEAD\n", t->id);
						else printf("%d(LAST)\n", t->id);
						break;
					}

					else
					{
						if (t->id == -1) printf("HEAD -> ", t->id);
						else printf("%d -> ", t->id);
						t = t->next;
					}
				}

				if ((r->next == NULL) && (next[i] != -1))
				{
					printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => NULL\n", next[i]);
				}

				else
				{
					if ((r->next == NULL) && (next[i] == -1))
					{
						printf("id => %d, next => NULL\n", r->id);
					}

					else if (next[i] != r->next->id)
					{
						printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => %d\n ", next[i], r->next->id);
						return 0;
					}

					else
					{
						printf("next link ID => %d\n", r->next->id);

						if (r->id != data[i])
						{
							printf(">>>>Fail: Expected inserted ID => %d, Your inserted ID => %d\n", data[i], r->id);
							return 0;
						}

						else
						{
							printf("inserted ID => %d\n", r->id);
						}
					}
				}
			}
		}

		else
		{
			r = Delete(data[i]);

			if (res[i] == NULL)
			{
				if (r != NULL)
				{
					printf(">>>>Fail: Expected return => 0x%.8X, Your return=> 0x%.8X\n", res[i], r);
					return 0;
				}

				else
				{
					printf("return => 0x%.8X\n", r);
				}
			}

			else
			{
				t = &HEAD;
				printf("LINK : ");

				for (;;)
				{
					if (t->next == NULL)
					{
						if (t->id == -1) printf("HEAD\n", t->id);
						else printf("%d(LAST)\n", t->id);
						break;
					}

					else
					{
						if (t->id == -1) printf("HEAD -> ", t->id);
						else printf("%d -> ", t->id);
						t = t->next;
					}
				}

				if ((r->next == NULL) && (next[i] != -1))
				{
					printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => NULL\n", next[i]);
				}

				else
				{
					if ((r->next == NULL) && (next[i] == -1))
					{
						printf("id => %d, next => NULL\n", r->id);
					}

					else if (next[i] != r->next->id)
					{
						printf(">>>>Fail: Expected ID of next link => %d,  Your ID of next link => %d\n", next[i], r->next->id);
						return 0;
					}

					else
					{
						printf("next link ID => %d\n", r->next->id);

						if (r->id != data[i])
						{
							printf(">>>>Fail: Expected deleted ID => %d, Your deleted ID => %d\n", data[i], r->id);
							return 0;
						}

						else
						{
							printf("deleted ID => %d\n", r->id);
							free(r);
						}
					}
				}
			}
		}
	}

	return 1;
}

#endif
