
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
