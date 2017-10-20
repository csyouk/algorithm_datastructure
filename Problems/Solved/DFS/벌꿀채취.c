//
//  벌꿀체취.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 20..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SQR(X) ((X)*(X))
#define Row 0
#define Col 1

typedef struct {
  int r, c, i;
} Pos;

int N, M, C;
int max_profit1, max_profit2, total_max_profit;
int map[12][12];
int vis[12][12];
int lut[12][12];
Pos pos[3];

void Init(void){
  memset(map, 0, sizeof(map));
  memset(vis, 0, sizeof(map));
  max_profit1 = max_profit2 = total_max_profit = -1;
  pos[1].i = 1; pos[0].i = -1;
}

void Input_Data(void){
  int i, j, cnt=1;
  scanf("%d %d %d", &N, &M, &C);
  for (i=1; i<= N; i++) {
    for (j=1; j<=N; j++) {
      scanf("%d", &map[i][j]);
      lut[i][j] = cnt++;
    }
  }
}
void Print(void){
  int i, j;
  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      printf("%d ", vis[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int Chk_Available(int r, int c){
  int i;
  if((c+(M-1)) > N) return 0;
  for (i=c; i<c+M; i++) {
    if(vis[r][i]) return 0;
  }
  return 1;
}

void Mark_Vis(int r, int c, int mark){
  int i;
  for (i=c; i<c+M; i++) {
    vis[r][i] = mark;
  }
}


void Get_Honey_2(int honey_room, int available, int profit2, int i){
  int honey =map[pos[1].r][pos[1].c + i];
  if(honey_room <= 0){
//    if(max_profit2 < profit2) max_profit2 = profit2;
    if(total_max_profit < (max_profit1 + profit2)) {
      total_max_profit = (max_profit1 + profit2);
    }
    return;
  }
  if(honey <= available){
    Get_Honey_2(honey_room - 1, available - honey, profit2 + SQR(honey), i+1);
  }
  Get_Honey_2(honey_room - 1, available, profit2, i+1);
}

void Get_Honey_1(int honey_room, int available, int profit1, int i){
  int honey =map[pos[0].r][pos[0].c + i];

  if(honey_room <= 0){
    if(max_profit1 > profit1) return;
    if(max_profit1 < profit1) max_profit1 = profit1;
    Get_Honey_2(M, C, 0, 0);
    return;
  }
  if(honey <= available){
    Get_Honey_1(honey_room - 1, available - honey, profit1 + SQR(honey), i+1);
  }
  Get_Honey_1(honey_room - 1, available, profit1, i+1);
}

void DFS(int n){
  int i, j;
  if(n > 1){
//    Print();
    Get_Honey_1(M, C, 0, 0);
    return;
  }
  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      if(vis[i][j]) continue;
      if(Chk_Available(i,j) == 0) continue;
      if(n == 1 && (lut[i][j] < pos[0].i)) continue;
      Mark_Vis(i, j, 1);
      pos[n].r = i;
      pos[n].c = j;
      pos[n].i = lut[i][j];
      DFS(n+1);
      Mark_Vis(i, j, 0);
    }
  }
}

int main(void){
  int T, tc=1;
  scanf("%d", &T);
  while (T--) {
    Init();
    Input_Data();
    DFS(0);
    printf("#%d %d\n", tc++, total_max_profit);
  }


  return 0;
}
