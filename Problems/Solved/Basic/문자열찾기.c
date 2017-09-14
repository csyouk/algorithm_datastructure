
#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]문자열 찾기
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 12  해결 문제 수 : 6
	 [제출][채점 상황 열람]
	 문제 설명
	 주어진 문자열에서 연속 3개의 문자가 IOI 이거나 KOI인 문자열이 각각 몇 개 있는지 찾는 프로그램을 작성하라.
	 문자열은 알파벳의 대문자로만 이루어진다.예를 들어 "KOIOIOI"라는 문자열은 KOI 1개, IOI 2개가 포함되어 있다.

	 * C 솔루션은 다음 코드를 참조하시오.

	 /* 솔루션1: 단순검색 */
#include <stdio.h>

	 char str[10000 + 10];
int  cnt_KOI, cnt_IOI;

unsigned int strlen(const char *d)
{
	unsigned int cnt = 0;

	while (*d++)
	{
		cnt++;
	}

	return cnt;
}

int main(void)
{
	int i, len;


	gets(str);


	len = (int)strlen(str);

	for (i = 0; i<len - 2; i++)
	{
		if (str[i] == 'K' && str[i + 1] == 'O' && str[i + 2] == 'I') cnt_KOI++;
		else if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') cnt_IOI++;
	}


	printf("%d\n%d", cnt_KOI, cnt_IOI);

	return 0;
}

/* 솔루션2: 라빈-카프 */
#include <stdio.h>

char str[10000 + 10];
int  cnt_KOI, cnt_IOI;

unsigned int strlen(const char *d)
{
	unsigned int cnt = 0;

	while (*d++)
	{
		cnt++;
	}

	return cnt;
}

int strncmp(const char *s1, const char *s2, unsigned int n)
{
	while (n--)
	{
		if (*s1 > *s2) return 1;
		else if (*s1 < *s2) return -1;
		else if (*s1 == 0) return 0;
		s1++;
		s2++;
	}
	return 0;
}

unsigned int hash(char* strarr, int s, int len)
{
	unsigned int pow_two = 1;
	unsigned int hash_val = 0;
	int i;
	for (i = s + len - 1; i >= s; i--)
	{
		hash_val += strarr[i] * pow_two;
		pow_two <<= 1;
	}
	return hash_val;
}

int main(void)
{
	unsigned int hash_KOI, hash_IOI, hash_str;
	unsigned int len_str;
	unsigned int pow_two;
	int i;


	gets(str);


	hash_KOI = hash("KOI", 0, 3);
	hash_IOI = hash("IOI", 0, 3);
	hash_str = hash(str, 0, 3);
	len_str = strlen(str);


	pow_two = 1 << 2;
	for (i = 0; i <= (int)len_str - 3; i++)
	{
		if (hash_KOI == hash_str)
		{
			if (!strncmp("KOI", &str[i], 3)) cnt_KOI++;
		}
		else if (hash_IOI == hash_str)
		{
			if (!strncmp("IOI", &str[i], 3)) cnt_IOI++;
		}

		hash_str = 2 * (hash_str - str[i] * pow_two) + str[i + 3];
	}


	printf("%d\n%d", cnt_KOI, cnt_IOI);

	return 0;
}



// JAVA 솔루션은 다음 코드를 참조하시오.



/* 1036: 문자열 찾기 */

import java.util.Scanner;



public class Main {



	static String str;

	static int cnt_koi, cnt_ioi;



	public static void main(String[] args) {



		// 입력받는 부분

		Scanner sc = new Scanner(System.in);

		str = sc.nextLine();

		sc.close();



		// 여기서부터 작성

		int n = str.length();



		for (int i = 0; i<n; i++)

		{

			if (str.regionMatches(i, "KOI", 0, 3) == true) cnt_koi++;

			if (str.regionMatches(i, "IOI", 0, 3) == true) cnt_ioi++;

		}



		// 출력하는 부분

		System.out.println(cnt_koi);

		System.out.println(cnt_ioi);



	}

}



입력
입력은 한 줄이며 10, 000자 이하의 알파벳 대문자로 구성된다.
출력
출력은 2줄이며, 첫 번째 줄에는 KOI의 개수, 두 번째 줄에는 IOI의 개수를 각각 출력하라.
입력 예시
KOIOIOI
출력 예시
1
2
도움말
[제출][채점 상황 열람]
#endif
