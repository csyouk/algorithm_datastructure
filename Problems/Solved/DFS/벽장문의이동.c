// 둘다 해법이 틀림.

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
