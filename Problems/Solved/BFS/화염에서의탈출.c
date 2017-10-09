//
//  화염에서의탈출.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 9..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#include <stdio.h>
#define DIRS 4
#define Empty 0
#define Unburned 1000
#define Neverburn 15234232
#define Fire 0x80000005
#define Rock 0x80000001
#define House 0x80000002
#define S 0x80000003
#define Impossible 0x80000004

typedef struct {
  int i, j, min;
} Pos;

Pos ManQ[100000];
Pos FireQ[100000];
Pos man, fire;
int R, C;
int rp, wp;
int frp, fwp;

char Raw[60][60];
int map[60][60];
int firemap[60][60];
int manmap[60][60];
int vis[60][60];
int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

int mintime = Impossible;

void conv(void){
  int i, j;
  for (i=1; i<=R; i++) {
    for (j=1; j<=C; j++) {
      firemap[i][j] = Unburned;
      switch (Raw[i][j]) {
        case '.':
          map[i][j] = Empty;
          break;
        case '*':
          map[i][j] = Rock;
          fire.i=i;fire.j=j; fire.min = 0;
          FireQ[fwp++] = fire;
          firemap[i][j] = 1;
          break;
        case 'X':
          map[i][j] = Rock;
          break;
        case 'D':
          map[i][j] = House;
          firemap[i][j] = Neverburn;
          break;
        case 'S':
          map[i][j] = Empty;
          vis[i][j] = 1;
          manmap[i][j] = -1;
          man.i = i; man.j = j; man.min = 0;
          break;
        default:
          break;
      }
    }
  }
}

void Burn(){
  int k, i, j, ni, nj;
  Pos in, out;

  while (frp < fwp) {
    out = FireQ[frp++];
    for (k=0; k<DIRS; k++) {
      ni = out.i + di[k];  nj = out.j + dj[k];
      if(ni < 1 || ni > R || nj < 1 || nj > C) continue;
      if(firemap[ni][nj] != Unburned || map[ni][nj]==House || map[ni][nj]==Rock) continue;
      firemap[ni][nj] = out.min + 1;
      in.i = ni;  in.j = nj;
      FireQ[fwp] = in; FireQ[fwp].min = out.min + 1;
      fwp++;
    }
  }
}

void Search(Pos man){
  int k, i, j, ni, nj;
  Pos in, out;
  ManQ[wp++] = man;

  while (rp < wp) {
    out = ManQ[rp++];
    manmap[out.i][out.j] = out.min;
    if(map[out.i][out.j] == House){
      mintime = out.min;
      return;
    }
    for (k=0; k<DIRS; k++) {
      ni = out.i + di[k];  nj = out.j + dj[k];
      if(ni < 1 || ni > R || nj < 1 || nj > C) continue;
      if(map[ni][nj] == Rock) continue;
      if(vis[ni][nj]) continue;
      if(out.min+1 >= firemap[ni][nj]) continue;

      vis[ni][nj] = 1;
      in.i = ni;  in.j = nj;
      ManQ[wp] = in; ManQ[wp].min = out.min + 1;
      wp++;
    }
  }

}


int main(void){
  int i;

  scanf("%d %d", &R, &C);
  for (i=1; i<=R; i++) {
    scanf("%s", &Raw[i][1]);
  }

  conv();

  Burn();
  Search(man);


  if(mintime == Impossible) printf("impossible");
  else(printf("%d", mintime));

  return 0;
}
