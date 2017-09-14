
#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]달팽이삼각형
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 5  해결 문제 수 : 4
	 [제출][채점 상황 열람]
	 문제 설명
	 삼각형의 높이 N을 입력 받아서 아래와 같이 숫자 0부터 달팽이 모양으로 차례대로 채워진 삼각형을 출력하는 프로그램을 작성하시오.
	 < 처리조건 >
	 왼쪽 위부터 시계방향으로 오른쪽 아래로 이동하면서 숫자 0부터 N개를 채우고 다시 왼쪽으로, 다음은 위쪽으로 반복하면서 채워 나간다. (숫자 9 다음에는 0부터 다시 시작함)


	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 int N;

int a[100 + 10][100 + 10];

int main(void)
{
	int i, j;
	int k, d = 0, flag = 0, cnt, max;


	scanf("%d", &N);


	i = -2;
	j = -1;
	max = N;
	for (k = 0; k<N; k++)
	{
		if (flag == 0)
		{
			for (cnt = 0, i += 2, j++; cnt<max; i++, j++, cnt++)
			{
				a[i][j] = d;
				if (d == 9) d = 0;
				else d++;

			}
			flag = 1;
		}
		else if (flag == 1)
		{
			for (cnt = 0, i--, j -= 2; cnt<max; j--, cnt++)
			{
				a[i][j] = d;
				if (d == 9) d = 0;
				else d++;
			}
			flag = 2;
		}
		else
		{
			for (cnt = 0, i--, j++; cnt<max; i--, cnt++)
			{
				a[i][j] = d;
				if (d == 9) d = 0;
				else d++;
			}
			flag = 0;
		}
		max--;
	}

	for (i = 0; i<N; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
입력
마름모의 한 변의 길이 N(N의 범위는 100 이하의 양의 정수)을 입력 받는다.
출력
주어진 형태대로 높이가 N인 달팽이 삼각형을 출력한다.숫자 사이는 한 개의 공백으로 구분한다.
입력 예시
6
출력 예시
0
4 1
3 5 2
2 0 6 3
1 9 8 7 4
0 9 8 7 6 5

#endif
