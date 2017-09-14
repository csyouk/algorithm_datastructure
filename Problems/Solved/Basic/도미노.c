
#if 0

문제 설명
도미노는 블록의 일종으로 두 개의 정사각형 칸(위칸, 아래칸으로 구분)으로 나뉘어진 블록을 말한다.도미노의 각 칸에 최소 0개 최대 N개의 점을 찍고자 하는데, 가능한 경우가 총 몇 가지인지 알아보고자 한다.
이 경우 도미노를 위 아래로 뒤집었을 때 찍힌 점의 개수가 동일한 경우 하나로 간주한다.예를 들어 위칸에 1이 찍히고 아래칸에 2가 찍힌 경우는, 위칸에 2가 찍히고 아래칸에 1이 찍힌 경우와 동일한 것으로 간주한다.
아래 그림은 N = 2일 경우의 예이다.

Figure 1: N = 2 경우
* C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

int N;
int sol;

int main(void)
{

	scanf("%d", &N);


	N++;
	sol = (N % 2) ? ((N)*(N - 1) / 2 + N) : ((N + 1)*N / 2);


	printf("%d", sol);

	return 0;
}
*JAVA 솔루션은 다음 코드를 참조하시오.

/* 1072: 도미노*/
/* 0부터N까지두개를고르는경우의수를구하는것임*/

import java.util.Scanner;

public class Main {

	static int N;
	static int sol;

	public static void main(String[] args) {
		// 입력받는부분
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		sc.close();

		// 여기서부터작성
		sol = (N + 1)*(N + 2) / 2;

		// 출력하는부분
		System.out.print(sol);
	}
}

입력
입력은 한 줄로 이루어지며, 정수 N(1≤N≤10, 000)이 입력된다.
출력
정수 N에 대해 점을 찍을 수 있는 수의 가짓수를 출력한다.
입력 예시
2
출력 예시
6
#endif
