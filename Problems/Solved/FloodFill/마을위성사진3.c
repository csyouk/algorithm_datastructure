#include <stdio.h>

int W, H;
int a[1000+10][1000+10];
int sol;

int chk[1000+10][1000+10];
int cnt;

void Fill(int ii, int jj)
{
      int k, i, j;
      static int di[]={0,1,1,1,0,-1,-1,-1};
      static int dj[]={-1,-1,0,1,1,1,0,-1};

      if(chk[ii][jj])   return;
      chk[ii][jj]=1;
      cnt++;

      for(k=0;k<8;k++)
      {
            i=ii+di[k], j=jj+dj[k];
            if(i>0 && i<=H && j>0 && j<=W && a[i][j]) Fill(i, j);
      }
}

int main(void)
{
      int i, j;


      scanf("%d %d", &W, &H);
      for(i=1;i<=H;i++)
      {
            for(j=1;j<=W;j++)
            {
                  scanf("%1d", &a[i][j]);
            }
      }


      for(i=1;i<=H;i++)
      {
            for(j=1;j<=W;j++)
            {
                  if(chk[i][j] || a[i][j]==0)  continue;
                  cnt=0;
                  Fill(i, j);
                  if(sol<cnt) sol=cnt;
            }
      }


      printf("%d", sol);

      return 0;
}
