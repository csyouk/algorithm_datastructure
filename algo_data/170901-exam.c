#if 0
#include <stdio.h>
int N, extra;
int main(void)
{
	int quot, i, stu, apple;

	//freopen("in.txt", "r", stdin);

	scanf("%d", &N);

	for ( i = 0; i < N; i++)
	{
		scanf("%d %d", &stu, &apple);
		if (stu == 0){
			extra += apple;
			continue;
		}
		quot = apple / stu;
		if (quot != 0){
			extra += apple % (quot * stu);
		}
		else {
			extra += apple % stu;
		}

	}

	printf("%d", extra);

	return 0;
}
#endif


// 문제 번호 B: [TST]체스판
#if 0
#include <stdio.h>

int R, C, A, B;
char chess[110][110];

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int I, J, i, j;
	scanf("%d %d", &R, &C);
	scanf("%d %d", &A, &B);

	// 큰 체스판 칠하기
	for ( I = 0; I < R; I++)
	{
		for ( J = 0; J < C; J++)
		{

			// 격자 칠하기
			for ( i = I*A; i < I * A + A; i++)
			{
				for ( j = J*B; j < J * B + B; j++)
				{
					if ((I + J) % 2 == 0) chess[i][j] = 'X';
					else  chess[i][j] = '.';
				}
			}


		}
	}



	// 칠하기
	for ( i = 0; i <R*A; i++)
	{
		printf("%s\n", chess[i]);
	}

	return 0;
}
#endif


// 문제 번호 C: [TST]주사위
#if 0
#include <stdio.h>
int N1, N2, N3;
int sum[20 * 20 * 40 + 10];
int main(void)
{

	//freopen("in.txt", "r", stdin);

	int i, j, k, max = 0x80000000, index;
	scanf("%d %d %d", &N1, &N2, &N3);

	for ( i = 1; i <=N1; i++)
	{
		for ( j = 1; j <=N2; j++)
		{
			for ( k = 1; k <=N3; k++)
			{
				sum[i + j + k]++;
			}
		}
	}

	for (i = 0; i < (20 * 20 * 40 + 9); i++)
	{
		if (max < sum[i]){
			max = sum[i];
			index = i;
		}
	}


	printf("%d", index);

	return 0;
}
#endif


// 문제 번호 D: [TST]저글링 방사능 오염
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 4
typedef struct _zergling{
	int x;
	int y;
	int sec;
} Zergling;
int R, C;
int si, sj, left_zergling_cnt, max_time;
int map[SIZE][SIZE];
int chk[SIZE][SIZE];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1, 0,1,0};

Zergling Q[SIZE*SIZE];
int RP, WP;

int BFS(int i, int j, int sec){
	Zergling tmp;
	int k, ni, nj;

	Q[WP].x = i; Q[WP].y = j; Q[WP++].sec = 3;

	while (RP < WP)
	{
		tmp.x = Q[RP].x; tmp.y = Q[RP].y; tmp.sec = Q[RP++].sec; chk[tmp.x][tmp.y] = tmp.sec;
		// 반환 조건.//
		//if (chk[tmp.x][tmp.y] != 0) return tmp.sec;

		for ( k = 0; k < DIRS; k++)
		{
			ni = tmp.x + di[k];   nj = tmp.y + dj[k];
			if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
			if (chk[ni][nj] != 0) continue;
			if (map[ni][nj] == 1 && chk[ni][nj] == 0){
				Q[WP].x = ni; Q[WP].y = nj; Q[WP++].sec = tmp.sec + 1; chk[ni][nj] = tmp.sec + 1;
			}

		}
	}
	return tmp.sec;
}

void Cal_Left_Zerglings(void){
	int i, j;
	for ( i = 1; i <=R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			if (map[i][j] == 1 && chk[i][j] == 0) left_zergling_cnt++;
			//if (max_time < chk[i][j]) max_time = chk[i][j];
		}
	}
}

int main(void)
{
	// 여기서부터 작성

	int i, j;

	//freopen("in.txt", "r", stdin);
	// 세로 가로 맵 크기
	scanf("%d %d", &C, &R);

	for ( i = 1; i <=R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	// 방사능 시작 위치.
	scanf("%d %d", &sj, &si);


	max_time = BFS(si, sj , 3);
	Cal_Left_Zerglings();


	printf("%d\n%d", max_time, left_zergling_cnt);
	return 0;
}
#endif

// 문제 번호 E: [TST]영역 구하기
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 4

typedef struct _seg{
	int id;
	int cnt;
} Seg;

int C, R, Num_Of_Square;
int Num_Of_Segments;
int area[SIZE][SIZE];
int chk[SIZE][SIZE];
Seg segments[SIZE*SIZE];

int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };

void Fill(int i, int j, int id)
{
	int k, ni, nj;
	if (area[i][j] == 1) return;
	chk[i][j] = id;
	segments[id].cnt++;

	for ( k = 0; k < DIRS; k++)
	{
		ni = i + di[k];     nj = j + dj[k]; 
		if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
		if (area[ni][nj] == 1 || chk[ni][nj] != 0) continue;
		Fill(ni, nj, id);
	}
}

void Sort_And_Print(){
	int i, j;
	Seg tmp;
	for ( i = 1; i <= Num_Of_Segments - 1; i++)
	{
		for ( j = i+1; j <= Num_Of_Segments; j++)
		{
			if (segments[i].cnt > segments[j].cnt){
				tmp = segments[i];
				segments[i] = segments[j];
				segments[j] = tmp;
			}
		}
	}
	printf("%d\n", Num_Of_Segments);
	for ( i = 1; i <=Num_Of_Segments; i++)
	{
		printf("%d ", segments[i].cnt);
	}
}
void Init(void){
	for (int i = 0; i < SIZE*SIZE; i++)
	{
		segments[i].id = i;
	}
}
int main(void)
{
	int i, j,k, lx,ly,rx,ry, id = 1;
	Init();
	//freopen("in.txt", "r", stdin);


	scanf("%d %d %d", &C, &R, &Num_Of_Square);

	for ( i = 1; i <=Num_Of_Square; i++)
	{
		scanf("%d %d %d %d", &lx, &ly, &rx, &ry);

		for ( j = lx+1; j <= rx; j++)
		{
			for ( k = ly+1; k <= ry; k++)
			{
				area[j][k] = 1;
			}
		}
	}
	
	for ( i = 1; i <= R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			if (area[i][j] == 1 || chk[i][j] != 0) continue;
			Fill(i, j, id);
			id++;
			Num_Of_Segments++;
		}
	}

	Sort_And_Print();


	return 0;
}
#endif


#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 4
typedef struct _path{
	int x;
	int y;
	int uv_size;
} UV;

int map[SIZE][SIZE];
int uv_cur[SIZE][SIZE];
int N, RP, WP;

int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };

UV Q[SIZE*SIZE];

UV s, e;

void Init(void){
	s.x = 1; s.y = 1;
	e.x = N; e.y = N;
}
void BFS(){


	UV tmp;
	int k, ni, nj;

	Q[WP++] = s;

	while (RP < WP)
	{
		tmp = Q[RP++];
		if (tmp.x == e.x && tmp.y == e.y) return;

		for (k = 0; k < DIRS; k++)
		{
			ni = tmp.x + di[k];   nj = tmp.y + dj[k];

			if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
			if (uv_cur[ni][nj] == 0){
				uv_cur[ni][nj] = tmp.uv_size + map[ni][nj];
			}
			if (uv_cur[ni][nj] == 0){

				Q[WP].x = ni; Q[WP].y = nj; Q[WP].uv_size = map[tmp.x][tmp.y];
				if (uv_cur[ni][nj]){
					if (uv_cur[ni][nj] > uv_cur[tmp.x][tmp.y] + map[ni][nj])
					{
						uv_cur[ni][nj] = uv_cur[tmp.x][tmp.y] + map[ni][nj];
					}

					WP++;
					continue;
				}
				uv_cur[ni][nj] = tmp.uv_size + map[ni][nj];

				WP++;
			}

		}
	}
}
int main(void)
{
	// 여기서부터 작성
	int i, j;

	//freopen("in.txt", "r", stdin);

	scanf("%d", &N);
	Init();
	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <=N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	BFS();

	printf("%d", uv_cur[N][N]);

	return 0;
}
#endif

#if 1
#include <stdio.h>
int N, M;
int gcd(a, b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main(void)
{
	int i;
	scanf("%d %d", &N, &M);

	printf("%d", M - gcd(N,M));
	return 0;
}
#endif