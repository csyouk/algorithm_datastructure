
// 색종이(중)
#if 0
#include <stdio.h>
//#define _CRT_SECURE_NO_WARINIGS
#define SIZE 10
#define WIDTH 100
#define HEIGHT 100
int N;
int canvas[WIDTH + 10][HEIGHT + 10];
int cnt;
int main(void)
{
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


	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (canvas[i][j])
			{
				if (canvas[i - 1][j] == 0) cnt++;
				if (canvas[i][j - 1] == 0) cnt++;
				if (canvas[i + 1][j] == 0) cnt++;
				if (canvas[i][j + 1] == 0) cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
#endif

//	색종이(중)
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
			if (a[i][j] != 1) continue;
			if (a[i - 1][j] == 0) sol++;
			if (a[i + 1][j] == 0) sol++;
			if (a[i][j - 1] == 0) sol++;
			if (a[i][j + 1] == 0) sol++;
		}
	}
	printf("%d", sol);
	return 0;
}
#endif
