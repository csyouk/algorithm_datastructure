
// 문제 번호 N: [TST]최단 경로 찾기
#if 0
#include <stdio.h>
#define E_SIZE 10 + 10
#define INF 0x7fffffff
#define VISITED 1
#define NO_PATH 0

int map[E_SIZE][E_SIZE];
int cost[E_SIZE], visited[E_SIZE];

int N;

int Dijkstra(int start, int total_node){
	int cur, node, rep, min;
	cur = start; cost[cur] = 0; visited[cur] = VISITED;

	for ( rep = 1; rep <=N-1; rep++){
		for (node = 1; node <= N; node++){
			if (visited[node] || map[cur][node] == NO_PATH) continue;
			if (cost[node] > cost[cur] + map[cur][node]){
				cost[node] = cost[cur] + map[cur][node];
			}
		}

		min = INF;
		for ( node = 1; node <= total_node; node++){
			if (visited[node] || cost[node] == INF) continue;
			if (min > cost[node]){
				min = cost[node];
				cur = node;
			}
		}
		visited[cur] = VISITED;
	}

	return cost[total_node];
}

int main(void){
	freopen("in.txt", "r", stdin);
	int i, j;
	scanf("%d", &N);

	for ( i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%d", &map[i][j]);
		}
		cost[i] = INF;
	}

	printf("%d", Dijkstra(1, N));

	return 0;
}
#endif
