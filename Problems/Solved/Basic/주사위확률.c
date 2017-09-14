
#if 0
주사위 두 개를 던져 나온 두 눈의 합이 입력 값 N(2이상, 12이하)과 같을 확률을 인쇄하라.
N이 범위를 벗어나는 경우는 없다고 가정하고, 이에 대한 예외 처리는 하지 않는다.

* C 솔루션은 다음 코드를 참조하시오.
입력
N을 입력한다.
출력
백분율의 형태로 출력하고 소수점 다섯 째 자릿수에서 반올림하여 네 번째 자릿수까지 인쇄한다.
#include <stdio.h>

int N;
double sol;

int main(void)
{
	int i, j, cnt = 0;


	scanf("%d", &N);


	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			if (i + j == N) cnt++;
		}
	}

	sol = (double)cnt * 100 / 36;


	printf("%.4f%%", sol);

	return 0;
}
#endif
