//
//  농장탈출.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 14..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#include <stdio.h>
int N, W[30], max=0x80000000;

int Check(int sum, int nth){
  while (sum) {
    if(sum % 10 < nth % 10) return 0;
    sum /=10; nth /= 10;
  }
  return 1;
}

void DFS(int n, int sum, int cnt){

  if(n > N){
    if(max < cnt) max = cnt;
    return;
  }

  if(Check(sum+W[n], W[n])) DFS(n+1, sum + W[n], cnt + 1);
  DFS(n+1, sum, cnt);
}

int main(void)
{
  

  scanf("%d", &N);
  for (int i = 1; i<=N; i++) scanf("%d", &W[i]);

  DFS(1,0,0);

  printf("%d", max);

  return 0;
}
