
// 문제 번호 B: [TST]두 수의 최대곱
#if 0
// 1, 2, 3, 4를 모두 사용하여 두 개의 정수를 만들고 그 곱을 구할 때 최대값은 얼마인가?
// 다양한 조합이 가능한데 그 중 41*32=1,312가 최대값이다.
// 최대곱을 구하는 프로그램을 작성하자.
// 첫 행에 N( 2 ≤ N ≤ 14)을 입력 받는다.
// 다음 행에 N개의 숫자를 입력 받는다. N개의 숫자는 0에서 9까지 범위의 숫자이다.
// 주어진 숫자를 모두 사용하여 두 개의 정수를 만들 때, 최대값을 출력하시오.
// 숫자를 중복하여 사용할 수 없다.

#include <stdio.h>
#define ULL unsigned long long int
#define ABS(x) (((x) > 0)? (x) : -(x))

int N, lVal, rVal;
ULL result;
int seq[14];
int leftOp[7];
int rightOp[7];
void sort_decending()
{
    int tmp;
    for (int i =0; i < 13; i++) {
        for (int j =i; j < 14; j++) {
            if(seq[i] < seq[j])
            {
                tmp = seq[i];
                seq[i] = seq[j];
                seq[j]= tmp;
            }
        }
    }
}
ULL getRVal(){
    ULL r =0, m=1;
    for (int i = 6; i >= 0; i--) {
        r += rightOp[i]*m;
        m *=10;
    }
    return r;
}
ULL getLVal(){
    ULL r =0, m=1;
    for (int i = 6; i >= 0; i--) {
        r += leftOp[i]*m;
        m *=10;
    }
    return r;
}
ULL power(int b, int e)
{
    ULL r =1;
    while (e--) {
        r *=b;
    }
    return r;
}
int main(void)
{
    scanf("%d", &N);
    for (int i =0; i < N; i++) {
        scanf("%d", &seq[i]);
    }

    sort_decending();
    for (int i =0; i < 14; i+=2) {
        ULL tmp = 0;
        if(seq[i] == seq[i+1]){
            leftOp[i/2] = seq[i];
            rightOp[i/2] = seq[i+1];
        }
        leftOp[i/2] = seq[i];
        rightOp[i/2] = seq[i+1];
        tmp = ABS(getLVal() - getRVal());

        leftOp[i/2] = seq[i+1];
        rightOp[i/2] = seq[i];
        if(ABS(getLVal() - getRVal()) > tmp) {
            leftOp[i/2] = seq[i];
            rightOp[i/2] = seq[i+1];
        }
    }
    ULL r = getRVal();
    ULL l = getLVal();
    result = getLVal() * getRVal() / power(10, (14-N));

    printf("%llu", result);

    return 0;
}
#endif
