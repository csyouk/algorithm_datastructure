
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


//	보너스(약간개선)
#if 0
#include <stdio.h>
int N, M, a[10 + 10][10 + 10], b[10 + 10], chk[10 + 10], s[10 + 10];
int Check(int n, int m){
	int i;
	for (i = 1; i < n; i++){
		if (a[n][i] == 1 && m <= s[i]) return 0;	//	부하직원
		if (a[i][n] == 1 && m >= s[i]) return 0;	//	상사
	}
	return 1;
}
int DFS(int n){
	int i;
	if (n > N)	return 1;
	for (i = 1; i <= N; i++){
		if (chk[i] || Check(n, b[i]) == 0) continue;
		chk[i] = 1; s[n] = b[i];
		if (DFS(n + 1) == 1) return 1;
		chk[i] = 0;
	}
	return 0;
}
int main(void){
	int i, k, l, max = 0, maxi;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++){
		scanf("%d %d", &k, &l);
		a[k][l] = 1;
	}
	for (i = 1; i <= N; i++){
		scanf("%d", &b[i]);
		if (max < b[i]) {
			max = b[i]; maxi = i;
		}
	}
	s[1] = max; chk[maxi] = 1;
	if (DFS(2) == 1){
		for (i = 1; i <= N; i++) printf("%d ", s[i]);
	}
	else printf("-1");
	return 0;
}
#endif

//	보너스
#if 0
#include <stdio.h>
int N, M, a[10 + 10][10 + 10], b[10 + 10], chk[10 + 10], s[10 + 10];
int Check(int n, int m){
	int i;
	for (i = 1; i < n; i++){
		if (a[n][i] == 1 && m <= s[i]) return 0;	//	부하직원
		if (a[i][n] == 1 && m >= s[i]) return 0;	//	상사
	}
	return 1;
}
int DFS(int n){
	int i;
	if (n > N)	return 1;
	for (i = 1; i <= N; i++){
		if (chk[i] || Check(n, b[i]) == 0) continue;
		chk[i] = 1; s[n] = b[i];
		if (DFS(n + 1) == 1) return 1;
		chk[i] = 0;
	}
	return 0;
}
int main(void){
	int i, k, l;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++){
		scanf("%d %d", &k, &l);
		a[k][l] = 1;
	}
	for (i = 1; i <= N; i++)	scanf("%d", &b[i]);
	if (DFS(1) == 1){
		for (i = 1; i <= N; i++) printf("%d ", s[i]);
	}
	else printf("-1");
	return 0;
}
#endif
