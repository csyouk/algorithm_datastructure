
// 문제 번호 Q: [TST]페이지 전환
#if 01
#include <stdio.h>
#define NODE_SIZE 500 + 10
#define PAGES 500+10
#define N_VISITED 0
#define VISITED 1
#define INF 0x7fffffff
#define NO_PATH 0
#define NO_PAGE 0

int N, P;
int map[NODE_SIZE][NODE_SIZE];
int visited[NODE_SIZE];
int cost[NODE_SIZE];
int Pages[PAGES];

void Init(void){
	int i;
	for ( i = 1; i <= N; i++){
		visited[i] = N_VISITED;
		cost[i] = INF;
	}
}

int Dijkstra(int start){
	int  rep, min, node, sum = 0, cur = start;
	visited[cur] = VISITED; cost[cur] = 0;

	for ( rep = 1; rep <= N-1; rep++)
	{
		for ( node = 1; node <= N; node++)
		{
			if (visited[node] || map[cur][node] == NO_PATH) continue;
			if (cost[node] > cost[cur] + map[cur][node]){
				cost[node] = cost[cur] + map[cur][node];
			}
		}

		min = INF;
		for (node = 1; node <= N; node++)
		{
			if (visited[node] || cost[node] == INF) continue;
			if (min > cost[node]){
				min = cost[node];
				cur = node;
			}
		}
		visited[cur] = VISITED;
	}


	for (node = 1; node <= N; node++) {
		if (cost[node] != INF) sum += cost[node];
	}
	return sum;
}

int main(void){

	//freopen("in.txt", "r", stdin);

	int i, s, e, sum=0;
	float result;
	scanf("%d", &N);
	for ( i = 1; i <= N; i++)
	{
		scanf("%d %d", &s, &e);
		map[s][e] = 1;
		Pages[s]++; Pages[e]++;
	}

	for (i = 0; i <PAGES; i++)
	{
		if (Pages[i] != NO_PAGE) P++;
	}

	for (i = 1; i <=N; i++)
	{
		Init();
		sum += Dijkstra(i);
	}

	result = (float)sum / (P*(P-1));

	printf("%.3f", result);

	return 0;
}
#endif
