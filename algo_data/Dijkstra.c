#define _CRT_SECURE_NO_WARNINGS

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


// 문제 번호 Q: [TST]페이지 전환
#if 0
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



// 문제 번호 G: [TST]경로 찾기
#if 0
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