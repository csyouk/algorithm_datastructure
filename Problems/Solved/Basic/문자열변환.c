
#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]문자열 변환
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 4  해결 문제 수 : 4
	 [제출][채점 상황 열람]
	 문제 설명
	 현석이가 책을 발간하기 위해서 원고를 작성하여 출판사에 보냈다.며칠 후 출판사에서 택배로 초안을 보내왔다.
	 현석이는 초안을 읽어보다가 오타를 발견하였다.그런데 오타가 한글자만 있는 것이 아니어서 수정해야 하는 문자를 기록하여 다시 출판사로 보내주었다.
	 여기서 문자란 숫자를 포함하며, 대소문자를 구별한다.즉, 대문자와 소문자는 다른 문자이다.
	 당신이 할 일은 현석이가 보내온 정보를 가지고 제대로 수정된 문장을 출력하는 것이다.
	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 int n, m;
char a[50 + 10];
char b[50 + 10];
char s[100000 + 10];

int main(void)
{
	int i;
	int j;


	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("\n%c %c\n", &a[i], &b[i]);
	}

	scanf("%d", &m);
	for (i = 0; i<m; i++)
	{
		scanf("\n%c", &s[i]);
	}


	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (s[i] == a[j])
			{
				s[i] = b[j];
				break;
			}
		}
	}
	printf("%s", s);

	return 0;
}
입력
입력의 첫 줄에는 수정해야 하는 정보의 개수 n(n≤50)이 들어온다.그 다음 줄부터 n개의 줄에 각각 2개씩의 문자가 들어오는데 이것은 첫 번째 문자를 두 번째 문자로 바꾸라는 것이다.
그 다음 오타가 포함되어있는 문장의 문자개수 m(1≤m≤100, 000)이 들어오고 그 다음부터 m개의 문자가 들어온다.
출력
출력은 m개의 문자를 수정하여 한 줄에 공백 없이 출력한다.
입력 예시
3
A a
0 5
5 4
10
A
B
C
0
1
4
5
a
b
A
출력 예시
aBC5144aba
도움말
#endif
