#include <stdio.h>
#include <string.h>
#define WALL '.' // replace as 0 when done
#define DIRS 4

typedef struct {
	int i, j;
} Pos;

Pos PosEntries[900];
int EntryRP, EntryWP;

// 큐에 같은 위치에 대한 복수개의 요소가 들어갈 수 이씩 때문에,
// 최대한 넉넉하게 사이즈를 잡아주는 것이 좋다.
Pos Q[30000];
int RP, WP;

int T, N, A, B, maxtime;

char map[32][32];
unsigned int time[32][32];

int di[DIRS] = { -1, 1, 0, 0 };
int dj[DIRS] = { 0, 0, -1, 1 };

void Input_Data(void){
	int i, j;
	scanf("%d %d %d", &N, &A, &B);
	for (i = 1; i <= N; i++)
	{
		scanf("%s", &map[i][1]);
		for (j = 1; j <= N; j++)
		{
			PosEntries[EntryWP].i = i;
			PosEntries[EntryWP++].j = j;
		}
	}
}



void BFS(void){
	int i,j, k, ni, nj, t;
	Pos data, ndata;

	while (EntryRP < EntryWP){
		// init time table
		for (i = 0; i < 32; i++)
			for (j = 0; j < 32; j++)
				time[i][j] = -1;

		RP = WP = 0;
		data = PosEntries[EntryRP++];
		time[data.i][data.j] = 0;
		Q[WP++] = data;

		while (RP < WP){
			data = Q[RP++];
			for (k = 0; k < DIRS; k++)
			{
				ni = data.i + di[k];
				nj = data.j + dj[k];
				if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
				t = ((map[ni][nj] == map[data.i][data.j]) ? A : B);
				if (time[ni][nj] <= time[data.i][data.j] + t) continue;
				time[ni][nj] = time[data.i][data.j] + t;
				Q[WP].i = ni; Q[WP++].j = nj;
			}
		}

		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				if (maxtime < time[i][j]) maxtime = time[i][j];
	}

}

int main(void){
	scanf("%d", &T);

	while (T--)
	{
		maxtime = 0;
		//EntryWP = EntryRP = 0;
		Input_Data();
		BFS();
		printf("%d\n", maxtime);
	}

	return 0;
}