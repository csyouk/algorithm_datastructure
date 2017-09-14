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



// 문제 번호 : [TST]소시지
#if 0
#include <stdio.h>
int N, M;
int main(void)
{
	int i, x;
	// 여기서부터 작성
	scanf("%d %d", &N, &M);


	for ( i = N; i >= 0; i--)
	{
		if (N%i == 0 && M%i == 0){
			x = i;
			break;
		}
	}
	printf("%d", M - x);

	//for ( i = N; i <=M; i += N)
	//{
	//	if ((N*i) % M == 0)
	//	{
	//		printf("%d", i);
	//		return 0;
	//	}
	//}



	return 0;
}
#endif
