
// 문제 번호 D: [TST]저글링 방사능 오염
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 4
typedef struct _zergling{
	int x;
	int y;
	int sec;
} Zergling;
int R, C;
int si, sj, left_zergling_cnt, max_time;
int map[SIZE][SIZE];
int chk[SIZE][SIZE];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1, 0,1,0};

Zergling Q[SIZE*SIZE];
int RP, WP;

int BFS(int i, int j, int sec){
	Zergling tmp;
	int k, ni, nj;

	Q[WP].x = i; Q[WP].y = j; Q[WP++].sec = 3;

	while (RP < WP)
	{
		tmp.x = Q[RP].x; tmp.y = Q[RP].y; tmp.sec = Q[RP++].sec; chk[tmp.x][tmp.y] = tmp.sec;
		// 반환 조건.//
		//if (chk[tmp.x][tmp.y] != 0) return tmp.sec;

		for ( k = 0; k < DIRS; k++)
		{
			ni = tmp.x + di[k];   nj = tmp.y + dj[k];
			if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
			if (chk[ni][nj] != 0) continue;
			if (map[ni][nj] == 1 && chk[ni][nj] == 0){
				Q[WP].x = ni; Q[WP].y = nj; Q[WP++].sec = tmp.sec + 1; chk[ni][nj] = tmp.sec + 1;
			}

		}
	}
	return tmp.sec;
}

void Cal_Left_Zerglings(void){
	int i, j;
	for ( i = 1; i <=R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			if (map[i][j] == 1 && chk[i][j] == 0) left_zergling_cnt++;
			//if (max_time < chk[i][j]) max_time = chk[i][j];
		}
	}
}

int main(void)
{
	// 여기서부터 작성

	int i, j;

	//freopen("in.txt", "r", stdin);
	// 세로 가로 맵 크기
	scanf("%d %d", &C, &R);

	for ( i = 1; i <=R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	// 방사능 시작 위치.
	scanf("%d %d", &sj, &si);


	max_time = BFS(si, sj , 3);
	Cal_Left_Zerglings();


	printf("%d\n%d", max_time, left_zergling_cnt);
	return 0;
}
#endif
