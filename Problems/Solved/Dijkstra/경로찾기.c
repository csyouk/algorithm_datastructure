// 문제 번호 G: [TST]경로 찾기
#if 01
#include <stdio.h>
#define INF 0x7fffffff

int bits[1000 + 10][30 + 10], map[1000 + 10][1000 + 10];
int visited[1000 + 10], cost[1000 + 10], root[1000 + 10];
int N, K, S, E;

int H(int s, int e){
	int i, cnt = 0;
	for (i = 1; i <= K; i++)
	{
		if (bits[s][i] != bits[e][i]) cnt++;
	}
	return cnt++;
}

void Create_Map(void){
	int i, j;
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			if (i == j) continue;
			map[i][j] = map[j][i] = H(i, j);
		}
	}
}

void Dijkstra(int start){
	int cur = start, node, rep, min;

	visited[start] = 1; cost[cur] = 0; root[cur] = 0;

	for (rep = 1; rep <= N - 1; rep++)
	{
		// 최단 경로 업데이트.
		for (node = 1; node <= N; node++)
		{
			if (visited[node] || map[cur][node] == 0) continue;
			if (map[cur][node] != 1) continue;
			if (cost[node] > cost[cur] + map[cur][node]){
				cost[node] = cost[cur] + map[cur][node];
				root[node] = cur;
			}
		}

		// 최소 값 찾기.
		min = INF;
		for (node = 1; node <= N; node++){
			if (visited[node] || cost[node] == INF) continue;
			if (min > cost[node]){
				min = cost[node]; cur = node;
			}
		}
		visited[cur] = 1;
	}
}
void Find_Path(int end){
	int prev = root[end];
	if (prev == 0 && end == E) { printf("-1"); return; }
	if (end == 0) return;
	Find_Path(prev);
	printf("%d ", end);
}
int main(void){
	int i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= K; j++)
		{
			scanf("%1d", &bits[i][j]);
		}
		cost[i] = INF;
	}
	scanf("%d %d", &S, &E);


	Create_Map();

	Dijkstra(S);

	Find_Path(E);

	return 0;
}
#endif
