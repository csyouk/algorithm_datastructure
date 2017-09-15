
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
