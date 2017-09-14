
#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]단어 세기
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 4  해결 문제 수 : 4
	 [제출][채점 상황 열람]
	 문제 설명
	 임의의 문장을 입력 받아 각 단어 별로 나눈 후에 단어들의 중복되는 개수를 구하는 프로그램을 작성하시오.
	 (1) 입력된 스트링은 글자의 제한은 없다.즉 공백이나 ', ' 등도 입력으로 들어 올 수 있다.
	 (2) 입력된 문장에서 각 단어 사이의 구분은 공백으로 한다.
	 (3) 단어에는 공백을 제외한 단어들만이 포함된다.
	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 char str[200 + 10];

char *strp[200 + 10];
char sol[100 + 10][200 + 10];
int  sp;

unsigned int strlen(const char *d)
{
	unsigned int cnt = 0;

	while (*d++)
	{
		cnt++;
	}

	return cnt;
}

int strcmp(const char *s1, const char *s2)
{
	for (;;)
	{
		if (*s1 > *s2) return 1;
		else if (*s1 < *s2) return -1;
		else if (*s1 == 0) return 0;
		s1++;
		s2++;
	}
}

int main(void)
{
	int i, j, len, n, cnt;

	for (;;)
	{

		gets(str);
		if (str[0] == 'E' && str[1] == 'N' && str[2] == 'D' && str[3] == '\0') break;


		len = (int)strlen(str);
		n = 0;
		strp[0] = &str[0];
		for (i = 1; i<len; i++)
		{
			if (str[i] == ' ')
			{
				str[i] = 0;
				n++;
				strp[n] = &str[i + 1];
			}
		}
		n++;

		/* 오름차순 정렬 */
		for (i = 0; i<n - 1; i++)
		{
			for (j = i + 1; j<n; j++)
			{
				if (strcmp(strp[i], strp[j])>0)
				{
					char *p;
					p = strp[i];
					strp[i] = strp[j];
					strp[j] = p;
				}
			}
		}

		cnt = 1;
		sp = 0;
		for (i = 1; i<n; i++)
		{
			if (strcmp(strp[i], strp[i - 1]) != 0)
			{
				sprintf(sol[sp++], "%s : %d", strp[i - 1], cnt);
				cnt = 1;
			}
			else
			{
				cnt++;
			}
		}
		sprintf(sol[sp++], "%s : %d", strp[i - 1], cnt);

		for (i = 0; i<sp; i++)
		{
			printf("%s\n", sol[i]);
		}
	}

	return 0;
}

*JAVA 솔루션은다음코드를참조하시오.

import java.util.Arrays;
import java.util.Scanner;

public class Main
{
	public static void main(String[] arg)
	{
		String str;
		String[] word;
		int i;
		int word_index;
		int dup;

		Scanner sc = new Scanner(System.in);

		for (;;)
		{
			str = sc.nextLine();
			if (str.equals("END")) break;

			word = str.split(" ");
			word_index = word.length;

			Arrays.sort(word);

			dup = 1;
			for (i = 1; i<word_index; i++)
			{
				if (word[i].equals(word[i - 1])) dup++;
				else
				{
					System.out.println(word[i - 1] + " : " + dup);
					dup = 1;
				}
			}

			System.out.println(word[i - 1] + " : " + dup);
		}

		sc.close();
	}
}
입력
임의의 문장을 입력 받는다. (문장의 길이는 200 이하)
하나의 결과가 나온 후에도 계속 새로운 입력을 받다가, "END"가 입력되면 프로그램을 종료하다.
출력
각 단어들의 발생 빈도를 사전 순으로 출력한다.
입력 예시
I AM DOG DOG DOG DOG A AM I
I AM OLYMPIAD JUNGOL JUNGOL OLYMPIAD
END
출력 예시
A : 1
AM : 2
DOG : 4
I : 2
AM : 1
I : 1
JUNGOL : 2
OLYMPIAD : 2
#endif
