
// 문제 번호 B: [TST]체스판
#if 0
#include <stdio.h>

int R, C, A, B;
char chess[110][110];

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int I, J, i, j;
	scanf("%d %d", &R, &C);
	scanf("%d %d", &A, &B);

	// 큰 체스판 칠하기
	for ( I = 0; I < R; I++)
	{
		for ( J = 0; J < C; J++)
		{

			// 격자 칠하기
			for ( i = I*A; i < I * A + A; i++)
			{
				for ( j = J*B; j < J * B + B; j++)
				{
					if ((I + J) % 2 == 0) chess[i][j] = 'X';
					else  chess[i][j] = '.';
				}
			}


		}
	}



	// 칠하기
	for ( i = 0; i <R*A; i++)
	{
		printf("%s\n", chess[i]);
	}

	return 0;
}
#endif
