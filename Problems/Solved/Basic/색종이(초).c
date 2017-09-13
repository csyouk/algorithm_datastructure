
// 색종이(초)
#if 0
#include <stdio.h>
#define SIZE 10
int canvas[100][100];
int N, area;
int main(void)
{
	// 여기서부터 작성
	//freopen("test.txt", "r", stdin);
	scanf("%d", &N);
	int x, y;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		for (int _x = 0; _x < SIZE; _x++)
		{
			for (int _y = 0; _y < SIZE; _y++)
			{
				canvas[x + _x][y + _y] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			area += canvas[i][j];
		}
	}

	printf("%d", area);

	return 0;
}
#endif

//	색종이(초)
#if 0
#include <stdio.h>
int N, sol;
int a[100 + 10][100 + 10];
int main(void){
	int i, j, k, si, sj;
	scanf("%d", &N);
	for (k = 0; k < N; k++){
		scanf("%d %d", &sj, &si);
		for (i = si; i < si + 10; i++){
			for (j = sj; j < sj + 10; j++){
				a[i][j] = 1;
			}
		}
	}
	for (i = 1; i <= 100; i++){
		for (j = 1; j <= 100; j++){
			if (a[i][j] == 1) sol++;
		}
	}
	printf("%d", sol);
	return 0;
}
#endif
