#include <stdio.h>

int T, A, B, C;
int imp;

int main(void)
{

      scanf("%d", &T);


      A = T / 300;
      T %= 300;
      B = T / 60;
      T %= 60;
      C = T / 10;
      if(T % 10 != 0) imp = 1;


      if(imp) printf("-1");
      else printf("%d %d %d ", A, B, C);

      return 0;
}
