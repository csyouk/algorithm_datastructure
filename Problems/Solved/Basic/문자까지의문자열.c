

#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]문자까지의 문자열
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 9  해결 문제 수 : 8
	 [제출][채점 상황 열람]
	 문제 설명
	 문자 N(‘a’ ~‘z’, ‘A’ ~‘Z’)을 입력 받아서 N이 ‘a’ ~‘z’ 이면 'a'부터 문자 N까지 인쇄하고, N이 ‘A’ ~’Z’ 이면 문자 N부터 'Z'까지 인쇄하라.
	 * C 솔루션은다음코드를참조하시오.

#include <stdio.h>

	 char N;

int main(void)
{
	char c;


	scanf("%c", &N);


	if (N >= 'a' && N <= 'z')
	{
		for (c = 'a'; c <= N; c++)
		{
			printf("%c", c);
		}
	}
	else if (N >= 'A' && N <= 'Z')
	{
		for (c = N; c <= 'Z'; c++)
		{
			printf("%c", c);
		}
	}
	else
	{
		printf("Error");
	}

	return 0;
}
// JAVA 솔루션은 다음 코드를 참조하시오. #1
/* 1032: 문자까지의 문자열 */
import java.io.IOException;
public class Main
{
	public static void main(String[] arg) throws IOException
	{
		char ch;
		char i, s, e;
		ch = (char)System.in.read();
		if ((ch >= 'A') && (ch <= 'Z'))
		{
			s = ch;
			e = 'Z';
		}
		else if ((ch >= 'a') && (ch <= 'z'))
		{
			s = 'a';
			e = ch;
		}
		else
		{
			System.out.print("Error");
			return;
		}
		for (i = s; i <= e; i++) System.out.print(i);
	}
}

// JAVA 솔루션은 다음 코드를 참조하시오. #2
/* 1032: 문자까지의 문자열 */
import java.io.IOException;
public class Main {
	static char N;

	public static void main(String[] arg) throws IOException{

		// 입력받는 부분
		N = (char)System.in.read();

		// 여기서부터 작성
		if ((N >= 'a') && (N <= 'z'))
		{
			for (char i = 'a'; i <= N; i++)
			{
				System.out.print(i);
			}
		}
		else if ((N >= 'A') && (N <= 'Z'))
		{
			for (char i = N; i <= 'Z'; i++)
			{
				System.out.print(i);
			}
		}
		else
		{
			System.out.print("Error");
		}
	}
}
입력
‘a’ ~’z’ 또는 ’A’ ~’Z’ 사이의 문자 N을 입력한다.
출력
주어진 형식으로 문자열을 인쇄한다.
N이 범위를 벗어나면 “Error”를 인쇄한다.
입력 예시
f
출력 예시
abcdef
도움말
[입력 예시 2]
Q

[출력 예시 2]
QRSTUVWXYZ

-------------------------------------------------------------------------------------------------- -
[입력 예시 3]
1

[출력 예시 3]
Error
#endif
