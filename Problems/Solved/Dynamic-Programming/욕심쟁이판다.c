#include <stdio.h>
#include <stdlib.h>
#define DIRS 4

typedef struct {
	int i, j, cnt;
}Pos;

Pos p[250000];
int N, wp;
int map[502][502];
int cost[502][502];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};


int comp(const Pos * p1, const Pos * p2){
	return p1->cnt - p2->cnt;
}

void Input_Data(void){
	int i, j;
	scanf("%d", &N);
	for ( i = 1; i <= N; i++)
	{
		for ( j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			p[wp].i = i; p[wp].j = j; p[wp++].cnt = map[i][j];
			cost[i][j] = 1;
		}
	}

	qsort(p, N*N, sizeof(Pos), comp);
	return ;
}

void Make(){
	int i, k, ni, nj;

	for ( i = 0; i < N*N; i++)
	{
		for (k = 0; k < DIRS; k++)
		{
			ni = p[i].i + di[k];  nj = p[i].j + dj[k];
			if ((map[ni][nj] > p[i].cnt) && (cost[ni][nj] < cost[p[i].i][p[i].j] + 1)){
				cost[ni][nj] = cost[p[i].i][p[i].j] + 1;
			}
		}
	}
}

int Find(){
	int i,j,max = (1 << 31);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (max < cost[i][j]) max = cost[i][j];
		}
	}
	return max;
}
int main(void){
	Input_Data();
	Make();
	printf("%d", Find());
	return 0;
}




/// DFS + Memoization
//
//  판다.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 16..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#include <stdio.h>
#define DIRS 4

int N, max = (1<<31);
int map[502][502];
int cost[502][502];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Input_Data(void){
  int i, j;
  scanf("%d",&N);

  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
      scanf("%d",&map[i][j]);
}

void DFS(int i, int j){
  int k, ni, nj, _cost=0;
  for (k=0; k<DIRS; k++) {
    ni = i + di[k]; nj = j + dj[k];
    if(ni < 1 || ni > N || nj < 1 || nj > N) continue;
    if(map[ni][nj] >= map[i][j]) continue;
    if(cost[ni][nj] == 0) {DFS(ni,nj);}
    if(_cost < cost[ni][nj]) {_cost = cost[ni][nj];}
  }

  cost[i][j] = _cost + 1;
  if(max < cost[i][j]) max = cost[i][j];
}

void Find(void){
  int i, j;
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
      if(cost[i][j] == 0) DFS(i, j);
}

int main(void){
  Input_Data();
  Find();
  printf("%d", max);
}
