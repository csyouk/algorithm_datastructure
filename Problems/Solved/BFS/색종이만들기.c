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