
#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]문자열 뒤집기Ⅱ
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 2  해결 문제 수 : 2
	 [제출][채점 상황 열람]
	 문제 설명
	 최대 길이 50이하인 문자열을 입력 받아 단어 별로 뒤집어서 출력하는 프로그램을 작성하시오.
	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 char s[50 + 10];

int main(void)
{
	int i, j, len, start, end;


	gets(s);


	for (i = 0; s[i]; i++);
	len = i;

	/* 소문자는 대문자로 */
	for (i = 0; i<len; i++)
	{
		if ((s[i] >= 'a') && (s[i] <= 'z')) s[i] -= 'a' - 'A';
	}

	start = 0;
	for (i = 0; i<len; i++)
	{
		/* 특수 문자가 나오면 이전까지의 알파뱃 출력하고 특수 문자도 출력*/
		if ((s[i] == '.') || (s[i] == '!') || (s[i] == ' '))
		{
			end = i;
			for (j = end - 1; j >= start; j--)
			{
				printf("%c", s[j]);
			}
			printf("%c", s[i]);
			start = i + 1;
		}
	}
	/* 마지막에 특수 문자가 아닌 경우 처리*/
	end = len;
	for (j = len - 1; j >= start; j--)
	{
		printf("%c", s[j]);
	}

	return 0;
}
입력
최대 길이 50이하인 문자열이 입력된다.
그리고 ".", "!"는 단어 맨 뒤에만 올 수 있으며, "!!"과 같이 느낌표는 여러 번 연속해서 입력될 수 있다.
출력
단어 별로 뒤집어서 출력하라.단 마침표와 느낌표만은 뒤집지 않으며 소문자는 모두 대문자로 바꾸어 출력한다.
입력 예시
I love GSHS Online Judge.
출력 예시
I EVOL SHSG ENILNO EGDUJ.
도움말
[제출][채점 상황 열람]

#endif
