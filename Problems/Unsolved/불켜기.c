#include <stdio.h>
#include <stdlib.h>
#define DIRS 4
typedef struct
{
	int sw_r, sw_c;
	int led_r, led_c;
}SWITCH;

int N, M;
int map[102][102];
int vis[102][102];
int lut[102][102];

int sw_flag;

SWITCH sw[20001];


void Init(void){
	memset(map, 0, sizeof(map));
	memset(vis, 0, sizeof(vis));
	memset(lut, 0, sizeof(lut));
	sw_flag = 1;
}

void Input_Data(void){
	int i;
	scanf("%d %d", &N, &M);
	for ( i = 1; i <=M; i++)
	{
		scanf("%d %d %d %d", &sw[i].sw_r, &sw[i].sw_c, &sw[i].led_r, &sw[i].led_c);
	}
}

int comp(const void * p1, const void * p2){
	if (((SWITCH *)p1)->sw_r == ((SWITCH *)p2)->sw_r) return ((SWITCH *)p1)->sw_c - ((SWITCH *)p2)->sw_c;
	else return ((SWITCH *)p1)->sw_r - ((SWITCH *)p2)->sw_r;
}

void Make_Lookup_Table(void){
	int i;
	for ( i = 1; i <=M; i++)
	{
		if ((sw[i].sw_r != sw[i - 1].sw_r) || (sw[i].sw_c != sw[i - 1].sw_c)){
			lut[sw[i].sw_r][sw[i].sw_c] = i;
		}
	}
}

void Turn_Lights(int start_index, int r, int c){
	int i;
	sw_flag = 1;
	for (i = start_index; i <= M; i++)
	{
		if (sw[i].sw_r != r || sw[i].sw_c != c) break;
		if (map[sw[i].led_r][sw[i].led_c] == 0){
			map[sw[i].led_r][sw[i].led_c] = 1;
		}
	}
	lut[r][c] = 0;
}

void Flood_Fill(int r, int c){
	int k, nr, nc;
	static int dr[] = {-1,1,0,0};
	static int dc[] = {0,0,-1,1};

	vis[r][c] = 1;

	if (lut[r][c]){ Turn_Lights(lut[r][c], r, c); }

	// flood fill
	for ( k = 0; k < 4; k++)
	{
		nr = r + dr[k]; nc = c + dc[k];
		if (map[nr][nc] && !vis[nr][nc]){
			Flood_Fill(nr, nc);
		}
	}
}


int Count(void){
	int r, c, cnt=0;
	for ( r = 1; r <=N; r++)
	{
		for ( c = 1; c <=N; c++)
		{
			if (map[r][c]) cnt++;
		}
	}
	return cnt;
}

void Init_Enviroment(void){
	sw_flag = 0;
	memset(vis, 0, sizeof(vis));
	map[1][1] = 1;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		Init();
		Input_Data();
		qsort(sw + 1, M, sizeof(SWITCH), comp);
		Make_Lookup_Table();

		sw_flag = 1;
		while (sw_flag)
		{
			Init_Enviroment();
			Flood_Fill(1, 1);
		}
		printf("%d\n", Count());
	}
	return 0;
}
