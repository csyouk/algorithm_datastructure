#include <stdio.h>

int N;
int val[1000+10];

int a[1000+10];

int main(void)
{
      int i;


      scanf("%d",&N);
      for(i=0;i<N;i++)
      {
            scanf("%d",&val[i]);
      }


      for(i=0;i<N;i++)
      {
            a[val[i]]++;
      }

      for(i=1;i<=1000;i++)
      {
            if(a[i]!=0)
            {
                  printf("%d\n",N);
                  N=N-a[i];
            }
      }

      return 0;
}
