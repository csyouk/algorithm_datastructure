#define _CRT_SECURE_NO_WARNINGS
/*
철수의 동생이 다니는 학교에서는 ‘구슬 집어넣기 게임’ 선풍적인 인기를 끌고 있다.철수 동생은 반 친구들과 이 게임의 성적을 놓고 경쟁을 하고 있다.
어느 날, 철수의 동생이 시무룩한 얼굴을 하고 집에 들어왔다.친구들보다 좋은 성적을 내지 못했다고 우울했던 것이다.그래서 철수는 동생을 위해 게임에서 최고 성적을 내는 방법을 알려주는 프로그램을 만들기로 했다.
게임은 다음 룰에 의해 진행된다.

1.게임판에는 빨간구슬, 파란구슬, 벽, 그리고 목표구멍이 있다.
2. 플레이어는 총 10회 게임판을 기울일 수 있다. (방향 : 상하좌우)
3. 플레이어가 게임판을 기울이게 되면 해당 방향으로 빨간구슬과 파란구슬이 한 칸 이동한다.
4. 이동방향에 벽이 있는 구슬은 움직일 수 없다.
5. 이동 시 빨간 구슬과 파란 구슬이 같은 위치로 움직여 부딪히는 경우 구슬이 깨지므로, 게임 실패다.
6. 파란구슬이 목표구멍으로 들어가는 것은 게임 실패다.
7. 기울임 횟수가 10회를 넘어서면 게임 실패다.
8. 빨간 구슬이 목표구멍으로 들어가는 것이 이 게임의 목표이다.
9. 적은 횟수를 기울여 해결할수록 많은 높은 점수를 얻을 수 있다.

기본적으로 게임판의 가장자리는 구슬이 게임판 밖으로 빠져나가지 못하도록 벽으로 둘러쌓여 있다.

철수는 우선 이 게임에서 문제를 해결할 수 있는 가장 적은 횟수를 알고 싶다. 이를 출력하는 프로그램을 작성하시오.
*/
#include <stdio.h>




#if 0 // 큐 2개
#define SIZE 30
#define DIRS 4

typedef struct {
	int i, j;
	int cnt, dis;
} Bead;

Bead hall, red, blue, or, ob, inr, inb;
Bead Q[100000];

int T, R, C, RP, WP;

char Raw[SIZE][SIZE];
int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };

void init(){
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			map[i][j] = 0;
		}
	}
	RP = WP = 0;
}

int re(char sym, int i, int j){
	switch (sym)
	{
	case '#': return 1;
	case '.': return 0;
	case 'R':
		red.i = i; red.j = j;
		return 0;
	case 'B':
		blue.i = i; blue.j = j;
		return 0;
	case 'H':
		hall.i = i; hall.j = j;
		return 0;
	default:
		break;
	}
	return -10;
}

void gen(void){
	int i, j;
	for (i = 1; i <= R; i++){
		for (j = 1; j <= C; j++){
			map[i][j] = re(Raw[i][j], i, j);
		}
	}
}


int BFS(void){
	int k, ri, rj, bi, bj;

	Q[WP++] = red;
	Q[WP++] = blue;

	while (RP < WP)
	{
		or = Q[RP++];
		ob = Q[RP++];

		// 구멍에 들어가면 성공.
		if ((or.i == hall.i) && (or.j == hall.j)) return or.dis;

		for (k = 0; k < DIRS; k++)
		{
			ri = or.i + di[k];
			rj = or.j + dj[k];

			bi = ob.i + di[k];
			bj = ob.j + dj[k];

			if (map[ri][rj]){ ri = or.i; rj = or.j; }
			if (map[bi][bj]){ bi = ob.i; bj = ob.j; }

			// 빨강, 파랑 공이 만나게 되는 경우는 종료되므로, 건너뛴다.
			if (ri == bi && rj == bj) continue;
			if (visited[ri][rj]) continue;
			visited[ri][rj] = 1;
			Q[WP].i = ri + or.i;
			Q[WP].j = rj + or.j;
			Q[WP].cnt = or.cnt + 1;
			if (ri != or.i) Q[WP].dis = or.dis + 1;
			WP++;

			Q[WP].i = bi + ob.i;
			Q[WP].j = bj + ob.j;
			Q[WP].cnt = ob.cnt + 1;
			if(bi != ob.i) Q[WP].dis = ob.dis + 1;
			WP++;
		}
	}
}

int main(void)
{
	int i;

	scanf("%d", &T);
	while (T--)
	{
		init();
		scanf("%d %d", &R, &C);
		for (i = 1; i <= R; i++)
		{
			scanf("%s", &Raw[i][1]);
		}
		gen();
		printf("%d\n", BFS());
	}
	return 0;
}

#endif

// 하나의 큐에 빨강공과 파랑공의 위치를 한꺼번에 기록해서 관리함.
#if 0 // 실패한 방식
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
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
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
		visited[i][j] = 1;
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
	return -10;
}

void gen(void){
	int i, j;
	for (i = 1; i <= R; i++){
		for (j = 1; j <= C; j++){
			map[i][j] = re(Raw[i][j], i, j);
		}
	}
}

int BFS(void){
	int k, nri, nrj, nbi, nbj;
	Bead out;

	Q[wp++] = bead;

	while (rp < wp)
	{
		out = Q[rp++];

		// 10회 이상 기울였으면 실패
		if (out.cnt > 10) return -1;

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
			if (visited[nri][nrj]) continue;

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

			visited[nri][nrj] = 1;

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
		for (i = 1; i <= R; i++)
		{
			scanf("%s", &Raw[i][1]);
		}
		gen();
		printf("%d\n", BFS());
	}
	return 0;
}
#endif