#define _CRT_SECURE_NO_WARNINGS







//	최단 경로 찾기
#if 0
#include <stdio.h>
#define INF 0x7fff0000
int N, a[10 + 10][10 + 10], c[10 + 10], chk[10 + 10];
int r[10 + 10];
int main(void){
	int i, j, sel, min;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++) scanf("%d", &a[i][j]);
		c[i] = INF;
		r[i] = 1;
	}
	sel = 1; chk[1] = 1; c[1] = 0;
	for (j = 1; j <= N - 1; j++){
		for (i = 1; i <= N; i++){
			if (chk[i] || a[sel][i] == 0) continue;
			if (c[i] > c[sel] + a[sel][i]){
				c[i] = c[sel] + a[sel][i];
				r[i] = sel;
			}
		}
		min = INF;
		for (i = 1; i <= N; i++){
			if (chk[i]) continue;
			if (min > c[i]) { min = c[i]; sel = i; }
		}
		chk[sel] = 1;
	}
	printf("%d", c[N]);
	return 0;
}
#endif

//	최소 비용 트리
#if 0
#include <stdio.h>
#define INF 0x7fffffff
int N, a[100 + 10][100 + 10], c[100 + 10], chk[100 + 10], sol;
int main(void){
	int i, j, sel, min;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= i; j++){
			scanf("%d", &a[i][j]);
			a[j][i] = a[i][j];
		}
		c[i] = INF;
	}
	sel = 1; chk[1] = 1; c[1] = 0;
	for (j = 0; j < N - 1; j++){
		for (i = 1; i <= N; i++){
			if (chk[i] || a[sel][i] == 0) continue;
			if (c[i] > a[sel][i]) c[i] = a[sel][i];
		}
		min = 0x7fff0000;
		for (i = 1; i <= N; i++){
			if (chk[i]) continue;
			if (min > c[i]) { min = c[i]; sel = i; }
		}
		chk[sel] = 1;
	}
	for (i = 1; i <= N; i++) sol += c[i];
	printf("%d", sol);
	return 0;
}
#endif

//	돌다리 건너기(BASIC)
#if 0
#include <stdio.h>
char s[10 + 10], str[2 + 10][30 + 10];
int M, N, sol;
void DFS(int n, int cnt, int p){
	if (n >= N){
		if (cnt == M) sol++;
		return;
	}
	if (s[cnt] == str[p][n]) DFS(n + 1, cnt + 1, !p);	//	밟는경우
	DFS(n + 1, cnt, p);	//	밟지 않는 경우
}
int main(void){
	scanf("%s %s %s", &s[0], &str[0][0], &str[1][0]);
	for (M = 0; s[M]; M++);
	for (N = 0; str[0][N]; N++);
	DFS(0, 0, 0);
	DFS(0, 0, 1);
	printf("%d", sol);
	return 0;
}
#endif

//	N QUEEN
#if 0
#include <stdio.h>
int N, c1[12 + 10], c2[12 + 12 + 10], c3[12 + 12 + 10], sol;
void DFS(int n){
	int j;
	if (n > N){ sol++;	return; }
	for (j = 1; j <= N; j++){
		if (c1[j] || c2[n + j] || c3[n - j + 12]) continue;
		c1[j] = c2[n + j] = c3[n - j + 12] = 1;
		DFS(n + 1);
		c1[j] = c2[n + j] = c3[n - j + 12] = 0;
	}
}
int main(void){
	scanf("%d", &N);
	DFS(1);
	printf("%d", sol);
	return 0;
}
#endif

//	벽장문의 이동
#if 0
#include <stdio.h>
#define ABS(x)	((x)>0?(x):-(x))
int T, L, R, N, a[20 + 10], sol = 0x7fff0000;
void DFS(int n, int cnt, int l, int r){
	if (sol <= cnt) return;
	if (n > N){
		if (sol > cnt) sol = cnt;
		return;
	}
	DFS(n + 1, cnt + ABS(l - a[n]), a[n], r);	//	왼쪽
	DFS(n + 1, cnt + ABS(r - a[n]), l, a[n]);	//	오른쪽
}
int main(void){
	scanf("%d %d %d %d", &T, &L, &R, &N);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	DFS(1, 0, L, R);
	printf("%d", sol);
	return 0;
}
#endif

//	책꽂이
#if 0
#include <stdio.h>
int T, N, B, a[20 + 10], sol;
void DFS(int n, int sum){
	if (sol == 0 || sol <= sum - B) return;
	if (n > N){
		if (sum >= B && sol > sum - B) sol = sum - B;
		return;
	}
	DFS(n + 1, sum + a[n]);
	DFS(n + 1, sum);
}
int main(void){
	int i;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &N, &B);
		for (i = 1; i <= N; i++) scanf("%d", &a[i]);
		sol = 0x7fffffff;
		DFS(1, 0);
		printf("%d\n", sol);
	}
	return 0;
}
#endif

//	해밀턴 순환회로
#if 0
#include <stdio.h>
int N, a[12 + 10][12 + 10], chk[12 + 10], sol = 0x7fffffff;
void DFS(int n, int sum, int city){
	int i;
	if (sol <= sum) return;
	if (n >= N){
		if (sol > sum + a[city][1]) sol = sum + a[city][1];
		return;
	}
	for (i = 1; i <= N; i++){
		if (chk[i]) continue;
		chk[i] = 1;
		DFS(n + 1, sum + a[city][i], i);
		chk[i] = 0;
	}
}
int main(void){
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0) a[i][j] = 10000;
		}
	}
	chk[1] = 1;
	DFS(1, 0, 1);
	printf("%d", sol);
	return 0;
}
#endif

//	자동차경주대회(BASIC2)
#if 0
#include <stdio.h>
int D, N, d[50 + 10], t[50 + 10], sol = 0x7fffffff;
void DFS(int n, int sum, int dist){
	if (sol <= sum) return;
	if (n > N){
		if (sol > sum) sol = sum;
		return;
	}
	if (dist + d[n] <= D) DFS(n + 1, sum, dist + d[n]);	//	정비 받지 않는 경우
	DFS(n + 1, sum + t[n], d[n]);	//	정비 받는경우
}

int main(void){
	int i;
	scanf("%d %d", &D, &N);
	for (i = 0; i <= N; i++) scanf("%d", &d[i]);
	for (i = 1; i <= N; i++) scanf("%d", &t[i]);
	DFS(1, 0, d[0]);
	printf("%d", sol);
	return 0;
}
#endif

//	건물세우기(BASIC)
#if 0
#include <stdio.h>
int N, a[15 + 10][15 + 10], sol = 0x7fffffff;
int chk[15 + 10], s[15 + 10], ps[15 + 10];
void DFS(int n, int sum){
	int i;
	if (sol <= sum) return;
	if (n > N){
		if (sol > sum){
			sol = sum;
			for (i = 1; i <= N; i++) ps[i] = s[i];
		}
		return;
	}
	for (i = 1; i <= N; i++){
		if (chk[i] == 1) continue;
		chk[i] = 1;	s[n] = i;
		DFS(n + 1, sum + a[n][i]);
		chk[i] = 0;
	}
}
int main(void){
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++) scanf("%d", &a[i][j]);
	}
	DFS(1, 0);
	printf("%d\n", sol);
	for (i = 1; i <= N; i++) printf("%d ", ps[i]);
	return 0;
}
#endif

//	더하기(루프)
#if 0
#include <stdio.h>
int T, N, K, a[20 + 10];
int Find(void){
	int bit, sum, i;
	for (bit = 0; bit < (1 << N); bit++){
		sum = 0;
		for (i = 0; i < N; i++){
			if (bit & 1 << i) sum += a[i];
		}
		if (sum == K) return 1;
	}
	return 0;
}
int main(void){
	int i;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &N, &K);
		for (i = 0; i < N; i++) scanf("%d", &a[i]);
		if (Find() == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
#endif

//	더하기(재귀)
#if 0
#include <stdio.h>
int T, N, K, a[20 + 10];
int DFS(int n, int sum){
	if (n > N){
		if (sum == K) return 1;
		return 0;
	}
	if (DFS(n + 1, sum + a[n]) == 1) return 1;	//	포함시킬 경우
	if (DFS(n + 1, sum) == 1) return 1;	//	포함시키지 않을 경우
	return 0;
}
int main(void){
	int i;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &N, &K);
		for (i = 1; i <= N; i++) scanf("%d", &a[i]);
		if (DFS(1, 0) == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
#endif

//	주사위 던지기2
#if 0
#include <stdio.h>
int N, M, s[7 + 10];
void DFS(int n, int sum){
	int i;
	if (n > N){
		if (sum == M){
			for (i = 1; i <= N; i++) printf("%d ", s[i]);
			printf("\n");
		}
		return;
	}
	for (i = 1; i <= 6; i++){
		s[n] = i;
		DFS(n + 1, sum + i);
	}
}
int main(void){
	scanf("%d %d", &N, &M);
	DFS(1, 0);
	return 0;
}
#endif

//
#if 0
#include <stdio.h>
int main(void){

	return 0;
}
#endif
