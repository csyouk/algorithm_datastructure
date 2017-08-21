
// 숫자맞추기
#if 0

int main(void)
{
	int a = 0, b = 0;
	char x[5], y[5];
	scanf("%s %s", &x, &y);

	for (int i = 0; i < sizeof(x)-1; i++)
	{
		if (x[i] == y[i])
		{
			a++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j) continue;
			if (x[i] == y[j])
			{
				b++;
			}
		}
	}


	printf("%dA%dB", a, b);

}
#endif


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


//choco += (N %M + N / M) / M;


// 배열 정리
#if 0

#include <stdio.h>
char matrix[1000][1000];
int main(void)
{
	freopen("test170818.txt", "r", stdin);
	int x, y, row_sum = 0;
	scanf("%d %d", &x, &y);

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}



	for (int i = 0; i < x; i++)
	{
		row_sum = 0;
		for (int j = 0; j < y; j++)
		{
			if (matrix[i][j] == 0) {
				row_sum = 0;
			}
			if (matrix[i][j] == 1){
				row_sum += matrix[i][j];
				matrix[i][j] = row_sum;
			}
		}
	}




	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}
#endif


// 줄세우기
#if 0

#include <stdio.h>
int student[101][101];
int ticket[101];
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &ticket[i]);
	}

	student[1][1] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i+1; j++)
		{

			if (i - ticket[i] == j)
			{
				// 새치기
				student[i][i - ticket[i]] = i;
			}
			else if (j < i - ticket[i])
			{
				student[i][j] = student[i - 1][j];
			}
			else
			{
				student[i][j] = student[i - 1][j-1];
			}
		}
	}



	for (int i = 1; i <= N; i++)
	{
		printf("%d ", student[N][i]);
	}

	return 0;
}
#endif

// 소수369
#if 0
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

#if 0
int main(void)
{
	printf("%d\n", sizeof("Samsung")); // 끝에 보이지 않는 널 문자포함 8
	printf("%d\n", sizeof("\0")); // 끝에 보이지 않는 널 문자포함 2
	printf("%d\n", sizeof("SCSA")); // 끝에 보이지 않는 널 문자포함 5
	printf("%d\n", sizeof("\n")); // 끝에 보이지 않는 널 문자포함 2

	// 끝에 보이지 않는 널 문자포함 14
	printf("%d\n", sizeof("Samsung\0SCSA\n")); 
	
	char aaa[] = "Samsung\0SCSA\n";
	printf("%d\n", aaa);

	int a = 0x123456;
	printf("%x\n", a & (~0x1f << 4) | (0x18 << 4)); // 123580
	printf("%x\n", a & (~0x1f << 4 | 0x18 << 4 ));  // 123400
	return 0;
}
#endif