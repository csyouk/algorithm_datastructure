
// 문제 번호 : [TST]건물세우기(BASIC)
#if 0
#include <stdio.h>
#define SIZE 20
int N, min=0x7fffffff;
int flag, found;

int map[SIZE][SIZE];
int place[SIZE];
int order[SIZE];
int final_order[SIZE];

void DFS(int depth, int sum){
	int i;
	if (sum >= min) return;
	if (depth > N){
		if (sum < min) {
			min = sum;
			for ( i = 1; i <= N; i++)
			{
				final_order[i] = order[i];
			}
		}
		return;
	}
	for ( i = 1; i <= N; i++)
	{
		if (place[i]) continue;
		place[i] = 1; order[depth] = i;
		DFS(depth + 1, sum + map[depth][i]);
		place[i] = 0;
	}

}


int main(void){
	freopen("in.txt", "r", stdin);
	int i, j, sum=0, found, depth = 1;
	scanf("%d", &N);

	for ( i = 1; i <= N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			scanf("%d ", &map[i][j]);
		}
	}

	DFS(depth, sum);

	printf("%d\n", min);
	for ( i = 1; i <= N; i++)
	{
		printf("%d ", final_order[i]);
	}
	return 0;
}

#endif
