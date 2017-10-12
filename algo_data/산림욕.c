#include <stdio.h>
#define DIRS 2
int N,max = -1;
int map[110][110];
int cost[110][110];
int di[DIRS] = {1,1};
int dj[DIRS] = {0,1};

void Input_Data(){
	int i, j;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (j > i) continue;
			scanf("%d", &map[i][j]);
		}
	}
	cost[1][1] = map[1][1];
}

void Find(){
	int i,j, ni,nj, k;

	for ( i = 1; i <= N; i++){
		for (j = 1; j <=i; j++)
		{
			for (k = 0; k < DIRS; k++)
			{
				ni = i + di[k];
				nj = j + dj[k];
				if (cost[ni][nj] < map[ni][nj] + cost[i][j]) cost[ni][nj] = map[ni][nj] + cost[i][j];
			}
		}
	}


	for ( k = 1; k <=N; k++)
	{
		if (max <= cost[N][k]) max = cost[N][k];
	}
}

int main(void){
	Input_Data();
	Find();
	printf("%d", max);

	return 0;
}