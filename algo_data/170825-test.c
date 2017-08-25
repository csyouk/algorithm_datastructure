//[Data Structure] Queue #1
#if 0
//4개 짜리 정수를 선입선출(FIFO) 방식으로 저장하는 환형 큐(Circular Queue)를 설계하려 한다. 일반적으로 환형 큐는 운영의 편리함 때문에 실제 저장할 데이터 수보다 1개 더 많은 버퍼를 잡는다. 환형 큐는 다음과 같이 동작한다.
//
//1. 초기는 WP(쓰기 포인터), RP(읽기 포인터) 모두 0이며 WP와 RP는 0~4를 순회한다 (그림 Ⓐ)
//2. 쓰기 요청이 오면 WP가 가리키는 방에 데이터를 저장하고 WP를 1증가 시킨다 (그림 Ⓑ)
//3. 읽기 요청이 오면 RP가 가리키는 방의 데이터를 읽어오고 RP를 1 증가 시킨다
//4. 항상 버퍼 1칸은 비워두므로 쓰기 불가(FULL 상태)는 WP의 다음 증가 값이 RP와 같아질 경우다 (그림 Ⓒ)
//5. 읽기 불가 상태는 현재 RP와 WP가 같은 값인 상황이다 (그림 Ⓓ)
//
//
//
//위와 같이 동작하는 4개 짜리 정수를 저장하는 환형 큐의 QUEUE, DEQUEUE 함수를 설계하라. 원형큐 CIRQ와 WP,  RP 는 주어진 다음 변수를 사용한다. main 함수로 설계한 프로그램의 동작을 검증할 수가 있다.
//
//int CIRQ[5];
//int RP = 0, WP = 0;
//
//QUEUE 함수의 기능은 다음과 같다.
//
//prototype
//int QUEUE(int d)
//parameter
//d : 환형 큐에 저장할 값
//	기능
//	d를 큐에 저장한다. 단, FULL 상태였다면 d를 큐에 저장하지 않고 WP도 변경하지 않는다
//	리턴
//	변경된 WP의 값, 단, FULL(쓰기 불가) 상태이면 -1을 리턴 한다
//
//	DEQUEUE 함수의 기능은 다음과 같다.
//
//	prototype
//	int DEQUEUE(int *p)
//	parameter
//p : 큐에서 dequeue한 값을 저장 받기 위한 주소
//	기능
//	dequeue한 데이터를 p 주소 메모리에 저장한다. 단, EMPTY이면 RP값과 p 내용은 변경하지 않는다
//	리턴
//	변경된 RP, 만약 EMPTY(읽기 불가) 상태면 -1을 리턴 한다

#include <stdio.h>
#define MAX_Q 5
#define FULL -1
#define EMPTY -1

int CIRQ[MAX_Q];
int RP = 0, WP = 0;

int QUEUE(int d)
{
	// 코드설계
	if ((WP + 1) % MAX_Q == RP) return FULL;
	CIRQ[WP++] = d;
	WP %= MAX_Q;
	return WP;
}

int DEQUEUE(int *p)
{
	// 코드설계
	if (RP == WP) return EMPTY;
	*p = CIRQ[RP++];
	RP %= MAX_Q;
	return RP;
}

/********************************************************************************/
/* 이부분은설계한코드의오류를확인하기위한테스트코드임가급적수정금지   */
/********************************************************************************/

int main(void)
{
	int i;
	int r;
	int d;

	int oper[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0 };
	int que[] = { 1, 3, 5, 7, 9, 1, 3, 5, 7, 0, 2, 4, 6, 2, 4, 8, 10, 6 };
	int res[] = { 1, 2, 3, 4, -1, 1, 2, 3, 4, -1, 0, 1, 2, 0, 1, 3, 4, 2 };

	for (i = 0; i<(sizeof(oper) / sizeof(oper[0])); i++)
	{
		printf("TEST VECTOR [%d]\n", i);

		if (oper[i] == 1)
		{
			r = QUEUE(que[i]);

			if (res[i] != r)
			{
				printf(">>>>Fail: Expected return => %d, YOur return => %d\n", res[i], r);
				return 0;
			}

			else
			{
				if ((r != -1) && (que[i] != CIRQ[(WP == 0) ? (4) : (WP - 1)]))
				{
					printf(">>>>Fail: Expected QUEUE data => %d, Your QUEUE data => %d\n", que[i], CIRQ[(WP == 0) ? (4) : (WP - 1)]);
					return 0;
				}

				else
				{
					if (r != -1) printf("return => %d, queue => %d\n", r, CIRQ[(WP == 0) ? (4) : (WP - 1)]);
					else printf("return => %d\n", r);
				}
			}
		}

		else
		{
			r = DEQUEUE(&d);

			if (res[i] != r)
			{
				printf(">>>>Fail: Expected return => %d, YOur return => %d\n", res[i], r);        return 0;
			}

			else
			{
				if ((r != -1) && (que[i] != d))
				{
					printf(">>>>Fail: Expected DEQUEUE data => %d, Your DEQUEUE data => %d\n", que[i], d);
					return 0;
				}

				else
				{
					if (r != -1) printf("return => %d, queue => %d\n", r, CIRQ[(WP == 0) ? (4) : (WP - 1)]);
					else printf("return => %d\n", r);
				}
			}
		}
	}

	return 1;
}

#endif

// [Data Structure] Stack #2
#if 0
//4개 짜리 정수를 후입선출(LIFO) 방식으로 저장하는 스택을 설계하려 한다. 이 스택은 다음과 같이 동작한다.
//
//1. 이 스택은 현재 SP가 가리키는 방의 자료가 비어있도록 만든 구조로서 다음과 같은 동작으로 운영된다.
//2. 초기 SP는 마지막 방 3을 가리키며 이 상태가 자료가 모두 비워져 있는 상태이다. (그림 Ⓐ)
//3. 1을 PUSH하라는 요청이 오면 SP가 가리키는 3번 방에 자료를 저장하고 SP를 1 감소시킨다. (그림 Ⓑ)
//4. 이후 5, 2, 7 순서로 PUSH하면 그림 Ⓒ와 그림 Ⓓ와 같이 되고 SP는 - 1이 된다.이 경우가 FULL 상태이다.
//5. 데이터의 POP 요청이 오면 먼저 SP를 1 증가시킨 후 그 방의 데이터를 꺼낸다. (그림 Ⓔ)
//6. 계속 자료를 POP하다가 SP가 3인 상태에서 POP 요청이 오면 EMPTY 상태이므로 더 이상 POP 할 수 없다.
//
//
//
//위와 같이 동작하는 4개 짜리 스택의 PUSH, POP 함수를 설계하라.스택과 스택 포인터 SP는 아래 변수를 사용한다.
//
//int STACK[4];
//int SP = 3;
//
//PUSH 함수의 기능은 다음과 같다.
//
//prototype
//int PUSH(int d)
//parameter
//d : 스택에 저장할 값
//	기능
//	d를 스택에 저장한다.단, FULL 상태였다면 d를 스택에 저장하지 않고 SP도 변경하지 않는다.
//	리턴
//	변경된 SP, 단, FULL 상태이면 반드시 0xFF를 리턴 한다.
//
//	POP 함수의 기능은 다음과 같다.주어진 main 함수로 동작을 검증할 수 있다.
//
//	prototype
//	int POP(int *p)
//	parameter
//p : 스택에서 POP한 값을 저장 받기 위한 주소
//	기능
//	POP한 데이터를 p 주소 메모리에 저장한다.단, EMPTY이면 SP와 p의 내용은 변경하지 않는다.
//	리턴
//	변경된 SP, 만약 EMPTY 상태면 PUSH 불가능 오류 코드로 0xFF를 리턴 한다.

#include <stdio.h>
#define FULL -1
#define EMPTY 4;
#define SIZE 4
#define ERROR 0xFF
#define EMPTY 3

int STACK[SIZE];
int SP = EMPTY;

int PUSH(int d)
{
	// 코드설계
	if (SP == FULL) return ERROR;
	STACK[SP--] = d;
	return SP;
}

int POP(int *p)
{
	// 코드설계
	if (SP == EMPTY) return ERROR;
	*p = STACK[++SP];
	return SP;
}

// 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지 

int main(void)
{
	int i;
	int r;
	int d;

	int oper[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0 };
	int stk[] = { 1, 3, 5, 7, 9, 7, 5, 3, 1, 0, 2, 4, 6, 6, 4, 8, 10, 10 };
	int res[] = { 2, 1, 0, -1, 0xff, 0, 1, 2, 3, 0xFF, 2, 1, 0, 1, 2, 1, 0, 1 };

	for (i = 0; i<(sizeof(oper) / sizeof(oper[0])); i++)
	{
		if (oper[i] == 1)
		{
			r = PUSH(stk[i]);

			if (r != res[i])
			{
				printf(">>>>Fail: Expected return => %d, Your return => %d\n", res[i], r);
				return 0;
			}

			if (r == 0xFF)
			{
				printf("return => 0x%.2X\n", r);
				continue;
			}

			if (STACK[SP + 1] != stk[i])
			{
				printf(">>>>Fail : Expected stack data => %d, Your stack data => %d\n", stk[i], STACK[SP + 1]);
				return 0;
			}

			printf("return => 0x%.2X\n", r);
			printf("PUSH => %d\n", STACK[SP + 1]);
		}

		else
		{
			r = POP(&d);

			if (r != res[i])
			{
				printf(">>>>Fail: Expected return => %d, Your return => %d\n", res[i], r);
				return 0;
			}

			if (r == 0xFF)
			{
				printf("return => 0x%.2X\n", r);
				continue;
			}

			if (d != stk[i])
			{
				printf(">>>>Fail: Expected POP data => %d, Your POP data => %d\n", stk[i], d);
				return 0;
			}

			printf("return => 0x%.2X\n", r);
			printf("POP => %d\n", d);
		}
	}

	return 1;
}
#endif

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


//	[Data Structure] Hash Table #1
#if 0
//아주 간단한 해시(Hash) 테이블 방식으로 자료를 관리하려 한다.해시 테이블은 다음과 같이 동작한다.
//
//1. 9개의 방의 초기에는 모두 - 1이 저장되어 있고 - 1이 들어 있는 방은 빈방을 의미한다(그림 Ⓐ)
//2. 이 해시 테이블은 데이터 저장 요청이 오면 저장할 값을 % 5 연산하여 나온 번호를 저장할 방으로 결정한다.
//3. 이 규칙에 의하여 0, 2 가 저장된 경우 0 % 5 = 0, 2 % 5 = 2이므로 해시 테이블은 그림 Ⓑ와 같게 된다.
//4. 그림 Ⓑ에서 5가 추가되는 경우 5 % 5 = 0 인데 이미 0번 방에 0이 저장되어 있으므로 다른 방으로 가야 한다.
//5. 다른 방을 찾을 때는 결정된 방에서부터 아래 방향으로 빈 방이 나올 때 까지 2씩 더해서 찾아 간다. (그림 Ⓒ)
//6. 그림 Ⓒ에서 4가 들어오면 4 % 5 = 4 이나 4번 방이 차있으므로 2를 더하여 6번 방으로 이동한다. (그림 Ⓓ)
//7. 그림 Ⓓ에서 7이 들어오면 7 % 5 = 2이고 역시 2씩 증가하려 결국 8번 방에 저장되게 된다. (그림 Ⓔ)
//8. 그림 Ⓔ에서 9가 들어오면 9 % 5 = 4이고 아래 방향으로 방을 찾았지만 8번까지 꽉 차있는 상태가 된다.
//9. 이 경우는 0~8번 방이 Ring처럼 연결되었다고 보고 2칸을 더 이동하여 1번 방에 저장하도록 한다. (그림 Ⓕ)
//10. 이와 같이 순회하면 8번 방에서 2칸을 더 가면 1번 방이 되고 7번 방에서 2칸을 더 가면 0번 방이 된다.
//11. 빈 방을 찾는 STEP이 2이므로 9개의 방중에서 언젠가는 빈 방을 찾게 되는데 만약 계속 빈방을 찾다가 처음
//지정 받았던 번호의 방으로 다시 찾아오게 되면 그 때는 더 이상 빈 방이 없는 상태로 판단하여 저장을 포기한다.
//
//
//
//위와 같이 동작하는 9개 짜리 해시 테이블의 Insert와 Delete 함수를 설계하라.해시 테이블은 다음과 같은 배열로 선언되어 있으며 해시 방정식은 위 그림의 예처럼 % 5로 하고 새로운 방을 위한 탐색 이동은 + 2칸씩으로 한다.
//
//int Hash[9] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
//#define STEP    2   // Hash 테이블 탐색을 위한 STEP 값
//#define HASH   5   // Hash 테이블 방 배정을 위한 Hash 함수에 쓰일 값, % HASH로 초기 방 번호 지정
//
//Insert 함수의 기능은 다음과 같다.
//
//prototype
//int Insert(int d)
//parameter
//d : 테이블에 저장할 값(0 ~65, 535 사이의 정수, 이 범위 밖의 값은 절대로 전달되지 않는다)
//	기능
//	d를 해시 방정식에 의거하여 해시 테이블에 저장한다
//	리턴
//	저장된 방의 번호, 데이터가 FULL 상태이거나 해당 ID가 이미 저장되어 있으면 - 1 리턴
//	즉, Hash 테이블에는 동일한 값은 저장될 수 없다.
//	주의 사항
//	따라서 데이터를 쓰기 전에 반드시 이미 저장된 ID 값인지 확인하여야 한다.
//
//	Delete 함수의 기능은 다음과 같다.주어진 main 함수로 동작을 검증할 수 있다.
//
//	prototype
//	int Delete(int d)
//	parameter
//d : 테이블에서 삭제할 값(0 ~65, 535 사이의 정수)
//	기능
//	d를 해시 테이블에서 찾은 후 삭제한다.삭제된 방은 반드시 - 1(빈 방 표시)을 저장하여야 한다
//	리턴
//	삭제된 해시 테이블의 방 번호, 단, 해당 데이터가 해시 테이블에 없는 경우 - 1을 리턴 한다.

#include <stdio.h>

#define STEP   2
#define HASH   5  
#define EMPTY -1
#define ERROR -1
#define MAX 9
#define GET_HASH_KEY(num) ((num)%HASH)

int Hash[MAX] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int Insert(int d)
{
	// 코드설계
	int key, pos;
	pos = key = GET_HASH_KEY(d);

	while (1)
	{
		if (Hash[pos] == EMPTY)
		{
			Hash[pos] = d;
			return pos;
		}
		if (Hash[pos] == d)
		{
			return ERROR;
		}
		pos += STEP;
		if (pos >= MAX) pos %= MAX;
		if (pos == key) return ERROR;
	}
}

int Delete(int d)
{
	// 코드설계
	int key, pos;
	pos = key = GET_HASH_KEY(d);

	while (1)
	{
		if (Hash[pos] == d)
		{
			Hash[pos] = EMPTY;
			return pos;
		}
		pos += STEP;
		if (pos >= MAX) pos %= MAX;
		if (pos == key) return ERROR;
	}
}

/********************************************************************************/
/* 이 부분은 설계한 코드의 오류를 확인하기 위한 테스트 코드임 수정금지   */
/********************************************************************************/

int main(void)
{
	int i;
	int r;

	int oper[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1 };
	int hash[] = { 2, 0, 5, 4, 7, 9, 9, 8, 15, 17, 21, 2, 31, 18, 50 };
	int res[] = { 2, 0, 4, 6, 8, 1, -1, 3, 5, 7, -1, 2, -1, 2, -1 };

	for (i = 0; i<(sizeof(oper) / sizeof(oper[0])); i++)
	{
		printf("TEST VECTOR [%d]\n", i);

		if (oper[i] == 1)
		{
			r = Insert(hash[i]);

			if (res[i] != r)
			{
				printf(">>>>Fail: Expected return => %d, Your return=> %d\n", res[i], r);
				return 0;
			}

			else
			{
				if ((r != -1) && (hash[i] != Hash[r]))
				{
					printf(">>>>Fail: Expected HASH data => %d, Your HASH data => %d\n", hash[i], Hash[r]);
					return 0;
				}

				else
				{
					if (r != -1) printf("return => %d, value => %d\n", r, Hash[r]);
					else printf("return => %d\n", r);
				}
			}
		}

		else
		{
			r = Delete(hash[i]);

			if (res[i] != r)
			{
				printf(">>>>Fail: Expected return => %d, Your return=> %d\n", res[i], r);
				return 0;
			}

			else
			{
				if ((r != -1) && (Hash[r] != -1))
				{
					printf(">>>>Fail: Expected HASH data => %d, Your HASH data => %d\n", hash[i], Hash[r]);
					return 0;
				}

				else
				{
					if (r != -1) printf("return => %d\n", r);
					else printf("return => %d\n", r);
				}
			}
		}
	}

	return 1;
}
#endif


// [Data Structure] Queue #2
#if 0
//Heap에 링크 방식으로 선입선출(FIFO) 선형 큐(Linear Queue)를 구성하려 한다.사용할 데이터 구조체와 HEAD 및 TAIL 구조체의 선언과 초기화 코드는 다음과 같다.HEAD와 TAIL은 자료를 저장하지 않고 링크 시작과 끝만 지시한다.
//
//
//
//
//struct st
//{
//	int id;
//	struct st * rp;
//	struct st * wp;
//};
//struct st HEAD = { 0, NULL, NULL };
//struct st TAIL = { 0, NULL, NULL };
//
//HEAD.rp = &TAIL;
//TAIL.wp = &HEAD;
//
//
//
//이 Heap기반 선형 큐의 자료 추가 동작은 다음과 같으며 각각의 큐 링크 상태는 그림 Ⓐ, Ⓑ, Ⓒ와 같다.
//
//
//1. 자료가 하나도 없는 초기에 HEAD의 rp는 TAIL의 주소를 TAIL의 wp는 HEAD의 주소를 가리킨다. (그림 Ⓐ)
//2. 새로운 자료를 추가하려면 먼저 Heap에 구조체를 하나 생성한 후 id에 값을 저장하고 이 구조체를 추가한다.
//3. Heap에 생성한 구조체를 새로 추가하는 경우 TAIL의 바로 앞에 위치하도록 링크를 구성해야 한다. (그림 Ⓑ)
//4. 자료를 꺼내가기 위한 출구인 HEAD 쪽의 노드 구성은 다음과 같이 수행한다.
//- 새 자료의 앞 자료(새 자료 추가전 TAIL의 wp)의 rp = 새 자료의 주소, 새 자료의 rp = TAIL의 주소
//5. 자료를 저장하기 위한 입구인 TAIL 쪽의 wp 링크의 연결은 다음과 같이 조정한다.
//- 새 자료의 wp = 새 자료의 앞 자료 주소(현재 TAIL의 wp), TAIL의 wp = 새 자료의 주소
//6. 초기 상태 그림 Ⓐ에서 id 10인 자료, id 5인 자료가 순서대로 추가 되었을 때 링크 구성은 그림 Ⓑ, Ⓒ와 같다
//
//
//
//
//
//
//
//Heap기반 선형 큐의 자료 출력(삭제) 동작은 다음과 같으며 각각의 큐 링크 상태는 그림 Ⓓ, Ⓔ, Ⓕ와 같다.
//
//
//1. 초기 큐에서 id가 10, 5인 자료들이 순서대로 입력된 후 선형 큐의 상태는 그림 Ⓓ와 같다.
//2. 이 큐에서 자료 하나를 출력하면 가장 먼저 입력된 10이 출력되어야 한다.즉, HEAD 바로 다음 자료 출력
//3. 다만, HEAD의 바로 다음이 TAIL이면 방이 모두 빈 상태를 의미하므로 에러코드(-1)을 리턴해야 한다.
//4. HEAD 다음 자료를 제거하기 위한 링크 정리는 다음과 같이 수행하며 링크 정리 완료 후에는 자료를 free 한다.
//5. 입구측인 TAIL의 wp 링크는 다음과 같이 조정되어야 한다.
//- 출력(삭제)할 자료의 다음 자료의 wp = HEAD의 주소, 즉, 그림 Ⓓ에서 id 5인 자료의 wp = HEAD 주소
//6. 자료의 출구측인 HEAD의 rp 링크는 다음과 같이 조정되어야 한다.
//- HEAD의 rp = 출력(삭제)할 자료 다음 자료의 주소(즉, 출력(삭제)할 자료의 rp)
//7. 그림 Ⓓ에서 두 번 자료를 출력(dequeue) 시키면 링크의 구성은 그림 Ⓔ, 그림 Ⓕ와 같이 변화한다.
//
//
//
//
//
//힙 기반 선형 큐에 값을 추가하는 QUEUE 함수의 기능은 다음과 같다.
//
//
//prototype
//struct st * QUEUE(int d)
//	parameter
//d : 선형 큐에 저장할 값
//	기능
//	Heap에 st 구조체를 하나 할당 받은 후 d를 구조체 id에 저장한 후 이 구조체를 큐에 추가 시킨다.
//	리턴
//	새로 추가된 구조체의 주소
//
//
//
//	선형 큐에 값을 삭제하는 DEQUEUE 함수의 기능은 다음과 같다.주어진 main 함수로 동작을 검증할 수 있다.
//
//
//	prototype
//	int DEQUEUE(int * p)
//	parameter
//	큐에서 자료를 출력(삭제)하고 출력된 자료의 id 값을 p가 가리키는 주소에 저장한다.
//	기능
//	꺼내려는 자료 즉, HEAD 바로 다음 자료의 id를 p 주소에 저장하고 이 자료가 삭제되도록 링크를 정리한 후 삭제를 위하여 이 자료를 heap에서 free 시킨다.단, 엉뚱한 자료를 free 시킬 경우는 문제가 발생할 수가 있으므로 주의해야 한다.
//	리턴
//	큐가 자료를 삭제할 수 없는EMPTY 상태면 - 1을, 정상적으로 삭제가 되었으면 0을 리턴 한다.
#include <stdio.h>
#include <malloc.h>
#define EMPTY -1
struct st
{
	int id;
	struct st * rp; // next
	struct st * wp; // prev
};
struct st HEAD = { 0, NULL, NULL };
struct st TAIL = { 0, NULL, NULL };

struct st * QUEUE(int d)
{
	// 코드설계 
	// tail을 조정
	struct st * head = &HEAD;
	struct st * tail = &TAIL;

	struct st * node = calloc(1, sizeof(struct st));
	if (!node) return NULL;
	node->id = d;

	// 큐에 처음 데이터가 들어가는 경우.
	if (head->rp == tail)
	{
		node->rp = tail;
		node->wp = head;
		head->rp = node;
		tail->wp = node;
		return node;
	}
	tail->wp->rp = node;
	node->rp = tail;
	node->wp = tail->wp;
	tail->wp = node;
	return node;
}

int DEQUEUE(int *p)
{
	// 코드설계.
	// head를 조정.
	struct st * head = &HEAD;
	struct st * tail = &TAIL;
	struct st * tmp;
	if (head->rp == tail) return EMPTY;
	tmp = head->rp;
	*p = head->rp->id;
	head->rp->rp->wp = head->rp->wp;
	head->rp = head->rp->rp;
	free(tmp);
	return 0;
}


/********************************************************************************/

/* 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지   */

/********************************************************************************/

int main(void)
{
	int i;
	int d;

	struct st * r, *t;
	int p[1];
	int oper[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0 };
	int que[] = { 1, 3, 5, 7, 9, 1, 3, 5, 7, 9, 0, 2, 4, 6, 2, 4, 8, 10, 6, 8, 10, 0 };
	int ans[] = { 1, 3, 5, 7, 9, 0, 0, 0, 0, 0, -1, 2, 4, 6, 0, 0, 8, 10, 0, 0, 0, -1 };

	HEAD.rp = &TAIL;
	TAIL.wp = &HEAD;

	for (i = 0; i<(sizeof(oper) / sizeof(oper[0])); i++)
	{
		printf("\nTEST VECTOR [%d]\n", i);

		if (oper[i] == 1)
		{
			r = QUEUE(que[i]);

			t = HEAD.rp;

			while (t->rp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->rp;
			}

			printf("\n");

			t = TAIL.wp;

			while (t->wp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->wp;
			}

			printf("\n");

			if (r == NULL)
			{
				printf(">>>>틀림: 리턴된구조체의주소가NULL 포인터임\n");
				return 0;
			}

			if (r->id != ans[i])
			{
				printf(">>>>틀림: 리턴된구조체주소의id 예상값=> %d, 실제리턴된구조체의id 값=> %d\n", ans[i], r->id);
				return 0;
			}

			if (TAIL.wp != r)
			{
				printf(">>>>틀림: TAIL측wp 링크오류(TAIL의wp가리턴된자료주소가아님)\n");
				return 0;
			}

			if (r->rp != &TAIL)
			{
				printf(">>>>틀림: 리턴된자료의rp가TAIL의주소가아님)\n");
				return 0;
			}

			t = &HEAD;

			for (;;)
			{
				if (t->rp == &TAIL) break;
				else t = t->rp;
			}

			if ((t != r) || (t->id != r->id))
			{
				printf(">>>>틀림: HEAD측으로부터찾은TAIL 바로앞에있어야하는구조체주소와리턴된구조체주소가다름\n");
				return 0;
			}

			printf("OK\n");
		}


		else
		{
			d = DEQUEUE(p);

			t = HEAD.rp;

			while (t->rp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->rp;
			}

			printf("\n");

			t = TAIL.wp;

			while (t->wp != NULL)
			{
				printf("=> [%d]", t->id);
				t = t->wp;
			}

			printf("\n");

			if (d != ans[i])
			{
				printf(">>>>틀림: 예상리턴값= %d, 실제리턴값= %d\n", ans[i], d);
				return 0;
			}

			if (d != -1)
			{
				if (*p != que[i])
				{
					printf(">>>>틀림: 큐에서꺼내서p 주소에들어있는데이터의예상값=> %d, 실제p 주소에들어있는값=> %d\n", que[i], *p);
					return 0;
				}

				t = &HEAD;

				for (;;)
				{
					if (t->rp == &TAIL) break;
					else t = t->rp;
				}

				t = &TAIL;

				for (;;)
				{
					if (t->wp == &HEAD) break;
					else t = t->wp;
				}
			}

			printf("OK\n");
		}
	}

	return 1;
}
#endif


//[Data Structure] Linked List #2
#if 0

//Heap을 쓰지 않고 간단한 배열에 구조체를 저장하고 이를 연결 리스트(Linked List)로 관리하려 한다. 구조체 배열은 다음과 같은 초기값으로 되어 있다. 구조체에서 id가 0이면 빈 방, next가 -1이면 링크의 마지막 방을 의미한다.
//struct st
//{
//	int id;
//	int next;
//} data[5] = {{0, -1}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
//
//배열을 이용한 링크드 리스트 자료구조는 다음과 같이 동작한다.
//
//1. 전체 자료의 id는 초기값이 0(빈방)이며 헤더로 사용되는 0번 방의 next 초기값은 -1(마지막 링크)을 갖는다.
//2. 헤더로 사용되는 0번 방은 항상 링크의 시작점이며 헤더로만 쓰이고 절대 데이터가 저장되지 않는다. (그림 Ⓐ)
//3. 자료 추가시 빈 방중 가장 작은 번호 방에 배정하고 오름차순으로 링크가 정렬되도록 링크를 수정한다. (그림 Ⓑ)
//4. 그림 Ⓐ에서 10이 들어오면 1 번 방에 배정하고 0번 방 next는1로, 1번 방 next는 -1로 만든다. (그림 Ⓑ)
//5. 그림 Ⓑ에서 5가 들어오면 2 번 방에 배정하되 10이 더 크므로 오름차순이 되게 링크를 정리한다. (그림 Ⓑ)
//6. 그림 D는 초기 그림 Ⓐ에서 10, 5, 20순으로 저장되었을 때 5-10-20 오름차순으로 링크가 구성된 상황이다.  
//7. 삭제 요청이 오면 자료에서 id를 찾아서 삭제한다. 삭제된 방의 id를 0으로 빈방 처리하고 링크를 수정한다.
//8. 삭제된 자료에 대한 링크는 나를 가리키던 이전 방의 next를 내가 가리키던 다음 방의 번호로 수정하면 된다.
//9. 그림 D에서 10, 20순으로 삭제되면 그림 E와 그림 F가 되고 새로 다시 80이 추가되면 그림 G가 된다.10. 자료에는 절대 동일한 id의 자료가 저장될 수 없으며 헤더인 0번 방은 사용이 금지되고 id는 항상 0이 된다.
//11. 쓰기시에는 동일 id가 있거나 빈 방이 없으면 오류로, 삭제시는 해당 id가 없으면 오류로 처리된다.
//
//
//설계해야하는 Delete 함수의기능은다음과같다. main 함수로설계한코드의동작을확인할수가있다.
//
//prototype
//int Delete(int d)
//parameter
//d : 구조체배열에서삭제할 id 값 (반드시 1 ~ 65535 사이의정수) , 0은빈방을의미, 삭제불가
//	기능
//	d를배열에서찾아서제거하고오름차순으로정렬되도록링크를수정한다.
//	리턴
//	삭제된방의요소번호, 해당데이터가배열에없는경우오류(-1)을리턴한다.
//
//	설계해야하는 Insert 함수의기능은다음과같다.
//
//
//	prototype
//	int Insert(int d)
//	parameter
//d : 구조체배열에저장할 id 값 (반드시 1 ~ 65535 사이의정수), 0은빈방을의미, 사용불가
//	기능
//	d를가장작은번호방에저장하고오름차순이되도록링크를수정한다. 오류시는 d를저장하지않음
//	리턴
//	저장된방의번호, 이미해당 id 자료가있거나빈방이없는경우오류(-1)을리턴한다.

#include <stdio.h>
#define ROOM 5
#define EMPTY -1
#define ERROR -1
struct st
{
	int id;
	int next;
};
struct st data[ROOM] = { { 0, -1 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

//int Insert2(int d)
//{
//	int pos = 0;
//
//	struct st head = data[pos];
//	data[head.next].id
//}

int Insert(int d)
{
	int pos;
	struct st * head = &data[0];
	struct st tmp = { d, 0 };
	struct st * node = &tmp;


	for (pos = 1; pos < ROOM; pos++)
	{
		if (data[pos].id == node->id) return ERROR;
		if (data[pos].id == 0) {
			// 오류가 났던 이유는, struct st의 선언과 변수 선언을 분리시키지 않아서 그렇다.
			// 분리시키면 오류가 없어진다.
			data[pos] = *node; 
			node = &data[pos];
			break;
		}
	}
	if (pos == ROOM) return ERROR;

	while (1)
	{
		if (head->next == EMPTY)
		{
			node->next = head->next;
			head->next = pos;
			return pos;
		}

		struct st * next_node = &data[head->next];

		if (next_node->id > node->id)
		{
			node->next = head->next;
			head->next = pos;
			return pos;
		}
		head = next_node;
	}

	return ERROR;
}

int Delete(int d)
{
	int pos;
	// 코드작성
	struct st * head = &data[0];

	for (pos = 1; pos < ROOM; pos++)
	{
		if (data[pos].id == d) break;
	}
	if (pos == ROOM) return ERROR;

	while (1)
	{
		if (head->next == EMPTY)
		{
			return ERROR;
		}

		struct st * node = &data[head->next];

		if (node->id == d)
		{
			int next = head->next;
			head->next = node->next;
			node->id = 0;
			return next;
		}
		head = node;
	}
}

/********************************************************************************/
/* 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지*/
/********************************************************************************/

int main(void)
{
	int i;
	int r;

	int j;

	int oper[] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0 };
	int val[] = { 10, 5, 20, 5, 7, 8, 10, 20, 15, 80, 100, 20, 7 };
	int next[] = { -1, 1, -1, 0, 1, 0, 0, 0, 0, -1, -1, 0, 0 };
	int res[] = { 1, 2, 3, -1, 4, -1, 1, 3, -1, 1, 3, -1, 4 };

	printf("ROOM-NO\tID\tNEXT\n");
	printf("---------------------\n");

	for (j = 0; j< 5; j++)
	{
		printf("%d\t%d\t%d\n", j, data[j].id, data[j].next);
	}

	printf("---------------------\n");

	for (i = 0; i<(sizeof(oper) / sizeof(oper[0])); i++)
	{
		printf("TEST VECTOR [%d]\n", i);

		if (oper[i] == 1) r = Insert(val[i]);
		else r = Delete(val[i]);

		printf("ROOM-NO\tID\tNEXT\n");
		printf("---------------------\n");

		for (j = 0; j< 5; j++)
		{
			printf("%d\t%d\t%d\n", j, data[j].id, data[j].next);
		}

		printf("---------------------\n");

		if (res[i] != r)
		{
			printf(">>>>Fail: Expected Return=> %d, Your Return=> %d\n", res[i], r);
			return 0;
		}

		else
		{
			if (r == -1)
			{
				printf("return => %d\n", r);
			}

			else
			{
				printf("return => %d\n", r);

				if ((val[i] != data[r].id) && (oper[i] == 1))
				{
					printf(">>>>Fail: Expected Saved ID => %d, Your ID => %d\n", val[i], data[r].id);
					return 0;
				}

				else
				{
					if (oper[i] == 1)
					{
						printf("id => %d\n", data[r].id);
					}

					else
					{
						printf("id => %d\n", data[r].id);
					}


					if (oper[i] == 1)
					{
						if (next[i] != data[r].next)
						{
							printf(">>>>Fail: Expected next => %d, Your next => %d\n", next[i], data[r].next);
							return 0;
						}

						else
						{
							printf("next => %d\n", data[r].next);
						}
					}
				}
			}
		}
	}

	return 1;
}

#endif