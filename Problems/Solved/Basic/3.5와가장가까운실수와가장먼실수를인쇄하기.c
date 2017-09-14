
#if 0
실수 데이터 5개를 입력 받아 3.5와 가장 가까운 실수와 가장 먼 실수를 인쇄하라.
실수 5개를 공백으로 구분하여 차례로 입력한다.
3.5로부터 가장 가까운 실수와 가장 먼 실수를 차례대로 인쇄한다.
같은 차이인 경우 작은 수를 인쇄한다.
#include <stdio.h>

double a[5+10];
double min, max;

double abs(double d1, double d2)
{
	return (d1>d2) ? (d1 - d2) : (d2 - d1);
}

int main(void)
{
	int i;
	int min_index, max_index;


	for (i = 0; i<5; i++)
	{
		scanf("%lf", &a[i]);
	}


	min = abs(3.5, a[0]);
	max = abs(3.5, a[0]);
	min_index = 0;
	max_index = 0;

	for (i = 1; i<5; i++)
	{
		double diff = abs(3.5, a[i]);
		if (diff<min)
		{
			min = diff;
			min_index = i;
		}
		if (diff>max)
		{
			max = diff;
			max_index = i;
		}
	}
	max = a[max_index];
	min = a[min_index];


	printf("%f %f", min, max);

	return 0;
}
#endif
