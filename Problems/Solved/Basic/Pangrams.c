#include <stdio.h>

char S[1000+10];
int flag;

int a[128];

unsigned int strlen(const char *d)
{
      unsigned int cnt = 0;

      while(*d++)
      {
            cnt++;
      }

      return cnt;
}

int main(void)
{
      int len, ans=0, i;


      gets(S);


      len = (int)strlen(S);
      for(i=0 ; i<len ; i++)
      {
            if (S[i] == ' ') continue;
            if (S[i] >= 'a') S[i] += ('A' - 'a');
            if (!(a[S[i]]++)) ans++;
      }

      if(ans == 26) flag = 1;


      if (!flag) printf("not ");
      printf("pangram");

      return 0;
}
