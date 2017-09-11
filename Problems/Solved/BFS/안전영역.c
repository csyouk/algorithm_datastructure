
// 문제 번호 : [TST]안전 영역
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 8

typedef struct _data{
	int x;
	int y;
	int dis;
} Area;

int map[SIZE][SIZE];
int chk[SIZE][SIZE];

Area Q[SIZE*SIZE];
int WP, RP, N;

int cal(void)
{
	int i, j, cnt = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (chk[i][j]) cnt++;
		}
	}
	return cnt;
}
int main(void)
{
	// 여기서부터 작성
	int i, j;
	scanf("%d", &N);

	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}


	return 0;
}

#endif
