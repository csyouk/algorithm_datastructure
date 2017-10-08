//
//  최고의수식을찾아라.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 7..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#include <stdio.h>
#define UNDER4 0
#define OVER5 1
#define SOL 2
#define RATE 3
#define NUM 4
#define THRESHOLD 5


int N, max;

int value[6][7+10]; /// 0번 index는 rate의 합을 저장하는 용도로 사용.
int alpha;

void DFS(int num, int n){
  int i, sum;
  if(n == 0){
    sum = 0;
    for (i=1; i<=7; i++) {
      if(value[RATE][i] < THRESHOLD) {
        sum += (value[UNDER4][i] + alpha)*value[RATE][i];
      } else {
        sum += (value[OVER5][i] + alpha)*value[RATE][i];
      }
    }
    if(max < sum) {
      max = sum;
      for (i=1; i<=7; i++) {
        value[SOL][i] = value[RATE][i];
      }
    }
    return;
  }

  for (i=num; i<=7; i++) {
    if(n < value[NUM][i]) continue;
    value[RATE][i]++;
    DFS(i, n - value[NUM][i]);
    value[RATE][i]--;
  }
}


int main(void){
  int i;
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);
  for (i=1; i<=7; i++) value[NUM][i] = 1<<(i-1);
  scanf("%d", &N);
  for (i=1; i<=7; i++) scanf("%d", &value[UNDER4][i]);
  for (i=1; i<=7; i++) scanf("%d", &value[OVER5][i]);
  scanf("%d", &alpha);

  DFS(1, N);


  printf("%d\n", max);
  for (i=1; i<=7; i++) printf("%d ",value[SOL][i]);



  return 0;
}
