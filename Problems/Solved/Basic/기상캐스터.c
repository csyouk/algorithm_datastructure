# include <stdio.h>
char map[110][110];
int sol[110][110];
int H,W;
int main(void)
{
      int tmp;
      scanf("%d %d", &H, &W);
      for(int i=0; i<H; i++)
      {
            scanf("%s",map[i]);
            tmp = -1;
            for(int j=0; j<W; j++)
            {
                  if(map[i][j]=='c')tmp = 0;
                  else if(tmp != -1)tmp++;
                  map[i][j]=tmp;
            }
      }
      for(int i=0; i<H; i++)
      {
            for(int j=0; j<W; j++)
            {
                  printf("%d ",map[i][j]);
            }
            printf("\n");
      }
}
