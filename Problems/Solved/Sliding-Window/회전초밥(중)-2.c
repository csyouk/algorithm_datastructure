#include <stdio.h>

int N, D, K, C;
int sushi[33000];
int chk[3001];

void Input_Data(void)
{
    int i;
    scanf("%d %d %d %d", &N, &D, &K, &C);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &sushi[i]);
    }
    for (i = 0; i < K;i++)
    {
        sushi[N + i] = sushi[i];
    }
}

int Solve(void)
{
    int cnt_with_coupon;
    int i, cnt = 0, maxcnt;
    for (i = 0; i < K; i++)
    {
        chk[sushi[i]]++;
        if (chk[sushi[i]] == 1) cnt++;
    }
    if (chk[C]) cnt_with_coupon = cnt;
    else cnt_with_coupon = cnt + 1;
    maxcnt = cnt_with_coupon;

    for (i = 1; i < N; i++)
    {
        chk[sushi[i - 1]]--;
        if (chk[sushi[i - 1]] == 0) cnt--;
        chk[sushi[(i + K - 1)]]++;
        if (chk[sushi[(i + K - 1)]] == 1) cnt++;

        if (chk[C]) cnt_with_coupon = cnt;
        else cnt_with_coupon = cnt + 1;
        if (maxcnt<cnt_with_coupon) maxcnt = cnt_with_coupon;
    }

    return maxcnt;
}


int main(void)
{
    Input_Data();

    printf("%d\n", Solve());

    return 0;
}
