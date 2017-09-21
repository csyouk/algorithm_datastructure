// 이 문제 같은 경우 SIZE 정의를 1000 + 10으로 해서
// Q-SIZE 가 잘못잡혀서 고생한 사례다. 조심하자.
#include <stdio.h>
#define SIZE 1010
#define QSIZE (SIZE * SIZE * SIZE)
#define DIRS 4
#define BLOCK 1
#define PATH 0


typedef struct {
  int i, j;
  int min, hp;
} Rat;

typedef struct {
  int i, j;
  int hp;
} Cheese;

Rat rat, out, in;
Rat Q[QSIZE];

int R, C, N, RP, WP;

char Raw[SIZE][SIZE];
int map[SIZE][SIZE];
int visited[SIZE][SIZE];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

Cheese cheese[10 + 10];


int replace(char sym, int i, int j){
  int pos;
  switch (sym)
  {
    case 'S':
      rat.i = i; rat.j = j; rat.hp = 1;
      visited[i][j] = rat.hp;
      return PATH;
    case '.': return PATH;
    case 'X': return BLOCK;
    default :
      pos = sym - '0';
      cheese[pos].i = i; cheese[pos].j = j; cheese[pos].hp = pos;
      return PATH;
  }
  return PATH;
}

void conv(void){

  int i, j;
  for ( i = 1; i <=R; i++){
    for ( j = 1; j <=C; j++){
      map[i][j] = replace(Raw[i][j], i, j);
    }
  }

}


int BFS(){
  int k, ni, nj, target = 1;
  Q[WP++] = rat;
  while (RP < WP)
  {
    out = Q[RP++];
    if ((out.hp == target) &&
        (out.i == cheese[target].i) &&
        (out.j == cheese[target].j ))
    {
      if (target++ == N) return out.min;
      RP=WP=0;
      in.i = out.i;  in.j = out.j;  in.hp = out.hp + 1;  in.min = out.min;
      Q[WP++] = in;
      out = Q[RP++];
    }

    for ( k = 0; k < DIRS; k++)
    {
      ni = out.i + di[k];   nj = out.j + dj[k];

      if (ni < 1 || ni > R || nj < 1 || nj > C) continue;
      if (map[ni][nj]) continue;
      if (visited[ni][nj] == out.hp) continue;

      visited[ni][nj] = out.hp;

      in.i = ni;   in.j = nj;
      in.min = out.min + 1;
      in.hp = out.hp;
      Q[WP++] = in;
    }
  }

  return out.min;
}

int main(void){
  int i;

  // freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);


  scanf("%d %d %d", &R, &C, &N);

  for ( i = 1; i <= R; i++) scanf("%s", &Raw[i][1]);

  conv();

  printf("%d", BFS());
  return 0;
}
