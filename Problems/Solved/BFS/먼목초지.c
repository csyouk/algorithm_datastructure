#include <stdio.h>
#include <string.h>
#define WALL '.' // replace as 0 when done
#define DIRS 4

typedef struct {
	int i, j;
} Pos;

Pos PosEntries[900];
int EntryRP, EntryWP;

// 큐에 같은 위치에 대한 복수개의 요소가 들어갈 수 있기 때문에,
// 최대한 넉넉하게 사이즈를 잡아주는 것이 좋다.
Pos Q[1000000];
int RP, WP;

int T, N, A, B, maxtime;

char map[32][32];
int time[32][32];
int vis[32][32];

int di[DIRS] = {-1,1,0,0};
int dj[DIRS] = {0,0,-1,1};

void Init(void){
	memset(map, 0, sizeof(map));
	EntryRP = EntryWP = 0; RP = WP = 0;
	maxtime = 0;
}

void Input_Data(void){
	int i, j;
	scanf("%d %d %d", &N, &A, &B);
	for ( i = 1; i <= N; i++)
	{
		scanf("%s", &map[i][1]);
		for ( j = 1; j <= N; j++)
		{
			PosEntries[EntryWP].i = i;
			PosEntries[EntryWP++].j = j;
		}
	}
}

void Find_Max(){
	int i, j;
	for ( i = 1; i <= N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			if (maxtime < time[i][j]) maxtime = time[i][j];
		}
	}
}

void Init_Time_Table(void){
	int i, j;
	for (i = 0; i < 32; i++)
	{
		for (j = 0; j < 32; j++)
		{
			time[i][j] = 0x7fffffff;
		}
	}
}

void BFS(void){
	int  k, ni, nj, t;
	Pos data, ndata;

	while (EntryRP < EntryWP)
	{
		Init_Time_Table();
		RP = WP = 0;
		data = PosEntries[EntryRP++];
		time[data.i][data.j] = 0;
		Q[WP++] = data;

		while (RP < WP)
		{
			data = Q[RP++];
			for ( k = 0; k < DIRS; k++)
			{
				ni = data.i + di[k];
				nj = data.j + dj[k];
				if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
				t = ((map[ni][nj] == map[data.i][data.j]) ? A : B);
				if (time[ni][nj] > time[data.i][data.j] + t) {
					time[ni][nj] = time[data.i][data.j] + t;
					Q[WP].i = ni; Q[WP++].j = nj;
				}
			}
		}
		Find_Max();
	}

}

int main(void){
	scanf("%d", &T);

	while (T--)
	{
		Init();
		Input_Data();
		BFS();
		printf("%d\n", maxtime);
	}

	return 0;
}
