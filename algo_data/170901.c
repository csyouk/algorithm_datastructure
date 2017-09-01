#if 0
#include <stdio.h>
#define SIZE 110
#define YES 1

typedef struct _computer{
	int id;
	int connected_computer_size;
	int connected_computer_ids[SIZE];
	int infected;
} Computer;

Computer computers[SIZE];
Computer Q[SIZE*SIZE];

int C, Pair, RP, WP;

void Init(void){
	for (int i = 0; i < SIZE; i++)
	{
		computers[i].id = i;
	}
}

void BFS(int start_computer_id){

	Computer tmp;
	int i;
	Q[WP] = computers[start_computer_id];
	computers[start_computer_id].infected = YES;
	WP++;

	while (RP < WP)
	{
		tmp = Q[RP++];
		for ( i = 0; i < tmp.connected_computer_size; i++)
		{
			if (computers[tmp.connected_computer_ids[i]].infected) continue;
			Q[WP] = computers[tmp.connected_computer_ids[i]];
			computers[tmp.connected_computer_ids[i]].infected = YES;
			WP++;
		}
	}
}

int main(void)
{
	// 여기서부터 작성
	int s, e;
	Init();

	freopen("in.txt", "r", stdin);

	scanf("%d %d", &C, &Pair);
	for (int i = 0; i < Pair; i++)
	{
		scanf("%d %d", &s, &e);
		for (int j = 0; j < SIZE; j++)
		{
			if (computers[s].connected_computer_ids[j]) continue;
			computers[s].connected_computer_ids[j] = e;
			computers[s].connected_computer_size++;
			break;
		}
	}


	BFS(1);

	printf("%d", WP - 1);


	return 0;
}
#endif


