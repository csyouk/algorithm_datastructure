
#if 01
//아래와 같이 둥근 케이크를 2번의 칼질로 4조각으로 나누려고 한다.
//케이크의 둘레에 시계방향으로 1~100까지 일정한 간격으로 번호가 부여되어 있다.
//칼로 자르려고 하는 부분은 2개의 정수로 표현한다.칼로 자르려는 부분이 2군데 주어질 때 칼로 잘리는 부분이 교차하는지 유무를 판단하는 프로그램을 작성하시오.
//아래 예는 12 53과 99 45를 자른 예를 나타낸다.
//
//첫 번째 줄에는 첫 번째 현의 정보를 나타내는 두 정수가 입력된다.
//두 번째 줄에는 두 번째 현의 정보를 나타내는 두 정수가 입력된다.
//
//주어진 두 잘린 부분이 교차한다면 "cross", 교차하지 않는다면 "not cross"를 출력한다.

#include <stdio.h>

int a, b, c, d, cross;

int main(void)
{
	int t;


	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);


	if (a>b)
	{
		t = a;
		a = b;
		b = t;
	}

	if ((a<c && c<b) && (a<d && d<b) || (a>c || c>b) && (a>d || d>b)) cross = 0;
	else cross = 1;


	if (cross == 1) printf("cross");
	else printf("not cross");

	return 0;
}
#endif
