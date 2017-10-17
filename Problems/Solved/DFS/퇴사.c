#include <stdio.h>

int N, max = (1<<31);
int T[16];
int P[16];
int chk[16];

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for ( i = 1; i <= N; i++){
		scanf("%d %d", &T[i], &P[i]);
	}
}

void DFS(int n, int task, int pay){
	if (n > N){
		if (max < pay) max = pay;
		return;
	}

	if (task == 0 && (n + T[n] - 1 <= N)) {
		chk[n] = 1;
		DFS(n + 1, task + T[n] - 1, pay + P[n]);
		chk[n] = 0;
	}
	if (task > 0) DFS(n + 1, task - 1, pay);
	else DFS(n + 1, task, pay);
}

int main(void){
	Input_Data();
	DFS(1, 0, 0);
	printf("%d", max);

	return 0;
}
