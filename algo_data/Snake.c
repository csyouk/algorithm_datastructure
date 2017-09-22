#define _CRT_SECURE_NO_WARNINGS

#if 0
#include <stdio.h>
#define DIRS 4

typedef struct {
	int t;
	char dir;
} Behavior;

enum Object{w,n,e,s,SNAKE=1,FRUIT=2};


typedef struct {
	int i, j;
	int len;
	int dir;
} Snake;

Behavior BQ[10000 + 10];

// Circular Queue를 쓴다. 끊김 없이 계속 돌아다닐 수 있으므로.
Snake SQ[10000];
Snake sout, sin;
Behavior bout, bin;


int N, K, L;
int fi, fj;
int brp, bwp;
int srp, swp;
int time = 0; 

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

int map[100 + 10][100 + 10];


int conv(char dir){

	if (dir == 'D'){ return 1; }
	return  -1;
}

void Game(void){
	int i;

	// init
	sin.i = 1;  sin.j = 1;  sin.len = 1; sin.dir = e;
	SQ[swp++] = sin;
	map[1][1] = 1;

	while (1){
		
		bout = BQ[brp++];
		for (i = 0; i < bout.t; i++)
		{
			sout = SQ[srp++];
			sout.i = sout.i + di[sout.dir];  sout.j = sout.j + dj[sout.dir]; 
			time++;

			map[sout.i][sout.j] = 1;
			sin.i = sout.i; sin.j = sout.j; sin.dir = sout.dir; sin.len = sout.len;
			SQ[swp++] = sin;
			//가장자리 침범시 게임 끝
			if (sout.i < 1 || sout.i > N || sout.j < 1 || sout.j > N) return;
			//몸통 부딪힐 시 게임 끝
			if (map[sout.i][sout.j] == SNAKE) return;
			if(map[sout.i][sout.j] != FRUIT)map[sout.i - di[sout.dir]][sout.j - dj[sout.dir]] = 0;
		}
		sout.dir += conv(bout.dir);
	}
}

int main(void){
	int i;
	scanf("%d", &N);
	scanf("%d", &K);
	for ( i = 1; i <= K; i++)
	{
		scanf("%d %d", &fi, &fj);
		map[fi][fj] = FRUIT;
	}

	scanf("%d", &L);
	for ( i = 1; i <= L; i++) { scanf("%d %c", &BQ[bwp].t, &BQ[bwp++].dir); }

	Game();

	printf("%d", time);

	return 0;
}

#endif