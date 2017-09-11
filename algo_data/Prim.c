#define _CRT_SECURE_NO_WARNINGS



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
