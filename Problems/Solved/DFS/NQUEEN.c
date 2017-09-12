
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



// 문제 번호 K: [TST]N QUEEN
#if 0
#include <stdio.h>
#define SIZE 23

int N, cnt;
int chkr[SIZE], chkdl[2 * SIZE], chkdr[2 * SIZE];

void DFS(int n){
	int i;
	if (n > N) { cnt++; return; }
	for (i = 1; i <= N; i++)
	{
		if (chkr[i] || chkdl[i - n + N] || chkdr[i+n]) continue;
		chkr[i] = chkdl[i - n + N] = chkdr[i + n] = 1;
		DFS(n + 1);
		chkr[i] = chkdl[i - n + N] = chkdr[i + n] = 0;
	}
}

int main(void){

	scanf("%d", &N);

	DFS(1);

	printf("%d", cnt);

	return 0;
}
#endif
