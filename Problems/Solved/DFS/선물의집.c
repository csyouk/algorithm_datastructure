// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=513&sca=4030
//  선물의집.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 8..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

/*
현준이는 가족들과 놀이동산에 놀러갔다. 그 놀이동산에는 선물의 집이라는 곳이 있는데 선물의 집은 이름대로 선물을 받을 수 있는 곳이다.

단, 선물의 집 내부는 정사각형의 미로 구조이며 한번지나간 길은 다시 돌아가지 못하게 되어있다. 선물은 미로의 여러지점에 놓여있는데 입구에서 출구로 나가는 동안 찾을 수 있는 선물은 모두 가져가도 된다.

선물의 집의 내부 지도를 어렵게 구한 현준이는 선물을 많이 갖고 싶어한다. 방법을 찾아보자.

입력의 첫 줄에 선물의 집 한 변의 길이 n(10이하의 자연수) 이 주어진다.
두 번째 줄부터 내부의 평면도가 주어며, 0은 길, 1은 벽, 2는 선물의 위치를 나타낸다.
왼쪽 맨 위가 입구이고, 오른쪽 맨 아래가 출구이다. 길이 막혀있는 경우는 없다.


선물의 집을 빠져나올 때 가장 많은 선물의 개수를 출력한다.

5
0 1 2 0 0
0 0 0 1 0
0 1 0 1 0
0 0 2 1 0
2 1 0 0 0
*/
#if 1
#include <stdio.h>
#define DIRS 4

int N, max=-1;
int map[20][20];
int vis[20][20];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void DFS(int i, int j, int cnt){
  int k, ni,nj;
  if(i+j == 2*N) {
    if(max < cnt/2) max = cnt/2;
    return;
  }
  for (k=0; k<DIRS; k++) {
    ni = i + di[k];  nj = j + dj[k];
    if(ni < 1 || ni > N || nj < 1 || nj > N) continue;
    if(map[ni][nj] == 1 || vis[ni][nj] == 1) continue;
    vis[ni][nj] = 1;
    DFS(ni,nj, cnt + map[ni][nj]);
    vis[ni][nj] = 0;
  }
}

int main(void){
  int i, j;
  scanf("%d", &N);
  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  vis[1][1] = 1;
  DFS(1, 1, map[1][1]);

  printf("%d", max);

  return 0;
}

#endif
