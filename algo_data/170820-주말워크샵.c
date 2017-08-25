// 문제 번호 A: [TST]덧셈(Plus)
#if 0
// 0이상 9이하의 숫자로 이뤄진 문자열 S가 주어졌을 때, S 사이에 적당히 +기호를 추가 하여 주어진 정수 X에 대해 SA + SB = X 를 만족시키는 경우가 존재하는지 알아내는 프로그램을 작성하라. 여기서 SA는 추가된 +기호 앞, SB는 추가된 +기호 뒤의 문자열을 뜻한다. 예를 들어 S = "1245", X = 57일 경우 2와 4 사이에 +기호를 추가시켜 12+45=57을 만들 수 있다.
// 입력은 한 줄로 이뤄지며 길이 20 이하의 문자열 S와 1이상 1,000,000,000 이하의 정수 X가 입력된다.
// 입력에 대해 SA + SB = X를 만족하는 경우가 존재하면 “SA+SB=X”(괄호제외)의 형태로 출력한다.
// 만약 존재하지 않을 경우 "NONE"을 출력한다.

#include <stdio.h>

#define UL unsigned int
#define ULL unsigned long long int
char operand[];

ULL str_to_int(ULL iter_cnt, char *p)
{
    ULL total = 0;
    ULL weight = 1;

    while(iter_cnt)
    {
        total += (*p - '0') * weight;
        weight *= 10;
        p--;
        iter_cnt--;
    }

    return total;
}
ULL str_length(char *p)
{
    int length = 0;
    while(*p) { length++; p++;}
    return length;
}

int main(void)
{

    ULL sol;


    scanf("%s %llu", operand, &sol);

    ULL operand_len = str_length(operand);
    for (ULL operator_pos = 1; operator_pos < operand_len; operator_pos++) {
        ULL total = 0;

        char *p = &operand[0];

        ULL leftOp = str_to_int(operator_pos, p + (operator_pos-1));

        ULL rightOp = str_to_int(operand_len - operator_pos, p + (operand_len - 1));

        total = leftOp + rightOp;

        if(total == sol) {printf("%llu+%llu=%llu", leftOp, rightOp, total); return 0;}
    }

    printf("NONE");



    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>
#define ULL unsigned long long int
int main(void)
{
	// separator를 2개로 해서 만들어보기.
	char test[] = "1245951324584536574355";
	ULL sol = 57;
	ULL A, B;
	int i, j, k;
	for (i = 0; i < strlen(test) - 1; i++)
	{
		A = 0;
		for (j = 0; j <= i; j++)
		{
			A = A * 10 + (test[j] - '0');
		}
		B = 0;
		for (k = j; k < strlen(test); k++)
		{
			B = B * 10 + (test[k] - '0');
		}
		printf("A=%20llu, B=%20llu, A+B=%20llu\n", A, B, A + B);
	}
}
#endif

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

#if 0
int main(void)
{

	return 0;
}
#endif

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

// 문제 번호 H: [TST]Two Strings
#if 0
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
