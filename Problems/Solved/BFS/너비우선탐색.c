
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
