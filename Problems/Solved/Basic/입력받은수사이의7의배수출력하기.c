#if 0
짝수이면서 7의 배수인 수 중 입력 받은 양의 정수 N(1이상, 1,000,000이하)과 가장 가까운 수를 인쇄하라.
짝수이면서 7의 배수인 수란 14, 28, 42, ... 을 의미한다.
조건을 만족하는 수가 두 개인 경우 작은 수를 인쇄한다.
N이 범위를 벗어나는 경우는 없다고 가정하고, 이에 대한 예외 처리는 하지 않는다.

/* 솔루션1: 탐색및조건비교 */

#include <stdio.h>

int N;
int sol;

int main(void)
{
	int min, max;


	scanf("%d", &N);


	max = 14;

	while (max < N)
	{
		max = max + 14;
	}

	min = max - 14;
	if (min == 0)
	{
		sol = 14;
	}
	else
	{
		if (N - min <= max - N) sol = min;
		else sol = max;
	}


	printf("%d", sol);

	return 0;
}


/* 솔루션2: 수식연산 */
#include <stdio.h>

int N;
int sol;

int main(void)
{
	int min, max;


	scanf("%d", &N);


	if (N <= 14) sol = 14;
	else
	{
		min = N / 14 * 14;
		max = min + 14;
		sol = (max - N < N - min) ? max : min;
	}


	printf("%d", sol);

	return 0;
}

#endif
