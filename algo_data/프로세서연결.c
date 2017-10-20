#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define IMPOSSIBLE 0
#define POSSIBLE 1
#define DRAW_MODE 1
#define CHK_MODE 0
#define REMOVE_MODE -1
#define R 0
#define C 1
#define POWER 2
int sol, N, processors, maxconnprocessors;
int map[14][14];
int P[3][14];
// ю╖ аб ╬ф╥║ ©Л
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };

void Init(void){
	memset(map, 0, sizeof(map));
	memset(P, 0, sizeof(P));
	sol = (~(1<<31)); N = 0; processors = 1;
	maxconnprocessors = (1 << 31);
}

void Input_Data(void){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <=N; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j]){
				P[R][processors] = i;
				P[C][processors] = j;
				P[POWER][processors] = 0;
				processors++;
			}
		}
	}
}

int Chk_Possible(int r, int c, int dir){

	if (dir % 2){
		// аб ©Л
		c += dc[dir];
		while (map[r][c] == 0)
		{
			c += dc[dir];
			if (c < 1 || c > N) return POSSIBLE;
			if (map[r][c]) return IMPOSSIBLE;
		}
		return IMPOSSIBLE;
	}

	// ╩С го
	r += dr[dir];
	while (map[r][c] == 0)
	{
		r += dr[dir];
		if (r < 1 || r > N) return POSSIBLE;
		if (map[r][c]) return IMPOSSIBLE;
	}
	return IMPOSSIBLE;
}

int Draw_Line(int r, int c, int dir, int mode){
	int cnt = 0;
	if (dir % 2){
		// аб ©Л
		while (1 <= c && c <= N){
			c += dc[dir];
			if (c < 1 || c > N) return cnt;
			if (mode == DRAW_MODE){ map[r][c] = 1; cnt++; }
			else map[r][c] = 0;
		}
		return cnt;
	}

	// ╩С го
	while (1 <= r && r <= N){
		r += dr[dir];
		if (r < 1 || r > N) return cnt;
		if (mode == DRAW_MODE){ map[r][c] = 1; cnt++; }
		else map[r][c] = 0;
	}
	return cnt;

}

void DFS(int n, int len){
	int k, nr, nc, cnt;

	if (n >= processors){
		int i, conn=0;
		for (i = 1; i < processors; i++)
		{
			if (P[POWER][i]) conn++;
		}
		if (maxconnprocessors < conn){
			maxconnprocessors = conn;
			sol = len;
		}
		else if (maxconnprocessors == conn){
			if (sol > len){
				sol = len;

			}
		}

		return;
	}

	for (cnt = 0, k = 0; k < 4; k++)
	{
		int newline;
		nr = P[R][n] + dr[k];
		nc = P[C][n] + dc[k];
		if (nr < 1 || nr > N || nc < 1 || nc > N) {
			P[POWER][n] = 1;
			DFS(n + 1, len);
			continue;
		}

		if (Chk_Possible(P[R][n], P[C][n], k) == IMPOSSIBLE){
			cnt++;
			continue;
		}

		newline = Draw_Line(P[R][n], P[C][n], k, DRAW_MODE);
		P[POWER][n] = 1;
		DFS(n + 1, len + newline);
		P[POWER][n] = 0;
		Draw_Line(P[R][n], P[C][n], k, REMOVE_MODE);
	}
	if (cnt == 4){
		P[POWER][n] = 0;
		DFS(n + 1, len);
	}
}

int main(void){
	int T, tc=1;
	scanf("%d", &T);

	while (T--)
	{
		Init();
		Input_Data();
		DFS(1, 0);
		printf("#%d %d\n", tc++, sol);
	}


	return 0;
}