#include <stdio.h>

int M, P;
char a[100+10][100+10];
char b[100+10][100+10];
int count;

int check_func(int y, int x)
{
      int i, j;
      for(i = 0; i < P; i++)
      {
            for(j = 0; j < P; j++)
            {
                  if(a[i + y][j + x] != b[i][j]) return 0;
            }
      }
      return 1;
}

int main(void)
{
      int i;
      int j;


      scanf("%d", &M);
      for(i=0 ; i<M ; i++)
      {
            scanf("%s", a[i]);
      }
      scanf("%d", &P);
      for(i=0 ; i<P ; i++)
      {
            scanf("%s", b[i]);
      }


      for(i=0 ; i<=M-P ; i++)
      {
            for(j=0 ; j<=M-P ; j++)
            {
                  count += check_func(i, j);
            }
      }


      printf("%d", count);

      return 0;
}
