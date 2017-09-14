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
