#include <stdio.h>
#include <string.h>
#define DIRS 4
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
typedef struct {
	int i, j, dis;
}Pos ;

Pos Q[100000];
Pos MaxHeightEntry[50];
int T, N, K, RP, WP, maxlen, maxheight;
int MaxHWP, MaxHRP;
int map[100][100];
int vis[100][100];

void Init_Data(void){
	memset(map, 0, sizeof(map));
	memset(vis, 0, sizeof(vis));
	memset(MaxHeightEntry, 0, sizeof(MaxHeightEntry));
	RP = WP = 0;
	maxlen = -1;
	maxheight = 0;
	MaxHWP =  MaxHRP = 0;
}

void Input_Data(void){
	int i, j;
	scanf("%d %d", &N, &K);
	for ( i = 1; i <= N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			maxheight = MAX(map[i][j], maxheight);
		}
	}
}

void Init_Q(void){
	int i, j;
	MaxHWP = MaxHRP = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (map[i][j] == maxheight) {
				MaxHeightEntry[MaxHWP].i = i;
				MaxHeightEntry[MaxHWP].j = j;
				MaxHeightEntry[MaxHWP++].dis = 1;
			}
		}
	}
}

void BFS(int cut){
	static int di[] = {-1,1,0,0};
	static int dj[] = {0,0,-1,1};
	int i, k, ni, nj;
	Pos ndata, data;
	// init Q
	Init_Q();

	while (MaxHRP < MaxHWP){
		RP = WP = 0;
		memset(vis, 0, sizeof(vis));
		data = Q[WP] = MaxHeightEntry[MaxHRP++];
		vis[data.i][data.j] = 1;
		WP++;
		while (RP < WP)
		{
			data = Q[RP++];
			ndata = data;
			if (maxlen < ndata.dis) {
				maxlen = ndata.dis;
			}
			for (k = 0; k < 4; k++)
			{
				ndata.i = data.i + di[k]; ndata.j = data.j + dj[k];
				if (ndata.i < 1 || ndata.i > N ||
					ndata.j < 1 || ndata.j > N) continue;
				if (map[ndata.i][ndata.j] >= map[data.i][data.j]) continue;
				if (vis[ndata.i][ndata.j] > vis[data.i][data.j] + 1) continue;
				vis[ndata.i][ndata.j] = vis[data.i][data.j] + 1;

				Q[WP] = ndata;
				Q[WP++].dis += 1;
			}
		}
	}
}

void Find(void){
	int i,j,k,backup;
	for (i = 1; i <= K; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			for ( k = 1; k <= N; k++)
			{
				backup = map[j][k];
				map[j][k] -= i;
				if (map[j][k] < 0) map[j][k] = 0;
				BFS(i);
				map[j][k] = backup;
			}
		}
	}
}

int main(void){
	int i = 1;
	scanf("%d", &T);
	while (T--)
	{
		Init_Data();
		Input_Data();
		Find();
		printf("#%d %d\n", i, maxlen);
		i++;
	}
	return 0;
}
