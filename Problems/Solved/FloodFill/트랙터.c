#include <stdio.h>
#include <string.h>
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
#define MIN(x,y) (((x) < (y))? (x) : (y))
#define MAX(x,y) (((x) > (y))? (x) : (y))
#define DIRS 4

typedef struct {
	int i, j;
} Pos;

int N, area;
int  max = 1 << 31, min = ~(1 << 31);
int map[510][502];
int vis[510][502];

int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };

void Init(void){
	memset(&vis[0][0], 0, sizeof(int [510][510]));
}

void Fill(int i, int j, int p){
	int k, ni, nj;
	vis[i][j] = 1;
	area++;
	for ( k = 0; k <DIRS; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
		if (vis[ni][nj] == 0 && ABS(map[ni][nj] - map[i][j]) <= p){
			Fill(ni, nj, p);
		}
	}
}

int Move(int power){
	int i, j, cnt = 1;
	int threshold = (N * N / 2) + (N % 2);
	Init();

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (vis[i][j] != 0) continue;
			area = 0;
			Fill(i, j, power);
			if (threshold <= area) return 1;
		}
	}

	return 0;
}

int Find(){

	int s,e, power, sol;
	s = 0; e = 1000000;
	while (s <= e){
		power = (s + e) / 2;
		if (Move(power)){
			sol = power;
			e = power - 1;
		}
		else {
			s = power + 1;
		}
	}
	return power;
}

void Input_Data(){
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			min = MIN(min, map[i][j]);
			max = MAX(max, map[i][j]);
		}
	}
}

int main(void){

	Input_Data();

	printf("%d", Find());

	return 0;
}
