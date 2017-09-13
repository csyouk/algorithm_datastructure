
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
