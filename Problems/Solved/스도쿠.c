//
//  스도쿠.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 4..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 0
#include <stdio.h>
#define MAP_SIZE 15
#define SIZE 9
#define EMPTY 0
#define PERFECT 45

typedef struct _point{
  int r;
  int c;
} Point;

Point points[MAP_SIZE * MAP_SIZE];

int sudoku[MAP_SIZE][MAP_SIZE];


void DFS(int num){
  
  
  
  
//  int m, n, i;
//  int r_sum=0, c_sum=0;
//  
//  if (depth > SIZE) {
//    return;
//  }
//
//  for (m=1; m<=SIZE; m++) r_sum += sudoku[r][m];
//  for (m=1; m<=SIZE; m++) c_sum += sudoku[m][c];
//  if(r_sum == PERFECT || c_sum == PERFECT){
//    return;
//  }
//  
//  for (i=1; i<=SIZE; i++) {
//    sudoku[r][c] = i;
//    DFS(depth + 1, r, c);
//  }
}

int main(void){
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  int i,j;
  Point tmp;
  for (i=1; i<=SIZE; i++) {
    for (j=1; j<=SIZE; j++) {
      scanf("%d", &sudoku[i][j]);
      if(!sudoku[i][j]){
        tmp.r = i; tmp.c = j;
        points[(i-1)*SIZE + (j-1)] = tmp;
      }
    }
  }
  
  
  DFS(0);
  
  
  for (i=1; i<=SIZE; i++) {
    for (j=1; j<=SIZE; j++) {
      if(sudoku[i][j] != 0) {printf("  "); continue;}
      printf("%d ", sudoku[i][j]);
    }
    printf("\n");
  }
  
 
  return 0;
}

















#endif
