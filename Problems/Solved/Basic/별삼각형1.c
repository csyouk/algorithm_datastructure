
#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]별삼각형1
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 7  해결 문제 수 : 4
	 [제출][채점 상황 열람]
	 문제 설명
	 삼각형의 높이 n과 종류 m을 입력 받은 후 다음과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오.


	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 int n, m;

int main(void)
{
	int i, j;


	scanf("%d %d", &n, &m);


	if ((n<1) || (n>100) || (m<1) || (m>3))
	{
		printf("INPUT ERROR!\n");
		return 0;
	}

	if (m == 1)
	{
		for (i = 0; i<n; i++)
		{
			for (j = 0; j <= i; j++) printf("*");
			printf("\n");
		}
	}
	else if (m == 2)
	{
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<(n - i); j++) printf("*");
			printf("\n");
		}
	}
	else
	{
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<(n - i - 1); j++) printf(" ");
			for (j = 0; j<(2 * i + 1); j++) printf("*");
			printf("\n");
		}
	}

	return 0;
}

// JAVA 솔루션은 다음 코드를 참조하시오.

/* 1074: 별삼각형1 */

import java.util.Scanner;

public class Main {

	static int n, m;

	public static void main(String[] args) {

		// 입력받는 부분
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		sc.close();

		// 여기서부터 작성
		int i, j;
		char str[] = new char[200 + 10];

		if ((n<1) || (n>100) || (m<1) || (m>3))
		{
			System.out.print("INPUT ERROR!");
			return;
		}
		// * 문자열 만들기
		for (i = 0; i<n * 2; i++)
		{
			str[i] = '*';
		}

		if (m == 1)
		{
			for (i = 0; i<n; i++)
			{
				System.out.println(String.valueOf(str).substring(0, i + 1));
			}
		}
		else if (m == 2)
		{
			for (i = 0; i<n; i++)
			{
				System.out.println(String.valueOf(str).substring(0, n - i));
			}
		}
		else
		{
			for (i = 0; i<n; i++)
			{
				for (j = 0; j<(n - i - 1); j++) System.out.print(" ");
				System.out.println(String.valueOf(str).substring(0, 2 * i + 1));
			}
		}

	}
}
입력
삼각형의 크기 n(n의 범위는 100 이하의 자연수)과 종류 m(m은 1부터 3사이의 자연수)을 입력 받는다.
출력
위에서 언급한 3가지 종류를 입력에서 들어온 높이 n과 종류 m에 맞춰서 출력한다.
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"을 출력한다.
입력 예시
3 2
출력 예시
***
**
*
도움말
[제출][채점 상황 열람]

#endif
