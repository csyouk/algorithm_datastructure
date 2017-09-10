//
//  벽장문의이동.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 5..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 0
#pragma warning (disable:4996)
#include <stdio.h>
#define ABS(a) (((a)>0)?(a):(-(a)))

int D[20 + 10]; // 인풋 배열 : 오픈할 문의 순서
int NN, D1, D2, N;
int MIN = 0x7fffffff;

void DFS(int n, int move, int d1, int d2) {
  
  // leaf.
  if (n > N) {
    printf("====>%d %d %d %d\n", n, move, d1, d2);
    if (move < MIN) {
      
      MIN = move;
    }
    return;
  }
  
  // binary tree. 두개의 문 각각의 경우로 나뉨.
  
  // 1. 첫번째 문의 <열림>을 움직이는 경우
  DFS(n + 1, move + ABS(D[n] - d1), D[n], d2); // 움직인 거리를 더하고 다음으로.
  
  // 2. 두번째 문의 <열림>을 움직이는 경우
  DFS(n + 1, move + ABS(d2 - D[n]), d1, D[n]);
}



int main(void) {
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  int i;
  scanf("%d %d %d %d", &NN, &D1, &D2, &N);
  for (i = 1; i <= N; i++) scanf("%d", &D[i]);
  DFS(1, 0, D1, D2);
  printf("%d", MIN);
  return 0;
}
#endif
