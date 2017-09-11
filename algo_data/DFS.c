#define _CRT_SECURE_NO_WARNINGS




// [TST] 더하기
#if 0
#include <stdio.h>
int T, N, K;
int a[30];
int chk[30];

int Determine(int n, int sum){

	if (sum > K) return 0;
	if (n > N){
		if (sum == K) return 1;
		return 0;
	}

	if (Determine(n + 1, sum + a[n])) return 1;
	if (Determine(n + 1, sum)) return 1;
	return 0;
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	int i, j;
	// 여기서부터 작성
	scanf("%d", &T);
	for ( i = 1; i <= T; i++)
	{
		scanf("%d %d", &N, &K);
		for ( j = 1; j <= N; j++) scanf("%d", &a[j]);

		if (Determine(1, 0)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
#endif



// 문제 번호 L: [TST]보너스
#if 0
int main(void){

	return 0;
}
#endif

// 문제 번호 K: [TST]N QUEEN
#if 0
#include <stdio.h>
#define SIZE 23

int N, cnt;
int chkr[SIZE], chkdl[2 * SIZE], chkdr[2 * SIZE];

void DFS(int n){
	int i;
	if (n > N) { cnt++; return; }
	for (i = 1; i <= N; i++)
	{
		if (chkr[i] || chkdl[i - n + N] || chkdr[i+n]) continue;
		chkr[i] = chkdl[i - n + N] = chkdr[i + n] = 1;
		DFS(n + 1);
		chkr[i] = chkdl[i - n + N] = chkdr[i + n] = 0;
	}
}

int main(void){

	scanf("%d", &N);

	DFS(1);

	printf("%d", cnt);

	return 0;
}
#endif
