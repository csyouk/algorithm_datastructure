//
//  자외선을피해가기.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 2..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 0
#include <stdio.h>
#define SIZE 110
#define START 1
#define DIRS 4
#define FIRST_TIME -1

typedef struct _uv{
  int i,j;
} UV;

int N, RP, WP;
UV Q[100000];
int map[SIZE][SIZE];
int uv[SIZE][SIZE];


int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void print_all(void){
  //  FILE *f = fopen("/Users/youk/workspace/scsa/codeground/codeground/out.txt", "w");
  //  if (f == NULL)
  //  {
  //    printf("Error opening file!\n");
  //    exit(1);
  //  }
  int i,j;
  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      //      fprintf(f, "%3d ",uv[i][j]);
      printf("%d ", uv[i][j]);
    }
    //    fprintf(f, "\n");
    printf("\n");
  }
   printf("\n");
}

void BFS(int i, int j){
  int k,ni,nj;
  UV cursor, uv_instance;
  uv_instance.i = i;
  uv_instance.j = j;
  uv[i][j] = 0;
  Q[WP++] = uv_instance;


  while (RP < WP) {
    cursor = Q[RP++];
    for (k=0; k<DIRS; k++) {
      ni = cursor.i + di[k];
      nj = cursor.j + dj[k];
      if(ni < 1 || ni > N || nj < 1 || nj > N ) continue;
      if(uv[ni][nj] == FIRST_TIME){
        uv[ni][nj] = uv[cursor.i][cursor.j] + map[ni][nj];
        uv_instance.i = ni;
        uv_instance.j = nj;
        Q[WP++] = uv_instance;
      }
      else if(uv[ni][nj] > uv[cursor.i][cursor.j] + map[ni][nj]){
        uv[ni][nj] = uv[cursor.i][cursor.j] + map[ni][nj];
        uv_instance.i = ni;
        uv_instance.j = nj;
        Q[WP++] = uv_instance;
      }
//      print_all();
    }
  }
}
void Init(){
  int i,j;
  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      uv[i][j] = FIRST_TIME;
    }
  }
}
int main(void)
{
  int i,j;

//  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  scanf("%d", &N);

  Init();

  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      scanf("%1d", &map[i][j]);
    }
  }


  BFS(START,START);

//  print_all();

  printf("%d", uv[N][N]);

  return 0;
}
#endif


//	휴대폰번호 정렬
#if 0
#include <stdio.h>
typedef struct{
	int n1, n2, n3, digit;
}P_t;
P_t a[50 + 10];
int N, p[10 + 10];
int cmp(int i, int j){
	if (p[a[i].n1 % 10] < p[a[j].n1 % 10]) return -1;
	if (p[a[i].n1 % 10] > p[a[j].n1 % 10]) return 1;

	if (a[i].digit > a[j].digit) return -1;
	if (a[i].digit < a[j].digit) return 1;

	if (a[i].n2 < a[j].n2) return -1;
	if (a[i].n2 > a[j].n2) return 1;

	if (a[i].n3 < a[j].n3) return -1;
	if (a[i].n3 > a[j].n3) return 1;

	return 0;
}
char str[50 + 10][13 + 10];
int main(void){
	int i, j, d;
	P_t t;
	scanf("%d", &N);
	for (i = 1; i <= 6; i++){
		scanf("%d", &d);
		p[d] = i;
	}
	for (i = 0; i < N; i++) scanf("%s", &str[i][0]);
	for (i = 0; i < N; i++){
		sscanf(str[i], "%d-%d-%d", &a[i].n1, &a[i].n2, &a[i].n3);
		if (str[i][12] == '\0') a[i].digit = 3;
		else a[i].digit = 4;
	}
	for (i = 0; i < N - 1; i++){	//	오름차순 정렬
		for (j = i + 1; j < N; j++){
			if (cmp(i, j) == 1){
				t = a[i]; a[i] = a[j]; a[j] = t;
			}
		}
	}
	for (i = 0; i < N; i++){
		if (a[i].digit == 3) printf("%03d-%03d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
		else printf("%03d-%04d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
	}
	return 0;
}
#endif
