
// UNIQUENESS
#if 0
int N;
char database[10000][21];
typedef struct{
	char word[24];
	short index[10000];
} WORD;
WORD words[10000];
int str_cmp(char *p, char *q)
{
	// return 0 when two strings are same
	while (*p || *q)
	{
		if (*p == *q){ p++; q++; continue; }
		return (*p > *q) ? 1 : -1;
		p++; q++;
	}
	return 0;
}
void str_cpy(char *d, const char *s)
{
	while (*d++ = *s++);
}
int main(void)
{
	int i, j, k;
	//freopen("170814-3.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", database[i]);
	}

	// 입력
	for (i = 0; i < N; i++)
	{
		j = 0;
		while (1)
		{
			// 순차적으로 비교후 문자열이 이미 존재할 경우,
			// index만 추가.
			if (str_cmp(&words[j].word, database[i]) == 0)
			{
				k = 0;
				while (1)
				{
					if (words[j].index[k] == 0){
						words[j].index[k] = i + 1;
						break;
					}
					k++;
				}
				break;
			}
			// 문자열이 존재하지 않을 경우 바로 추가.
			// 문자열, 인덱스 추가.
			else
			{
				if (words[j].index[0] != 0){ j++; continue; }
				str_cpy(&words[j].word, database[i]);
				k = 0;
				while (1)
				{
					if (words[j].index[k] == 0){
						words[j].index[k] = i + 1;
						break;
					}
					k++;
				}
				break;
			}
			j++;
		}

	}


	if (words[N-1].index[0] != 0)
	{
		printf("unique");
		return;
	}

	// 출력
	for (i = 0; i < N; i++)
	{
		if (words[i].index[1] == 0) continue;
		printf("%s ", words[i].word);
		j = 0;
		while (1)
		{
			if (words[i].index[j] == 0) break;
			printf("%d ", words[i].index[j]);
			j++;
		}
		printf("\n");

	}

}
#endif



#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]UNIQUENESS
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 1  해결 문제 수 : 1
	 [제출][채점 상황 열람]
	 문제 설명
	 N개의 문자열이 주어졌을 때, 동일한 문자열이 존재하는지 판단하는 프로그램을 작성하라.

	 문자열이란 사이에 공백이 없는 연속된 알파벳 소문자 열을 뜻한다.
	 문자열의 길이는 최소 1글자, 최대 20글자이다.
	 입력되는 문자열의 개수는 2개 이상 10, 000개 이하이다.
	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 int N;
char s[100000 + 10][20 + 10];

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
	int i;
	int j, cnt, unique = 1;


	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%s", s[i]);
	}


	for (i = 1; i<N; i++)
	{
		cnt = 0;
		if (s[i][0] == 0) continue;

		for (j = i + 1; j <= N; j++)
		{
			if (s[j][0] == 0) continue;
			if (strcmp(s[i], s[j]) == 0)
			{
				if (cnt == 0)
				{
					printf("%s %d %d", s[i], i, j);
				}
				else
				{
					printf(" %d", j);
				}
				cnt++;
				s[j][0] = 0;
				unique = 0;
			}
		}
		if (cnt) printf("\n");
	}

	if (unique) printf("unique");

	return 0;
}

*JAVA 솔루션은 다음 코드를 참조하시오.

import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] arg) throws IOException
	{
		int N, i, j, unique = 0, flag;
		String str;
		String[] arr;
		int[] check;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); sc.nextLine();
		str = sc.nextLine();

		arr = str.split(" ");
		check = new int[N];

		for (i = 0; i<N; i++){
			if (check[i] == 0){
				for (j = i + 1, flag = 0; j<N; j++){
					if (arr[i].compareTo(arr[j]) == 0){
						check[j] = 1; unique = 1;
						if (flag == 0){
							System.out.print(arr[i] + " " + (i + 1) + " " + (j + 1));
							flag = 1;
						}
						else{
							System.out.print(" " + (j + 1));
						}
					}
				}
				if (flag == 1) System.out.println();
			}
		}
		if (unique == 0) System.out.println("unique");
	}
}

입력
입력의 첫 번째 줄에는 입력될 문자열의 개수 N이 입력된다.그 다음 줄에는 N개의 문자열이 공백을 사이에 두고 입력된다.전제조건을 어긋나는 입력이 들어오는 경우는 없다.
출력
입력에서 동일한 문자열이 존재하지 않을 경우는 "unique"를 출력한다(큰 따옴표 제외).동일한 문자열이 발생한 경우에는 한 줄에 해당 문자열과, 문자열이 몇 번째로 입력되었는지를 출력해야 하는데, 이 경우 우선 앞에 동일한 문자열이 발견된 문자열을 출력한 다음 공백을 출력한 다음, 공백을 사이에 두고 몇 번째로 입력이 되었는지를 출력한다.동일한 문자열이 존재하는 문자열이 여럿 발견 되었을 경우, 매 줄마다 입력된 순서대로 앞에 나온 형식에 맞춰서 출력을 한다.자세한 사항은 입력예시를 참고한다.
입력 예시
10
alice bob libe lie libe libe alice bob alice alice
출력 예시
alice 1 7 9 10
bob 2 8
libe 3 5 6
도움말
[입력 예시 2]
2
a b

[출력 예시 2]
unique

-------------------------------------------------------------------------------------------------- -
[입력 예시 3]
3
a b a

[출력 예시 3]
a 1 3

#endif
