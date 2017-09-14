
// 앞뒤 같은 제곱
#if 0
'앞뒤 같은 수'란 앞에서부터 읽으나 뒤에서부터 읽으나 동일한 수를 말한다. 수 12321 이 '앞뒤 같은 수'의 예가 될 수 있다.

N(1≤N≤300, 10진수)중에서 N ^ 2이 B(2≤B≤20, 10진수)진수로 표현했을 때, '앞뒤 같은 수'가 될 때의 N과 N ^ 2를 B진수로 출력하라.

진수표현에 있어 10, 11 그리고 이상의 수들은 'A', ’B’로 표현한다.
* C 솔루션은 다음 코드를 참조하시오.
진수 B가 들어온다.
N2이 '앞뒤 같은 수'가 되는 모든 수를 B진수로 표기한 N과 N2을 출력한다.

#include <stdio.h>

int  B;

char N[300 + 10][20 + 10];
char M[300 + 10][20 + 10];
int cnt;
char nums[] = "0123456789ABCDEFGHIJ";

int trans(char*N, int t)
{
	int p = 0;

	while (t != 0)
	{
		N[p++] = nums[t%B];
		t /= B;
	}
	N[p] = '\0';
	return p;
}

void reverse(char*N, int p)
{
	int temp, j;
	for (j = 0; j<p / 2; j++)
	{
		temp = N[j];
		N[j] = N[p - 1 - j];
		N[p - 1 - j] = temp;
	}
}

int main(void)
{
	int i, j, p;


	scanf("%d", &B);


	for (i = 1; i <= 300; i++)
	{
		p = trans(N[cnt], i*i);

		for (j = 0; j <= p / 2; j++)
		{
			if (N[cnt][j] != N[cnt][p - j - 1])
				break;
		}

		if (j>p / 2)
		{
			p = trans(M[cnt], i);
			reverse(M[cnt], p);
			cnt++;
		}
	}

	for (i = 0; i<cnt; i++)
	{
		printf("%s %s\n", M[i], N[i]);
	}

	return 0;
}
#endif
