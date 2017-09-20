#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 30
#define DIRS 4

typedef struct {
	int ri, rj;
	int bi, bj;
	int cnt, dis;
} Bead;

typedef struct {
	int i, j;
} Hall;

Bead bead;
Hall hall;

Bead Q[10000];

int rp, wp;
int T, R, C;
char Raw[SIZE][SIZE];
int map[SIZE][SIZE];
int visited[SIZE][SIZE];

int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };

void init(){
	int i, j;
	for ( i = 0; i < SIZE; i++)
	{
		for ( j = 0; j < SIZE; j++)
		{
			map[i][j] = visited[i][j] = 0;
		}
	}
	rp = wp = 0;
}

int re(char sym, int i, int j){
	switch (sym)
	{
	case '#': return 1;
	case '.': return 0;
	case 'R': 
		bead.ri = i; bead.rj = j;
		//visited[i][j] = 1;
		return 0;
	case 'B': 
		bead.bi = i; bead.bj = j;
		return 0;
	case 'H':
		hall.i = i; hall.j = j;
		return 0;
	default:
		break;
	}
	return - 10;
}

void gen(void){
	int i, j;
	for ( i = 1; i <= R; i++){
		for ( j = 1; j <= C; j++){
			map[i][j] = re(Raw[i][j], i, j);
		}
	}
}

int BFS(void){
	int k, nri,nrj, nbi,nbj;
	Bead out;

	Q[wp++] = bead;

	while (rp < wp)
	{
		out = Q[rp++];

		// 10회 이상 기울였으면 실패
		//if (out.cnt > 10) return -1;

		// 빨강공이 구멍에 들어갔으면 성공. 이동거리 리턴
		if ((out.ri == hall.i) && (out.rj == hall.j)) return out.dis;

		// 4방향으로 기울여본다.
		for (k = 0; k < DIRS; k++)
		{
			nri = out.ri + di[k];   nrj = out.rj + dj[k];
			nbi = out.bi + di[k];   nbj = out.bj + dj[k];

			// 파랑공이 홀로 빠지면 게임 종료이므로 건너뜀.	
			if (nbi == hall.i && nbj == hall.j) continue;

			// 이미 방문했던 곳은 건너뜀.
			//if (visited[nri][nrj]) continue;

			// 벽으로 막혀있으면, 움직이지 않는다. 
			if (map[nri][nrj]){ 
				nri = out.ri; 
				nrj = out.rj; 
			}

			if (map[nbi][nbj]){
				nri = out.bi; 
				nrj = out.bj; 
			}


			// 빨강, 파랑 공이 만나게 되는 경우는 종료되므로, 건너뛴다.
			if (nri == nbi && nrj == nbj) continue;

			//visited[nri][nrj] = 1;

			Q[wp].ri = nri;  
			Q[wp].rj = nrj;

			Q[wp].bi = nbi; 
			Q[wp].bj = nbj;

			Q[wp].cnt = out.cnt + 1;
			Q[wp].dis = out.dis + 1;

			wp++;
		}
	}

	return -1;
}

int main(void)
{
	int i;

	scanf("%d", &T);
	while (T--)
	{
		init();
		scanf("%d %d", &R, &C);
		for ( i = 1; i <= R; i++)
		{
			scanf("%s", &Raw[i][1]);
		}
		gen();
		printf("%d\n", BFS());
	}
	return 0;
}