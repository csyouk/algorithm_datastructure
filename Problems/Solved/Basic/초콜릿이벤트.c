
// 초콜릿 이벤트
#if 0
#include <stdio.h>

int main(void)
{
	//freopen("test170818.txt", "r", stdin);
	int testcase, N, C, M, backup, choco;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		scanf("%d%d%d", &N, &C, &M);

		int total = N / C;

		if (total >= M)
		{
			choco = total;
			while (choco >= M)
			{
				int bonus = choco / M;
				total += bonus;
				choco = choco % M + bonus;
			}
		}
		printf("%d\n", total);

	}

	return 0;
}
#endif
