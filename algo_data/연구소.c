#include <stdio.h>
#include <string.h>
#define DIRS 4
#define SIZE 13

typedef struct {
	int i, j;
} Pos;

int N, M, wp, vwp;
int max = (1<<31);
int map[SIZE][SIZE];
int mirror[SIZE][SIZE];
Pos Q[64 + 10];
Pos Virus[10 + 10];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Input_Data(void){
	int i, j;
	scanf("%d %d", &N, &M);
	for ( i = 1; i <= N; i++)
	{
		for ( j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				Q[wp].i = i; Q[wp++].j = j;
			}
			if (map[i][j] == 2){
				Virus[vwp].i = i; Virus[vwp++].j = j;
			}
		}
	}
	for (i = 0; i <= M; i++)
	{
		map[0][i] = 1;  map[N+1][i] = 1;
	}
	for (i = 0; i <= N; i++)
	{
		map[i][0] = 1;  map[i][M + 1] = 1;
	}
}

void Fill(int i, int j){
	int k, ni, nj;
	// �̹� ���̷����� �����ְų�, ���̶�� ����.
	if (mirror[i][j] == 1) return;
	// ���̷��� ��Ʈ��
	mirror[i][j] = 2;

	for ( k = 0; k < DIRS; k++)
	{
		ni = i + di[k];  nj = j + dj[k];
		if (mirror[ni][nj] == 1 || mirror[ni][nj] == 2) continue;
		Fill(ni, nj);
	}
}

void DFS(int n, int wall_cnt){
	int i, j;
	if (n > wp) return;
	if (wall_cnt == 0){
		int cnt = 0;
		// ����(���� ����)
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				mirror[i][j] = map[i][j];
			}
		}

		// ���̷��� ��Ʈ��.
		for ( i = 0; i < vwp; i++){
			Fill(Virus[i].i, Virus[i].j);
		}

		// �������� ���� ���ϱ�
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (mirror[i][j] == 0) cnt++;
			}
		}

		if (max < cnt) max = cnt;
		return;
	}

	// ������.
	if (wall_cnt > 0){
		map[Q[n].i][Q[n].j] = 1;
		DFS(n + 1, wall_cnt - 1);
		map[Q[n].i][Q[n].j] = 0;
	}
	DFS(n + 1, wall_cnt);

}

int main(void){
	Input_Data();

	DFS(0, 3);
	printf("%d", max);

	return 0;
}