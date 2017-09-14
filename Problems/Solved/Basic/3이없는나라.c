
// 문제 번호 : [TST]3이 없는 나라
#if 0
#include <stdio.h>
#define ULL unsigned long long int
#define DIGITS 13
#define SIZE 11
ULL table[DIGITS][SIZE+3];


ULL pow(int b, int e)
{
	ULL r = 1;
	while (e)
	{
		r *= b;
		e--;
	}
	return r;
}
void create_lookuptable(void)
{
	ULL tmp;
	int i, j;
	table[1][1] = 1;
	table[1][SIZE] = 1;
	for ( i = 2; i < DIGITS; i++)
	{
		for ( j = 1; j < SIZE; j++)
		{
			table[i][j] = table[i - 1][SIZE];
			if (j == 3+1) table[i][j] = pow(10, i - 1);
			table[i][SIZE] += table[i][j];
		}
	}
}
ULL conv(ULL num)
{
	int w = 1, add = 0, digit = 1, quot, r, c;
	int first = num % 10;
	if (first > 2) add++;
	num -= first; w = pow(10, digit);
	while (num)
	{
		quot = num / w % 10;
		digit++;

		for (c = 1; c <=quot; c++)
		{
			add += table[digit][c];
			//printf("%d %d\n", digit, c);
		}
		num -= pow(10, digit - 1)*quot;
		w = pow(10, digit);
	}


	return add;
}
int main(void)
{
	// 여기서부터 작성
	ULL num;
	create_lookuptable();
	scanf("%llu", &num);

	printf("%llu", num - conv(num));

	return 0;
}
#endif
