
// 문제 번호 : [TST]암소 미인 대회(Bronze)
#if 0
#include <stdio.h>
#define DIRS 4
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
typedef struct _pos{
	int x;
	int y;
} Pos;
Pos seg1[50 * 50];
Pos seg2[50 * 50];
Pos minseg1, minseg2;
int seg1cnt, seg2cnt;
int N, M, dis=0x7fffffff;
char farm[60][60];
int chk[60][60];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Fill(int i, int j, int mark)
{
	int k, ni, nj;
	if (chk[i][j] != 0) return;
	chk[i][j] = mark;
	if (mark == 1){
		seg1[seg1cnt].x = i;
		seg1[seg1cnt].y = j;
		seg1cnt++;
	}
	else if (mark == 2)
	{
		seg2[seg2cnt].x = i;
		seg2[seg2cnt].y = j;
		seg2cnt++;
	}
	for ( k = 0; k < DIRS; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (farm[ni][nj] == 'X'){
			Fill(ni, nj, mark);
		}
	}
}
int cal(void)
{
	int i, j,x,y;
	for ( i = 0; i <seg1cnt; i++)
	{
		for ( j = 0; j <seg2cnt; j++)
		{
			x = ABS( seg1[i].x - seg2[j].x );
			y = ABS( seg1[i].y - seg2[j].y );
			if (x + y < dis){
				minseg1.x = seg1[i].x;
				minseg1.y = seg1[i].y;

				minseg2.x = seg2[j].x;
				minseg2.y = seg2[j].y;
				dis = x + y;
			}
		}
	}
}
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int i, j, mark = 0, cnt=0;
	// 여기서부터 작성
	scanf("%d %d", &N, &M);

	for ( i = 1; i <=N; i++)
	{
		scanf("%s", &farm[i][1]);
	}

	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <=M; j++)
		{
			if (farm[i][j] == 'X' && chk[i][j] == 0)
			{
				mark++;
				Fill(i, j, mark);
			}
		}
	}
	cal();
	printf("%d", ABS(minseg2.x - minseg1.x) + ABS(minseg2.y - minseg1.y) - 1);

	return 0;
}
#endif
