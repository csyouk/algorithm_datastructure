#define _CRT_SECURE_NO_WARNINGS

#if 01
#include <stdio.h>
#define DIRS 3
#define MAXQ 1000000
enum Object{Blank, Enemy, Star};

typedef struct {
	int i, j;
	int score;
} Airplane;

Airplane Q[MAXQ];
Airplane out, in;

int RP, WP, flag, total_star_cnt;

int di[DIRS] = {-1,-1,-1};
int dj[DIRS] = {-1, 0, 1};

int T, max=0x80000000;

char Raw[13 + 10][5 + 10];
int map[13 + 10][5 + 10];
int replace(char sym){
	switch (sym)
	{
		case '0': return Blank;
		case 'X': return Enemy;
		case '*':
			total_star_cnt++;
			return Star;
	}
	return Blank;
}

void convert(){
	int i, j;
	for ( i = 1; i <=13; i++)
	{
		for ( j = 1; j <= 5; j++)
		{
			map[i][j] = replace(Raw[i][j]);
		}
	}
}

void BFS(int i, int j){
	if (flag) return;
	int k, ni, nj;

	Q[WP].i = i;
	Q[WP].j = j;
	Q[WP++].score = 0;

	while (RP < WP)
	{
		out = Q[RP++];
		if (RP % MAXQ == 0) RP = 0;
		if (out.i == 1) {
			if (max < out.score) { max = out.score; }
			if (max == total_star_cnt * 10) {
				flag = 1;
				return;
			}
			continue;
		}
		for (k = 0; k < DIRS; k++)
		{
			ni = out.i + di[k];
			nj = out.j + dj[k];
			in.score = out.score;
			if (nj < 1 || nj > 5) continue;
			if (map[ni][nj] == Star) in.score += 10;
			if (map[ni][nj] == Enemy) in.score -= 7;
			in.i = ni; in.j = nj;
			Q[WP++] = in;
			if (WP % MAXQ == 0) WP = 0;
		}
	}
}

void Bomb(int r){
	int i, j;
	for ( i = r; i < r+ 5; i++)
	{
		for ( j = 1; j < 5; j++)
		{
			if (map[i][j] == Enemy) map[i][j] = Blank;
		}
	}
}

int main(void){
	int i, j;
	scanf("%d", &T);
	for ( j = 1; j <= T; j++)
	{
		for (i = 1; i <= 13; i++)
		{
			scanf("%s", &Raw[i][1]);
		}
		for ( i = 1; i <= 9; i++)
		{
			convert();
			Bomb(i);
			BFS(13, 3);
			RP = WP = 0;
		}
		printf("%d\n", max);
		flag = 0; max = 0x80000000;
	}

	return 0;
}

#endif
