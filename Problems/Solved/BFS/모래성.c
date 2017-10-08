//
//  최고의수식을찾아라!.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 7..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
// 9 이하의 모래가 전부 없어질 것이라는 가정을 세우고 문제를 해결하려고 해서 막혔다.
// 모래의 위치를 기준으로 침식이 있었는지 없었는지 여부를 체크한다.

#include <stdio.h>
#define DIRS 8
#define VOID -1
#define MAX_Q 1000000

typedef struct {
  int i, j;
} Castle;

Castle Q[MAX_Q];
int rp, wp, cnt;

int di[DIRS] = {0,-1,-1,-1,0,1,1,1};
int dj[DIRS] = {-1,-1,0,1,1,1,0,-1};

int R,C;
char map[1010][1010];

int wave(void){
  int k, ni, nj, backup_wp = wp, flag = 0;
  Castle out, in;

  while (rp < backup_wp) {
    out = Q[rp++];
    for (k=0; k < DIRS; k++) {
      ni = out.i + di[k];  nj = out.j + dj[k];
      if(ni < 1 || ni > R || nj < 1 || nj > C) continue;
      if(map[ni][nj] == '.') continue;
      if(map[ni][nj] != '.') map[ni][nj]--;
      if(map[ni][nj] == '0'){
        map[ni][nj] = '.';
        in.i = ni; in.j = nj;  flag = 1;
        Q[wp++] = in;
      }
    }
  }

  return flag;
}

int main(void){
  int i, j;

  scanf("%d %d", &R, &C);
  for (i=1; i<=R; i++) {
    for (j=1; j<=C; j++) {
      scanf(" %c", &map[i][j]);
      if(map[i][j] == '.'){
        Q[wp].i = i;
        Q[wp++].j = j;
      }
    }
  }


  while (wave()) cnt++;

  printf("%d", cnt);
  return 0;
}
