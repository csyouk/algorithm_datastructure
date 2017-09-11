
//문제 번호 T : [TST]지하철
#if 0
#include <stdio.h>
#define SIZE 110
#define INF 0x7fffffff
#define START 0

int map[SIZE][SIZE];
int visited[SIZE];
int cost[SIZE];
int path[SIZE];

int N, M;
void Find_Path(M){
	int prev = path[M];
	if (M == START) return;
	Find_Path(prev);
	printf("%d", M);
}

int Dijkstra(int start){
	int rep, node, min, cur = start, sum = 0;
	visited[cur] = 1; cost[cur] = 0; path[cur] = cost[cur];

	for ( rep = 1; rep <= N-1; rep++)
	{
		for ( node = 1; node <= N; node++)
		{
			if (visited[node]) continue;
			if (map[cur][node] == 0) continue;
			if (cost[node] > cost[cur] + map[cur][node]){
				cost[node] = cost[cur] + map[cur][node];
				path[node] = cur;
			}
		}

		min = INF;
		for ( node = 1; node <= N; node++)
		{
			if (visited[node]) continue;
			if (cost[node] == INF) continue;
			if (min > cost[node]){
				min = cost[node];
				cur = node;
			}
		}
		visited[cur] = 1;
	}

	return cost[M];
}

int main(void){

	freopen("in.txt", "r", stdin);

	int i, j;
	scanf("%d %d", &N, &M);

	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <=N; j++)
		{
			scanf("%d ", &map[i][j]);
		}
		cost[i] = INF;
	}


	printf("%d\n", Dijkstra(1));

	Find_Path(M);
	return 0;
}
#endif
