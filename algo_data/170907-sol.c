#define _CRT_SECURE_NO_WARNINGS

//	휴대폰번호 정렬
#if 0
#include <stdio.h>
typedef struct{
	int n1, n2, n3, digit;
}P_t;
P_t a[50 + 10];
int N, p[10 + 10];
int cmp(int i, int j){
	if (p[a[i].n1 % 10] < p[a[j].n1 % 10]) return -1;
	if (p[a[i].n1 % 10] > p[a[j].n1 % 10]) return 1;

	if (a[i].digit > a[j].digit) return -1;
	if (a[i].digit < a[j].digit) return 1;

	if (a[i].n2 < a[j].n2) return -1;
	if (a[i].n2 > a[j].n2) return 1;

	if (a[i].n3 < a[j].n3) return -1;
	if (a[i].n3 > a[j].n3) return 1;

	return 0;
}
char str[50 + 10][13 + 10];
int main(void){
	int i, j, d;
	P_t t;
	scanf("%d", &N);
	for (i = 1; i <= 6; i++){
		scanf("%d", &d);
		p[d] = i;
	}
	for (i = 0; i < N; i++) scanf("%s", &str[i][0]);
	for (i = 0; i < N; i++){
		sscanf(str[i], "%d-%d-%d", &a[i].n1, &a[i].n2, &a[i].n3);
		if (str[i][12] == '\0') a[i].digit = 3;
		else a[i].digit = 4;
	}
	for (i = 0; i < N - 1; i++){	//	오름차순 정렬
		for (j = i + 1; j < N; j++){
			if (cmp(i, j) == 1){
				t = a[i]; a[i] = a[j]; a[j] = t;
			}
		}
	}
	for (i = 0; i < N; i++){
		if (a[i].digit == 3) printf("%03d-%03d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
		else printf("%03d-%04d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
	}
	return 0;
}
#endif

//	자외선을 피해 가기
#if 0
#include <stdio.h>
#define	INF	(100*100*10)
typedef struct{
	int i, j;
}Q_t;
Q_t Q[100 * 100 * 100 + 10];
int N, a[100 + 10][100 + 10], s[100 + 10][100 + 10];
int rp, wp;
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
int BFS(void){
	int ti, tj, ni, nj, k;
	Q[wp].i = 1; Q[wp++].j = 1; s[1][1] = a[1][1];
	while (rp < wp){
		ti = Q[rp].i; tj = Q[rp++].j;
		for (k = 0; k < 4; k++){
			ni = ti + di[k]; nj = tj + dj[k];
			if (ni<1 || ni>N || nj<1 || nj>N) continue;
			if (s[ni][nj]>s[ti][tj] + a[ni][nj]){
				s[ni][nj] = s[ti][tj] + a[ni][nj];
				Q[wp].i = ni; Q[wp++].j = nj;
			}
		}
	}
	return s[N][N];
}
int main(void){
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%1d", &a[i][j]); s[i][j] = INF;
		}
	}
	printf("%d", BFS());
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

//	계단 오르기(BASIC)
#if 0
#include <stdio.h>
int N, a[50 + 10], sol;
void DFS(int n, int cnt, int sum){
	if (n < 1){
		if (sol < sum) sol = sum;
		return;
	}
	if (cnt < 2) DFS(n - 1, cnt + 1, sum + a[n]);	//	밟는 경우
	if (cnt > 0) DFS(n - 1, 0, sum);	//	밟지 않는 경우
}
int main(void){
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &a[i]);
	DFS(N - 1, 1, a[N]);
	printf("%d", sol);
	return 0;
}
#endif

//	양팔저울(BASIC)
#if 0
#include <stdio.h>
int N, a[12 + 10], T, sol;
void DFS(int n, int l, int r){
	if (n > N){
		if (l == r) sol = 1;
		return;
	}
	DFS(n + 1, l + a[n], r);	//	left
	DFS(n + 1, l, r);					//	none
	DFS(n + 1, l, r + a[n]);		//	right
}
int main(void){
	int i, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &a[i]);
	scanf("%d", &T);
	while (T--){
		scanf("%d", &t);
		sol = 0;
		DFS(1, t, 0);
		if (sol == 1) printf("Y ");
		else printf("N ");
	}
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

//	회전 초밥(중)
#if 0
#include <stdio.h>
int N, d, k, c, sol, a[30000 + 10], cnt[3000 + 10];
int main(void){
	int i, total = 1;
	scanf("%d %d %d %d", &N, &d, &k, &c);
	cnt[c]++;
	for (i = 0; i < N; i++) scanf("%d", &a[i]);
	for (i = 0; i < N + k - 1; i++){
		if (++cnt[a[i%N]] == 1) total++;
		if (i >= k - 1){
			if (sol < total) sol = total;
			if (--cnt[a[i - k + 1]] == 0) total--;
		}
	}
	printf("%d", sol);
	return 0;
}
#endif

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
