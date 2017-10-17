#if 0
#include <stdio.h>
#include <stdlib.h>
#define DIRS 4
typedef struct {
	int i, j, cnt;
}Pos;
Pos p[250000];
int N, wp;
int map[502][502];
int cost[502][502];
int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };
int comp(const Pos * p1, const Pos * p2){
	return p1->cnt - p2->cnt;
}
void Input_Data(void){
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			p[wp].i = i; p[wp].j = j; p[wp++].cnt = map[i][j];
			cost[i][j] = 1;
		}
	}
	qsort(p, N*N, sizeof(Pos), comp);
	return;
}
void Make(){
	int i, k, ni, nj;
	for (i = 0; i < N*N; i++)
	{
		for (k = 0; k < DIRS; k++)
		{
			ni = p[i].i + di[k];  nj = p[i].j + dj[k];
			if ((map[ni][nj] > p[i].cnt) && (cost[ni][nj] < cost[p[i].i][p[i].j] + 1)){
				cost[ni][nj] = cost[p[i].i][p[i].j] + 1;
			}
		}
	}
}
int Find(){
	int i, j, max = (1 << 31);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (max < cost[i][j]) max = cost[i][j];
		}
	}
	return max;
}
int main(void){
	Input_Data();
	Make();
	printf("%d", Find());
	return 0;
}
#endif