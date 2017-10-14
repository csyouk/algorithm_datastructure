
// 소수369
#if 01
#include <stdio.h>
int is_prime(int a)
{
	int i;
	if (a == 1) return 0;
	if (a == 2 || a == 3) return 1;
	for (i = 3; i*i <= a; i+=2)
	{
		if (a % i == 0) return 0;
	}
	return 1;
}
int prime(int a)
{
	int i;
	if (a == 1 || a == 4 || a == 6 || a == 8 || a == 9 || a == 10) return 0;
	if (a == 2 || a == 3 || a == 5 || a == 7) return a;

	for (i = 3; i*i <= a; i ++)
	{
		if (a % i == 0) return 0;
	}
	return a;
}
int clap_cnt[1000];
int main(void)
{

	for (size_t i = 15; i < 100; i+=2)
	{
		int pp = prime(i);
		(pp) ? printf("%d\n", pp) : 0;
	}
	//int N, M, i;
	//int cursor = 0;
	//scanf("%d%d%d", &N, &M, &i);


	//for (int i = 1; i <= M; i++)
	//{
	//	if (is_prime(i))
	//	{
	//		clap_cnt[cursor]++;
	//	}
	//	cursor++;
	//	if (cursor == N) cursor = 0;
	//}

	//printf("%d", clap_cnt[i]);

	return 0;
}
#endif
