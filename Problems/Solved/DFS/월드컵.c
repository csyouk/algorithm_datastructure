#include <stdio.h>

#define N 6
int win[N+10], lose[N+10], draw[N+10];
int flag;

#define M 15
int genWin[N+10], genLose[N+10], genDraw[N+10];
int gen[M+10], p1[M+10], p2[M+10];

void recur(int cnt)
{
      int n1;
      int n2;

      if (cnt == M)
      {
            flag = 1;
            return;
      }

      n1 = p1[cnt];
      n2 = p2[cnt];

      genWin[n1]++; genLose[n2]++;
      if (genWin[n1]<=win[n1] && genLose[n2]<=lose[n2])
            recur(cnt+1);
      genWin[n1]--; genLose[n2]--;

      genDraw[n1]++; genDraw[n2]++;
      if (genDraw[n1]<=draw[n1] && genDraw[n2]<=draw[n2])
            recur(cnt+1);
      genDraw[n1]--; genDraw[n2]--;

      genLose[n1]++; genWin[n2]++;
      if (genLose[n1]<=lose[n1] && genWin[n2]<=win[n2])
            recur(cnt+1);
      genLose[n1]--; genWin[n2]--;
}

void process()
{
      int i, j, cnt = 0;

      flag = 0;

      for(i=0 ; i<N ; i++)
      {
            genWin[i] = 0;
            genLose[i] = 0;
            genDraw[i] = 0;

            if(win[i]+lose[i]+draw[i] != N-1) return;
      }

      for(i=0 ; i<N ; i++)
      {
            for (j=i+1 ; j<N ; j++)
            {
                  p1[cnt] = i;
                  p2[cnt] = j;
                  cnt++;
            }
      }

      recur(0);
}

int main()
{
      int i, loop;

      for(loop=0 ; loop<4 ; loop++)
      {


            for(i=0 ; i<N ; i++)
            {
                  scanf("%d %d %d", &win[i], &draw[i], &lose[i]);
            }


            process();


            if(flag) printf("1 ");
            else printf("0 ");
      }

      return 0;
}
