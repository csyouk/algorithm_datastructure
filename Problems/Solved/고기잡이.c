#if 0
#include <stdio.h>
#define SIZE 110
int N, l, M;
int C[SIZE], R[SIZE];
//int map[SIZE][SIZE];
int max=0x80000000;

void sort(int *p){
  int i,j, tmp;
  
  for (i=0; i<M-1; i++) {
    for (j=i+1; j<M; j++) {
      if(p[i] > p[j]){
        tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
      }
    }
  }
}

void capture(void){
  int i,j,m,n, cnt, width, height;
  
  int half = l/2;
  
  for (i=0; i < M; i++) {
    for (j=0; j < M; j++) {
      
      width = 1;
      while (width != half) {
        height = half - width;
        cnt = 0;
        for (m = R[i]; m <= R[i] + width ; m++) {
          for (n = C[j]; n <= C[j] + height; n++) {
//            printf("%d, %d\n", m,n);
//            if(map[m][n]) {
//            if
//              cnt++;
//            }
          }
        }
        if(max < cnt) max = cnt;
        
        width++;
      }
    }
  }
}

void Print(void){
  int i,j;
  for (i=1; i<=N; i++) {
    for (j=1; j<=N; j++) {
      printf("%d", map[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int i;
//  freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);

  // 입력받는 부분
  scanf("%d %d %d", &N, &l, &M);
  
  for(i=0; i<M; i++)
  {
    scanf("%d %d", &R[i], &C[i]);
    map[R[i]][C[i]] = 1;
  }
  
  sort(R);
  sort(C);
//  Print();
  capture();
  
  // 출력하는 부분
  printf("%d", max);
  return 0;
}

#endif
