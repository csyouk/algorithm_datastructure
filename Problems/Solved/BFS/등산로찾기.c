#include <stdio.h>

#define SQR(x) ((x)*(x))

#define MAX_Q 1000000
#define SIZE 110
#define MAX (~(1<<31))
#define MIN_MAX (1<<31)
#define DIRS 4

typedef struct {
  int i,j,p;
}Pos;

Pos peak, in, out;
Pos Q[MAX_Q];
Pos Points[500];

int N,rp, wp,min=MAX;
int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Init(void){
  int i, j;
  for (i=0; i<=N+1; i++) {
    for (j=0; j<=N+1; j++) {
      if(map[i][j] != 0) continue;
      in.i = i; in.j = j; in.p = 0;
      Q[wp++] = in;
    }
  }
}

void BFS(void){
  int k, ni, nj,dis;

  while (rp < wp) {
    out = Q[rp++];
    for (k=0; k<DIRS; k++) {
      ni = out.i + di[k];  nj = out.j + dj[k];
      if(ni < 1 || ni > N || nj < 1 || nj > N) continue;

      dis = map[out.i][out.j] - map[ni][nj];
      if(dis < 0) dis *= dis;
      in.p = out.p + dis;
      if(visited[ni][nj] > in.p) {
        visited[ni][nj] = in.p;
        if(ni == peak.i && nj == peak.j) continue;
        in.i = ni;  in.j = nj;
        Q[wp++] = in;
      }
    }
  }

}

int main(void)
{

  int i,j;
  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);
  scanf("%d", &N);
  scanf("%d %d", &peak.i, &peak.j);

  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      scanf("%d", &map[i][j]);
      visited[i][j] = MAX;
    }
  }

  Init();
  BFS();

  printf("%d", visited[peak.i][peak.j]);

  return 0;
}
