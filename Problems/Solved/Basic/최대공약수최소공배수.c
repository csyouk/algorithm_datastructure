// 문제 번호 P: [TST]최대공약수와최소공배수
#if 0
int gcd(a, b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
int lcm(a, b)
{
	return a*b / gcd(a, b);
}
int main(void)
{
	// 여기서부터 작성
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", gcd(a,b));
	printf("%d", lcm(a, b));
	return 0;
}
#endif
