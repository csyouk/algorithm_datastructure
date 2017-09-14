
#if 0
N개의 정수를 입력 받아 왼쪽으로 한 칸씩 Rotate하여 인쇄하라.
맨 앞의 정수는 맨 뒤로 이동한다.
첫째 줄에 정수들의 개수 N(1이상, 10이하)가 입력되고, 그 다음 줄에 N개의 정수가 공백으로 구분되어 입력된다.
정수들을 왼쪽으로 한 칸씩 Rotate하여 인쇄한다.

#include <stdio.h>

int N;
int a[10 + 10];

int main(void)
{
	int i;
	int tmp;


	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%d", &a[i]);
	}


	tmp = a[0];
	for (i = 0; i<N - 1; i++)
	{
		a[i] = a[i + 1];
	}
	a[i] = tmp;


	for (i = 0; i<N - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("%d", a[i]);

	return 0;
}
#endif
