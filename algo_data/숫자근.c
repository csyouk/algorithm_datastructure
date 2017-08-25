#include <stdio.h>
#include <string.h>

#if 1
int N;
char num[1000001];
char backup[1000001];
int find(char *p)
{
	int total = 0;
	if (*p == 0) return *p;
	total += *p++ - '0';
	return total + find(p);
}

int main(void)
{
	int digit_root = 0;
	int tmp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", num);
		tmp = find(num);
		if (digit_root < tmp)
		{
			strcpy(backup, num);
		}
	}

	printf("result=%s\n", backup);
}
#endif