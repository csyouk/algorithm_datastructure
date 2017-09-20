#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#if 1

int sol[90];
int N, flag;

int Check(int n, int d){
	int i, j, cnt = 0;
	sol[n] = d;
	if (n == 1 || n == 2 || n == 3) return 0;
	for (i = 2; i <= n/2; i++)
	{
		cnt = 0;
		for ( j = 0; j < i; j++)
		{
			if (sol[n - j] == sol[n - i - j]) cnt++;
		}
		if (cnt == i) return 1;
	}
	return 0;
}

void DFS(int n, int d){
	int i;
	if (flag) return;
	if (Check(n, d)) return;
	if (n == N) {
		flag = 1;
		return;
	}
	for ( i = 1; i <= 3; i++)
	{
		if (sol[n] != i) DFS(n + 1, i);
	}
}

int main(void)
{
	// 여기서부터 작성
	int i;
	scanf("%d", &N);
	DFS(1, 1);
	for (i = 1; i <= N; i++) printf("%d", sol[i]);

	return 0;
}
#endif