
// 숫자맞추기
#if 0

int main(void)
{
	int a = 0, b = 0;
	char x[5], y[5];
	scanf("%s %s", &x, &y);

	for (int i = 0; i < sizeof(x)-1; i++)
	{
		if (x[i] == y[i])
		{
			a++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j) continue;
			if (x[i] == y[j])
			{
				b++;
			}
		}
	}


	printf("%dA%dB", a, b);

}
#endif



#if 0
경곽이는 친구들과 게임을 하기로 했다. 이 게임에는 n명의 플레이어가 참가한다.
게임의 룰은 다음과 같다.
각각의 플레이어는 1이상 100이하의 좋아하는 정수를 카드에 적어서 제출한다.
각 플레이어는 자신과 같은 수를 쓴 사람이 없을 경우에, 자신이 카드에 쓴 만큼의 점수를 얻는다.
자신과 같은 수를 쓴 사람이 있는 경우에는 득점할 수 없다.
경곽이와 친구들은 게임을 3번 했다.각 플레이어가 3번 게임에 대해서 쓴 카드의 정수가 주어질 때, 각 플레이어가 3번 게임에서 얻는 점수의 합계를 구하는 프로그램을 작성하시오.
첫 번째 줄에는 정수 n(2 <= n <= 200)이 주어진다.
두 번째 줄부터 n줄에 걸쳐서 각각 3개의 1이상 100이하의 자연수가 공백으로 구분되어 입력된다.
각 줄에 각 플레이어가 얻은 점수를 출력한다.

#include <stdio.h>

int n;
int a[200 + 10][3];
int sol[200 + 10];

int main(void)
{
	int i;
	int j, k;


	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}


	for (i = 0; i<3; i++)
	{
		for (j = 0; j<n; j++)
		{
			for (k = 0; k<n; k++)
			{
				if (j == k)continue;
				if (a[j][i] == a[k][i]) break;
			}
			if (k == n) sol[j] += a[j][i];
		}
	}


	for (i = 0; i<n; i++)
	{
		printf("%d\n", sol[i]);
	}

	return 0;
}
#endif
