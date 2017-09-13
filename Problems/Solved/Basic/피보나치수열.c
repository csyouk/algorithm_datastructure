// 피보나치수열
#if 0
#define ULL unsigned long long int
ULL memo[50];
ULL fib(n)
{
	if (n == 1) return 1;
	else
	{
		if (memo[n-1]) return memo[n-1];
		else
		{
			memo[n-1] = fib(n - 1);
			return memo[n - 1] + memo[n-2];
		}
	}
}
int main(void)
{
	// 여기서부터 작성
	int N;
	scanf("%d", &N);
	printf("%llu", fib(N));
	return 0;
}
#endif
