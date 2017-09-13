// 문제 번호 : [TST] 연결된 세포
#if 0
#include <stdio.h>
int R, C, mark=1;
int cell[12][12];
int chk[12][12];
int di[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; // 상하 좌우, 밑2개 위 2개
int dj[] = { 0, 0, -1, 1, -1, 1, -1, 1 }; // 상하 좌우, 밑2개 위 2개
int cnt[12*12/2];

void Fill(int i, int j, int mark)
{
	int k, ni, nj;
	if (chk[i][j] == 1) return;
	chk[i][j] = 1;
	cnt[mark]++;
	for ( k = 0; k < 8; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (cell[ni][nj] == 1){
			Fill(ni, nj, mark);

		}
	}
}
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int i, j, max=0x80000000;
	scanf("%d %d", &R, &C);
	for (i = 1; i <= R; i++){
		for ( j = 1; j <= C; j++){
			scanf("%d", &cell[i][j]);
		}
	}

	for ( i = 1; i <= R; i++){
		for ( j = 1; j <= C; j++){
			if (cell[i][j] == 1 && chk[i][j] == 0){
				Fill(i, j, mark); mark++;
			}
		}
	}

	for ( i = 1; i <= mark; i++)
	{
		if (max < cnt[i]) max = cnt[i];
	}

	printf("%d", max);

	return 0;
}
#endif
