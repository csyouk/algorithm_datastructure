
// 문제 번호 W: [TST]분수의 합 구하기
#if 0
#include <stdio.h>
typedef struct _fraction
{
	short numerator;
	unsigned short delimeter;
} Frac;

Frac fractions[100];
int n;

int gcd(a, b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
int lcm(a, b)
{
	if (a == 0 || b == 0) return 0;
	return a*b / gcd(a, b);
}
int main(void)
{
	// 여기서부터 작성
	int D=1, N=0, _gcd=0;

	freopen("test.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &fractions[i].numerator, &fractions[i].delimeter);
	}

	for (int i = 0; i < n; i++)
	{
		D = lcm(D, fractions[i].delimeter);
	}
	for (int i = 0; i < n; i++)
	{
		if (fractions[i].numerator == 0) continue;
		N += (D / fractions[i].delimeter) * fractions[i].numerator;
	}

	_gcd = gcd(D,N);

	if (_gcd == 0 || N/_gcd==0) printf("%d", 0);
	else {
		if (D / _gcd < 0) { printf("%d/%d", -N / _gcd, -D / _gcd); }
		else{ printf("%d/%d", N / _gcd, D / _gcd); }
	}

	return 0;
}
#endif
