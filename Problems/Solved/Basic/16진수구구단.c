
#if 0
16진수(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F)를 배운 경곽이는 16진수끼리 곱하는 16진수 구구단에 대해서 궁금해졌다.
A, B, C, D, E, F 중 하나가 입력될 때, 1부터 F까지 곱한 16진수 구구단의 내용을 출력해보자.
16진수로 한자리 수가 입력된다.
단, A ~ F 까지만 입력된다.
입력한 16진수에 1~F까지 순서대로 곱한, 16진수 구구단을 줄을 바꿔 출력한다.
계산 결과도 16진수로 출력해야 한다.
#include <stdio.h>

int N;

int main(void)
{
	int i;


	scanf("%X", &N);


	for (i = 1; i <= 0xf; i++)
	{
		printf("%X*%X=%X\n", N, i, N*i);
	}

	return 0;
}
#endif
