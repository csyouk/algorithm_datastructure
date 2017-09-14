// K
#if 0
#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 19
int con[MAX_ROW][MAX_COL];
void print_pascal(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = MAX_ROW - n; j < MAX_ROW + i; j++)
		{
			if (con[i][j] == 0)
			{
				printf("   ");
			}
			else
			{
				printf("%3d", con[i][j]);
			}
		}
		printf("\n");
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);

	// 사선 1로 채우기
	for (int i = 0; i < MAX_ROW; i++)
	{
		con[i][MAX_ROW - i - 1] = 1;
		con[i][MAX_ROW + i - 1] = 1;
	}

	//print_pascal(n);

	// 파스칼 삼각형 내부 채우기
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 0; j < MAX_ROW + i; j++)
		{
			//printf("%d %d %d\n", i, j, con[i][j]);
			if (con[i][j] != 0)
			{
				con[i + 1][j + 1] = con[i][j] + con[i][j + 2];
			}
		}
	}


	for (int i = 0; i < MAX_ROW; i++)
	{
		con[i][MAX_ROW - i - 1] = 1;
		con[i][MAX_ROW + i - 1] = 1;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = MAX_ROW - n; j < MAX_ROW + i; j++)
		{
			if (con[i][j] == 0)
			{
				printf("   ");
			}
			else
			{
				printf("%3d", con[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
#endif
