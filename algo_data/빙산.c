#define _CRT_SECURE_NO_WARNINGS

#if 01
#include <stdio.h>
#define DIRS 4
#define MAXQ 1000000

typedef struct {
	int i, j;
};

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

int R, C, min_time = 0x7fffffff, seg = 1;

int map[300 + 10][300 + 10];
int visited[300 + 10][300 + 10];

void BFS(int i, int j){

}

int find_time(){
	int i, j;
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (visited[i][j]) continue;
			BFS(i, j, seg);
			seg++;
			return min_time;
		}
	}
	return min_time;
}

int main(void){
	int i, j;

	scanf("%d %d", &R, &C);
	for ( i = 1; i <= R; i++)
	{
		for ( j = 1; j <= C; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}





	printf("%d", min_time);

	return 0;
}

#endif