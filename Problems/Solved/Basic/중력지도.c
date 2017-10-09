#include <stdio.h>

int n;
char a[100+10][100+10];

int main(void)
{
      int i;
      int j;


      scanf("%d", &n);

      for(i=0;i<n;i++)
      {
            scanf("%s", a[i]);
      }


      for(i=1;i<n-1;i++)
      {
            for(j=1;j<n-1;j++)
            {
                  if((a[i][j] > a[i-1][j]) && (a[i][j] > a[i+1][j]) && \
                        (a[i][j] > a[i][j-1]) && (a[i][j] > a[i][j+1]))
                  {
                        a[i][j] = 'X';
                  }
            }
      }


      for(i=0;i<n;i++)
      {
            printf("%s\n", a[i]);
      }

      return 0;
}
