//
//  도서관.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 5..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 1
#include <stdio.h>
int N;
typedef struct {
  unsigned int s,e;
} Time;

Time longest_stay, shortest_stay;
Time tmp_longest_stay, tmp_shortest_stay;

Time list[10000+10];
Time tmp[10000+10];

void Merge(int s,int e, int m){
  int idx1, idx2, idxtmp;
  idx1 = s; idx2 = m+1; idxtmp = s;

  while (idx1 <= m && idx2 <= e) {
    if(list[idx1].s < list[idx2].s){
      tmp[idxtmp++] = list[idx1++];
    }else{
      tmp[idxtmp++] = list[idx2++];
    }
  }

  if(idx1 <= m){
    while (idx1 <= m) tmp[idxtmp++] = list[idx1++];
  }else{
    while (idx2 <= e) tmp[idxtmp++] = list[idx2++];
  }

  for (idxtmp=s; idxtmp<=e; idxtmp++) {
    list[idxtmp] = tmp[idxtmp];
  }
}

void MergeSort(int s, int e){
  int m;
  if(s >=e)return;
  m = (s+e)/2;
  MergeSort(s, m);
  MergeSort(m+1, e);
  Merge(s,e,m);
}

int main(void)
{
  int i;

  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  scanf("%d", &N);
  for (i=1; i<=N; i++) {
    scanf("%u %u", &list[i].s, &list[i].e);
  }

  MergeSort(1,N);



  for (i=1; i<=N; i++) {
    if(i==1){
      tmp_longest_stay = list[i];
      continue;
    }

    if(tmp_longest_stay.e >= list[i].s){
      if(tmp_longest_stay.e <= list[i].e){
        tmp_longest_stay.e = list[i].e;
      }
    } else {


      tmp_shortest_stay.s = tmp_longest_stay.e;
      tmp_shortest_stay.e = list[i].s;

      tmp_longest_stay = list[i];
    }

    if(tmp_longest_stay.e-tmp_longest_stay.s > longest_stay.e-longest_stay.s){
      longest_stay = tmp_longest_stay;
    }
    if(tmp_shortest_stay.e-tmp_shortest_stay.s > shortest_stay.e - shortest_stay.s){
      shortest_stay = tmp_shortest_stay;
    }
  }

  printf("%d %d", longest_stay.e-longest_stay.s, shortest_stay.e - shortest_stay.s);

  return 0;
}

#endif
