







#if 0
#include <stdio.h>
#define NODE 7
#define EMPTY -1
int rear = -1;
int front = -1;
int Visit[NODE] = { 0 };
int Queue[NODE];

void EnQueue()


#endif





#if 0
#include <stdio.h>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define VISITED 1
#define N_VISITED 0
#define SIZE 30
int N;
int RP, WP;
int map[SIZE][SIZE], Q[SIZE], visit[SIZE];

void BFS(int v){

	int i;

	visit[v] = 1;
	printf("%d ", v);
	Q[WP++] = v;

	while (RP < WP){
		v = Q[RP++];
		for ( i = 1; i <= N ; i++){
			if (map[v][i] == VISITED && visit[i] == N_VISITED){
				visit[i] = 1;
				printf("%d ", i);
				Q[WP++] = i;
			}
		}
	}
}

int main(void){

	freopen("in.txt", "r", stdin);
	int start;
	int v1, v2;
	scanf("%d%d", &N, &start);

	while (1)
	{
		scanf("%d%d", &v1, &v2);
		if (v1 == -1 && v2 == -1) break;
		map[v1][v2] = map[v2][v1] = 1;
	}

	BFS(start);

	return 0;
}
#endif


#if 0
#include <stdio.h>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 110
#define VISITED 1
#define N_VISITED 0

int N, E, RP, WP;
int map[SIZE][SIZE];
int visited[SIZE];
int Q[SIZE];

void BFS(int start_node_id){

	int node, node_id;

	visited[start_node_id] = 1;
	printf("%d ", start_node_id);

	Q[WP++] = start_node_id;

	while (RP < WP)
	{
		node = Q[RP++];
		for (node_id = 1; node_id <= N; node_id++)
		{
			if (map[node][node_id] == VISITED && visited[node_id] == N_VISITED){
				visited[node_id] = VISITED;
				printf("%d ", node_id);
				Q[WP++] = node_id;
			}
		}
	}
}


int main(void)
{
	int i, v1, v2;
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &E);

	for ( i = 1; i <=N; i++)
	{
		scanf("%d %d", &v1, &v2);
		map[v1][v2] = i;
	}
	BFS(1);

	return 0;
}
#endif


// BFS 양방향 무가중치 그래프 탐색
#if 0
#include <stdio.h>
#define CONNECTION_SIZE 210
#define NODE_SIZE 110
#define VISITED 1
#define N_VISITED 0
typedef struct _connection{
	int s;
	int e;
} Conn;

// 커넥션 상태는 건드리지 말아야 한다.
Conn connections[CONNECTION_SIZE];

// 방문할 꼭지점만 큐에 저장한다.
int Q[CONNECTION_SIZE];

int visited[NODE_SIZE];
int N, E, RP, WP;

void BFS(int start_node){

	int tmp;
	int i;
	Q[WP++] = start_node;
	//printf("%d ", Q[RP]);
	visited[Q[RP]] = VISITED;

	while (RP < WP){
		tmp = Q[RP++];
		for (i = 1; i <=E; i++)
		{
			if (tmp == connections[i].s && visited[connections[i].e] == N_VISITED){
				//printf("%d ", connections[i].e);
				Q[WP++] = connections[i].e;
				visited[connections[i].e] = VISITED;
			}
			else if (tmp == connections[i].e && visited[connections[i].s] == N_VISITED)
			{
				Q[WP++] = connections[i].s;
				visited[connections[i].s] = VISITED;
			}
		}
	}
}

void PrintAll(void){

	int i;
	for ( i = 0; i <WP; i++)
	{
		printf("%d ", Q[i]);
	}

}

int main(void)
{
	int i;
	// 여기서부터 작성
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &E);

	for ( i = 1; i <=E; i++)
	{
		scanf("%d %d", &connections[i].s, &connections[i].e);
	}

	BFS(1);

	PrintAll();
	return 0;
}
#endif

#if 0
#include <stdio.h>
#define VERTICES 110
#define SIZE 200
#define N_VIS 0
#define VIS 1
#define CONNECTED 1
int Node, Connections;

int graph[VERTICES][VERTICES];
int visited[VERTICES];

int STACK[VERTICES];
int SP = -1;

void DFS(int start){
	int i;
	SP++;
	visited[start] = VIS;
	STACK[SP] = start;
	for ( i = 1; i <= Node; i++)
	{
		if (graph[start][i] == CONNECTED && visited[i] == N_VIS){
			DFS(i);
		}
	}

}

int main(void)
{
	//freopen("in.txt", "r", stdin);

	int i, v1, v2;
	scanf("%d", &Node);
	scanf("%d", &Connections);
	for (i = 1; i <= Connections; i++)
	{
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = 1;
	}

	DFS(1);

	printf("%d", SP);

	return 0;
}
#endif
