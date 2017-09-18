#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 20+10
#define DIRS 4
typedef struct {
	int ri, rj, rdis;
	int bi, bj, bdis;
} Bead;

typedef struct {
	int i, j;
} Hall;

Bead Q[SIZE * SIZE];
Bead bead;
Hall hall;
int T, R, C,RP,WP;

char raw[SIZE][SIZE];
int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void init(){
	int i, j;
	for ( i = 0; i <SIZE; i++)
	{
		for ( j = 0; j <SIZE; j++)
		{
			visited[i][j] = 0;
		}
	}
}
int replace(char sym,int i, int j){
	switch (sym)
	{
	case '#': return 1;
	case '.': return 0;
	case 'H': (hall.i = i, hall.j = j); return -1;
	case 'B': (bead.bi = i, bead.bj = j); return 2;
	case 'R': (bead.ri = i, bead.rj = j); return 3;
	default: break;
	}
}

void convert(){
	int i, j;
	for (i = 1; i <=R; i++)
	{
		for (j = 1; j <=C; j++)
		{
			map[i][j] = replace(raw[i][j], i, j);
		}
	}
}



int BFS(){
	int k, nri, nrj, nbi, nbj;
	Bead out, in;
	Q[WP++] = bead;
	visited[bead.ri][bead.rj] = 1;

	while (RP < WP)
	{
		out = Q[RP++];
		if (out.rdis > 10) continue;
		if (out.ri == hall.i && out.rj == hall.j) return out.rdis;
		for (k = 0; k < DIRS; k++)
		{
			nri = out.ri + di[k]; nrj = out.rj + dj[k];
			
			//nbi = out.bi + di[k]; nbj = out.bj + dj[k];
			// 파랑공 nbi,nbj 위치 계산하기.
			// 벽을 만나는 경우 위치를 움직이지 않는다.
			//if (map[nbi][nbj]) { nbi = out.bi; nbj = out.bj; }
			if (nri < 1 || nri > R || nrj < 1 || nrj > C) continue;
			if (visited[nri][nrj]) continue;
			if (map[nri][nrj]) continue;
			//두 공이 만나는 경우.
			//if (nri == nbi || nrj == nbj) continue;
			// 파랑공이 홀로 빠지는 경우.
			//if (nbi == hall.i && nbj == hall.j) continue;
			// 파랑공이 범위를 벗어나는 경우.
			//if (nbi < 1 || nbi > R || nbj < 1 || nbj > C) continue;

			visited[nri][nrj] = 1;
			in.ri = nri;  in.rj = nrj;  in.rdis = out.rdis + 1;
			//in.bi = nbi;  in.bj = nbj;
			Q[WP++] = in;
		}
	}
	// 불가능한 경우.
	return -1;
}
int main(void){
	int i, j;
	scanf("%d", &T);

	for (i = 1; i <=T; i++)
	{
		init();
		scanf("%d %d", &R, &C);
		for ( j = 1; j <=R; j++){
			scanf("%s", &raw[j][1]);
		}
		convert();
		printf("%d\n", BFS());
	}

	return 0;
}