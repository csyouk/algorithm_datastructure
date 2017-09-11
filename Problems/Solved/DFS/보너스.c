
// 문제 번호 : [TST]보너스
#if 0
#include <stdio.h>
#define SIZE 20
#define CONN_SIZE 110
#define SUB 0
#define N_SUB 1
#define DONE 1

typedef struct {
	int s, e;
} Conn;

Conn cases[CONN_SIZE];
int bonus[SIZE], people[SIZE], result[SIZE];
int N, M, flag;


int is_i_sub(int n, int i){
	int j;

	for ( j = 1; j <= M; j++)
	{
		if (people[j]) continue;
		if (cases[j].s == n && cases[j].e == i) return SUB;
	}
	return N_SUB;
}

void DFS(int n){
	int i;
	if (flag) return;
	if (n > N) { flag = 1; return; }

	//for (i = 2; i <=M; i++)
	//{
	//	if (is_i_sub(n, i) == N_SUB) continue;
	//	result[i] = bonus[n+1];
	//	people[i] = DONE;
	//	DFS(n + 1);
	//}

}

void sort(int *p, int n){
	int i, j, tmp;
	for (i = 1; i <= n-1; i++)
	{
		for (j = i+1; j <= n; j++)
		{
			if (p[i] < p[j]) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}
int main(void){

	freopen("in.txt", "r", stdin);

	int i;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= M; i++) scanf("%d %d", &cases[i].s, &cases[i].e);
	for (i = 1; i <= N; i++) scanf("%d ", &bonus[i]);
	sort(bonus, N);

	for (i = 1; i <= N; i++) printf("%d ", result[i]);


	return 0;
}
#endif
