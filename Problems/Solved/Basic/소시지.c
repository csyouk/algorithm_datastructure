#if 0
#include <stdio.h>
int N, M;
int gcd(a, b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main(void)
{
	int i;
	scanf("%d %d", &N, &M);

	printf("%d", M - gcd(N,M));
	return 0;
}
#endif
