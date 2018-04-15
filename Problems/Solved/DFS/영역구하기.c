// 사고흐름
// 배열에 색을 칠하는 방식으로 가는 것이 좋겠다.
// loop & flood fill 로 갯수 & 영역을 구해야겠다.
// 출력

#include <stdio.h>
#define SIZE 100
int M,N,K;
int board[SIZE+2][SIZE+2];
int area_cnt, pt;
int areas[SIZE*SIZE];
int rx[4] = {0,1,0,-1};
int cx[4] = {-1,0,1,0};
int fill(int, int);


void sort(void){
  int i,j,tmp;
  for (i=0; i<pt; i++) {
    for (j=i; j<pt; j++) {
      if(areas[i] > areas[j]){
        tmp = areas[i];
        areas[i] = areas[j];
        areas[j] = tmp;
      }
    }
  }
}

int fill(int r, int c){
  int i;
  int area=0;
  if(r < 0 || r >= N) return 0;
  if(c < 0 || c >= M) return 0;
  if(board[r][c]) return 0;
  board[r][c] = 1;
  area++;
  for (i=0; i<4; i++) {
    if(board[r + rx[i]][c + cx[i]]) continue;
    area += fill(r+rx[i], c+cx[i]);
  }
  return area;
}

int main(void){
  int r1,c1,r2,c2;
  int i,j,k;
  scanf("%d %d %d", &M, &N, &K);
  for (i=0; i<N; i++) {board[i][M] = 1;}
  for (i=0; i<M; i++) {board[N][i] = 1;}
  for (i=0; i<K; i++) {
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    // 색칠
    for (j=r1; j<r2; j++) {
      for (k=c1; k<c2; k++) {
        board[j][k] = 1;
      }
    }
  }
  

  
  // 보드를 순회하며 영역 개수 구하기
  for (i=0; i<N; i++) {
    for (j=0; j<M; j++) {
      if(board[i][j] == 0){
        area_cnt++;
        areas[pt++] = fill(i,j);
      }
    }
  }
  
  sort();
  
  printf("%d\n", area_cnt);
  for (i=0; i<pt; i++) {
    printf("%d ", areas[i]);
  }


  return 0;
}



