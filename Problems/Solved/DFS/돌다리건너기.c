
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
