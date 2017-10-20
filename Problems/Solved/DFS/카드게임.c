#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int T, max;
int N;
int A[25 + 1];
int B[25 + 1];
void Init(void){
	max = 0;
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
}
void Input_Data(void){
	int i;
	scanf("%d", &N);
	for ( i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &B[i]);
	}
}

void DFS(int ai, int bi, int score){
	if (ai > N+1) return;
	if (bi > N+1) return;
	if (ai == N+1 || bi == N+1){
		if (max < score) max = score;
		return;
	}

	if (A[ai] > B[bi]){
		DFS(ai, bi + 1, score + B[bi]);
	}
	else{
		DFS(ai + 1, bi, score);
		DFS(ai + 1, bi + 1, score);

	}
}

int main(void){

	scanf("%d", &T);
	while (T--)
	{
		Init();
		Input_Data();
		DFS(1, 1, 0);
		printf("%d\n", max);
	}

	return	0;
}



/// 다이나믹 테이블 작성
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int T, max;
int N;
int A[25 + 1];
int B[25 + 1];
int D[27][27];
void Init(void){
	max = 0;
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(D, 0xff, sizeof(D));
}
void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &B[i]);
	}
}

void DFS(int ai, int bi, int score){
	if (ai > N + 1) return;
	if (bi > N + 1) return;
	if (D[ai][bi] >= score) return;
	D[ai][bi] = score;
	if (ai == N + 1 || bi == N + 1){
		if (max < score) max = score;
		return;
	}

	if (A[ai] > B[bi]){
		DFS(ai, bi + 1, score + B[bi]);
	}
	else{
		DFS(ai + 1, bi, score);
		DFS(ai + 1, bi + 1, score);

	}
}

int main(void){

	scanf("%d", &T);
	while (T--)
	{
		Init();
		Input_Data();
		DFS(1, 1, 0);
		printf("%d\n", max);
	}

	return	0;
}
