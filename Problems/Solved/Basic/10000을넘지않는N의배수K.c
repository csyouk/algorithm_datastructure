
#if 0
//양의 정수 N(1이상, 10,000미만)을 입력 받아, N부터 N의 배수의 합을 구해서 합이 10,000을 넘지 않도록 하는 가장 큰 N의 배수 K를 인쇄하라.
//예를 들어, N이 7이라면, 7 + 14 + 21 + ... + K < 10, 000 인 K 중 가장 큰 값을 인쇄한다.
//N이 범위를 벗어나는 경우는 없다고 가정하고, 이에 대한 예외 처리는 하지 않는다.
//10,000미만의 값 N을 입력한다.
//조건을 만족하는 N의 배수 K를 인쇄한다.
#include <stdio.h>

int N;
int sol;

int main(void)
{
	int sum, K;


	scanf("%d", &N);


	K = N;
	sum = K;
	while (sum < 10000)
	{
		K += N;
		sum += K;
	}
	sol = K - N;


	printf("%d", sol);

	return 0;
}
#endif
