#define _CRT_SECURE_NO_WARNINGS

#if 1
#include <stdio.h>
#define DIRS 4

typedef struct {
	int t;
	char dir;
} Behavior;

enum Object{W,N,E,S,FRUIT=2};


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
	sin.i = 1;  sin.j = 1;  sin.len = 1; sin.dir = E;
	SQ[swp++] = sin;
	map[1][1] = 1;

	while (1)
	{
		sout = SQ[srp++];
		bout = BQ[brp++];
		for (i = 0; i < bout.t; i++)
		{
			sout.i = sout.i + di[sout.dir];  sout.j = sout.j + dj[sout.dir]; 
			time++;
			if (sout.i < 1 || sout.i > N || sout.j < 1 || sout.j > N) return;
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