
// 문제 번호 : [TST]자동차경주대회(BASIC2)
#if 01
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

	// 정답 1
	DFS(n + 1, time + T[n], D[n]); // 정비 받는 경우
	if (dis + D[n] <= MAX) DFS(n + 1, time, dis + D[n]); // 정비 안받는 경우

	// 정답 2
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

// 문제 번호 : [TST]자동차경주대회(BASIC2)
#if 0
#include <stdio.h>
int N, M, min = 0x7fffffff;
int d[60], t[60];

void DFS(int n, int dis, int time){
	if (min < time) return;
	if (n > M){
		if (min > time) min = time;
		return;
	}

	DFS(n + 1, d[n], time + t[n]);
	if (dis + d[n] <= N) DFS(n + 1, dis + d[n], time);
}

int main(void){
	int i;
	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 0; i <= M; i++) scanf("%d", &d[i]);
	for (i = 1; i <= M; i++) scanf("%d", &t[i]);

	DFS(1, d[0], 0);

	if (min == 0x7fffffff) printf("0");
	else printf("%d", min);

	return 0;
}
#endif
