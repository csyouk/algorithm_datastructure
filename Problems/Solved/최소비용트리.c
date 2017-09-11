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
