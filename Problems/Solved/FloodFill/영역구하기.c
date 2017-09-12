
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
