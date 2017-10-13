#include <stdio.h>
#define DIRS 4
#define MAX_Q 200000

typedef struct{
	int i, j, dis;
} Pos;

Pos Q[MAX_Q];
Pos s, e;
int R, C, rp, wp;

char map[4010][4010];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Input_Data(void){
	int i, j, flag[2] = { 0 };
	scanf("%d %d", &R, &C);
	for (i = 1; i <= R; i++)
	{
		scanf("%s", &map[i][1]);
	}
	for ( i = 1; i <=R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			if (map[i][j] == 'S'){
				s.i = i; s.j = j; s.dis = 0;
				flag[0] = 1;
				if (flag[0] && flag[1]) return;
			}
			if (map[i][j] == 'G'){
				e.i = i; e.j = j;
				flag[1] = 1;
				if (flag[0] && flag[1]) return;
			}
		}
	}
}

int BFS(void){
	Pos in, out;
	int k, ni, nj;
	Q[wp++] = s;
	map[s.i][s.j] = '#';
	while (rp != wp)
	{
		out = Q[rp++];
		if (rp % MAX_Q == 0) rp = 0;
		if (out.i == e.i && out.j == e.j) return out.dis;
		for ( k = 0; k < DIRS; k++)
		{
			ni = out.i + di[k];
			nj = out.j + dj[k];
			if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
			if (map[ni][nj] == '#') continue;
			map[ni][nj] = '#';

			in.i = ni;  in.j = nj;
			Q[wp] = in; Q[wp++].dis = out.dis + 1;
			if (ni == e.i && nj == e.j) return out.dis + 1;
			if (wp % MAX_Q == 0) wp = 0;
		}
	}
	return -1;
}

int main(void){

	Input_Data();
	printf("%d", BFS());

	return 0;
}
