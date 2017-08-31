// 하노이
//void Hanoi(int n, int s, int t, int e)
//{
//	if (n < 1) return;
//	Hanoi(n - 1, s, e, t);
//	printf("%d : %d -> %d\n", n, s, e);
//	Hanoi(n - 1, t, s, e);
//}




// 문제 번호 : [TST]미로 탈출 로봇
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 4
typedef struct _pos{
	int x;
	int y;
} Pos;

Pos S, E;

int map[SIZE][SIZE];
int chk[SIZE][SIZE];
int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };
int X, Y, min = 0x80000000;
void Init(void)
{
	int i, j;
	for (i = 0; i <SIZE; i++)
	{
		for (j = 0; j <SIZE; j++)
		{
			map[i][j] = -1;
		}
	}
}

//void Find(int i, int j, int dis)
//{
//	int ni, nj, k;
//	if (i == E.x && j == E.y) {
//		if (chk[i][j] == 0){
//			chk[i][j] = dis;
//		}
//		if (dis < chk[i][j]){
//			chk[i][j] = dis;
//		}
//		return;
//	}
//	map[i][j] = -1;
//	chk[i][j] = dis;
//
//
//	for ( k = 0; k < DIRS; k++)
//	{
//		ni = i + di[k]; nj = j + dj[k];
//		if (map[ni][nj] == 0 && chk[ni][nj] == 0)
//		{
//			Find(ni, nj, dis + 1);
//		}
//		if (chk[ni][nj] != 0 && chk[ni][nj] > chk[i][j])
//		{
//			Find(ni, nj, chk[i][j]+1);
//		}
//	}
//
//}

void Find_BruteForce(int x, int y)
{

}
int main(void)
{
	// 여기서부터 작성
	freopen("in.txt", "r", stdin);
	int x, y,i,j, dis= 0;
	Init();
	scanf("%d %d", &Y , &X);

	scanf("%d %d %d %d", &S.y, &S.x, &E.y, &E.x);

	for ( i = 1; i <=X; i++)
	{
		for ( j = 1; j <=Y; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}


	//Find(S.x, S.y, dis);
	Find_BruteForce(S.x, S.y);


	printf("%d", chk[E.x][E.y]);
	return 0;
}

#endif