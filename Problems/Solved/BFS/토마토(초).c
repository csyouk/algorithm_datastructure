#include <stdio.h>

int M, N, H;
int a[100+10][100+10][100+10];
int sol;

typedef struct
{
      int x, y, z;
}Q_T;
Q_T queue[100*100*100+10];
int wt, rd;

int main(void)
{
      int i, j, k;
      int count=0, x, y, z;
      Q_T temp;
      int xx[] = {0, 0, -1, 1, 0, 0};
      int yy[] = {0, 0, 0, 0, -1, 1};
      int zz[] = {-1, 1, 0, 0, 0, 0};


      scanf("%d %d %d", &M, &N, &H);
      for(i=1 ; i<=H ; i++)
      {
            for(j=1 ; j<=N ; j++)
            {
                  for(k=1 ; k<=M ; k++)
                  {
                        scanf("%d", &a[i][j][k]);
                  }
            }
      }


      for(i=1 ; i<=H ; i++)
      {
            for(j=1 ; j<=N ; j++)
            {
                  for(k=1 ; k<=M ; k++)
                  {
                        if(a[i][j][k] == 1)
                        {
                              temp.z=i, temp.y=j, temp.x=k;
                             queue[wt++] = temp;
                        }
                        else if(a[i][j][k] == 0) count++;
                  }
            }
      }

      if(count == 0)
      {
            sol = 0;
      }
      else
      {
            while(rd<wt)
            {
                  temp = queue[rd++];
                  x=temp.x, y=temp.y, z=temp.z;
                  k=a[z][y][x];
                  for(i=0 ; i<6 ; i++)
                  {
                        temp.x=x+xx[i], temp.y=y+yy[i], temp.z=z+zz[i];
                        if((temp.x<1) || (temp.x>M) || (temp.y<1) || (temp.y>N) || (temp.z<1) || (temp.z>H)) continue;
                        if(a[temp.z][temp.y][temp.x] == 0)
                        {
                             a[temp.z][temp.y][temp.x] = k+1;
                             queue[wt++] = temp;
                             count--;
                        }
                  }
            }
            if(count != 0) sol = -1;
            else sol = k-1;
      }


      printf("%d", sol);

      return 0;
}
