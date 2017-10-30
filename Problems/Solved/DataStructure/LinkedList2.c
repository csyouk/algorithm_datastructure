
//[Data Structure] Linked List #2
#if 01

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
