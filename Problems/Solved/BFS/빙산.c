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


#if 01
#include <string.h>
#include <stdio.h>
#define DIRS 4
#define MAXQ 100000

typedef struct {
  int i, j;
} Cell;

Cell Q[MAXQ];
Cell out, in;

int RP, WP;

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

int R, C, min_time = 0, all_melted;

int map[300 + 10][300 + 10];
int b_map[300 + 10][300 + 10];
int visited[300 + 10][300 + 10];

void BFS(int i, int j){
  int k, ni, nj;

  in.i = i; in.j = j;
  Q[WP++] = in;
  visited[i][j] = 1;
  while (RP < WP)
  {
    out = Q[RP++];

    for ( k = 0; k < DIRS; k++)
    {
      ni = out.i + di[k];   nj = out.j + dj[k];
      if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
      if (map[ni][nj] == 0 || visited[ni][nj]) continue;
      visited[ni][nj] = 1;
      in.i = ni;  in.j = nj;
      Q[WP++] = in;
    }
  }

}

void melt(){

  int i, j, ni, nj, k, cnt;
  memcpy(b_map, map, sizeof(int [310][310]));


  for ( i = 1; i <= R; i++)
  {
    for ( j = 1; j <= C; j++)
    {
      if (map[i][j] == 0) continue;
      for (k = 0; k < DIRS; k++)
      {
        ni = i + di[k];   nj = j + dj[k];
        if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
        if (b_map[ni][nj] != 0) continue;
        map[i][j]--;
        if (map[i][j] < 0) map[i][j] = 0;
      }
    }
  }

  cnt = 0;
  for ( i = 1; i <= R; i++)
  {
    for ( j = 1; j <=C; j++)
    {
      if (map[i][j] == 0) cnt++;
    }
  }
  if (cnt == R*C) all_melted = 1;
  memset(visited, 0, sizeof(int[310][310]));
  RP = WP = 0;
}

void cal_time(){
  int i, j, cnt, seg;


  while (1)
  {
    cnt = 0; seg = 1;
    for (i = 1; i <= R; i++)
    {
      for (j = 1; j <= C; j++)
      {
        if (map[i][j] == 0 || visited[i][j]) continue;
        if (seg > 1) return;
        BFS(i, j);
        seg++;
      }
    }

    melt();
    min_time++;
    if (all_melted) {
      if (seg == 2) min_time = 0;
      return;
    }
  }
}

int main(void){
  int i, j;

  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  scanf("%d %d", &R, &C);
  for ( i = 1; i <= R; i++)
  {
    for ( j = 1; j <= C; j++)
    {
      scanf("%d ", &map[i][j]);
    }
  }


  cal_time();


  printf("%d", min_time);

  return 0;
}

#endif
