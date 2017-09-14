
#if 0
//정수 A와 B를 같은 양의 정수 M으로 나누었을 때 나머지가 같다면 (A-B)는 M으로 나누어 떨어진다.
//
//A = MQ + R(0≤R＜M)
//B = MQ'+R
//A - B = M(Q - Q') + (R-R)
//그러므로 A - B = M(Q - Q')
//즉, A - B는 M으로 나누어 떨어지고 M의 배수이다.
//
//예로 세 자연수 13511, 13903, 14589를 같은 수로 나누었을 때, 같은 수의 나머지가 남도록 하는 정수 중에서 가장 큰 것을 구하면,
//13511 = nQ + R
//13903 = nQ' + R
//14589 = nQ'' + R
//이때 가장 큰 n은 98이다.
//* C 솔루션은 다음 코드를 참조하시오.
//첫 줄에 3개의 자연수 a, b, c(1≤a, b, c≤100,000,000)가 공백으로 구분하여 입력된다.
//첫 줄에 3개의 자연수를 같은 수로 나누었을 때, 같은 수의 나머지가 남도록 하는 정수 중에서 가장 큰 것을 출력한다.

#include <stdio.h>

int a, b, c;
int sol;

#define ABS(a,b) (((a)>(b))?((a)-(b)):((b)-(a)))

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{

	scanf("%d %d %d", &a, &b, &c);


	if (a != b) a = ABS(a, b);
	if (b != c) b = ABS(b, c);
	sol = gcd(a, b);


	printf("%d", sol);

	return 0;
}
#endif
