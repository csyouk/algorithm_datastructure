
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
