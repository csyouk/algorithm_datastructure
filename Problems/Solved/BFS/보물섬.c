//
//  보물섬.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 11..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
// BFS 문제이다.

#if 01
#include <stdio.h>
#define DIRS 4
typedef struct _area{
  int i, j, dis;
}Area;
Area Q[100 * 100];

int R, C, RP, WP, max = 0x80000000;
char map[60][60];
int chk[60][60];
int dis[60][60];

int di[DIRS] = { 0,-1, 0, 1};
int dj[DIRS] = {-1, 0, 1, 0};

void BFS(int i, int j, int d){
  int ni, nj, k;
  Area tmp;

  tmp.i = i; tmp.j = j; tmp.dis = d;
  dis[i][j] = d;
  Q[WP++] = tmp;


  while (RP < WP){
    tmp = Q[RP++];
    if (max < tmp.dis) max = tmp.dis;
    for ( k = 0; k < DIRS; k++){
      ni = tmp.i + di[k];    nj = tmp.j + dj[k];
      if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
      if (dis[ni][nj]) continue;
      if (chk[ni][nj] == 0) continue;
      Q[WP].i = ni;   Q[WP].j = nj;   Q[WP++].dis = tmp.dis + 1;
      dis[ni][nj] = tmp.dis + 1;
    }
  }

}

void Reset(void){
  int i, j;
  for ( i = 1; i <=R; i++)
  {
    for ( j = 1; j <=C; j++)
    {
      dis[i][j] = 0;
    }
  }
  RP = WP = 0;
}

int main(void){


  int i, j;
  scanf("%d %d", &R, &C);

  for (i = 1; i <= R; i++){
    scanf("%s", &map[i][1]);
  }

  for (i = 1; i <= R; i++){
    for (j = 1; j <= C; j++){
      if (map[i][j] == 'L') chk[i][j] = 1;
    }
  }

  for ( i = 1; i <=R; i++)
  {
    for ( j = 1; j <= C; j++)
    {
      if (chk[i][j] == 0) continue;
      BFS(i, j, 1);
      Reset();
    }
  }

  printf("%d", max-1);

  return 0;
}
#endif
