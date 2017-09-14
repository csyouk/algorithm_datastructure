
#if 0
한 정수 n을 입력 받아서 이차원 배열 n*n을 아래와 같이 "ㄹ"자로 채워서 출력하는 프로그램을 작성하시오.

n = 3인 예
1 2 3
6 5 4
7 8 9

n = 5인 예
1 2 3 4 5
10 9 8 7 6
11 12 13 14 15
20 19 18 17 16
21 22 23 24 25
한 정수 n( 2 <= n <= 100 )이 입력된다.
n*n배열(행렬)을 "ㄹ"자 모양으로 채우시오

#include <stdio.h>

int N;
int sol[100 + 10][100 + 10];

int main(void)
{
	int i, j;
	int cnt = 0;


	scanf("%d", &N);


	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			sol[i][j] = (i % 2 == 0) ? ++cnt : cnt--;
		}
		cnt += N;
	}

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			printf("%d ", sol[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#endif
