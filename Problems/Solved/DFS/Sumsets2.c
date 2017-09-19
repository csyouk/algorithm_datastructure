임의의 숫자 N(N≤64)이 주어졌을 때 2의 제곱수들의 합이 N이 되는 경우가 총 몇 가지가 있는지 알아내는 프로그램을 작성하라.
예를 들어 N=7일 경우는 다음과 같이 6가지가 존재한다.
1.    1+1+1+1+1+1+1
2.    1+1+1+1+1+2
3.    1+1+1+2+2
4.    1+1+1+4
5.    1+2+2+2
6.    1+2+4

입력
첫 번째 줄에는 테스트 케이스의 개수 T(1≤T≤64)가 주어지며, 각 테스트 케이스는 한 줄에 정수 N이 입력된다.
출력
각 테스트 케이스에 대해 가능한 경우의 수가 몇 가지인지 출력한다.
입력 예시
2
1
7
출력 예시
1
6


//
//  Sumsets2.c
//
//  Created by youkchangsu on 2017. 9. 19..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#if 1
#include <stdio.h>

int T, N, cnt;

int p(int b, int e){
  int r=1;
  while (e--) {
    r *= b;
  }
  return r;
}

void DFS(int n, int sum, int e){
  if(sum > N) return;
  if(sum == N){
    cnt++;
    return;
  }
  if(n > N){
    return;
  }

  DFS(n + 1, sum + p(2, e), e);
  DFS(n + 1, sum + p(2, e), e + 1);
}

int main(void){
  int i;


  scanf("%d", &T);
  for (i=1; i<=T; i++) {
    cnt = 0;
    scanf("%d", &N);
    DFS(1, 1, 0);
    printf("%d\n", cnt);
  }

  return 0;
}

#endif
