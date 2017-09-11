
// 문제 번호 : [TST]장기
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 8
typedef struct _data{
	int x;
	int y;
	int dis;
}QData;
QData Q[SIZE*SIZE];
int N, M, R, C, S, K;
int map[SIZE][SIZE];
int chk[SIZE][SIZE];
int di[DIRS] = {-1,-2,-2,-1, 1, 2, 2, 1};
int dj[DIRS] = {-2,-1, 1, 2, 2, 1,-1,-2};

int WP, RP;

int BFS(void)
{
	QData tmp;
	int k, ni,nj;
	Q[WP].x = R; Q[WP].y = C; Q[WP++].dis = 0; chk[R][C] = 1;

	while (RP < WP)
	{
		tmp.x = Q[RP].x; tmp.y = Q[RP].y; tmp.dis = Q[RP++].dis;
		if (tmp.x == S && tmp.y == K){
			return tmp.dis;
		}
		for ( k = 0; k < DIRS; k++)
		{
			ni = tmp.x + di[k]; nj = tmp.y + dj[k];
			if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
			if (chk[ni][nj] != 0) continue;
			Q[WP].x = ni; Q[WP].y = nj; Q[WP++].dis = tmp.dis + 1; chk[ni][nj] = 1;
		}
	}
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	// 여기서부터 작성
	scanf("%d %d %d %d %d %d", &N, &M, &R, &C, &S, &K);

	printf("%d", BFS());

	return 0;
}
#endif
