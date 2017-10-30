//
//  암호만들기.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 21..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

// 영어 모음 a,e,i,o,u
// 최소 1개 모음 최소 2개 자음
// 오름차순
#include <stdio.h>
#include <stdlib.h>
#define IS_MOEUM (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u')
int L, C;
char alphabet[17];
int choice[17];

int comp(const void * p1, const void *p2){
  return (*(char *)p1) - (*(char *)p2);
}

void DFS(int n, int k){
  int i;
  if(n > L){
    int jaeum, moeum;
    jaeum = moeum = 0;
    for (i=1; i<=C; i++) {
      if(choice[i] == 0) continue;
      if(IS_MOEUM){
        moeum++;
      }else{
        jaeum++;
      }
    }
    if(moeum < 1) return;
    if(jaeum < 2) return;
    for (i=1; i<=C; i++) {
      if(choice[i] && alphabet[i]){
        printf("%c", alphabet[i]);
      }
    }
    printf("\n");
    return;
  }
  for (i=k; i<=C; i++) {
    choice[i] = 1;
    DFS(n+1, i+1);
    choice[i] = 0;
  }
}

int main(void){
  int i;

  scanf("%d %d", &L, &C);
  for (i=1; i<=C; i++) {
    scanf(" %c", &alphabet[i]);
  }

  qsort(alphabet + 1, C, sizeof(char), comp);

  DFS(1, 1);

  return 0;
}
