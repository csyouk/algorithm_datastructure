//
//  lower_upper_bound_binary_search.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 15..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

// 이진 탐색을 할때는, 데이터가 정렬되어 있어야 한다.

#include <stdio.h>
#include <stdlib.h>
#define FAILED (-1)

int data1[] = {-2,3,15,2,-193,-23,53,-661,-4,3,1,6,7,8,9,10,22,35,57,57,51,72,45,81,24,-46,-75};
int data2[100]; // 홀수 데이터를 만든다.
int data3[200]; // 연속 데이터를 만든다.

int comp(const int *p1, const int *p2){
  return *p1 - *p2;
}
void Make_Data(void){
  int i, wp1,wp2;
  wp1 = wp2 = 0;
  for (i=-50; i<51; i++) {
    if(i%2) data2[wp1++] = i;
    data3[wp2++] = i;
  }
}

int Binary_Search_Lower(int s, int e, int lower, int * d){
  int m, sol;
  sol = FAILED;

  while (s<=e) {
    m = (s+e)/2;
    if(lower <= d[m]){
      sol = m;
      e = m-1;
    }else s = m+1;
  }
  return sol;
}

int Binary_Search_Upper(int s, int e, int upper, int *d){
  int m, sol;
  sol = FAILED;

  while (s<=e) {
    m = (s+e)/2;
    if(d[m] <= upper){
      sol = m;
      s = m+1;
    } else e = m-1;
  }

  return sol;
}

int main(void){

  int i, lower, upper;

  // 데이터는 정렬되어 있어야 한다.
  qsort(data1, sizeof(data1)/sizeof(data1[0]), sizeof(int), comp);

  // 홀수용 데이터를 만든다.
  Make_Data();

  // -15 ~30 사이의 데이터 개수를 찾는다.
  lower = Binary_Search_Lower(0, sizeof(data1)/sizeof(data1[0]) - 1, -15, data1);
  if(lower != FAILED){
    upper = Binary_Search_Upper(0, sizeof(data1)/sizeof(data1[0]) -1, 30, data1);
    printf("%d\n", upper - lower + 1);
    i = lower-1; while(i++ < upper) printf("%d ", data1[i]);
  }else printf("0 \n");

  return 0;
}
