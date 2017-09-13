
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
