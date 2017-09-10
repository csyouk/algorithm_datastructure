//
//  안전영역.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 2..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#if 0
#include <stdio.h>
#define SIZE 110
#define N_SINKED -1
#define DIRS 4
typedef struct _tile{
  int x;
  int y;
} Tile;

Tile Q[SIZE * SIZE];
Tile empty;
int RP, WP, N, hmin=0x7fffffff, hmax=0x80000000;
int segments = 0x80000000;
int map[SIZE][SIZE];
int chk[SIZE][SIZE];
int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Delete_Over_N(int n){
  int i, j;
  for (i = 1; i <= N ; i++) {
    for (j = 1; j <= N ; j++) {
      if(map[i][j] > n){
        chk[i][j] = N_SINKED;
      }
      else{
        chk[i][j] = map[i][j];
      }
    }
  }
}
void Init_Q(){
  for (int i =0; i<SIZE*SIZE; i++) {
    Q[i] = empty;
  }
  RP = WP = 0;
}
void Print_maps(void){
  printf("check========\n");
  for (int i = 1; i<=N; i++) {
    for (int j = 1; j<=N; j++) {
      printf("%d", chk[i][j]);
    }
    printf("\n");
  }
  
  printf("maps=========\n");
  for (int i = 1; i<=N; i++) {
    for (int j = 1; j<=N; j++) {
      printf("%d", map[i][j]);
    }
    printf("\n");
  }
}
void BFS(int x, int y, int seg_id){
  int k, ni,nj;
  Tile pop;
  Q[WP].x = x;
  Q[WP++].y = y;
  chk[x][y] = seg_id;
  while (RP < WP) {
    pop = Q[RP++];
    for (k = 0; k < DIRS; k++) {
      ni = pop.x + di[k];
      nj = pop.y + dj[k];
      if( ni < 1 || ni > N || nj < 1 || nj > N) continue;
      if(chk[ni][nj] != N_SINKED) continue;
      Q[WP].x = ni; Q[WP++].y = nj; chk[ni][nj] = seg_id;
    }
  }
}

void BFS_ALL(int min, int max){
  int i,j, k, cnt;
  for (k = min-1; k <= max; k++) {
    Delete_Over_N(k);
    Init_Q();
    cnt = 0;
//    Print_maps();
    for (i = 1; i <= N ; i++) {
      for (j = 1; j<= N; j++) {
        if(chk[i][j] != N_SINKED) continue;
        BFS(i,j, cnt);
        RP = WP = 0;
        cnt ++;
      }
    }
//    Print_maps();
    if(segments < cnt) segments = cnt;
  }
}

int main(void)
{
  int i,j;
//  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  
  scanf("%d", &N);
  
  for (i = 1; i <= N; i++) {
    for (j = 1; j<= N; j++) {
      scanf("%d", &map[i][j]);
      if(hmin > map[i][j]){ hmin = map[i][j];};
      if(hmax < map[i][j]){ hmax = map[i][j];};
    }
  }
  Print_maps();
  BFS_ALL(hmin,hmax);
  
  printf("%d", segments);
  
  return 0;
}
#endif
