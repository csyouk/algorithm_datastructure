/*
개구리가 연못 위에서 놀고 있다. 개구리는 N개의 연 잎 들을 이용해서 이리저리 뛰어 놀고 있다.

개구리가 뛰는 장면을 보던 철수는 개구리가 도약을 하는 경우가 얼마나 있는지 궁금해졌다. 여기서 도약은 아래 조건을 만족하는 경우를 말한다.

1. 개구리가 뛴 거리가 이전에 뛴 거리 이상 뛰지만 그 2배보다 멀리 뛰지는 않는다.
2. 개구리는 오른쪽으로만 뛴다.
3. 개구리는 두 번만 뛴다.
4. 위 세 가지 조건을 만족한다면 어느 곳에서든 시작할 수 있다.

허나, 연 잎 들이 너무 많기 때문에 가능한 횟수가 매우 많아질 것 같다고 생각한 철수는, 개구리가 오른쪽으로 도약하는 경우가 얼마나 되는지 구해달라고 했다. 철수를 위해 프로그램을 짜주자.
입력
첫 번째 줄에는 연 잎의 수 N(3 ≤ N ≤ 1,000)이 주어진다.
두 번째 줄부터 N개의 줄에는 각 연 잎의 좌표가 주어진다. 모든 좌표는 0 이상 108 이하이다.

출력
개구리가 오른쪽으로 도약하는 경우의 수를 출력한다.

입력 예시
5
3
1
10
7
4
출력 예시
4
도움말
개구리가 오른쪽으로 도약하는 경우는 다음 4가지뿐이다.
(1, 3, 7), (1, 4, 7), (4, 7, 10), (1, 4, 10)
*/
//
//  도약.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 6..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 1
#include <stdio.h>
int N, freq;
int pos[1000+10];
int tmp[1000+10];

void Merge(int s, int e, int m){
  int idx1, idx2, idxtmp;
  idx1 = s; idx2 = m+1; idxtmp = s;

  while (idx1 <= m && idx2 <= e) {
    if(pos[idx1] < pos[idx2]){
      tmp[idxtmp++] = pos[idx1++];
    }else{
      tmp[idxtmp++] = pos[idx2++];
    }
  }

  if(idx1 <= m){
    while (idx1 <= m) tmp[idxtmp++] = pos[idx1++];
  }else{
    while (idx2 <= e) tmp[idxtmp++] = pos[idx2++];
  }

  for (idxtmp=s; idxtmp<=e; idxtmp++) {
    pos[idxtmp] = tmp[idxtmp];
  }
}

void MergeSort(int s, int e){

  int m;
  if(s >= e) return;
  m = (s+e)/2;
  MergeSort(s, m);
  MergeSort(m+1, e);

  Merge(s,e,m);
}

void calculate(void){
  int i,j,k;
  for (i=1; i<=N-2; i++) {
    for (j=i+1; j<=N-1; j++) {
      for (k=j+1; k<=N; k++) {
        if((pos[j] - pos[i]) <= (pos[k]-pos[j]) && (pos[k]-pos[j]) <= 2*(pos[j] - pos[i])){
          freq++;
        }
      }
    }
  }
}

int main(void)
{
  int i;
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);
  scanf("%d", &N);

  for (i=1; i<=N; i++) {
    scanf("%d", &pos[i]);
  }

  MergeSort(1,N);

  calculate();

  printf("%d", freq);

  return 0;
}

#endif
