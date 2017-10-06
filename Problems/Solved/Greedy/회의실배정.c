/*
회의실이 하나 있다. 여러 회의들이 시작시간과 종료시간이 예약되어 있으며, 시간대가 겹치는 회의는 동시에 개최가 불가능하다. 따라서 같은 시간대에 속하는 회의들 중 하나만 개최하고 나머지 회의들은 버려야 한다.

단, 종료시간과 시작시간이 같은 경우에는 시간이 겹친다고 말하지 않는다. 회의의 개수 N과 각 회의의 시작시간, 종료시간이 주어졌을 때 되도록 많은 회의를 개최하고자 한다.

회의를 최대한 많이 배정하는 프로그램을 작성하시오.
입력
첫 줄에는 회의의 수 N(5<=N<=500), 둘째 줄부터 i-1번 회의의 번호와 시작시간과 종료시간이 차례로 주어진다. (500이하의 정수)
출력
첫 줄에는 배정 가능한 최대의 회의수를 출력하고 다음 줄부터는 배정한 회의의 번호를 시간대 순으로 출력한다. 만약, 답이 여러 가지(최대 회의수가 될 수 있는 배정 방법이 여러가지)라면 그 중 아무거나 하나 출력한다.
입력 예시
6
1 1 10
2 5 6
3 13 15
4 14 17
5 8 14
6 3 12
출력 예시
3
2 5 4

*/
//
//  회의실배정.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 27..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 1
#include <stdio.h>
int N;
typedef struct {
  int i, s, e;
} Meet;

Meet Q[510];
Meet tmp[510];

int rp, wp;

int main(void){
  int i,j;
  Meet tMeet;
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);
  scanf("%d", &N);

  for (i=1; i<=N; i++) {
    scanf("%d %d %d", &tmp[i].i, &tmp[i].s, &tmp[i].e);
  }

  for (i=1; i<=N-1; i++) {
    for (j=i+1; j<=N; j++) {
      if(tmp[i].e > tmp[j].e){
        tMeet = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = tMeet;
      }
    }
  }

  Q[wp++] = tmp[1];

  for (i=2; i<=N; i++) {
    if( tmp[i].s < Q[rp].e ) continue;
    Q[wp++] = tmp[i];
    rp++;
  }
  printf("%d\n", wp);
  rp=0;
  while (rp < wp) {
    printf("%d ", Q[rp++].i);
  }
  return 0;
}
#endif
