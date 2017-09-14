
// 연속부분최대곱
#if 0
int N;
double d[10000 + 10];
double max;
int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &d[i]);
	}

	for (int i = 0; i < N; i++)
	{
		double tmp = 1.0;
		for (int j = i; j < N; j++)
		{
			tmp *= d[j];
			if (max < tmp)
			{
				max = tmp;
			}
		}
	}

	printf("%.3f", max);

	return 0;
}
#endif

//	연속부분최대곱
#if 0
#include <stdio.h>
int N;
double a[10000 + 10], sol = 0.0;
int main(void){
	int i, j;
	double mul = 1.0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%lf", &a[i]);
	for (i = 0; i < N; i++){
		if (mul < 1.0)	mul = a[i];
		else mul *= a[i];
		if (sol < mul)	sol = mul;
	}
	printf("%.3lf", sol);
	return 0;
}
#endif


#if 0
N개의 양의 실수가 있을 때, 한 개 이상의 연속된 수들의 곱이 최대가 되는 부분을 찾아, 그 곱을 출력하는 프로그램을 작성하시오.예를 들어 아래와 같이 8개의 양의 실수가 주어진다면,

색칠된 부분의 곱이 최대가 되며, 그 값은 1.638이다.
결과는 double형의 범위를 넘지 않는다.
* C 솔루션은 다음 코드를 참조하시오.
입력
첫째 줄은 나열된 양의 실수들의 개수 N이 주어지고, 그 다음 줄부터 N개의 수가 한 줄에 하나씩 들어 있다. N은 10,000 이하의 자연수이다.
출력
계산된 최대값을 소수점 이하 넷째 자리에서 반올림하여 소수점 이하 셋째 자리까지 출력한다.
#include <stdio.h>

int N;
double d[10000 + 10];
double sol;

int main(void)
{
	int i;
	int j;
	double value;


	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%lf", &d[i]);
	}


	sol = d[0];
	for (i = 0; i<N; i++)
	{
		value = d[i];
		if (value > sol) sol = value;

		for (j = i + 1; j<N; j++)
		{
			value *= d[j];
			if (value > sol) sol = value;
		}
	}


	printf("%.3lf", sol);

	return 0;
}
#endif
