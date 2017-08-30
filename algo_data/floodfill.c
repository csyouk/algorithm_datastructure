//// 문제 번호 : [TST]마을 위성사진II
//// 재귀함수로 짠다. 
//// 코드를 간단하게 만드는 방법.
//// flood fill 알고리즘을 쓰는 방법이다.
//// 빠르진 않지만, 간단한 방법이다.
////5
////00001
////00100
////10000
////00100
////00001
//
#if 0
#include <stdio.h>
int N, a[100 + 10][100 + 10], chk[100 + 10][100 + 10], sol;
int di[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; // 상하 좌우, 밑2개 위 2개
int dj[] = { 0, 0, -1, 1, -1, 1, -1, 1 }; // 상하 좌우, 밑2개 위 2개

void Fill(int i, int j){
	// 재귀함수를 구현할 때는, top down방식의 사고방식이 필요하다. 
	// i,j 기준으로 바로 위부터 시계방향으로 체크해 나간다.
	// 3. 사용변수 선언
	int k, ni, nj;
	// 1. 일단 종료조건부터 작성한다.
	if (chk[i][j] == 1) return; 
	// 2. 방문 표시.
	chk[i][j] = 1;
	// 4. 8방향 체크
	for ( k = 0; k < 8; k++){
		ni = i + di[k]; nj = j + dj[k];
		// 5. 호수일 때만, flood fill 호출
		if (a[ni][nj] == 1) {
			Fill(ni, nj);
		}
	}


	
	//int k, ni, nj;
	//for (k = 0; k < 8; k++)
	//{
	//	ni = i + di[k]; nj = j + dj[k];
	//	if (a[ni][nj] == 1 && chk[ni][nj] == 0)
	//	{
	//		chk[ni][nj] = 1;
	//		Fill(ni, nj);
	//	}
	//}
	
	//
	//int k, ni, nj;
	//if (chk[i][j] == 1) return;
	//chk[i][j] = 1;
	//for (k = 0; k < 8; k++)
	//{
	//	ni = i + di[k]; nj = j + dj[k];
	//	if (ni<1 || ni > N || nj < 1 || nj > N) continue;
	//	if (a[ni][nj] != 1)continue;
	//	Fill(ni, nj);
	//}
	
}
int main(void)
{
	// 여기서부터 작성
	freopen("in.txt", "r", stdin);

	int i, j;
	scanf("%d", &N);

	// 가능하면 이런 좌표는 1부터 받는다. 
	// 최악의 경우에도 범위를 벗어나지 않기 때문이다.
	for ( i = 1; i <=N; i++){
		for (j = 1; j <= N; j++) scanf("%1d", &a[i][j]);
	}

	for ( i = 1; i <=N; i++){
		for ( j = 1; j <=N; j++){
			if (a[i][j] == 1 && chk[i][j] == 0){
				Fill(i, j);
				sol++;
			}
		}
	}

	printf("%d", sol);
	return 0;
}
#endif


#if 0
#include <stdio.h>

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, k, chk[26][26], cnt[26 * 26];
char arr[26][26];

void fill(int x, int y) {
	chk[x][y] = k;
	arr[x][y] = '0';
	cnt[k]++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (arr[nx][ny] == '1') fill(nx, ny);
	}
}

int main() {
	int i, j;
	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%s", arr[i]);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++){
			if (arr[i][j] == '1' && !chk[i][j]) {
				k++; fill(i, j);
			}
		}
	}

	printf("%d\n", k);
	for (i = 1; i <= k; i++) printf("%d\n", cnt[i]);

	return 0;
}
#endif

#if 0
#include <stdio.h>
#define SIZE 8
int N, mark = 1;
int c[SIZE][SIZE];
int chk[SIZE][SIZE];
int cnt[SIZE * SIZE / 2];
int di[] = { -1, 1, 0, 0}; // 상하 좌우
int dj[] = { 0, 0, -1, 1 }; // 상하 좌우

void Fill(int i, int j, int mark)
{
	int k, ni, nj;
	if (chk[i][j] == mark) return;
	chk[i][j] = mark;
	cnt[mark]++;
	for ( k = 0; k < 4; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (c[ni][nj] == 1){
			Fill(ni, nj, mark);
		}	
	}
}

int main(void)
{
	// 여기서부터 작성
	freopen("in.txt", "r", stdin);
	int i, j, tmp;

	scanf("%d", &N);
	for ( i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%1d", &c[i][j]);
		}
	}

	for ( i = 1; i <=N; i++){
		for ( j = 1; j <=N; j++){
			if (c[i][j] == 1 && chk[i][j] == 0){
				Fill(i, j, mark); mark++;
			}
		}
	}

	for (i = 0; i < mark-1; i++)
	{
		for ( j = i+1; j < mark; j++)
		{
			if (cnt[i] > cnt[j]){
				tmp = cnt[i];
				cnt[i] = cnt[j];
				cnt[j] = tmp;
			}
		}
	}

	printf("%d\n", mark);
	for ( i = 0; i < mark; i++)
	{
		printf("%d\n", cnt[i]);
	}

	return 0;
}
#endif

// 문제 번호 : [TST]미술관람 대회
#if 0
#include <stdio.h>
#define DIRECTIONS 4
int N;
char canvas[110][110];
int chk[110][110];

int di[DIRECTIONS] = {0,-1,0,1}; // 좌 상 우 하
int dj[DIRECTIONS] = {-1,0,1,0};

char Color[4] = "RGB";

void Fill(int i, int j, char target, int mark)
{
	int k, ni, nj;
	// 0 이 아니라는 뜻은 이미 체크가 끝났다는 뜻이다.
	if (chk[i][j] != 0) return;
	chk[i][j] = mark;

	for ( k = 0; k < DIRECTIONS; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (canvas[ni][nj] == target){
			Fill(ni, nj, target, mark);
		}
	}

}
void flush(void)
{
	for (int i = 0; i < N+1; i++)
	{
		for (int j = 0; j < N+1; j++)
		{
			chk[i][j] = 0;
		}
	}
}
void filter(void)
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (canvas[i][j] == 'R')
			{
				canvas[i][j] = 'G';
			}
		}
	}
}
int main(void)
{
	freopen("in.txt", "r", stdin);
	int i, j, mark = 0, color;
	// 여기서부터 작성
	scanf("%d", &N);

	for ( i = 1; i <=N; i++)
	{
		scanf("%s", &canvas[i][1]);
	}

	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <=N; j++)
		{
			// 먼저 레드부터 작성.
			for ( color = 0; color < 3; color++)
			{
				if (canvas[i][j] == Color[color] && chk[i][j] == 0){
					mark++;
					Fill(i, j, Color[color], mark);
				}
			}
		}
	}
	printf("%d ", mark);

	mark = 0;
	flush();
	filter();
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			// 먼저 레드부터 작성.
			for (color = 0; color < 3; color++)
			{
				if (canvas[i][j] == Color[color] && chk[i][j] == 0){
					mark++;
					Fill(i, j, Color[color], mark);
				}
			}
		}
	}
	printf("%d", mark);

	return 0;
}
#endif


// 문제 번호 : [TST]암소 미인 대회(Bronze)
#if 1
#include <stdio.h>
#define DIRS 4
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
typedef struct _pos{
	int x;
	int y;
} Pos;
Pos seg1[50 * 50];
Pos seg2[50 * 50];
Pos minseg1, minseg2;
int seg1cnt, seg2cnt;
int N, M, dis=0x7fffffff;
char farm[60][60];
int chk[60][60];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Fill(int i, int j, int mark)
{
	int k, ni, nj;
	if (chk[i][j] != 0) return;
	chk[i][j] = mark;
	if (mark == 1){
		seg1[seg1cnt].x = i;
		seg1[seg1cnt].y = j;
		seg1cnt++;
	}
	else if (mark == 2)
	{
		seg2[seg2cnt].x = i;
		seg2[seg2cnt].y = j;
		seg2cnt++;
	}
	for ( k = 0; k < DIRS; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (farm[ni][nj] == 'X'){
			Fill(ni, nj, mark);
		}
	}
}
int cal(void)
{
	int i, j,x,y;
	for ( i = 0; i <seg1cnt; i++)
	{
		for ( j = 0; j <seg2cnt; j++)
		{
			x = ABS( seg1[i].x - seg2[j].x );
			y = ABS( seg1[i].y - seg2[j].y );
			if (x + y < dis){
				minseg1.x = seg1[i].x;
				minseg1.y = seg1[i].y;

				minseg2.x = seg2[j].x;
				minseg2.y = seg2[j].y;
				dis = x + y;
			}
		}
	}
}
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int i, j, mark = 0, cnt=0;
	// 여기서부터 작성
	scanf("%d %d", &N, &M);

	for ( i = 1; i <=N; i++)
	{
		scanf("%s", &farm[i][1]);
	}

	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <=M; j++)
		{
			if (farm[i][j] == 'X' && chk[i][j] == 0)
			{
				mark++;
				Fill(i, j, mark);
			}
		}
	}
	cal();
	printf("%d", ABS(minseg2.x - minseg1.x) + ABS(minseg2.y - minseg1.y) - 1);

	return 0;
}
#endif