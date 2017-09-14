
#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]종이접기
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 2  해결 문제 수 : 2
	 [제출][채점 상황 열람]
	 문제 설명
	 직사각형 종이의 왼쪽 반을 오른쪽 반 위로 오도록 접는 것을 오른쪽 접기라 한다.다음 그림은 오른쪽 접기를 연속 두 번 수행하는 과정을 보여준다.



	 오른쪽 접기를 여러 번 수행한 후, 다음 그림과 같이 원래대로 펼치면, 아래로 접힌 골 과 위로 접힌 마루로 이루어진 자국들이 남는다.



	 접은 종이에 남은 자국에서 마루를 ^로, 골을 V로 나타낼 때, 직사각형 종이를 두 번 오른쪽 접기를 수행한 후 원래대로 펼치면, 접은 자국은 왼쪽에서 오른쪽으로 차례대로 ^VV의 모양이 된다.직사각형 종이를 세 번 오른쪽 접기를 수행한 후 원래대로 펼치면, 접은 자국은 왼쪽에서 오른쪽으로 차례대로 ^^VV^VV의 모양이 된다.

	 직사각형 종이를 오른쪽 접기를 수행한 후 원래대로 펼칠 때, 접은 자국을 왼쪽에서 오른쪽으로 마루와 골을 출력하는 프로그램을 작성하시오.
	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 int N;

char a[1024 * 1024];

int main(void)
{
	int i, j;
	int max, hop;
	char toggle;


	scanf("%d", &N);


	max = 1 << N;
	hop = max / 2;

	for (i = 0; i<N; i++, hop /= 2)
	{
		toggle = 0; /* v first */
		for (j = max - hop; j>0; j -= hop * 2)
		{
			a[j] = toggle;
			toggle ^= 1;
		}
	}

	for (i = 1; i<max; i++)
	{
		if (a[i] == 0) printf("V");
		else printf("^");
	}

	return 0;
}
*JAVA 솔루션은다음코드를참조하시오.

/* 1080: 종이접기*/
import java.util.Scanner;

public class Main {

	static int N;
	static char[]a;

	public static void main(String[] args) {

		// 입력받는부분
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		sc.close();

		// 여기서부터작성
		int max = 1 << N;
		int hop = max / 2;
		boolean toggle = false;
		a = new char[max];
		for (int i = 0; i<N; i++, hop /= 2)
		{
			toggle = false; /* v first */
			for (int j = max - hop; j>0; j -= hop * 2)
			{
				a[j] = (toggle == false) ? 'V' : '^';
				toggle = !toggle;
			}
		}

		System.out.println(String.copyValueOf(a).substring(1, a.length));
		/*
		for(int i=1; i<max; i++)
		{
		if(a[i] == '0') System.out.print("V");
		else System.out.print("^");
		}
		*/
	}
}
입력
첫 줄에 오른쪽 접기를 수행할 회수 N(1≤N≤20)이 입력된다.
출력
첫 줄에 마루와 골을 왼쪽부터 순서대로 출력한다.
입력 예시
4
출력 예시
^^V^^VVV^^VV^VV
도움말
[제출][채점 상황 열람]

#endif
