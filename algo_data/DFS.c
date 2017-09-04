// 문제 번호 : [TST]주사위 던지기2
/*
자연수 N과 M을 입력 받아서 주사위를 N번 던져서 나온 눈의 합이 
M이 나올 수 있는 모든 경우를 출력하는 프로그램을 작성하시오.
*/
#if 0
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



// 문제 번호 : [TST] 더하기
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
#if 0
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


// 문제 번호 : [TST]건물세우기(BASIC)
#if 0
#include <stdio.h>
#define SIZE 20
int N, min=0x7fffffff;
int flag, found;

int map[SIZE][SIZE];
int place[SIZE];
int order[SIZE];
int final_order[SIZE];

void DFS(int depth, int sum){
	int i;
	if (sum => min) return;
	if (depth > N){
		if (sum < min) {
			min = sum;
			for ( i = 1; i <= N; i++)
			{
				final_order[i] = order[i];
			}
		}
		return;
	}
	for ( i = 1; i <= N; i++)
	{
		if (place[i]) continue;
		place[i] = 1; order[depth] = i;
		DFS(depth + 1, sum + map[depth][i]);
		place[i] = 0;
	}

}


int main(void){
	freopen("in.txt", "r", stdin);
	int i, j, sum=0, found, depth = 1;
	scanf("%d", &N);

	for ( i = 1; i <= N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			scanf("%d ", &map[i][j]);
		}
	}

	DFS(depth, sum);

	printf("%d\n", min);
	for ( i = 1; i <= N; i++)
	{
		printf("%d ", final_order[i]);
	}
	return 0;
}

#endif

// 문제 번호 : [TST]자동차경주대회(BASIC2)
#if 0
#include <stdio.h>
int MAX, N, min=0x7fffffff;
int D[50 + 10];
int T[50 + 10];

void DFS(int n, int time, int dis){
	int i, j;
	if (time > min) return;
	if (n > N){
		if (min > time) min = time;			
		return;
	}
	// 나의 코드
	//DFS(n + 1, time + T[n], dis + D[n]); // 정비 받는 경우
	//if (dis + D[n] <= MAX) DFS(n + 1, time, dis + D[n]); // 정비 안받는 경우

	// 정답
	DFS(n + 1, time + T[n], D[n]); // 정비 받는 경우
	if (dis + D[n] <= MAX) DFS(n + 1, time, dis + D[n]); // 정비 안받는 경우

	// 가지치기를 한다면 0, 1 순으로 호출하는 것이 좋다.
	if (dis + D[n] <= MAX) DFS(n + 1, time, dis + D[n]); // 정비 안받는 경우
	DFS(n + 1, time + T[n], D[n]); // 정비 받는 경우
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	int i;
	scanf("%d", &MAX);
	scanf("%d", &N);

	for (i = 0; i <= N; i++) scanf("%d ", &D[i]);
	for (i = 1; i <= N; i++) scanf("%d ", &T[i]);


	DFS(1, T[0], D[0]);
	
	printf("%d", min);


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
		printf("%d", min);

	}

	return 0;
}
#endif