
// 문제 번호 : [TST]토마토(고)
#if 0
#include <stdio.h>
#define SIZE 1000
#define DIRS 4

typedef struct _data{
	int x;
	int y;
	int dis;
} Tomato;

int R, C, cooked_tomato, RP, WP;
int box[SIZE + 10][SIZE + 10];
int chk[SIZE + 10][SIZE + 10];

int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };
Tomato done[SIZE*SIZE];
Tomato Q[SIZE * SIZE + 10];


int BFS(void)
{
	Tomato tmp;
	int i, ni, nj, k;
	for (i = 0; i < cooked_tomato; i++)
	{
		Q[WP].x = done[i].x; Q[WP++].y = done[i].y; chk[done[i].x][done[i].y] = 1;
	}

	while (RP < WP)
	{
		tmp.x = Q[RP].x; tmp.y = Q[RP].y; tmp.dis = Q[RP++].dis;
		//if () return tmp.dis;
		for ( k = 0; k < DIRS; k++)
		{
			ni = tmp.x + di[k]; nj = tmp.y + dj[k];
			if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
			if (chk[ni][nj] || box[ni][nj] == -1) continue;
			Q[WP].x = ni;   Q[WP].y = nj;   Q[WP++].dis = tmp.dis + 1; chk[ni][nj] = 1;
		}
	}
	return tmp.dis;
	//printf("d");
}
int check_not_cooked_tomato(void)
{
	int i, j;
	for (i = 1; i <R + 1; i++)
	{
		for (j = 1; j < C + 1; j++)
		{
			if (chk[i][j] == 0) {
				return -1;
			}
		}
	}
	return 1;
}
int main(void)
{
	// 여기서부터 작성

	//freopen("in.txt", "r", stdin);

	int i, j, result, flag = 0;
	scanf("%d %d", &C, &R);
	for ( i = 1; i <=R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) {
				done[cooked_tomato].x = i;
				done[cooked_tomato].y = j;
				cooked_tomato++;
			}
			if (box[i][j] == -1){
				chk[i][j] = -1;
			}
		}
	}

	if (done[R*C - 1].x != 0) { printf("0"); return;}

	result = BFS();
	if (check_not_cooked_tomato() == -1) result = -1;


	printf("%d", result);



	return 0;
}
#endif
