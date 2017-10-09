//
//  스도쿠.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 9..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 1
#include <stdio.h>
typedef struct {
  int i, j;
} Pos;

Pos void_list[100];

int N, flag;
int map[10][10];

void show(void);


int find(Pos pos, int digit){

  int i, j;
  for (i=1; i<=9; i++) {
    if(map[pos.i][i] == digit) return 1;
    if(map[i][pos.j] == digit) return 1;
  }

  pos.i = (pos.i-1)/3 * 3 + 1;
  pos.j = (pos.j-1)/3 * 3 + 1;

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      if(map[pos.i + i][pos.j + j] == digit) return 1;
    }
  }
  return 0;
}

void DFS(int n){
  Pos out; int i;

  if(n >= N){
    flag = 1;
    return;
  }
  out = void_list[n];
  for (i=1; i<=9; i++) {
    if(find(out, i)) continue;
    map[out.i][out.j] = i;
    DFS(n + 1);
    if(flag) return;
    map[out.i][out.j] = 0;
  }
}

void show(){
  int i,j;
  for (i=1; i<=9; i++) {
    for (j=1; j<=9; j++) {
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  int i, j;
  for (i=1; i<= 9; i++) {
    for (j=1; j<=9; j++) {
      scanf("%d", &map[i][j]);
      if(!map[i][j]){
        void_list[N].i = i; void_list[N].j = j; N++;
      }
    }
  }


  DFS(0);
  show();

  return 0;
}

#endif
