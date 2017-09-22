// 성공 버전.
// edge case를 잡음.
// 하지만 완벽하지는 않다.
#define _CRT_SECURE_NO_WARNINGS

#if 1
#include <stdio.h>
#define DIRS 4

enum Directions {w,n,e,s};

typedef struct {
	unsigned char dir[4];
	unsigned int no;
} Cell;

int R, C, room_cnt, max_area=0x80000000;
int first, second;

int map[50 + 10][50 + 10];
int visited[50 + 10][50 + 10];

int rooms[60 * 60];
int b_rooms[60 * 60];
int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

Cell dir_data[60][60];

void tear_down(int d, int i, int j){
	dir_data[i][j].dir[w] = d & 0x1;
	dir_data[i][j].dir[n] = d>>1 & 0x1;
	dir_data[i][j].dir[e] = d>>2 & 0x1;
	dir_data[i][j].dir[s] = d>>3 & 0x1;
}

int find_big(void){
	int i, max=0x80000000;
	for (i = 1; i <= room_cnt; i++)
	{
		if (max < rooms[i]) max = rooms[i];
	}
	return max;
}

void Fill(int i, int j, int no){
	int k, ni, nj;
	if (dir_data[i][j].no != 0) return;
	dir_data[i][j].no = no;
	visited[i][j] = no;
	rooms[room_cnt]++;

	for ( k = 0; k < DIRS; k++)
	{
		if (dir_data[i][j].dir[k]) continue;
		ni = i + di[k];    nj = j + dj[k];
		if (ni < 1 || nj < 1 || ni > R || nj > C) continue;

		if (dir_data[ni][nj].no) continue;

		Fill(ni, nj, no);


	}
}

void sort(){
	int i, j, tmp;
	for ( i = 0; i <60*60; i++)
	{
		b_rooms[i] = rooms[i];
	}

	for (i = 1; i < 3; i++)
	{
		for ( j = i+1; j < 60*60; j++)
		{
			if (b_rooms[i] < b_rooms[j]){
				tmp = b_rooms[i];
				b_rooms[i] = b_rooms[j];
				b_rooms[j] = tmp;
			}
		}
	}
	first = b_rooms[1];
	second = b_rooms[2];
}


int is_near(int r1, int r2){
	int i, j, k, ni, nj;
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (visited[i][j] != r1) continue;
			for (k = 0; k < DIRS; k++)
			{
				ni = i + di[k];  nj = j + dj[k];
				if (ni < 1 || nj < 1 || ni > R || nj > C) continue;
				if (visited[ni][nj] == r1) continue;
				if (visited[ni][nj] == r2) return 1;
			}
		}
	}
	return 0;
}


int find_max(){
	int i, j;
	for (i = 1; i <= room_cnt; i++)
	{
		for (j = i + 1; j <= room_cnt; j++)
		{
			if (is_near(i, j)){
				if (max_area < (rooms[i] + rooms[j])) { max_area =  rooms[i] + rooms[j]; }
				if (max_area == (first + second)) return max_area;
			}
		}
	}
	return max_area;
}

int main(void){
	int i, j;
	scanf("%d\n%d", &R, &C);
	for (i = 1; i <= R; i++)
	{
		for ( j = 1; j <= C; j++)
		{
			scanf("%d ", &map[i][j]);
			tear_down(map[i][j], i, j);
		}
	}

	for (i = 1; i <=R; i++)
	{
		for ( j = 1; j <= C; j++)
		{
			if (dir_data[i][j].no != 0) continue;
			room_cnt++;
			Fill(i, j, room_cnt);

		}
	}



	//(1) 이 성에 있는 방의 개수
	printf("%d\n", room_cnt);
	//(2) 가장 넓은 방의 넓이
	printf("%d\n", find_big());

	sort();

	//(3) 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
	printf("%d\n", find_max());
	return 0;
}
#endif



// 초반 실패 버전.
// edge case제거에 실패.
#if 0
#include <stdio.h>
#define DIRS 4

enum Directions { w, n, e, s };

typedef struct {
	unsigned char dir[4];
	unsigned int no;
} Cell;

int R, C, room_cnt, max_area = 0x80000000;

int map[50 + 10][50 + 10];
int visited[50 + 10][50 + 10];
int rooms[60 * 60];
int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };

Cell dir_data[60][60];

void tear_down(int d, int i, int j){
	dir_data[i][j].dir[w] = d & 0x1;
	dir_data[i][j].dir[n] = d >> 1 & 0x1;
	dir_data[i][j].dir[e] = d >> 2 & 0x1;
	dir_data[i][j].dir[s] = d >> 3 & 0x1;
}

int find_big(void){
	int i, max = 0x80000000;
	for (i = 1; i <= room_cnt; i++)
	{
		if (max < rooms[i]) max = rooms[i];
	}
	return max;
}

void Fill(int i, int j, int no){
	int k, ni, nj;
	if (dir_data[i][j].no != 0) return;
	dir_data[i][j].no = no;
	visited[i][j] = no;
	rooms[room_cnt]++;

	for (k = 0; k < DIRS; k++)
	{
		if (dir_data[i][j].dir[k]) continue;
		ni = i + di[k];    nj = j + dj[k];
		if (ni < 1 || nj < 1 || ni > R || nj > C) continue;

		if (dir_data[ni][nj].no) continue;

		Fill(ni, nj, no);


	}
}

int is_near(int r1, int r2){
	int i, j, k, ni, nj;
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (visited[i][j] != r1) continue;
			for (k = 0; k < DIRS; k++)
			{
				ni = i + di[k];  nj = j + dj[k];
				if (ni < 1 || nj < 1 || ni > R || nj > C) continue;
				if (visited[ni][nj] != r2) continue;
				return 1;
			}
		}
	}
	return 0;
}

int main(void){
	int i, j;
	scanf("%d\n%d", &R, &C);
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			scanf("%d ", &map[i][j]);
			tear_down(map[i][j], i, j);
		}
	}

	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (dir_data[i][j].no != 0) continue;
			room_cnt++;
			Fill(i, j, room_cnt);

		}
	}



	//(1) 이 성에 있는 방의 개수
	printf("%d\n", room_cnt);
	//(2) 가장 넓은 방의 넓이
	printf("%d\n", find_big());

	//(3) 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기

	for (i = 1; i <= room_cnt; i++)
	{
		for (j = i + 1; j <= room_cnt; j++)
		{
			if (is_near(i, j)){
				if (max_area < (rooms[i] + rooms[j])) max_area = (rooms[i] + rooms[j]);
			}
		}
	}

	printf("%d\n", max_area);
	return 0;
}
#endif
