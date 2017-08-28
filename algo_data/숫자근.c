#include <stdio.h>
#include <string.h>
// JUNG 1260
#if 0
int N;
unsigned long long int data;

int main(void)
{
	int digit_root = 0;
	int tmp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		data = 0;
		scanf("%llu", &data);
		tmp = data;
		while (data / 10)
		{
			data = data / 10 + data % 10;
		}
		if (digit_root < data) digit_root = tmp; 
	}

	printf("result=%d\n", digit_root);
}
#endif