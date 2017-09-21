#if 1
#include <stdio.h>
#define SIZE 1000 + 10
#define MAXQ (SIZE * SIZE * 10)
#define DIRS 4
#define BLOCK -9
#define PATH 0

#pragma warning(disable:4996)

typedef struct {
	int i, j;
	int min, hp;
} Rat;

typedef struct {
	int i, j;
	int hp;
} Cheese;

Rat rat, out, in;
Rat Q[SIZE * SIZE * 10];

int R, C, N, RP, WP;

char Raw[SIZE][SIZE];
int map[SIZE][SIZE];
int visited[SIZE][SIZE];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

Cheese cheese[10 + 10];



int replace(char sym, int i, int j){
	int pos;
	switch (sym)
	{
		case 'S': 
			rat.i = i; rat.j = j; rat.hp = 1;
			visited[i][j] = 1;
			return 0;
		case '.': return PATH;
		case 'X': return BLOCK;
		default : 
			pos = sym - '0';
			cheese[pos].i = i;
			cheese[pos].j = j;
			cheese[pos].hp = pos;
			return 0;
	}
	return 0;
}

void conv(void){

	int i, j;
	for ( i = 1; i <=R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			map[i][j] = replace(Raw[i][j], i, j);
		}
	}
}

void flush_vis(void){
	memset(visited, 0, sizeof(int [SIZE][SIZE]) );
	RP = WP = 0;
}

int BFS(){
	int k, ni, nj, target = 1;
	Q[WP++] = rat;

	while (RP < WP)
	{
		out = Q[RP++];
		if (RP)
		if (out.hp == cheese[target].hp && 
			out.i == cheese[target].i &&
			out.j == cheese[target].j  
			)
		{
			flush_vis(out.i, out.j);
			out.hp++;
			Q[WP++] = out;
			if (target == N) return out.min;
			target++;
			out = Q[RP++];
		}

		for ( k = 0; k < DIRS; k++)
		{
			ni = out.i + di[k];   nj = out.j + dj[k];

			if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
			if (map[ni][nj] == BLOCK) continue;
			if (visited[ni][nj] == 1) continue; 

			visited[ni][nj] = 1;

			in.i = ni;   in.j = nj;
			in.min = out.min + 1;
			in.hp = out.hp;
			Q[WP++] = in;
		}
	}

	return -1;
}

int main(void){
	int i;
	scanf("%d %d %d", &R, &C, &N);

	for ( i = 1; i <= R; i++) scanf("%s", &Raw[i][1]);

	conv();

	printf("%d", BFS());
	return 0;
}
#endif