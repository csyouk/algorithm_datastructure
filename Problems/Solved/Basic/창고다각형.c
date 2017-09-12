//
//  창고다각형.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 9..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 0
#include <stdio.h>
typedef struct _rod{
  int p, h;
} Rod;
Rod rods[1010];

int N;
int height[1010];

int area(void){
  int i, r=0;
  for (i=0; i<1010; i++) {
    r += height[i];
  }
  return r;
}
void sort(void){
  int i,j;
  Rod tmp;
  for (i=1; i<=N-1; i++) {
    for (j=i+1; j<=N; j++) {
      if(rods[i].p > rods[j].p){
        tmp = rods[i];
        rods[i] = rods[j];
        rods[j] = tmp;
      }
    }
  }
}
int main(void) {
  int i, j, p, h;
  Rod max;
  max.h = 0; max.p = 0;
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  scanf("%d", &N);
  for (i=1; i<=N; i++) {
    scanf("%d %d", &p, &h);
    rods[i].p = p; rods[i].h = h;
    height[rods[i].p] = rods[i].h;
  }
  
  sort();
  
  for (i = 1; i <= N; i++) {
    if(max.h <= rods[i].h) {
      for (j = max.p; j < rods[i].p; j++) {
        height[j] = max.h;
      }
      max = rods[i];
    }
  }
  
  for (i = 1; i <= N; i++) {
    if(max.h > rods[i].h){
      for (j = rods[i].p; j > max.p; j--) {
        if(height[j] > rods[i].h) break;
        height[j] = rods[i].h;
      }
    }
  }

  
  
  printf("%d", area());
  
  return 0;
}

#endif
