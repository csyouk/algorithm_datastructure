
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
