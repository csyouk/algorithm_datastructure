// ���� ��ȣ : [TST]�ּ� ��� Ʈ��
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


// ���� ��ȣ : [TST]�ּ� ��� Ʈ��
#if 01
#include <stdio.h>
#define SIZE 110
#define NO_PATH 0
#define INF 0x7fffffff

int map[SIZE][SIZE];
int visited[SIZE];
int cost[SIZE]; // 1�� ��ο��� 2,3,... N������ ���� ��θ� ���.
int root[SIZE]; // ��θ� Ȯ���ϰ� �ʹٸ�, ��� �迭�� �����.
int N;

int costN[SIZE][SIZE]; // select�� k�� ����. k�� ��ο��� �������� ���� ��� ���.
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
			// �̹� ���ų�, ��ο� ���� ���� ���� �����Ѵ�.
			if (visited[i] || map[sel][i] == NO_PATH) continue;

			// ������ ��뺸��, �����ؼ� ���� ����� �����ϴٸ� �� ���� �����Ѵ�.
			if (cost[i] > cost[sel] + map[sel][i]) { 
				// ��ΰ� �ٲ�� ������ �̰��̴�.
				cost[i] = cost[sel] + map[sel][i]; 
				root[i] = sel; // ��θ� �� �������� Ȯ���� �� �ִ�.
			}
			//else{ 
			//	cost[i] = map[sel][i]; 
			//}
		}

		min = INF;
		for (i = 1; i <= N; i++)
		{
			// �̹� �湮�� ���� pass
			if (visited[i]) continue;
			if (min > cost[i]) { min = cost[i]; sel = i; }
		}
		visited[sel] = 1;
	}


	printf("%d", cost[N]);

	return 0;
}
#endif