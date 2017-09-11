
// 만약 이 문제에서 0값대신, 0x7fffffff라는 값을 준다면 어떻게 됐을까?
// 코드가 더 간단해 졌을 것이다.
// 문제 번호 : [TST]해밀턴 순환회로
#if 0
#include <stdio.h>
#define SIZE 22
#define NO_PATH 0
#define HOME 1
#define CHECK 1
#define UNCHECK 0

int N, min=0x7fffffff;
int map[SIZE][SIZE];
int visited[SIZE];

void DFS(int depth, int s, int sum){
	int e;

	if (sum > min) return;
	if (depth > N-1){
		if (map[s][HOME] == NO_PATH) return;
		sum += map[s][HOME];
		if (sum < min) {
			min = sum;
		}
		return;
	}

	for (e = 2; e <= N; e++){
		if (map[s][e] == NO_PATH) continue;
		if (visited[e]) continue;

		visited[e] = CHECK;
		DFS(depth + 1, e, sum + map[s][e]);
		visited[e] = UNCHECK;
	}
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	int i, j;
	scanf("%d", &N);

	for ( i = 1; i <= N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	//visited[1] = 1;
	DFS(1, 1, 0);

	if (min == 0x7fffffff) printf("0");
	else printf("%d", min);


	return 0;
}
#endif

// 해밀턴 순환회로 변형
#if 0
#include <stdio.h>

#define SIZE 22
#define NO_PATH 0x7fffffff
#define HOME 1
#define CHECK 1
#define UNCHECK 0


int N, min=0x7fffffff;
int map[SIZE][SIZE];
int visited[SIZE];

void DFS(int depth, int s, int sum){
	int e;

	if (min <= sum) return;
	if (depth >= N){
		if (min > sum + map[s][HOME]) min = sum + map[s][HOME];
		return;
	}

	for (e = 1; e <= N; e++){
		if (visited[e]) continue;

		visited[e] = CHECK;
		DFS(depth + 1, e, sum + map[s][e]);
		visited[e] = UNCHECK;
	}
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	int i, j;
	scanf("%d", &N);

	for ( i = 1; i <= N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) map[i][j] = NO_PATH;
		}
	}

	visited[1] = 1;
	DFS(1, 1, 0);
	printf("%d", min);


	return 0;
}
#endif
