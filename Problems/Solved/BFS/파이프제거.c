//
//  파이프제거.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 2..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 0
#include <stdio.h>

#define CONNECTED -1
#define NO_PIPE 0
#define DIRS 4
#define MAP_SIZE 15
#define Q_SIZE 200
typedef struct _pipe{
  int x, y;
  int type;
  int dirs[DIRS];
} Pipe;

Pipe start;
Pipe Q[Q_SIZE];
Pipe pipe_map[MAP_SIZE][MAP_SIZE];

int di[DIRS] = {-1,0,1,0}; // 상 우 하 좌
int dj[DIRS] = {0,1,0,-1};
int N, RP, WP;

int map[MAP_SIZE][MAP_SIZE];
char tmp[MAP_SIZE][MAP_SIZE];


void Print_All(void){
  int i,j;
  printf("origin======\n");
  for (i = 1; i <=N; i++) {
    for (j = 1; j <=N; j++) {
      printf("%c  ", tmp[i][j]);
    }
    printf("\n");
  }
  
  
  printf("map======\n");
  for (i = 1; i <=N; i++) {
    for (j = 1; j <=N; j++) {
      printf("%2d ", map[i][j]);
    }
    printf("\n");
  }
}


void Init(void){
  int i,j, k;
  Pipe t_pipe;
  // 입력값 받기.
  for (i = 1; i <=N; i++) {
    scanf("%s", &tmp[i][1]);
  }
  
  // 입력값을 정수형으로 변환.
  for (i=1; i<=N; i++) {
    for (j =1; j<=N; j++) {
      if(tmp[i][j] == 'A' || tmp[i][j] == 'B'){
        map[i][j] = tmp[i][j] -'A' + 10;
        continue;
      }
      map[i][j] = tmp[i][j] - '0';
    }
  }

  // 파이프 맵을 만든다.
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N; j++) {
      t_pipe.x = i;
      t_pipe.y = j;
      t_pipe.type = map[i][j];
      switch (map[i][j]) {
        case 0:
          for (k=0; k<DIRS; k++) {
            t_pipe.dirs[k] = 0;
          }
          break;
        case 1:
          t_pipe.dirs[0] = 0;
          t_pipe.dirs[1] = 1;
          t_pipe.dirs[2] = 0;
          t_pipe.dirs[3] = -1;
          break;
        case 2:
          t_pipe.dirs[0] = 1;
          t_pipe.dirs[1] = 0;
          t_pipe.dirs[2] = -1;
          t_pipe.dirs[3] = 0;
          break;
        case 3:
          t_pipe.dirs[0] = 0;
          t_pipe.dirs[1] = 1;
          t_pipe.dirs[2] = -1;
          t_pipe.dirs[3] = 0;
          break;
        case 4:
          t_pipe.dirs[0] = 0;
          t_pipe.dirs[1] = 0;
          t_pipe.dirs[2] = -1;
          t_pipe.dirs[3] = -1;
          break;
        case 5:
          t_pipe.dirs[0] = 1;
          t_pipe.dirs[1] = 0;
          t_pipe.dirs[2] = 0;
          t_pipe.dirs[3] = -1;
          break;
        case 6:
          t_pipe.dirs[0] = 1;
          t_pipe.dirs[1] = 1;
          t_pipe.dirs[2] = 0;
          t_pipe.dirs[3] = 0;
          break;
        case 7:
          t_pipe.dirs[0] = 1;
          t_pipe.dirs[1] = 1;
          t_pipe.dirs[2] = -1;
          t_pipe.dirs[3] = 0;
          break;
        case 8:
          t_pipe.dirs[0] = 0;
          t_pipe.dirs[1] = 1;
          t_pipe.dirs[2] = -1;
          t_pipe.dirs[3] = -1;
          break;
        case 9:
          t_pipe.dirs[0] = 1;
          t_pipe.dirs[1] = 0;
          t_pipe.dirs[2] = -1;
          t_pipe.dirs[3] = -1;
          break;
        case 10: // a
          t_pipe.dirs[0] = 1;
          t_pipe.dirs[1] = 1;
          t_pipe.dirs[2] = 0;
          t_pipe.dirs[3] = -1;
          break;
        case 11: // b
          t_pipe.dirs[0] = 1;
          t_pipe.dirs[1] = 1;
          t_pipe.dirs[2] = -1;
          t_pipe.dirs[3] = -1;
          break;
        default:
          break;
      }
      pipe_map[i][j] = t_pipe;
    }
  }
}

int Count_Disconnected_Pipe(void){
  
  int i,j;
  int left=0;
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N; j++) {
      if(map[i][j] == CONNECTED) continue;
      if(map[i][j] == NO_PIPE) continue;
      left++;
    }
  }
  
  return left;
}
void BFS(int x, int y){
  int k, nx,ny;
  Pipe poped;
  Q[WP++] = pipe_map[x][y];
  if(pipe_map[x][y].type != 0) map[x][y] = CONNECTED;
  
  
  while (RP < WP) {
    poped = Q[RP++];
    for (k=0; k < DIRS; k++) {
      nx = poped.x + di[k];
      ny = poped.y + dj[k];
      if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
      if(map[nx][ny] == CONNECTED) continue;
      if(pipe_map[nx][ny].type == NO_PIPE || poped.type == NO_PIPE) continue;
      if(pipe_map[nx][ny].dirs[(k+2) % DIRS] == NO_PIPE || poped.dirs[k] == NO_PIPE) continue;
      if((poped.dirs[k] +  pipe_map[nx][ny].dirs[(k+2) % DIRS]) == 0) {
        Q[WP++] = pipe_map[nx][ny];
        map[nx][ny] = CONNECTED;
      }
    }
//    Print_All();
  }
}
int main(void)
{
  int left = 0;
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  scanf("%d", &N);
  scanf("%d %d", &start.x, &start.y);
  Init();
  
  BFS(start.y+1, start.x+1);
  left = Count_Disconnected_Pipe();

  Print_All();
  
  printf("%d", left);
  return 0;
}
#endif
