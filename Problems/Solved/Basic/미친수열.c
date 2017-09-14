
#if 0
다음과 같은 수열이 있다. 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5... (숫자 k가 연달아 k번 나오는 수열).정수 n이 주어졌을 때, 해당 수열에서 n번째 나오는 숫자를 출력하는 프로그램을 작성하라.수열의 첫 번째 원소는 1이다.
* C 솔루션은 다음 코드를 참조하시오.
입력
입력은 한 줄에 정수 n이 들어온다. n은 1이상 1018 이하의 정수이다.
출력
수열에서의 n번째 원소를 출력한다.
#include <stdio.h>

long long n, sol;

double sqrt(const double d)
{
	/*
	바빌로니아법:
	Xn+1 = (Xn + d / Xn) / 2 에서 n을 계속 증가시키면 Xn은 d의 제곱근에 수렴
	Xn의 초기값 X0는 임의의 양의 실수를 선택하면 되는데 보통 1.0을 사용
	이전 수(Xn)는 x, 다음 수(Xn+1)는 n일 때 코드 구현은 다음과 같음
	*/

	double n = d / 2.0;
	double x = 0.0;

	while (n != x)
	{
		x = n;
		n = (n + d / n) / 2.0;
	}

	return n;
}

int main(void)
{
	long long temp;


	scanf("%lld", &n);


	sol = (long long)((-1 + sqrt((double)1 + 8 * n)) / 2);
	temp = (sol + 1)*sol / 2;
	if (temp < n) sol++;


	printf("%d", sol);

	return 0;
}
#endif
