
// 문제 번호 : [TST]주사위 던지기2
#if 01
/*
자연수 N과 M을 입력 받아서 주사위를 N번 던져서 나온 눈의 합이
M이 나올 수 있는 모든 경우를 출력하는 프로그램을 작성하시오.
*/
#include <stdio.h>
int N, M;
int sol[7 + 10];
void DFS(int n, int sum){
	int i;
	if (n > N) {
		if (sum == M){
			for (i = 1; i <= N; i++)
			{
				printf("%d ", sol[i]);
			}
			printf("\n");
		}
		return;
	}
	for (i = 1; i <= 6; i++)
	{
		sol[n] = i;
		DFS(n + 1, sum + i);
	}
}

int main(void)
{

	// 여기서부터 작성
	scanf("%d %d", &N, &M);

	DFS(1, 0);

	return 0;
}
#endif
