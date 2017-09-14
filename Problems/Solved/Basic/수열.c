
// 문제 번호 E: [TST]수열
#if 0
// 0에서부터 9까지의 숫자로 이루어진 N개의 숫자가 나열된 수열이 있다. 그 수열 안에서 연속해서 커지거나(같은 것 포함), 혹은 연속해서 작아지는(같은 것 포함) 수열 중 가장 길이가 긴 것을 찾아내어 그 길이를 출력하는 프로그램을 작성하라.
//
// 예를 들어 수열 1 2 2 4 4 5 7 7 2 의 경우에는 1≤2≤2≤4≤4≤5≤7≤7 이 가장 긴 구간이 되므로 그 길이 8을 출력한다. 수열 4 1 3 3 2 2 9 2 3 의 경우에는 3≥3≥2≥2 가 가장 긴 구간이 되므로 그 길이 4를 출력한다. 또 1 5 3 6 4 7 1 3 2 9 5 의 경우에는 연속해서 커지거나 작아지는 수열의 길이가 3 이상인 경우가 없으므로 2를 출력하여야 한다.
// 첫째 줄에는 수열의 길이 N이 주어지고, 둘째 줄에는 N개의 숫자가 빈칸을 사이에 두고 주어진다.
// N은 1 이상 100,000 이하의 정수이다.
// 첫째 줄에 가장 긴 길이를 출력한다.
// 입력 예시
// 9
// 1 2 2 4 4 5 7 7 2
// 출력 예시
// 8

#include <stdio.h>
unsigned int N, max, longest, shortest;
char seq[100001];

int main(void)
{

    scanf("%d", &N);
    for (int i = 0; i<N; i++) {
        scanf(" %c", &seq[i]);
    }


    for (int i =0; i < N+1; i++)
    {
        char *p = seq+i;
        longest = 1;
        shortest = 1;
        while(*p <= *(p+1) && *p != 0)
        {
            longest++;
            p++;
        }
        if(max < longest){max = longest;}
        if(max == N) break;
        if(i > N/2 && max > N/2) break;

        p = seq+i;
        while(*p >= *(p+1) && *(p+1) != 0)
        {
            shortest++;
            p++;
        }
        if(max < shortest){max = shortest;}
        if(max == N) break;
        if(i > N/2 && max > N/2) break;
    }

    printf("%d", max);

    return 0;
}
#endif
