//
//  기업투자.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 6..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#if 0
#include <stdio.h>
#define FIND 1
#define N_FIND 0

int Table[30 + 10][1 + 7 + 10];
int Company[7 + 10];
int M, C, max=0x80000000;

int DFS(int company, int money, int sum){
  int i, found = 0;

  if (company > C ){
    if (max < sum) {
      max = sum;
      return FIND;
    }
    return N_FIND;
  }
  
  for ( i = 0; i <= money; i++)
  {
    if(DFS(company + 1, money - i, sum + Table[i][company])){
      Company[company] = i;
      found = 1;
    }
  }
  return found;
}

int main(void){
  
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);
  
  int i, j;
  scanf("%d %d", &M, &C);
  
  for ( i = 1; i <= M; i++)
  {
    for ( j = 0; j <=C; j++)
    {
      scanf("%d", &Table[i][j]);
    }
  }
  
  DFS(1, M, 0);
  
  printf("%d\n", max);
  
  for (i = 1; i <= C; i++) printf("%d ", Company[i]);
}
#endif
