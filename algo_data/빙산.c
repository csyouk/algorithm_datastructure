#define _CRT_SECURE_NO_WARNINGS

#if 01
#include <string.h>
#include <stdio.h>
#define DIRS 4
#define MAXQ 100000

typedef struct {
	int i, j;
} Cell;

Cell Q[MAXQ];
Cell out, in;

int RP, WP;

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

int R, C, min_time = 0, seg=1, all_melted;

int map[300 + 10][300 + 10];
int b_map[300 + 10][300 + 10];
int visited[300 + 10][300 + 10];

void BFS(int i, int j){
	int k, ni, nj;

	in.i = i; in.j = j;
	Q[WP++] = in;

	while (RP < WP)
	{
		out = Q[RP++];
		visited[out.i][out.j] = 1;
		for ( k = 0; k < DIRS; k++)
		{
			ni = out.i + di[k];   nj = out.j + dj[k];
			if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
			if (map[ni][nj] == 0) continue;
			if (visited[ni][nj]) continue;
			in.i = ni;     
			in.j = nj;
			Q[WP++] = in;
		}
	}
	
}

void melt(){

	int i, j, ni, nj, k, cnt;
	memcpy(b_map, map, sizeof(int [310][310]));


	for ( i = 1; i <= R; i++)
	{
		for ( j = 1; j <= C; j++)
		{
			if (map[i][j] == 0) continue;
			for (k = 0; k < DIRS; k++)
			{
				ni = i + di[k];   nj = j + dj[k];
				if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
				if (b_map[ni][nj] != 0) continue;
				map[i][j]--;
				if (map[i][j] < 0) map[i][j] = 0;
			}
		}
	}

	cnt = 0;
	for ( i = 1; i <= R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			if (map[i][j] == 0) cnt++;
		}
	}
	if (cnt == R*C) all_melted = 1;
	memset(visited, 0, sizeof(int[310][310]));
	RP = WP = 0;
}

void cal_time(){
	int i, j, cnt, flag;


	while (1)
	{
		flag = 0; cnt = 0; seg = 0;
		for (i = 1; i <= R; i++)
		{
			for (j = 1; j <= C; j++)
			{
				if (map[i][j] == 0 || visited[i][j]) continue;
				if (seg > 1) return;
				BFS(i, j);
				seg++;
			}
		}

		melt();
		min_time++;
		if (all_melted) {
			if (seg == 1) min_time = 0;
			return;
		}
	}
}

int main(void){
	int i, j;

	scanf("%d %d", &R, &C);
	for ( i = 1; i <= R; i++)
	{
		for ( j = 1; j <= C; j++)
		{
			scanf("%d ", &map[i][j]);
		}
	}


	cal_time();


	printf("%d", min_time);

	return 0;
}

#endif