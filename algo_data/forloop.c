#define _CRT_SECURE_NO_WARNINGS

// 문제 번호 A: [LAB]고기잡이
#if 0
#include <stdio.h>

int N, l, M;
int x[100 + 10], y[100 + 10];
int row[100 + 10], col[100 + 10];
int max, cnt_r, cnt_c;
int Find_Diff_Cnt(int *p, int n){
	int i, j, tmp, cnt = 0;
	for (i = 0; i < n; i++)
	{
		tmp = p[i];
		if (p[i] == -1) continue;
		for ( j = 0; j < n; j++)
		{
			if (p[j] == tmp) { p[j] = -1; }
		}
		cnt++;
	}
	return cnt;
}
int Catch_Fisn(int r, int c, int m, int n){
	int cnt = 0;
	int i, j;
	for (i = 0; i < cnt_r; i++)
	{
		if (row[m] <= row[i] && row[i] <= row[m] + r){
			for (j = 0; j < cnt_c; j++)
			{
				if (col[n] <= col[j] && col[j] <= col[n] + c){
					cnt++;
				}
			}
		}
	}
	return cnt;
}
void sort(int *p){
	int i, j, tmp;
	for ( i = 1; i <N-1; i++)
	{
		for ( j = i+1; j <N; j++)
		{
			if (p[i] > p[j]){
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}
int main(void)
{
	int i, fish;
	int r = 0, c,m,n,j, cnt;
	// 입력받는 부분
	scanf("%d %d %d", &N, &l, &M);

	for (i = 0; i<M; i++)
	{
		scanf("%d %d", &row[i], &col[i]);
		y[i] = row[i]; x[i] = col[i];
	}

	// 여기서부터 작성
	cnt_r = Find_Diff_Cnt(y, M);
	cnt_c = Find_Diff_Cnt(x, M);
	sort(row); sort(col);

	while (r != (l/2 -1))
	{
		r++; c = l / 2 - r;
		for ( m = 0; m < cnt_r; m++)
		{
			for ( n = 0; n < cnt_c; n++)
			{
				fish = Catch_Fisn(r, c, m, n);
				if (max < fish) max = fish;
			}
		}
	}


	// 출력하는 부분
	printf("%d", max);
	return 0;
}
#endif


#if 0
#include <stdio.h>
typedef struct _rod{
	int r, h;
} Rod;

int map[1010][1010];
int N;

int main(void){

	int i, j, r, len;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d %d", &r, &len);
		for ( j = 0; j < len; j++)
		{
			map[r][j] = 1;
		}
	}




	return 0;
}
#endif
