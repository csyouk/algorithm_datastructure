
// 문제 번호 W: [LAB]계단 오르기(BASIC)
#if 0
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
