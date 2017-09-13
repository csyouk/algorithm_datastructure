
// [TST]단지 번호붙이기
#if 0
#include <stdio.h>
int N, mark;
int c[30][30];
int chk[30][30];
int cnt[30 * 30 / 2];
int di[] = { -1, 1, 0, 0}; // 상하 좌우
int dj[] = { 0, 0, -1, 1 }; // 상하 좌우

void Fill(int i, int j, int mark)
{
	int k, ni, nj;
	if (chk[i][j] == 1) return;
	chk[i][j] = 1;
	cnt[mark]++;
	for ( k = 0; k < 4; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (c[ni][nj] == 1){
			Fill(ni, nj, mark);
		}
	}
}

int main(void)
{
	// 여기서부터 작성
	freopen("in.txt", "r", stdin);
	int i, j, tmp;

	scanf("%d", &N);
	for ( i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%1d", &c[i][j]);
		}
	}

	for ( i = 1; i <=N; i++){
		for ( j = 1; j <=N; j++){
			if (c[i][j] == 1 && chk[i][j] == 0){
				Fill(i, j, mark); mark++;
			}
		}
	}

	for (i = 0; i < mark-1; i++)
	{
		for ( j = i+1; j < mark; j++)
		{
			if (cnt[i] > cnt[j]){
				tmp = cnt[i];
				cnt[i] = cnt[j];
				cnt[j] = tmp;
			}
		}
	}

	printf("%d\n", mark);
	for ( i = 0; i < mark; i++)
	{
		printf("%d\n", cnt[i]);
	}

	return 0;
}
#endif
