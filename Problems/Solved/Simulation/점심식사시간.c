// https://www.swexpertacademy.com/main/learn/course/lectureHtmlViewer.do#
//
//  점심식사시간.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 19..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) > (Y) ? (Y) : (X))
#define ABS(X,Y) ((X) > (Y) ? ((X) - (Y)) : ((Y) - (X)))
#define C_DIS(X,Y) (ABS(man[p].c, stair[s].c))
#define R_DIS(X,Y) (ABS(man[p].r, stair[s].r))
// X는 사람의 인덱스, Y는 계단의 인덱스
#define DIS(X,Y) ( (C_DIS(X, Y)) + (R_DIS(X, Y)) )
#define STAIR1 0
#define STAIR2 1
#define STAIRS 2
#define MAX_N (10 + 1)
#define MAX_TIME (2*(MAX_N) + MAX_N * MAX_N)

typedef struct {
  int r, c;
} Pos;

Pos man[MAX_N];  // 사람은 최대 10명
Pos stair[STAIRS]; // 계단은 2개

// N : 방 한변의 길이
// M : 사람의 수
// S : 계단의 수
int T, N, M, S;
int min_time;

int map[MAX_N][MAX_N];
int stair_choice_list[MAX_N];

// 시간이 t일때 계단에 도착하는 사람의 수
int arrival_time[MAX_N * 2];

// 시간 t일때 계단을 내려가고 있는 사람의 수
int current_stair[MAX_TIME];

void Init(void){
  M= S = 0;
  min_time = (~(1<<31));
  memset(arrival_time, 0, sizeof(arrival_time));
}

void Input_Data(void){
  int i, j;
  for (i=1; i<=N; i++) {
    for (j=1;j<=N; j++) {
      scanf("%d", &map[i][j]);
      if(map[i][j] == 1) {man[M].r = i; man[M++].c = j;}
      if(map[i][j] >=  2) {stair[S].r = i; stair[S++].c = j;}
    }
  }
}


void Calculate_Time(void){
  int s, p, time, remain_time, walk_time;
  int total_min_time = 0;
  int now_min_time = 0;
  Pos now_stair;

  for (s = 0; s < STAIRS; s++) {
    now_stair = stair[s];
    for (p = 0; p < M; p++) {
      if(stair_choice_list[p] == s){
        arrival_time[ DIS(p, s) + 1]++;
      }
    }
 }

  for (time = 0; time <= 20; time++) {
    while (arrival_time[time] > 0) {
      arrival_time[time]--;

      remain_time = map[now_stair.r][now_stair.c];

      for (walk_time = time; walk_time < MAX_TIME; walk_time++) {
        if(current_stair[walk_time] < 3){
          current_stair[walk_time]++;
          remain_time--;
          if(remain_time == 0){
            now_min_time = MAX(now_min_time, walk_time + 1);
            break;
          }
        }
      }
    }

    total_min_time = MAX(total_min_time, now_min_time);
  }


  min_time = MIN(min_time, total_min_time);
}




// n은 사람의 index
// 전략 : 사람이 어떤 계단으로 갈것인지 미리 선택을 한다.
// 이진 탐색

void DFS(int n){
  if(n == M){
    Calculate_Time();
    return;
  }

  stair_choice_list[n] = STAIR1;
  DFS(n + 1);
  stair_choice_list[n] = STAIR2;
  DFS(n + 1);

}

int main(void){

  static int tc = 1;
  scanf("%d", &T);
  while (T--) {
    Init();
    Input_Data();
    DFS(0);
    printf("#%d %d\n", tc++, min_time);
  }
}
