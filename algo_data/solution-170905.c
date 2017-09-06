//
// Control + M + L 로 접어서 하나씩 보세요.
//

// 미닫이 문
// N은 몇 번째로 정해진/요청받은/약속된 문을 열것이냐를 의미함.
#if 0
#pragma warning (disable:4996)
#include <stdio.h>
#define ABS(a) (((a)>0)?(a):(-(a)))

int D[20 + 10]; // 인풋 배열 : 오픈할 문의 순서
int NN, D1, D2, N;
int MIN = 0x7fffffff;

void DFS(int n, int move, int d1, int d2) {

	// leaf.
	if (n > N) {
		if (move < MIN) MIN = move;
		return;
	}

	// binary tree. 두개의 문 각각의 경우로 나뉨.
	//
	// 1. 첫번째 문의 <열림>을 움직이는 경우
	DFS(n + 1, move + ABS(D[n] - d1), D[n], d2); // 움직인 거리를 더하고 다음으로.
	// 2. 두번째 문의 <열림>을 움직이는 경우
	DFS(n + 1, move + ABS(d2 - D[n]), d1, D[n]);
}

int main(void) {
	int i;
	scanf("%d %d %d %d", &NN, &D1, &D2, &N);
	for (i = 1; i <= N; i++) scanf("%d", &D[i]);
	DFS(1, 0, D1, D2);
	printf("%d", MIN);
	return 0;
}
#endif


// N QUEEN. (최적화 버전)
// N은 기본적으로 row값을 의미함.
// why? 한 행(또는 열)에는 단 한개의 퀸밖에 존재할 수 없음을 이용하기 때문이다.
// 그러므로 기본적으로 이 접근법은 다음의 장점을 갖는다.
// "행이 원인이 되는 퀸의 <위치 불가능>은 일어나지 않는다."
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
	int i, j;
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
	return 0;
}

int main(void) {
	scanf("%d", &N);
	DFS(1);
	printf("%d", CNT);
	return 0;
}
#endif

// N QUEEN 이해용 오답 버전 :  정답이 N! 개 만큼 곱해져서 나옴.
// N은 기본적으로 몇 번째로 퀸을 놓을 것이냐를 의미함.
// N QUEEN.
#if 0
#pragma warning (disable:4996)
#include <stdio.h>
#define ABS(a) ((a>0)?(a):(-(a)))

int N, NN, CNT;
int b[10 + 10][2]; // 저장 배열 : 퀸을 놓아둔 모든 위치를 적어둔다.

int check(int x, int y, int n){ // 저장된 모든 퀸들과 대각선/가로/세로를 체크.
	int i;
	for (i = 1; i < n; i++) { // 저장된 퀸 값이 n-1개 이므로 1 ~ n-1 까지 배열 점검.
		if ((b[i][0] == x) || (b[i][1] == y)) return 1; // 가로 세로 점검
		if ((x - b[i][0]) == ABS(b[i][1] - y)) return 1; // 대각선 점검.
	}
	return 0;
}

void DFS(int n, int x, int y) {
	// leaf
	if (n > N) {
		CNT++;
		return;
	}

	// multi tree : N*N 개의 점을 모두 탐색.
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {

			// 가로 세로 대각선 체크
			if (check(i, j, n)) continue;

			// 가능한 경우에 퀸을 놓은 자리를 b[n][2]에 저장하고 DFS 실행.
			b[n][0] = i;
			b[n][1] = j;
			DFS(n + 1, i, j);
		}
	}
	return 0;
}

int main(void) {
	scanf("%d", &N);
	NN = N*N;
	DFS(1, 0, 0);
	printf("%d", CNT);
	return 0;
}
#endif

//RINGS :: N번째 다리에서 판단을 중심으로
#if 0
#pragma warning (disable:4996)
#include <stdio.h>

int K, N, CNT;
char A[10 + 10]; // 인풋배열 : 단어를 입력 받음
char B[2][30 + 10]; // 인풋배열 : 두개의 다리에 적힌 단어를 두줄로 입력받음

void DFS(int n, int words, int shuffle) {
	// cut.
	if (words > K) { CNT++; return; } // 모든 단어 조건을 통과하면 우선적으로 계산하고 컷.

	// leaf.
	if (n > N) return; // 모든 단어를 다 건너면 종결

	// binary tree. - 다리를 건너뛰는/생략하는 경우와 정답에 포함하는 경우로 나뉨
	//
	// 1. n번째 다리의 글자를 정답에 포함시킨다.
	if (B[shuffle][n - 1] == A[words - 1])
	{
		DFS(n + 1, words + 1, !shuffle); // !shuffle 가 다른 다리로 전환시킨다.
	}
	// 2. n번째 다리의 글자를 건너뛴다/생략한다.
	DFS(n + 1, words, shuffle);
}


int main(void) {
	scanf("%s", A);
	scanf("%s", B[0]);
	scanf("%s", B[1]);
	while (A[K]) K++; // 글자수 세기.
	while (B[0][N]) N++; // 글자수 세기.

	DFS(1, 1, 0); // shuffle = 0 : ANGEL first.
	DFS(1, 1, 1); // shuffle = 1 : DEVIL first.
	printf("%d", CNT);
	return 0;
}
#endif

//Painting :: N 번째로 공간에 그리는 것을 중심으로
#if 0
#pragma warning (disable:4996)
#include <stdio.h>

int N, M, ESCAPE;
int a[12 + 10][12 + 10]; // 인풋배열 : a[i][j] = 1 ? i번째 공간은 j번째 공간으로부터 연결됨.
int note[12 + 10]; // 체크배열 : note[k] ? k번째 공간에 적혀있는 색.

void DFS(int n) {
	int k, i, flag;

	// cut.
	if (ESCAPE) return; // 한번이라도 인쇄되면 모든 트리를 빠져나옴.

	// leaf.
	if (n > N) {
		for (i = 1; i <= N; i++) printf("%d ", note[i]);
		ESCAPE = 1;
		return;
	}

	// multi tree. - M개의 모든 색깔 경우에 대해서 나눔(분기).
	for (k = 1; k <= M; k++) {

		// 연결되어있는 공간 중에서 같은 색이 있는지 체크
		flag = 0;
		for (i = 1; i < n; i++) {
			if (a[n][i] && note[i] == k) {
				flag = 1;
				break;
			}
		}
		if (flag) continue;

		//
		note[n] = k;
		DFS(n + 1);
	}
}

int main(void) {
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	DFS(1);
	if (ESCAPE == 0) printf("-1");
	return 0;
}
#endif


//BONUS :: N 번째로 지급된 돈을 중심으로.
//보통의 풀이법은 다음의 인풋을 해결하지 못하는 경우가 많음.
//3 2
//1 2
//3 2
//10 20 30
//WHY? 상급자와의 관계만을 고려하기 때문.
#if 0
#pragma warning (disable:4996)
#include <stdio.h>

int N, E, ESCAPE;
int a[10 + 10][10 + 10]; // Input 배열 : 상급자 관계 ( a[i][j] == 1 : j가 i의 상급자)
int pay[10 + 10]; // Input 배열 : 지급해야 할 돈들 ( pay[i] : i 번째로 지급 될 돈 )
int paid[10 + 10]; // 체크&저장 배열 : 각자가 받은 돈 ( paid[k] : k 번 사람이 받은 돈 / NOTICE : 돈 순서와 다름!)

// n은 n번째로 지급될 돈을 의미함.
void DFS(int n) {
	int k, i, flag;

	// cut
	if (ESCAPE) return; // 한번이라도 인쇄된 경우에 모든 트리를 빠져나옴.

	// leaf
	if (n > N) {
		for (i = 1; i <= N; i++) printf("%d ", paid[i]); // 답 인쇄.
		ESCAPE = 1;
		return;
	}

	// multi tree - 각각의 모든 사람에 대해서 나눔(분기).
	for (k = 1; k <= N; k++) {

		// 상급자 조사
		flag = 0;
		for (i = 1; i <= N; i++) {
			if (a[k][i]) {
				if (paid[i] == 0) continue; // 안 정해진 경우 예외
				if (pay[n] >= paid[i]) { flag = 1; break; }
			}
		}
		if (flag) continue;

		// 하급자 조사
		for (i = 1; i <= N; i++) {
			if (a[i][k]) {
				if (paid[i] == 0) continue; // 안 정해진 경우 예외
				if (paid[i] >= pay[n]) { flag = 1; break; }
			}
		}
		if (flag) continue;

		// 보너스 할당 및 중복지급 막기.
		if (paid[k]) continue;
		paid[k] = pay[n];
		{
			DFS(n + 1);
		}
		paid[k] = 0;
	}
}

int main(void) {
	int i, j, up, down, tmp;
	scanf("%d %d", &N, &E);
	for (i = 0; i < E; i++) {
		scanf("%d %d", &up, &down);
		a[down][up] = 1;
	}
	for (i = 1; i <= N; i++) scanf("%d", &pay[i]);
	DFS(1);
	return 0;
}
#endif

//BONUS (FAIL - 29%) :: N 번째 사람을 중심으로 
#if 0
#pragma warning (disable:4996)
#include <stdio.h>

int N, E, ESCAPE, CNT;
int a[10 + 10][10 + 10];
int pay[10 + 10];
int paid[10 + 10];
int note[10 + 10];

void DFS(int n) {
	int k, i, flag;

	// cut
	if (ESCAPE) return;

	// leaf
	if (n > N) {
		for (i = 1; i <= N; i++) printf("%d ", note[i]);
		printf("\n");
		ESCAPE = 1;
		return;
	}

	// multi tree
	for (k = 1; k <= N; k++) {
		// 상급자와의 관계
		flag = 0;
		for (i = 1; i < n; i++) {
			if (a[n][i] && note[i] <= pay[k]) { flag = 1; break; }
		}
		if (flag) continue;

		// 지급상태.
		if (paid[k]) continue;
		paid[k] = 1;
		{
			note[n] = pay[k];
			DFS(n + 1);
		}
		paid[k] = 0;
	}

}

int main(void) {
	int i, j, up, down;
	scanf("%d %d", &N, &E);
	for (i = 0; i < E; i++) {
		scanf("%d %d", &up, &down);
		a[down][up] = 1;
	}
	for (i = 1; i <= N; i++) scanf("%d", &pay[i]);
	DFS(1);
	return 0;
}
#endif

//
// written by DJ.