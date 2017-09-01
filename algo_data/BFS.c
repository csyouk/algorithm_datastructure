// 문제 번호 : [TST]미로 탈출 로봇
#if 0
#include <stdio.h>
#define EMPTY 0
#define SIZE 110
#define DIRS 4

typedef struct _data{
	int x;
	int y;
	int dis;
} QData;

QData Q[SIZE * SIZE];
QData S, E;

int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };

int map[SIZE][SIZE];
int chk[SIZE][SIZE];

int WP = EMPTY;
int RP = EMPTY;

int X, Y;

int BFS(int x, int y, int d)
{
	QData tmpQ;
	int k, ni, nj;
	// 초기화,  체크 배열에 방문을 했다는 것을 표시한다. WP를 증가시킨다.
	// 오류를 줄이기 위해서 한 줄에 다 적는다.
	Q[WP].x = x; Q[WP].y = y; Q[WP].dis = d; chk[x][y] = 1; WP++;

	while (RP < WP)
	{
		// 큐에서 하나 꺼냄.
		tmpQ.x = Q[RP].x; tmpQ.y = Q[RP].y; tmpQ.dis = Q[RP].dis; RP++;
		if (tmpQ.x == E.x && tmpQ.y == E.y) {
			return tmpQ.dis;
		}

		// x,y를 중심으로 상하좌우를 체크해본다.
		for ( k = 0; k < DIRS; k++){
			ni = tmpQ.x + di[k]; nj = tmpQ.y + dj[k];
			// 배열 밖인지 체크한다.
			if (ni < 1 || ni > X || nj < 1 || nj > Y) continue;
			if (map[ni][nj] != 0 || chk[ni][nj] != 0) continue;
			Q[WP].x = ni;  Q[WP].y = nj;  Q[WP].dis = tmpQ.dis + 1;  chk[ni][nj] = 1; WP++;

		}
	}
}


int main(void)
{
	//freopen("in.txt", "r", stdin);
	// 여기서부터 작성
	int x, y,i,j,d = 0;
	scanf("%d %d", &Y, &X);

	scanf("%d %d %d %d", &S.y, &S.x, &E.y, &E.x);

	for (i = 1; i <= X; i++)
	{
		for (j = 1; j <= Y; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}






	printf("%d", BFS(S.x,S.y, d));


	return 0;
}

#endif


// 문제 번호 : [TST]장기
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 8
typedef struct _data{
	int x;
	int y;
	int dis;
}QData;
QData Q[SIZE*SIZE];
int N, M, R, C, S, K;
int map[SIZE][SIZE];
int chk[SIZE][SIZE];
int di[DIRS] = {-1,-2,-2,-1, 1, 2, 2, 1};
int dj[DIRS] = {-2,-1, 1, 2, 2, 1,-1,-2};

int WP, RP;

int BFS(void)
{
	QData tmp;
	int k, ni,nj;
	Q[WP].x = R; Q[WP].y = C; Q[WP++].dis = 0; chk[R][C] = 1;

	while (RP < WP)
	{
		tmp.x = Q[RP].x; tmp.y = Q[RP].y; tmp.dis = Q[RP++].dis;
		if (tmp.x == S && tmp.y == K){
			return tmp.dis;
		}
		for ( k = 0; k < DIRS; k++)
		{
			ni = tmp.x + di[k]; nj = tmp.y + dj[k]; 
			if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
			if (chk[ni][nj] != 0) continue;
			Q[WP].x = ni; Q[WP].y = nj; Q[WP++].dis = tmp.dis + 1; chk[ni][nj] = 1;
		}
	}
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	// 여기서부터 작성
	scanf("%d %d %d %d %d %d", &N, &M, &R, &C, &S, &K);

	printf("%d", BFS());

	return 0;
}
#endif


// 문제 번호 : [TST]토마토(고)
#if 0
#include <stdio.h>
#define SIZE 1000
#define DIRS 4

typedef struct _data{
	int x;
	int y;
	int dis;
} Tomato;

int R, C, cooked_tomato, RP, WP;
int box[SIZE + 10][SIZE + 10];
int chk[SIZE + 10][SIZE + 10];

int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };
Tomato done[SIZE*SIZE];
Tomato Q[SIZE * SIZE + 10];


int BFS(void)
{
	Tomato tmp;
	int i, ni, nj, k;
	for (i = 0; i < cooked_tomato; i++)
	{
		Q[WP].x = done[i].x; Q[WP++].y = done[i].y; chk[done[i].x][done[i].y] = 1;
	}

	while (RP < WP)
	{
		tmp.x = Q[RP].x; tmp.y = Q[RP].y; tmp.dis = Q[RP++].dis; 
		//if () return tmp.dis;
		for ( k = 0; k < DIRS; k++)
		{
			ni = tmp.x + di[k]; nj = tmp.y + dj[k];
			if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
			if (chk[ni][nj] || box[ni][nj] == -1) continue;
			Q[WP].x = ni;   Q[WP].y = nj;   Q[WP++].dis = tmp.dis + 1; chk[ni][nj] = 1;
		}
	}
	return tmp.dis;
	//printf("d");
}
int check_not_cooked_tomato(void)
{
	int i, j;
	for (i = 1; i <R + 1; i++)
	{
		for (j = 1; j < C + 1; j++)
		{
			if (chk[i][j] == 0) {
				return -1;
			}
		}
	}
	return 1;
}
int main(void)
{
	// 여기서부터 작성

	//freopen("in.txt", "r", stdin);

	int i, j, result, flag = 0;
	scanf("%d %d", &C, &R);
	for ( i = 1; i <=R; i++)
	{
		for ( j = 1; j <=C; j++)
		{
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) {
				done[cooked_tomato].x = i;
				done[cooked_tomato].y = j;
				cooked_tomato++;
			}
			if (box[i][j] == -1){
				chk[i][j] = -1;
			}
		}
	}

	if (done[R*C - 1].x != 0) { printf("0"); return;}

	result = BFS();
	if (check_not_cooked_tomato() == -1) result = -1;


	printf("%d", result);



	return 0;
}
#endif


//문제 번호 : [TST]너비우선탐색Ⅰ
#if 0
#include <stdio.h>
#define SIZE 110
#define NOT_VISITED 0
#define EMPTY 0
#define VISITED 1
typedef struct _node{
	int id;
	int connected_nodes_size;
	int connected_node_ids[SIZE];
	int visited;
} Node;

Node nodes[SIZE];
Node Queue[SIZE*SIZE];

int Node_Size, Edge_Size;
int RP, WP;

void Init(void){
	for (int i = 0; i < SIZE; i++)
	{
		nodes[i].id = i;
		nodes[i].visited = NOT_VISITED;
	}
}
void BFS(int start_node_id){

	Node tmp;
	int i, node_id;
	// 일단 큐에 데이터를 넣는다.
	Queue[WP] = nodes[start_node_id];
	Queue[WP].visited = VISITED;
	WP++;

	while (RP < WP){
		tmp = Queue[RP];
		nodes[tmp.id].visited = VISITED;
		RP++;
		for ( i = 0; i < tmp.connected_nodes_size; i++){
			node_id = tmp.connected_node_ids[i];
			if (nodes[node_id].visited == VISITED) continue;
			Queue[WP++] = nodes[node_id];
		}
	}
}

void PrintAll(void){
	for (int i = 0; i < SIZE; i++)
	{
		if (Queue[i].id == 0) return;
		printf("%d ", Queue[i].id);
	}
}

int main(void)
{
	int i, j, start_node, end_node, nodeid, tmp;
	Init();

	freopen("in.txt", "r", stdin);

	scanf("%d %d", &Node_Size, &Edge_Size);

	for ( i = 1; i <=Node_Size; i++){
		scanf("%d %d", &start_node, &end_node);
		if (end_node < start_node){
			tmp = start_node;
			start_node = end_node;
			end_node = tmp;
		}
		for ( j = 0; j < SIZE; j++)
		{
			if (nodes[start_node].connected_node_ids[j] == EMPTY) {
				nodes[start_node].connected_node_ids[j] = end_node;
				nodes[start_node].connected_nodes_size++;
				break;
			}
		}
	}

	BFS(1);

	PrintAll();

	return 0;
}
#endif


// 문제 번호 : [TST]안전 영역
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 8

typedef struct _data{
	int x;
	int y;
	int dis;
} Area;

int map[SIZE][SIZE];
int chk[SIZE][SIZE];

Area Q[SIZE*SIZE];
int WP, RP, N;

int cal(void)
{
	int i, j, cnt = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (chk[i][j]) cnt++;
		}
	}
	return cnt;
}
int main(void)
{
	// 여기서부터 작성
	int i, j;
	scanf("%d", &N);

	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}


	return 0;
}

#endif


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


