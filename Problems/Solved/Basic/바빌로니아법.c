
#if 0

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
	int a, b;
	scanf("%d %d", &a, &b); // 4 10

	//printf("%d", find_divisors_cnt(a, b));

	printf("%d", b - a + 1 - (int)sqrt(b) + (int)sqrt(a - 1));

	//printf("%d %d %d", (int)sqrt(b), (int)sqrt(a), (int)sqrt(a - 1));

	return 0;
}
#endif
