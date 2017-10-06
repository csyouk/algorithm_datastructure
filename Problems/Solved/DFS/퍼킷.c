/*
퍼킷은 유명하고 맛있는 음식이다. 퍼킷을 만들기 위해서는 재료를 신중하게 골라야 한다. 당신은 N개의 재료를 갖고 있으며 각각의 재료의 신맛의 정도 S와 쓴맛의 정도 B를 알고 있다. 주어진 재료로 퍼킷을 만들 경우, 퍼킷의 신맛은 재료 각각의 신맛 정도의 곱이고, 퍼킷의 쓴맛은 재료 각각의 쓴맛 정도의 합으로 나타낼 수 있다. 퍼킷이 맛있어 지려면 신맛의 정도와 쓴맛의 정도의 차이가 작을수록 맛있어진다. N개의 재료가 주어질 때 최고의 퍼킷을 만들어 보라.
* C 제출은 다음 Template을 복사하여 코드를 작성하시오.
입력
첫 번째 줄에는 재료 개수 N(2≤N≤10)이 입력 된다. 두 번째 줄부터 N+1 번째 줄에는 각 재료의 신맛 정도 S와 쓴맛 정도 B가 입력된다. B와 S는 모두 1,000,000,000 보다 작은 양의 정수이다.
출력
주어진 재료로 만들 수 있는 최고 퍼킷의 신맛과 쓴맛의 차이를 출력하라.
입력 예시
4
1 7
2 6
3 8
4 9
출력 예시
*/

//
//  퍼킷.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 5..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 1
#include <stdio.h>
#define LL long long int
#define ABS(x)  (((x) > 0) ? (x) : -(x))

int N;
typedef struct {
  LL s,b;
}Pucket;
Pucket puckets[10+10];

LL min = 0x7fffffffffffffff;


void DFS(int n, LL ts, LL tb){

  if(n > N){
    if(ts == 1 && tb == 0) return;
    if( ABS(ts-tb) < min ) {
      min = ABS(ts-tb);
    }
    return;
  }

  DFS(n+1, ts * puckets[n].s, tb + puckets[n].b);
  DFS(n+1, ts, tb);
}

int main(void)
{
  int i;
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);
  scanf("%d", &N);
  for (i=1; i<=N; i++) {
    scanf("%lld %lld", &puckets[i].s, &puckets[i].b);
  }

  DFS(1, 1, 0);

  printf("%lld", min);

  return 0;
}
#endif
