
// 문제 번호 V: [TST]주차요금
#if 0
#include <stdio.h>
int n;
int rule(int min)
{
	if (min < 10) return 0;
	if (min <= 30) return 500;
	int t = 500;
	min -= 31;
	t += (min / 10 + 1)*300;

	if (t > 50000) t = 50000;
	return t;
}
int main(void)
{
	// 여기서부터 작성
	int fee = 0, d;
	//freopen("test.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d);
		fee += rule(d);
	}
	printf("%d", fee);
	return 0;
}
#endif
