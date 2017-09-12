
// 문제 번호 : [TST] 더하기
#if 0
/*
덧셈을 못하는 철수를 공부시키기 위해 자연수들을 주고, 그 중에 몇 개의 수를 골라서 그 합이 K가 될 수 있는지 알아보라고 시켰다. 철수 어머니가 자연수들을 무작위로 선택해서 본인도 가능한지 아닌지 모르고 있다. 어머니가 채점을 할 수 있게 주어진 문제의 답을 찾아주자.
입력
첫 번째 줄에 테스트 케이스 개수 T(1≤T≤10)가 주어진다.
두 번째 줄부터 아래 내용이 T개 만큼 주어진다.
첫 줄에 자연수 개수 N(5 <= N <= 20)과 K(1 <= K <= 2,000,000)가 공백으로 구분되어 입력된다.
다음 줄에 N개의 자연수 di(1 <= di <= 100,000)가 공백으로 구분되어 입력된다.
출력
T줄에 걸쳐 각 테스트 케이스 별로 주어진 자연수 중 몇 개의 합이 K가 되면 “YES”를 아니면 “NO”를 출력한다.
*/
#include <stdio.h>
int T, N, K, sol;
int a[20 + 10];
void DFS(int n, int sum){
	if (n > N){
		if (sum == K) sol = 1;
		return;
	}
	DFS(n + 1, sum + a[n]); // 포함 시킬 경우.
	DFS(n + 1, sum);        // 포함 안시킬 경우.
}


int main(void)
{
	freopen("in.txt", "r", stdin);
	int i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &K);
		for ( i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
		}
		sol = 0;
		DFS(1, 0);
		if (sol) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

#endif

// 더하기 다르게 풀기.
#if 0
#include <stdio.h>
int T, N, K, sol;
int a[20 + 10];
void DFS(int n, int sum){
	if (sum > K) return; // 가지치기
	if (n > N){
		if (sum == K) sol = 1;
		return;
	}
	DFS(n + 1, sum + a[n]); // 포함 시킬 경우.
	DFS(n + 1, sum);        // 포함 안시킬 경우.
}


int main(void)
{
	freopen("in.txt", "r", stdin);
	int i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &K);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
		}
		sol = 0;
		DFS(1, 0);
		if (sol) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
#endif

// 탐색 더 안하기.
#if 0
#include <stdio.h>
int T, N, K, sol;
int a[20 + 10];
void DFS(int n, int sum){
	if (sum > K || sol == 1) return; // 가지치기, 탐색 더 안하기.
	if (n > N){
		if (sum == K) sol = 1;
		return;
	}
	DFS(n + 1, sum + a[n]); // 포함 시킬 경우.
	DFS(n + 1, sum);        // 포함 안시킬 경우.
}


int main(void)
{
	freopen("in.txt", "r", stdin);
	int i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &K);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
		}
		sol = 0;
		DFS(1, 0);
		if (sol) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
#endif

#if 0
// return 값으로 사용
#include <stdio.h>
#define FOUND 1
#define N_FOUND 0
int T, N, K, sol;
int a[20 + 10];

int DFS(int n, int sum){
	if(sum > K) return 0; // 들어가도 되고 안들어가도 되고.
	if (n > N){
		if (sum == K) return 1;
		return 0;
	}
	if (DFS(n + 1, sum + a[n])) return 1; // 포함 시킬 경우.
	if (DFS(n + 1, sum)) return 1;        // 포함 안시킬 경우.
	return 0;
}


int main(void)
{
	freopen("in.txt", "r", stdin);
	int i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &K);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
		}
		sol = 0;

		if (DFS(1, 0) == 1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
#endif

// 이진트리의 경우 비트 연산을 통해서 구할수도 있다.
#if 0
#include <stdio.h>
int T, N, K, sol;

int main(void)
{
	// 여기서부터 작성
	int bit, r, sum, j, found = 0;
	scanf("%d", &T);


	for ( bit = 0; bit < (1 << N); bit++)
	{
		sum = 0;
		for ( j = 0; j < N; j++)
		{
			if (bit & (1 << j)) sum += a[j];
		}
		if (sum == K){ found = 1; };
	}

	if (found) printf("YES");
	else printf("NO");


	return 0;
}
#endif



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
