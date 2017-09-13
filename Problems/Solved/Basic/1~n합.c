// 1~n 합
#if 0
#include <stdio.h>
int sum(int n)
{
	if (n == 1) return 1;
	return n + sum(n - 1);
}

int main(void)
{
	// 여기서부터 작성
	int N;
	scanf("%d", &N);

	printf("%d", sum(N));

	return 0;
}
#endif
