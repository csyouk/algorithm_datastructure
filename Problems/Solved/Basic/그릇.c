
// 문제 번호 S: [TST]그릇
#if 0
#include <stdio.h>
char d[55];
int main(void)
{
	// 여기서부터 작성
	char *prev = d + 54;
	char *p = d;
	int h = 0;
	//freopen("test.txt", "r", stdin);
	scanf("%s", d);

	while (*p)
	{
		if (*prev == *p)
		{
			h += 5;
		}
		else
		{
			h += 10;
		}
		prev = p;
		p++;
	}

	printf("%d", h);


	return 0;
}
#endif
