
// 문제 번호 H: [TST]Two Strings
#if 01
// 두 개의 주어진 A와 B 문자열이 있다. A와 B 모두의 부분 문자열을 구하여 일치하는 부분 문자열이 있는지 없는지를 판단하라.
// 입력
// 첫 번째 줄에는 Test case 의 수 T(1≤T≤10)를 입력 받는다.
// 다음 줄부터 문자열 A와 B가 줄 단위로 구분되어 T개가 입력된다.
// 모든 문자는 소문자만 입력되고 각 문자열의 길이는 1 이상, 100,000 이하이다.
// 출력
// A와 B의 부분 문자열 중 일치하는 부분 문자열이 있으면 “YES”를, 없으면 “NO”를 출력한다.
// 입력 예시
// 2
// hello
// world
// hi
// world
// 출력 예시
// YES
// NO
// 도움말
// 입력 예제를 보면 hello 와 world와 같은 경우는 o 와 l 이 부분문자열로 존재하므로 YES이고,
// hi 와 world 와 같은 경우는 부분문자열이 없으므로 NO이다.
// 문자열의 길이가 긴 만큼 Time limit도 고려하여야 한다.

#include <stdio.h>
char pattern[100001];
char text[100001];

int letterBits(const char *p)
{
    int t =0;
    while(*p){
        t |= 1 << (*p - 'a');
        p++;
    }
    return t;
}

int main(void)
{
    int testcases;
    scanf("%d", &testcases);
    while (testcases--) {
        scanf("%s", pattern);
        scanf("%s", text);
        int bitP = letterBits(pattern);
        int bitT = letterBits(text);
        printf("%s", (bitP & bitT)? "YES\n":"NO\n");
    }
    return 0;
}

#endif
