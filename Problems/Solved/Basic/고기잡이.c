#include <stdio.h>

int N, l, M;
int x[100+10], y[100+10];
int max;

int main(void)
{
  int i;
  int j, k, w, h, count=0;


  scanf("%d %d %d", &N, &l, &M);

  for(i=0; i<M; i++)
  {
    scanf("%d %d", &y[i], &x[i]);
  }


  l /= 2;
  for(h=1; h<l; h++)
  {
    w = l - h;
    for(i=0; i<M; i++)
    {
      for(j=0; j<M; j++)
      {
        count = 0;
        for(k=0; k<M; k++)
        {
          /* 시작점을 기준으로 h, w 범위에 있는 점을 카운트 */
          if( ((y[k] >= y[i]) && (y[k] <= y[i] + h)) && ((x[k] >= x[j]) && (x[k] <= x[j] + w)) )
          {
            count++;
          }
        }
        if(count > max) max = count;
      }
    }
  }


  printf("%d", max);
  return 0;
}
