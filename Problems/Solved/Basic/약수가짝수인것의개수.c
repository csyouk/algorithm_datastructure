
#if 0
//두 정수 A, B를 입력 받아서 A이상 B이하의 정수들 중 약수의 수가 짝수인 수의 개수를 출력하는 프로그램을 작성하시오.
//예를 들어, A가 4이고 B가 10인 경우, 약수의 개수가 짝수인 수는 5, 6, 7, 8, 10으로 총 5개가 존재한다.
//계산이 빠른 방법을 고민하라.
//
//첫 번째 줄에 두 정수 A, B가 공백으로 구분되어 입력된다.
//(1 ≤ A ≤ B ≤ 2,000,000,000 (20억))
//
//해당 범위에서 약수의 수가 짝수인 수의 개수를 출력한다.
#include <stdio.h>

int A, B;
int sol;

int root(int a)
{
	int i;
	if (a == 0) return 0;
	for (i = 1; i <= a; i++)
	{
		if (i*i > a) return i - 1;
	}
	return 1;
}

int main(void)
{

	scanf("%u %u", &A, &B);


	sol = B - A + 1 - (root(B) - root(A - 1));


	printf("%d", sol);

	return 0;
}

#endif
