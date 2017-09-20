#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#if 1

int sol[90];
int N, flag;

int Check(int n, int d){
	int i, cnt = 0;
	sol[n] = d;
	if (n == 1) return 0;
	for (i = 0; i < n/2; i++){
		if (n % 2) {
			if (sol[n - i] == sol[(n / 2 + 1) - i]) cnt++;
		}
		else{
			if (sol[n - i] == sol[(n / 2) - i]) cnt++;
		}
	}
	if (cnt == n / 2) return 1;
	else return 0;
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
	//printf("\n%d\n", 5 / 2);
	return 0;
}
#endif