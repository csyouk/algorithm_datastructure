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
