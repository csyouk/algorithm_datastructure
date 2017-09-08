#define _CRT_SECURE_NO_WARNINGS
// 문제 번호 : [TST]최소 비용 트리
#if 0
#include <stdio.h>
#define SIZE 110
#define INF 0x7fffffff
#define NO_PATH 0

int N;
int cost[SIZE];
int check[SIZE];
int map[SIZE][SIZE];

int main(void){
	freopen("in.txt", "r", stdin);
	int i, j, k, sel, min, sum = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		for ( j = 1; j <= i; j++){
			scanf("%d ", &map[i][j]);
			map[j][i] = map[i][j];
		}
		cost[i] = INF;
	}

	sel = 1;
	check[sel] = 1;
	cost[sel] = 0;

	 // prim
	for (k = 1; k <= N; k++){
		for (i = 1; i <= N; i++){
			if (check[i] || map[sel][i] == 0) continue;
			if (cost[i] > map[sel][i]) {
				cost[i] = map[sel][i];
			}
		}

		min = INF;
		for (i = 1; i <= N; i++){
			if (check[i]) continue;
			if (min > cost[i]) { 
				min = cost[i]; 
				sel = i; 
			}
		}
		check[sel] = 1;
	}


	for (i = 1; i <= N; i++) sum += cost[i];
	

	printf("%d", sum);

	return 0;
}
#endif


// 문제 번호 : [TST]최소 비용 트리
#if 0
#include <stdio.h>
#define SIZE 110
#define NO_PATH 0
#define INF 0x7fffffff

int map[SIZE][SIZE];
int visited[SIZE];
int cost[SIZE]; // 1번 경로에서 2,3,... N번까지 가는 경로를 계산.
int root[SIZE]; // 경로를 확인하고 싶다면, 경로 배열을 만든다.
int N;

int costN[SIZE][SIZE]; // select를 k로 시작. k번 경로에서 나머지로 가는 경로 계산.
int costN[SIZE][SIZE];
int visitedN[SIZE][SIZE];

int main(void){
	freopen("in.txt", "r", stdin);
	int i, j, k, sel, min;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &map[i][j]);
		}
		cost[i] = INF;
	}

	sel = 1; visited[sel] = 1; cost[sel] = 0;

	for ( j = 1; j < N; j++){
		for ( i = 1; i <= N; i++){
			// 이미 갔거나, 경로에 길이 없을 경우는 제외한다.
			if (visited[i] || map[sel][i] == NO_PATH) continue;

			// 기존의 비용보다, 경유해서 가는 비용이 저렴하다면 그 값을 변경한다.
			if (cost[i] > cost[sel] + map[sel][i]) { 
				// 경로가 바뀌는 시점은 이곳이다.
				cost[i] = cost[sel] + map[sel][i]; 
				root[i] = sel; // 경로를 이 시점에서 확인할 수 있다.
			}
			//else{ 
			//	cost[i] = map[sel][i]; 
			//}
		}

		min = INF;
		for (i = 1; i <= N; i++)
		{
			// 이미 방문한 곳은 pass
			if (visited[i]) continue;
			if (min > cost[i]) { min = cost[i]; sel = i; }
		}
		visited[sel] = 1;
	}


	printf("%d", cost[N]);

	return 0;
}
#endif

// 문제 번호 : [TST]최소 비용 트리
#if 0
#include <stdio.h>
#define SIZE 100+10
#define VISIT 1
#define NO_PATH 0
#define INF 0x7fffffff

int map[SIZE][SIZE];
int cost[SIZE], visited[SIZE];
int N;

void Print_Cost(void){
	int i;
	for (i = 1; i <= N; i++) printf(" %d", cost[i]);
}

int Prim(int start, int total_node){
	int rep, node, current_node, min, sum=0;
	visited[start] = VISIT; cost[start] = 0;
	current_node = start;

	for (rep = 1; rep <= total_node - 1; rep++)
	{
		for (node = 1; node <= total_node; node++)
		{
			if (visited[node]) continue;
			if (map[current_node][node] == NO_PATH) continue;
			if (cost[node] > map[current_node][node]) {
				cost[node] = map[current_node][node];
			}
		}

		min = INF;
		for ( node = 1; node <= total_node; node++)
		{
			if (visited[node]) continue;
			if (cost[node] == INF) continue;
			if (min > cost[node]){
				min = cost[node];
				current_node = node;
			}
		}
		visited[current_node] = VISIT;
	}
	

	for (node = 1; node <=N; node++)
	{
		sum += cost[node];
	}
	return sum;
}
void Init(void){
	int i, j;
	// 연결 상태 저장.
	for (i = 1; i <= N; i++)
	{
		for ( j = 1; j <=i; j++)
		{
			scanf("%d", &map[i][j]);
			map[j][i] = map[i][j];
		}
		cost[i] = INF;
	}
}
int main(void){
	//freopen("in.txt", "r", stdin);
	int sel = 1;
	scanf("%d", &N);
	Init();

	printf("%d", Prim(sel, N));

	return 0;
}
#endif


// 문제 번호 P: [TST]최대신장트리
#if 0
#include <stdio.h>
#define NODE_SIZE 1000+10
#define INF 0x80000000
#define VISITED 1
#define N_VISTED 0
#define NO_PATH 0
#define ULL unsigned long long 

int N, M;
int map[NODE_SIZE][NODE_SIZE];
int visited[NODE_SIZE];
int cost[NODE_SIZE];
int edges[NODE_SIZE];

ULL Prim(int start, int total_node){
	int cur, rep, node, max;
	ULL sum = 0;
	cur = start; visited[cur] = VISITED; cost[cur] = 0;

	for ( rep = 1; rep <= total_node - 1; rep++)
	{
		for ( node = 1; node <= total_node; node++)
		{
			if (visited[node]) continue;
			if (map[cur][node] == NO_PATH) continue;
			if (cost[node] < map[cur][node]){
				cost[node] = map[cur][node];
			}
		}

		max = INF;
		for ( node = 1; node <= total_node; node++)
		{
			if (visited[node] || cost[node] == INF) continue;
			if (max < cost[node]){
				max = cost[node];
				cur = node;
			}
		}
		visited[cur] = VISITED;
	}

	for ( node = 1; node <= total_node; node++)
	{
		if (cost[node] != INF) sum += cost[node];
	}
	return sum;
}

void Init(int nodes){
	int i;
	for (i = 1; i <= nodes; i++) {
		cost[i] = INF;
		visited[i] = N_VISTED;
	}
}

int main(void){
	freopen("in.txt", "r", stdin);
	int i, s, e, w, result,  max = INF;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= M; i++)
	{
		scanf("%d %d %d", &s, &e, &w);
		if (map[s][e] < w) map[s][e] = map[e][s] = w;
	}

	for (i = 1; i <= N; i++)
	{
		Init(N);
		result = Prim(i, N);
		if (max < result) max = result;
	}
	printf("%llu", max);

	return 0;
}
#endif
