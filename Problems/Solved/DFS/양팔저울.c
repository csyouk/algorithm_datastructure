
// 문제 번호 U: [TST]양팔저울(BASIC)
#if 0
#include <stdio.h>

int N, M, found;
int W[12 + 10];

void DFS(int n, int sum, int t){
	if (found) return;
	if (sum == t) {
		found = 1;
		return;
	}
	if (n > N){
		if (sum < 0)return;
		if (sum == t) { found = 1; }
		return;
	}

	DFS(n + 1, sum + W[n], t);
	DFS(n + 1, sum, t);
	DFS(n + 1, sum - W[n], t);
}

int main(void){
	freopen("in.txt", "r", stdin);
	int i,j, s;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &W[i]);
	}

	scanf("%d", &M);
	for (i = 1; i <= M; i++)
	{
		scanf("%d", &s);
		found = 0;
		DFS(1, 0, s);

		printf("%c ", (found) ? 'Y' : 'N');
	}




	return 0;
}
#endif
