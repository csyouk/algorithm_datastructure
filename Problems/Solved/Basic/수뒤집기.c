
#if 0
수 124를 뒤집으면 421이 되고 이 두 수를 합하면 545가 된다.
124와 같이 원래 수와 뒤집은 수를 합한 수가
좌우 대칭이 되는지 테스트하는 프로그램을 작성하시오.
첫째 줄에 정수 N(1≦ N ≦ 100)이 입력되고 다음 줄부터 N개의 줄에 정수 M(1≦ M ≦ 1,000,000)이 입력된다.
N개 만큼의 원래 수와 뒤집은 수를 합한 수가 좌우 대칭이 되면 YES를 아니면 NO를 출력한다.

#include <stdio.h>

int N, M, sym;

int reverse(int num)
{
	int rnum = 0;

	while (num>0)
	{
		rnum *= 10;
		rnum += num % 10;
		num /= 10;
	}
	return rnum;
}

int main(void)
{
	int i;
	int new_num;


	scanf("%d", &N);

	for (i = 0; i<N; i++)
	{

		scanf("%d", &M);


		new_num = M + reverse(M);
		if (new_num == reverse(new_num))    sym = 1;
		else  sym = 0;


		if (sym == 1)      printf("YES\n");
		else  printf("NO\n");
	}

	return 0;
}
#endif
