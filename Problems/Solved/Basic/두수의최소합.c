//
//  두수의최소합.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 2..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 01
#include <stdio.h>
#define CHECK -1
#define MSD 0
typedef struct _operand{
  int cnt;
  int digits[8];
  int sum;
} Op;
Op L, R;
int N;
int data[20];

void sort_ascending(void){
  int i,j,tmp;
  for (i = 0; i < N-1; i++) {
    for (j = i+1; j < N; j++) {
      if(data[i] > data[j]){
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
      }
    }
  }
}
void Set_MSD(Op * op){
  int i;
  for (i = 0; i< N; i++) {
    if(data[i] == 0) continue;
    if(data[i] == CHECK) continue;
    op->digits[MSD] = data[i];
    (op->cnt)++;
    data[i] = CHECK;
    return;
  }
}
void assemble(void){
  int i, weight = 1;
  for (i = 0; i<N; i++) {
    if(data[i] == CHECK) continue;
    if(i%2){
      R.digits[R.cnt++] = data[i];
    }else{
      // LSD 가 가장 작은 우선적으로 배치한다.
      L.digits[L.cnt++] = data[i];
    }
    data[i] = CHECK;
  }

  while (L.cnt) {
    L.sum += L.digits[L.cnt-1]*weight;
    weight *= 10;
    L.cnt--;
  }
  weight = 1;
  while (R.cnt) {
    R.sum += R.digits[R.cnt-1]*weight;
    weight *= 10;
    R.cnt--;
  }


}
int main(void){

  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  Op * l, * r;

  scanf("%d", &N);
  for (int i =0; i < N; i++) {
    scanf("%d", &data[i]);
  }
  l = &L;
  r = &R;
  sort_ascending();
  Set_MSD(l);
  Set_MSD(r);

  assemble();


  printf("%d", L.sum + R.sum);


  return 0;
}

#endif
