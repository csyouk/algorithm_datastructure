
// 문제 번호 W: [LAB]계단 오르기(BASIC)
#if 01
#include <stdio.h>

int s[50 + 10];
int N, max = 0x80000000;

// 경계조건이 문제였다.
// N번째 있는 계단을 무조건 밟는 다는 가정하에 짠다.
// N -> N-1 -> N-2 ...
void DFS(int n, int step, int sum){
	if (n < 1){
		if (max < sum) max = sum;
		return;
	}
	if (step < 2) DFS(n - 1, step + 1, sum + s[n]);
	if (step > 0) DFS(n - 1, 0, sum);
}

int main(void){
	freopen("in.txt", "r", stdin);
	int i;
	scanf("%d", &N);
	for ( i = 1; i <= N; i++)
	{
		scanf("%d", &s[i]);
	}
	//DFS(N-1, 1, s[N]);
	DFS(N, 0, 0);

	printf("%d", max);

	return 0;
}
#endif


// 문제 번호 W: [LAB]계단 오르기(BASIC)
#if 0
#include <stdio.h>

int score[50 + 10];
int N, max = 0x80000000;

void DFS(int n, int sum, int step){
	if (step > 2) return;
	if (n > N){
		if (max < sum) max = sum;
		return;
	}
	DFS(n + 1, sum + score[n], step + 1);
	DFS(n + 1, sum, 0);
}

int main(void){
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &score[i]);
	}
	DFS(0, 0, 0);

	printf("%d", max);

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
