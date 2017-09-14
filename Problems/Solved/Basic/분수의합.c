
#if 0
N개의 분수가 주어질 때, 모든 분수의 합을 기약분수로 나타내는 프로그램을 작성하시오.
기약분수란 분모와 분자 사이에 공약수가 1 뿐이어서 더 이상 약분되지 않는 분수이다.
입력
첫 번째 줄에 분수의 수 N을 입력 받는다.
두 번째 줄부터 N줄에 걸쳐서 각 분수의 분자의 값과 분모의 값이 공백으로 구분되어 입력된다. (단, N은 100이하의 자연수, 분자의 값은 폐구간 - 100~100의 범위의 정수, 분모는 100이하의 자연수이다.)
출력
N개의 분수의 합을 기약분수 꼴로 분자와 분모를 “ / ”로 구분하여 출력하는데, 결과가 0 / ? 일 경우에는 0만 출력한다.
#include <stdio.h>

int N;
int C[100 + 10];
int P[100 + 10];
int sol1, sol2;

int cal_GCD(int n1, int n2)
{
	if (n2 == 0) return n1;
	return cal_GCD(n2, n1%n2);
}

int cal_LCM(int n1, int n2)
{
	return n1*n2 / cal_GCD(n1, n2);
}

int main(void)
{
	int i;
	int lcm, sum, gcd;


	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%d %d", &C[i], &P[i]);
	}


	/* 분모의 최대 공배수 */
	lcm = P[0];
	for (i = 1; i<N; i++)
	{
		lcm = cal_LCM(lcm, P[i]);
	}

	/* 분자의 합 */
	sum = 0;
	for (i = 0; i<N; i++)
	{
		sum += C[i] * (lcm / P[i]);
	}

	/* 기약 분수 */
	gcd = cal_GCD(lcm, sum);
	sol1 = sum / gcd;
	sol2 = lcm / gcd;


	if (sol1 == 0) printf("0");
	else printf("%d/%d", sol1, sol2);

	return 0;
}

#endif
