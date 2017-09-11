
// 문제 번호 : [TEST] 책꽂이
// multi branch
#if 0
#include <stdio.h>
#define SIZE 30
#define INITIAL 0x7fffffff
#define USE 1
#define UNUSE 0

int cow[SIZE];
int used[SIZE];
int min, T, N, B;


void DFS(int depth, int sum){
	int diff, i;
	if (B < sum){
		diff = sum - B;
		if (min > diff) min = diff;
		return;
	}
	if (depth > N){
		if (B < sum){
			diff = sum - B;
			if (min > diff) min = diff;
		}
		return;
	}

	for ( i = 1; i <= N; i++){
		if (used[i]) continue;
		used[i] = USE;
		DFS(depth + 1, sum + cow[i]);
		used[i] = UNUSE;
	}

}

int main(void){
	freopen("in.txt", "r", stdin);
	int i, j, sum;
	scanf("%d", &T);

	for ( i = 1; i <=T; i++)
	{
		// 초기화
		min = INITIAL; sum = 0;
		for ( j = 1; j <= N; j++){
			used[j] = UNUSE;
		}


		scanf("%d %d", &N, &B);
		for ( j = 1; j <= N; j++)
		{
			scanf("%d", &cow[j]);
			sum += cow[j];
		}


		DFS(1, 0);
		printf("%d", min);

	}

	return 0;
}
#endif

// 책꽂이 이진트리
#if 0
#include <stdio.h>
#define SIZE 30
#define INITIAL 0x7fffffff
#define USE 1
#define UNUSE 0

int cow[SIZE];
int used[SIZE];
int min, T, N, B;


void DFS(int depth, int sum){
	int diff, i;
	if (B <= sum){
		diff = sum - B;
		if (min > diff) min = diff;
		return;
	}
	if (depth > N){
		if (B < sum){
			diff = sum - B;
			if (min > diff) min = diff;
		}
		return;
	}

	DFS(depth + 1, sum + cow[depth]);
	DFS(depth + 1, sum);

}

int main(void){
	freopen("in.txt", "r", stdin);
	int i, j, sum;
	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		// 초기화
		min = INITIAL; sum = 0;
		for (j = 1; j <= N; j++){
			used[j] = UNUSE;
		}


		scanf("%d %d", &N, &B);
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &cow[j]);
			sum += cow[j];
		}


		DFS(1, 0);
		printf("%d\n", min);

	}

	return 0;
}
#endif
