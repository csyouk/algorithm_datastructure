// 문제 번호 : [TST]미로 탈출 로봇
#if 0
#include <stdio.h>
#define EMPTY 0
#define SIZE 110
#define DIRS 4

typedef struct _data{
	int x;
	int y;
	int dis;
} QData;

QData Q[SIZE * SIZE];
QData S, E;

int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };

int map[SIZE][SIZE];
int chk[SIZE][SIZE];

int WP = EMPTY;
int RP = EMPTY;

int X, Y;

int BFS(int x, int y, int d)
{
	QData tmpQ;
	int k, ni, nj;
	// 초기화,  체크 배열에 방문을 했다는 것을 표시한다. WP를 증가시킨다.
	// 오류를 줄이기 위해서 한 줄에 다 적는다.
	Q[WP].x = x; Q[WP].y = y; Q[WP].dis = d; chk[x][y] = 1; WP++;

	while (RP < WP)
	{
		// 큐에서 하나 꺼냄.
		tmpQ.x = Q[RP].x; tmpQ.y = Q[RP].y; tmpQ.dis = Q[RP].dis; RP++;
		if (tmpQ.x == E.x && tmpQ.y == E.y) {
			return tmpQ.dis;
		}

		// x,y를 중심으로 상하좌우를 체크해본다.
		for ( k = 0; k < DIRS; k++){
			ni = tmpQ.x + di[k]; nj = tmpQ.y + dj[k];
			// 배열 밖인지 체크한다.
			if (ni < 1 || ni > X || nj < 1 || nj > Y) continue;
			if (map[ni][nj] != 0 || chk[ni][nj] != 0) continue;
			Q[WP].x = ni;  Q[WP].y = nj;  Q[WP].dis = tmpQ.dis + 1;  chk[ni][nj] = 1; WP++;

		}
	}
}


int main(void)
{
	//freopen("in.txt", "r", stdin);
	// 여기서부터 작성
	int x, y,i,j,d = 0;
	scanf("%d %d", &Y, &X);

	scanf("%d %d %d %d", &S.y, &S.x, &E.y, &E.x);

	for (i = 1; i <= X; i++)
	{
		for (j = 1; j <= Y; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}






	printf("%d", BFS(S.x,S.y, d));


	return 0;
}

#endif


// 문제 번호 : [TST]장기
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 8
typedef struct _data{
	int x;
	int y;
	int dis;
}QData;
QData Q[SIZE*SIZE];
int N, M, R, C, S, K;
int map[SIZE][SIZE];
int chk[SIZE][SIZE];
int di[DIRS] = {-1,-2,-2,-1, 1, 2, 2, 1};
int dj[DIRS] = {-2,-1, 1, 2, 2, 1,-1,-2};

int WP, RP;

int BFS(void)
{
	QData tmp;
	int k, ni,nj;
	Q[WP].x = R; Q[WP].y = C; Q[WP++].dis = 0; chk[R][C] = 1;

	while (RP < WP)
	{
		tmp.x = Q[RP].x; tmp.y = Q[RP].y; tmp.dis = Q[RP++].dis;
		if (tmp.x == S && tmp.y == K){
			return tmp.dis;
		}
		for ( k = 0; k < DIRS; k++)
		{
			ni = tmp.x + di[k]; nj = tmp.y + dj[k]; 
			if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
			if (chk[ni][nj] != 0) continue;
			Q[WP].x = ni; Q[WP].y = nj; Q[WP++].dis = tmp.dis + 1; chk[ni][nj] = 1;
		}
	}
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	// 여기서부터 작성
	scanf("%d %d %d %d %d %d", &N, &M, &R, &C, &S, &K);

	printf("%d", BFS());

	return 0;
}
#endif


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


//문제 번호 : [TST]너비우선탐색Ⅰ
#if 1
int main(void)
{

	return 0;
}
#endif


// 문제 번호 : [TST]안전 영역
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 8

typedef struct _data{
	int x;
	int y;
	int dis;
} Area;

int map[SIZE][SIZE];
int chk[SIZE][SIZE];

Area Q[SIZE*SIZE];
int WP, RP, N;

int cal(void)
{
	int i, j, cnt = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (chk[i][j]) cnt++;
		}
	}
	return cnt;
}
int main(void)
{
	// 여기서부터 작성
	int i, j;
	scanf("%d", &N);

	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}


	return 0;
}

#endif