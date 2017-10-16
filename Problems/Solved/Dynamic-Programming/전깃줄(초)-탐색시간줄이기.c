#include <stdio.h>

int N;
typedef struct
{
    int A;
    int B;
}LINE;

LINE line[101];
int LIS[101];

void Input_Data(void)
{
    int i;
    scanf("%d",&N);
    for (i = 1; i <= N;i++)
    {
        scanf("%d %d",&line[i].A, &line[i].B);
    }
}

int comp(const LINE* p1, const LINE* p2)
{
    return p1->B - p2->B;
}

int Find_Length(int s, int e, int d)
{
    int sol = -1, m;

    while (s<=e)
    {
        m = (s + e) / 2;
        if (LIS[m] < d)
        {
            sol = m;
            s = m + 1;
        }
        else e = m - 1;
    }
    return sol+1;
}

int Find_LIS(void)
{
    int n, len, maxlen = 0;
    for (n = 1; n <= N;n++)
    {
        len = Find_Length(0, maxlen, line[n].A);
        LIS[len] = line[n].A;
        if (maxlen < len) maxlen = len;
    }
    return maxlen;
}


int main(void)
{
    Input_Data();

    qsort(line + 1, N, sizeof(LINE), comp);
