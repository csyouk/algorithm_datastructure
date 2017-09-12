
// 문제 번호 : [TST]그래프 칠하기
#if 0
#include <stdio.h>
#define SIZE 22
int N, M, flag;
int map[SIZE][SIZE];

int node[SIZE];
int color[SIZE];

int Check(int n, int c){
	int n_i;
	if (flag) return;
	for (n_i = 1; n_i <= N; n_i++){
		if (map[n_i][n] == 0) continue;
		if (color[n_i] == c) return 1;
	}
	return 0;
}

void DFS(int n ){
	int c;
	if (flag) return;
	if (n > N){
		flag = !flag;
		return;
	}

	for (c = 1; c <= M; c++){
		if (Check(n, c)) continue;
		color[n] = c;
		DFS(n + 1);
		if(flag == 0) color[n] = 0;
	}
}

int main(void){

	freopen("in.txt", "r", stdin);

	int i, j;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++){
		for ( j = 1; j <= i; j++)
		{
			scanf("%d", &map[i][j]);
			map[j][i] = map[i][j];
		}
	}

	DFS(1);
	if (flag){ for (i = 1; i <= N; i++) printf("%d ", color[i]); }
	else printf("-1");

	return 0;
}
#endif



//	그래프 칠하기
#if 0
#include <stdio.h>
int N, M, a[12 + 10][12 + 10], s[12 + 10];
int Check(int n, int c){
	int i;
	for (i = 1; i < n; i++){
		if (a[n][i] == 1 && s[i] == c) return 0;
	}
	return 1;
}
int DFS(int n){
	int i;
	if (n > N)	return 1;
	for (i = 1; i <= M; i++){
		if (Check(n, i) == 0) continue;
		s[n] = i;
		if (DFS(n + 1) == 1) return 1;
	}
	return 0;
}
int main(void){
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= i; j++) scanf("%d", &a[i][j]);
	}
	if (DFS(1) == 0) printf("-1");
	else{
		for (i = 1; i <= N; i++) printf("%d ", s[i]);
	}
	return 0;
}
#endif
