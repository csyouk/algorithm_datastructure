#include <stdio.h>
#include <stdlib.h>

int N, M;
int map[102][102];
int chk[102][102];
int index[102][102];

typedef struct
{
	int sw_r;
	int sw_c;
	int light_r;
	int light_c;
}SW;
SW sw[20001];


int ff_cnt;
int sw_flag;
int sol;

void Input_Data(void)
{
	int i;
	scanf("%d %d",&N,&M);
	map[1][1] = 1;
	for (i = 1; i <= M;i++)
	{
		scanf("%d %d %d %d", &sw[i].sw_r, &sw[i].sw_c, &sw[i].light_r, &sw[i].light_c);
	}
}

int comp(const void* p1,const void* p2)
{
	if (((SW*)p1)->sw_r == ((SW*)p2)->sw_r) return ((SW*)p1)->sw_c - ((SW*)p2)->sw_c;
	return ((SW*)p1)->sw_r - ((SW*)p2)->sw_r;
}

void Make_Index_Data(void)
{
	int i;
	for (i = 1; i <= M;i++)
	{
		if ((sw[i].sw_r != sw[i - 1].sw_r) || (sw[i].sw_c != sw[i - 1].sw_c))
		{
			index[sw[i].sw_r][sw[i].sw_c] = i;
		}
	}
}

void Clear_Chk(void)
{
	int r, c;

	for (r = 1; r <= N;r++)
	{
		for (c = 1; c <= N;c++)
		{
			chk[r][c] = 0;
		}
	}
}

void Flood_Fill(int r,int c)
{
	int nr, nc,i;
	int dr[] = {0,0,1,-1};
	int dc[] = {1,-1,0,0};

	chk[r][c] = 1;

	if (index[r][c])
	{
		sw_flag = 1;
		for (i = index[r][c]; i <= M; i++)
		{
			if (sw[i].sw_r != r || sw[i].sw_c != c) break;
			if (map[sw[i].light_r][sw[i].light_c] == 0)
			{
				map[sw[i].light_r][sw[i].light_c] = 1;
				sol++;
			}
		}
		index[r][c] = 0;
	}

	for (i = 0; i < 4;i++)
	{
		nr = r + dr[i]; nc = c + dc[i];
		if (map[nr][nc] && !chk[nr][nc])
		{
			Flood_Fill(nr, nc);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while (T--)
	{

		memset(sw, 0, sizeof(sw));
		memset(map, 0, sizeof(map));
		Input_Data();
		qsort(sw + 1, M, sizeof(SW), comp);
		Make_Index_Data();
		sw_flag = 1;
		sol = 1;
		while (sw_flag)
		{
			sw_flag = 0;
			Clear_Chk();
			Flood_Fill(1,1);
		}
		printf("%d\n", sol);
	}
	return 0;
}
