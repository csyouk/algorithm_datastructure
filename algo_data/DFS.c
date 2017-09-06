#define _CRT_SECURE_NO_WARNINGS
// 문제 번호 : [TST]주사위 던지기2
#if 0
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

//문제 번호 : [TST] 벽장문의 이동
// 뚫려 있는 문을 이동시키는 방법이 가장 손쉬운 풀이를 만들어낸다.
// 문제를 변형시켜서 재단하지 말자.
#if 0
#include <stdio.h>
#define SIZE 30
#define OPEN 1
#define CLOSE 0
#define NO_PATH 0x7fffffff
#define L -1
#define R 1

int D1, D2, N, Doors, Current;
int doors[SIZE];

int DFS(int depth, int door, int cnt, int dir){
	if (door < 1 || door > N) return NO_PATH;
	if (doors[door] == OPEN){ return cnt; }
	return DFS(depth + 1, door + dir, cnt + 1, dir);
}

int main(void){
	freopen("in.txt", "r", stdin);
	int i, sum=0, left, right;
	scanf("%d", &N);
	scanf("%d %d", &D1, &D2);
	scanf("%d", &Doors);

	doors[D1] = OPEN;
	doors[D2] = OPEN;

	for ( i = 1; i <=Doors; i++){
		scanf("%d", &Current);
		left = DFS(1, Current, 0 , L);
		right = DFS(1, Current, 0, R);

		if (left == 0 || right == 0) continue;

		doors[Current] = OPEN;
		if (left < right){ doors[Current - left] = CLOSE; }
		else { doors[Current + right] = CLOSE; }
		sum += (left < right) ? left : right;
		
	}

	printf("%d", sum);

	return 0;
}
#endif


// 문제 번호 : [TST] 벽장문의 이동
#if 0
#include <stdio.h>
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define SIZE 30
#define OPEN 1
#define CLOSE 0

int sol = 0x7fffffff;

int  N, Doors, Target;
int a[SIZE];

void DFS(int n, int cnt, int l, int r){
	if (sol <= cnt) return;
	if (n > N){
		if (sol > cnt) sol = cnt;
		return;
	}
	DFS(n + 1, cnt + ABS(l - a[n]), a[n], r);
	DFS(n + 1, cnt + ABS(r - a[n]), l, a[n]);
}

int main(void){
	freopen("in.txt", "r", stdin);
	int i, sum = 0, d1, d2, L, R;

	scanf("%d", &N);
	scanf("%d %d", &L, &R);
	scanf("%d", &Doors);
	for (i = 1; i <= Doors; i++) scanf("%d", &a[i]);

	DFS(1, 0, L, R);

	printf("%d", sol);

	return 0;
}
#endif

// 문제 번호 : [TST]N QUEEN(BASIC)
// 내 코드
#if 0
#include <stdio.h>
#define SIZE 20

int chess[SIZE][SIZE];
int N, sol;

int check(int r, int c){
	int i;

	// 같은 행을 전부 검색
	for (i = r-1; i >= 1; i--){
		if (chess[i][c]) return 1;
	}

	// \ 방향 검색
	for (i = 1; i <= N; i++)
	{ 
		if ((r - i) == 0 || (c - i) == 0) return 0;
		if (chess[r - i][c - i]) return 1;
	}

	// / 방향 검색
	for (i = 1; i <= N; i++)
	{
		if ((r - i) == 0 || (c + i) == N) return 0;
		if (chess[r - i][c + i]) return 1;
	}
	return 0;
}

void DFS(int r, int c){
	int i;
	if (r > N){ sol++; return; }

	if (check(r, c)) return;
	for (i = 1; i <= N; i++){
		chess[r][i] = 1;
		DFS(r + 1, 1);
		chess[r][i] = 0;
	}
}

int main(void){
	scanf("%d", &N);

	DFS(1, 1);
	printf("%d", sol);


	return 0;
}
#endif

// N Queen 문제
#if 0
#include <stdio.h>
int N, chess[20][20], sol;

int Check(int si, int sj){
	int i, j;
	for (i = si; i >= 1; i--) {
		if (chess[i][sj]) return 0;
	}

	for (i = si, j = sj; i > 0 && j > 0; i--, j--){
		if (chess[i][j]) return 0;
	}

	for (i = si, j = sj; i > 0 && j <= N; i--, j++)
	{
		if (chess[i][j]) return 0;
	}
	return 1;
}

void DFS(int n){
	int i;
	if (n > N) { sol++; return; }
	for ( i = 1; i <= N; i++)
	{
		if (Check(n, i) == 0) continue;
		chess[n][i] = 1;
		DFS(n + 1);
		chess[n][i] = 0;
	}
}

int main(void){
	scanf("%d", &N);
	DFS(1);
	printf("%d", sol);
}
#endif


// 문제 번호 : [TST]돌다리 건너기(BASIC)
#if 0
#include <stdio.h>
#include <string.h>
#define DEVIL 0
#define ANGEL 1

char spell[15];
char bridge[5][60];

unsigned int sol, N, B, len_d, len_a;


void DFS(int n, int s, int type){
	int i;
	if (n > N){ sol++; return; }

	for (i = s; i <= B; i++)
	{
		//if (i < s ) continue;
		if (spell[n] == bridge[type][i]){
			DFS(n + 1, i+1, (type + 1) % 2);
		}
	}
}

int main(void){
	freopen("in.txt", "r", stdin);
	int d, a, i, start_d, start_a;
	scanf("%s", &spell[1]);
	scanf("%s", &bridge[0][1]);
	scanf("%s", &bridge[1][1]);

	B = strlen(&bridge[1][1]);
	N = strlen(&spell[1]);

	for (i = 1; i <=B; i++)
	{
		if (spell[1] == bridge[0][i]) break;
	}
	DFS(1, i, DEVIL);

	for (i = 1; i <= B; i++)
	{
		if (spell[1] == bridge[1][i]) break;
	}
	DFS(1, i, ANGEL);

	if (sol)printf("%d", sol);
	else printf("0");
	return 0;
}
#endif

// 돌다리 건너기 sol 코드
#if 0
#include <stdio.h>
char s[20], str[4][60];
int M, N, sol;

void DFS(int n, int cnt, int p){
	// 최적화
	if (cnt == M) sol++;
	// 종료 조건
	if (n >= N){
		if (cnt == M) sol++;
		return;
	}

	// 밟는 경우.
	if (s[cnt] == str[p][n]) DFS(n + 1, cnt + 1, !p);

	// 밟지 않는 경우.
	DFS(n + 1, cnt + 1, p);
}

int main(void){
	
	scanf("%s %s %s", &s[0], &str[0][0], &str[1][0]);

	for (M = 0; s[M]; M++);
	for (N = 0; str[0][N]; i++);

	DFS(0, 0, 0);
	DFS(0, 0, 1);

	printf("%d", sol);

	return 0;
}
#endif

// 문제 번호 : [TST]그래프 칠하기
#if 0
#include <stdio.h>
#define SIZE 22
int N, M, flag;
int map[SIZE][SIZE];

int node[SIZE];
int color[SIZE];

int Check(int n, int c){
	int n_i;
	if (flag) return;
	for (n_i = 1; n_i <= N; n_i++){
		if (map[n_i][n] == 0) continue;
		if (color[n_i] == c) return 1;
	}
	return 0;
}

void DFS(int n ){
	int c;
	if (flag) return;
	if (n > N){
		flag = !flag;
		return;
	}

	for (c = 1; c <= M; c++){
		if (Check(n, c)) continue;
		color[n] = c;
		DFS(n + 1);
		if(flag == 0) color[n] = 0;
	}
}

int main(void){

	freopen("in.txt", "r", stdin);

	int i, j;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++){
		for ( j = 1; j <= i; j++)
		{
			scanf("%d", &map[i][j]);
			map[j][i] = map[i][j];
		}
	}

	DFS(1);
	if (flag){ for (i = 1; i <= N; i++) printf("%d ", color[i]); }
	else printf("-1");
	
	return 0;
}
#endif


// 다시 도전하는 N Queen + 속도 향상
#if 0
#include <stdio.h>
#define SIZE 20
#define N_PROMISING 0
#define PROMISING 1
#define PUT_QUEEN 1
#define COLLECT_QUEEN 0
#define QUEEN_ALREADY_EIXT 1

#define VISITED 1
#define N_VISITED 0

int chess[SIZE][SIZE];
int col_visited[SIZE];
int N, cnt;

int promising(int r, int c, int N){
	int i, j;

	// | 방향
	for (i = r, j = c; i > 0; i--){
		if (chess[i][c]) return N_PROMISING;
	}

	// \ 방향
	for (i = r, j = c; (i > 0 && j > 0); i--, j--)
	{
		if (chess[i][j]) return N_PROMISING;
	}

	// / 방향
	for (i = r, j = c; (i > 0 && j < N+1) ; i--, j++)
	{
		if (chess[i][j]) return N_PROMISING;
	}

	return PROMISING;
}

void DFS(int n, int N){
	int i;
	if (n > N) { cnt++; return; }

	for (i = 1; i <= N; i++){
		if (col_visited[i]) continue;
		if (promising(n, i, N) == N_PROMISING) continue;
		//chess[n][i] = PUT_QUEEN;
		col_visited[i] = VISITED;
		DFS(n + 1, N);
		col_visited[i] = N_VISITED;
		//chess[n][i] = COLLECT_QUEEN;
	}
}

int main(void){
	scanf("%d", &N);

	DFS(1, N);

	printf("%d", cnt);

	return 0;
}
#endif

// N Queen 속도 향상 버전
#if 0

#pragma warning (disable:4996)
#include <stdio.h>
#define ABS(a) ((a>0)?(a):(-(a)))

int N, CNT;
int b[10 + 10]; // 저장배열 : b[row] ? 해당 row에 위치한 퀸의 col값 저장. 
int Y[10 + 10]; // 중복방지 체크배열 : Y[col] = 1 ? 해당 col값은 이미 퀸이 존재해서 불가함.

int check(int row, int col){ // 대각선 체크 함수.
	int i;
	for (i = 1; i < row; i++)
	{
		if ((row - i) == ABS(b[i] - col)) return 1;
		// 가로차이와 세로차이가 같다면 대각선상으로 인식하고 TRUE를 리턴한다.
	}
	return 0;
}

void DFS(int n) {

	// leaf. (종료 조건)
	if (n > N)
	{
		CNT++; // 끝까지 return 되지 않고 도달 가능하다면, 갯수를 센다.
		return;
	}

	// multi tree. : 이곳에서 각 행(n)에 대해서 열(j)를 선택한다.
	int j;
	for (j = 1; j <= N; j++)
	{
		// Y[j]를 통한 <열 체크> 그리고 check(n,j)를 통한 <대각선 체크>
		// NOTICE : <행 체크>는 필요가 없다.
		if (Y[j]) continue;
		if (check(n, j)) continue;
		Y[j] = 1;
		{
			b[n] = j;
			DFS(n + 1);
		}
		Y[j] = 0;
	}
	return;
}

int main(void) {
	scanf("%d", &N);
	DFS(1);
	printf("%d", CNT);
	return 0;
}
#endif


// 문제 번호 : [TST]보너스
#if 0
#include <stdio.h>
#define SIZE 20
#define CONN_SIZE 110
#define SUB 0
#define N_SUB 1
#define DONE 1

typedef struct {
	int s, e;
} Conn;

Conn cases[CONN_SIZE];
int bonus[SIZE], people[SIZE], result[SIZE];
int N, M, flag;


int is_i_sub(int n, int i){
	int j;

	for ( j = 1; j <= M; j++)
	{
		if (people[j]) continue;
		if (cases[j].s == n && cases[j].e == i) return SUB;
	}
	return N_SUB;
}

void DFS(int n){
	int i;
	if (flag) return;
	if (n > N) { flag = 1; return; }

	//for (i = 2; i <=M; i++)
	//{
	//	if (is_i_sub(n, i) == N_SUB) continue;
	//	result[i] = bonus[n+1];
	//	people[i] = DONE;
	//	DFS(n + 1);
	//}

}

void sort(int *p, int n){
	int i, j, tmp;
	for (i = 1; i <= n-1; i++)
	{
		for (j = i+1; j <= n; j++)
		{
			if (p[i] < p[j]) { 
				tmp = p[i]; 
				p[i] = p[j]; 
				p[j] = tmp; 
			}
		}
	}
}
int main(void){

	freopen("in.txt", "r", stdin);

	int i;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= M; i++) scanf("%d %d", &cases[i].s, &cases[i].e);
	for (i = 1; i <= N; i++) scanf("%d ", &bonus[i]);
	sort(bonus, N);

	for (i = 1; i <= N; i++) printf("%d ", result[i]);


	return 0;
}
#endif


// N-Queen 최적화(솔루션)
#if 0
int main(void){


	return 0;
}
#endif