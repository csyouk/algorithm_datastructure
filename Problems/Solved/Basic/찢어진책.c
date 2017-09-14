
#if 0
//도서관 사서인 현준이는 만화책의 한 장이 찢어졌다는 것을 알고, 찢어진 페이지를 알아보려고 한다.
//그 만화책은 N 페이지 (N은 짝수)였고, 1,2쪽이 같은 종이에 있고 그 뒤부터 N쪽까지 쭉 쪽수가 매겨져 있다.
//현준이는 책의 쪽번호의 합을 구하는 기계를 가지고 있었기 때문에, 쪽번호의 합
//Sum을 구할 수 있었으나, 그걸 이용해서 찢어진 페이지의 번호를 구하기에는 역부족이었다.
//현준이를 도와 찢어진 페이지를 구하는 프로그램을 작성하여라.
//첫 번째 줄에 N과 Sum이 입력된다. (2≤N≤500, 1≤Sum≤125,000)
//만약 입력이 잘못되었으면 "Error"을 출력한다.
//그렇지 않으면 찢어진 장에 새겨져 있는 페이지의 번호 두 개를 오름차순으로 출력한다.
#include <stdio.h>

int N, Sum;

int error;
int pageno;

int main(void)
{
	int page_sum;
	int lost_sum;


	scanf("%d %d", &N, &Sum);


	/* N이 홀수이면 에러*/
	if (N % 2)
	{
		error = 1;
	}
	else
	{
		/* 페이지의 합 계산*/
		page_sum = (1 + N)*(N / 2);
		lost_sum = page_sum - Sum;

		/* 찢어진 페이지의 합이 짝수이면 에러*/
		/* 찢어진 페이지의 합이 3 미만이면 에러*/
		/* 찢어진 페이지의 합이 (N-1)+N 초과이면 에러*/
		/* 찢어진 페이지/2가 짝수이면 에러*/
		if ((lost_sum % 2 == 0) || (lost_sum<3) || (lost_sum>(N - 1) + N) || lost_sum / 2 % 2 == 0)
		{
			error = 1;
		}
	}
	pageno = lost_sum / 2;

	if (error == 1) printf("Error");
	else printf("%d %d", pageno, pageno + 1);

	return 0;
}
#endif
