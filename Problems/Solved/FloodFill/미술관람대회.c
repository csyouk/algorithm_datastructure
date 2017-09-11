
// 문제 번호 : [TST]미술관람 대회
#if 0
#include <stdio.h>
#define DIRECTIONS 4
int N;
char canvas[110][110];
int chk[110][110];

int di[DIRECTIONS] = {0,-1,0,1}; // 좌 상 우 하
int dj[DIRECTIONS] = {-1,0,1,0};

char Color[4] = "RGB";

void Fill(int i, int j, char target, int mark)
{
	int k, ni, nj;
	// 0 이 아니라는 뜻은 이미 체크가 끝났다는 뜻이다.
	if (chk[i][j] != 0) return;
	chk[i][j] = mark;

	for ( k = 0; k < DIRECTIONS; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (canvas[ni][nj] == target){
			Fill(ni, nj, target, mark);
		}
	}

}
void flush(void)
{
	for (int i = 0; i < N+1; i++)
	{
		for (int j = 0; j < N+1; j++)
		{
			chk[i][j] = 0;
		}
	}
}
void filter(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (canvas[i][j] == 'R')
			{
				canvas[i][j] = 'G';
			}
		}
	}
}
int main(void)
{
	freopen("in.txt", "r", stdin);
	int i, j, mark = 0, color;
	// 여기서부터 작성
	scanf("%d", &N);

	for ( i = 1; i <=N; i++)
	{
		scanf("%s", &canvas[i][1]);
	}

	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <=N; j++)
		{
			// 먼저 레드부터 작성.
			for ( color = 0; color < 3; color++)
			{
				if (canvas[i][j] == Color[color] && chk[i][j] == 0){
					mark++;
					Fill(i, j, Color[color], mark);
				}
			}
		}
	}
	printf("%d ", mark);

	mark = 0;
	flush();
	filter();
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			// 먼저 레드부터 작성.
			for (color = 0; color < 3; color++)
			{
				if (canvas[i][j] == Color[color] && chk[i][j] == 0){
					mark++;
					Fill(i, j, Color[color], mark);
				}
			}
		}
	}
	printf("%d", mark);

	return 0;
}
#endif
