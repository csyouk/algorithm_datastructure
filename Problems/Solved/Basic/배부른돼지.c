#include <stdio.h>

int n;
int a[100+10];
char b[100+10];

int main(void)
{
      int i;
      int max_N=2, min_Y=10;


      scanf("%d", &n);

      for(i=0 ; i<n ; i++)
      {
            scanf("%d %c", &a[i], &b[i]);
      }


      if(n == 0)
      {
            printf("F\n");
            return 0;
      }

      for(i=0 ; i<n ; i++)
      {
            if(b[i] == 'N')
            {
                  if(max_N < a[i]) max_N = a[i];
            }
            else
            {
                  if(min_Y > a[i]) min_Y = a[i];
            }
      }

      if(min_Y <= max_N) printf("F\n");
      else printf("%d\n", min_Y);

      return 0;
}
