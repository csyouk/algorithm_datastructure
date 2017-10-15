#if 01
#include <stdio.h>
#include <math.h>

typedef struct{
	int i, j, len, area;
} Pos;

Pos Q[50000];

int N, white, blue;
int map[129][129];
int rp, wp;

void Input_Data(){
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

Pos area_num_to_pos(int i, int j, int k_th,int len){
	Pos tmp;


	tmp.i = i + (k_th / (2)) * len;
	tmp.j = j + (k_th % (2)) * len;

	return tmp;
}

int is_homogeneous(int r, int c, int len){
	int i, j, flag;
	map[r][c] ? (flag = 1) : (flag = 0);
	for (i = r; i <r + len; i++)
	{
		for (j = c; j <c+ len; j++)
		{
			if (map[i][j] != flag) return 0;
		}
	}
	return 1;
}

void BFS(){
	Pos out, in, tmp;
	int i, j, k;

	in.i = 0; in.j = 0; in.len = N; in.area = N * N;
	Q[wp++] = in;

	while (rp < wp)
	{
		out = Q[rp++];
		if (is_homogeneous(out.i, out.j, out.len)){
			if (map[out.i][out.j]) blue++;
			else white++;
			continue;
		}
		for (k = 0; k < 4; k++)
		{
			tmp = area_num_to_pos(out.i, out.j, k, out.len/2);
			in.i = tmp.i;
			in.j = tmp.j;
			in.len = out.len / 2;
			Q[wp++] = in;
		}
	}
}

int main(void){
	Input_Data();

	BFS();

	printf("%d\n%d", white, blue);

	return 0;
}

#endif




// 선생님 풀이
#if 1
#include <stdio.h>

int N;
int paper[128][128];
int cnt[2];

void Input_Data(void)
{
	int r, c;
	scanf("%d",&N);
	for (r = 0; r < N;r++)
	{
		for (c = 0; c < N;c++)
		{
			scanf("%d",&paper[r][c]);
		}
	}
}

void Count_Paper(int sr, int sc, int size)
{
	int color,r,c,er,ec;

	color = paper[sr][sc];
	er = sr + size - 1;
	ec = sc + size - 1;

	for (r = sr; r <= er ;r++)
	{
		for (c = sc; c <= ec;c++)
		{
			if (paper[r][c] != color) goto END_OF_LOOP;
		}
	}

END_OF_LOOP:
	if (r == er + 1) cnt[color]++;
	else
	{
		Count_Paper(sr, sc, size/2);
		Count_Paper(sr, sc + (size / 2), size / 2);
		Count_Paper(sr + (size / 2), sc, size / 2);
		Count_Paper(sr + (size / 2), sc + (size / 2), size / 2);
	}
}


int main(void)
{
	Input_Data();

	Count_Paper(0,0,N);

	printf("%d\n%d\n",cnt[0],cnt[1]);

	return 0;
}
#endif
