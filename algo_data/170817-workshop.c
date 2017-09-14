
#if 0
정사각형은 4개의 꼭지점을 갖는다.하나의 정사각형에서 가로 줄과 세로 줄을 1개씩 추가하여 같은 크기의 정사각형 4개로 나누면 꼭지점의 개수는 9개가 된다.이 상태에서 4개로 나누어진 각각의 정사각형에 가로줄과 세로줄을 1개씩 추가하면 16개의 정사각형으로 나누어지고 꼭지점의 개수는 25개가 된다.이와 같은 상황에 대한 그림이 아래에 있다.

아래 그림에서 검은 색 점은 가로 줄과 세로줄을 추가할 때 새로 생기는 점들이다.



초기 정사각형에서 위와 같은 방법으로 가로줄과 세로줄을 추가하여 나누는 것을 1 - iteration이라고 하자.iteration 의 수 N을 입력 받아 N번의 iteration 후의 꼭지점의 총 개수를 출력하는 프로그램을 작성하시오.
* C 솔루션은 다음 코드를 참조하시오.
입력
iteration 의 수 N(1 ≤ N ≤ 15)이 입력된다.
출력
N-iteration 후 꼭지점의 총 수를 출력하시오.
#include <stdio.h>

int N;
int sol;

int main(void)
{

	scanf("%d", &N);


	sol = ((1 << N) + 1) * ((1 << N) + 1);


	printf("%d", sol);

	return 0;
}
#endif

#if 0
당신은 유명한 인디 그룹 "장기두는 얼큰이들"의 N(1≤N≤200)곡의 미 발표곡 노래에 대한 권리를 양도받았다.
당신은 1개의 CD로 이 곡들을 발표할 계획이다.각 CD는 최대 T(1≤T≤100)분 노래를 저장할 수 있다.
당신은 이 노래의 예술적 가치를 판단할 수 없어 만들어진 순서대로 CD에 가장 많은 노래를 수록하려고 한다. (물론 가장 많은 곡을 담는 것이 목표이기에 중간에 빠지는 노래도 발생할 수 있음)
* C 솔루션은 다음 코드를 참조하시오.
입력
첫 줄은 두 개의 정수 N(1≤N≤200)과 T(1≤T≤100)가 입력된다. 다음 줄에 N개의 노래들이 만들어진 순서대로 각 노래의 크기(50 보다 작은 자연수)가 입력된다.
출력
출력은 1 개의 CD에 담을 수 있는 최대 노래 수를 나타내는 정수하나를 출력한다.
#include <stdio.h>

int N, T;
int a[200 + 10];
int sol;

int main(void)
{
	int i;
	int j, t, sum = 0;


	scanf("%d %d", &N, &T);

	for (i = 0; i<N; i++)
	{
		scanf("%d", &a[i]);
	}


	for (i = 0; i<N - 1; i++)
	{
		for (j = i + 1; j<N; j++)
		{
			if (a[i]>a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	/* sum */
	for (i = 0; i<N; i++)
	{
		if (sum + a[i] > T) break;
		sum += a[i];
	}
	sol = i;


	printf("%d", sol);

	return 0;
}
#endif

#if 0
N개의 분수가 주어질 때, 모든 분수의 합을 기약분수로 나타내는 프로그램을 작성하시오.
기약분수란 분모와 분자 사이에 공약수가 1 뿐이어서 더 이상 약분되지 않는 분수이다.
입력
첫 번째 줄에 분수의 수 N을 입력 받는다.
두 번째 줄부터 N줄에 걸쳐서 각 분수의 분자의 값과 분모의 값이 공백으로 구분되어 입력된다. (단, N은 100이하의 자연수, 분자의 값은 폐구간 - 100~100의 범위의 정수, 분모는 100이하의 자연수이다.)
출력
N개의 분수의 합을 기약분수 꼴로 분자와 분모를 “ / ”로 구분하여 출력하는데, 결과가 0 / ? 일 경우에는 0만 출력한다.
#include <stdio.h>

int N;
int C[100 + 10];
int P[100 + 10];
int sol1, sol2;

int cal_GCD(int n1, int n2)
{
	if (n2 == 0) return n1;
	return cal_GCD(n2, n1%n2);
}

int cal_LCM(int n1, int n2)
{
	return n1*n2 / cal_GCD(n1, n2);
}

int main(void)
{
	int i;
	int lcm, sum, gcd;


	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%d %d", &C[i], &P[i]);
	}


	/* 분모의 최대 공배수 */
	lcm = P[0];
	for (i = 1; i<N; i++)
	{
		lcm = cal_LCM(lcm, P[i]);
	}

	/* 분자의 합 */
	sum = 0;
	for (i = 0; i<N; i++)
	{
		sum += C[i] * (lcm / P[i]);
	}

	/* 기약 분수 */
	gcd = cal_GCD(lcm, sum);
	sol1 = sum / gcd;
	sol2 = lcm / gcd;


	if (sol1 == 0) printf("0");
	else printf("%d/%d", sol1, sol2);

	return 0;
}

#endif

#if 0
N개의 양의 실수가 있을 때, 한 개 이상의 연속된 수들의 곱이 최대가 되는 부분을 찾아, 그 곱을 출력하는 프로그램을 작성하시오.예를 들어 아래와 같이 8개의 양의 실수가 주어진다면,

색칠된 부분의 곱이 최대가 되며, 그 값은 1.638이다.
결과는 double형의 범위를 넘지 않는다.
* C 솔루션은 다음 코드를 참조하시오.
입력
첫째 줄은 나열된 양의 실수들의 개수 N이 주어지고, 그 다음 줄부터 N개의 수가 한 줄에 하나씩 들어 있다. N은 10,000 이하의 자연수이다.
출력
계산된 최대값을 소수점 이하 넷째 자리에서 반올림하여 소수점 이하 셋째 자리까지 출력한다.
#include <stdio.h>

int N;
double d[10000 + 10];
double sol;

int main(void)
{
	int i;
	int j;
	double value;


	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%lf", &d[i]);
	}


	sol = d[0];
	for (i = 0; i<N; i++)
	{
		value = d[i];
		if (value > sol) sol = value;

		for (j = i + 1; j<N; j++)
		{
			value *= d[j];
			if (value > sol) sol = value;
		}
	}


	printf("%.3lf", sol);

	return 0;
}
#endif

#if 0
다음과 같은 수열이 있다. 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5... (숫자 k가 연달아 k번 나오는 수열).정수 n이 주어졌을 때, 해당 수열에서 n번째 나오는 숫자를 출력하는 프로그램을 작성하라.수열의 첫 번째 원소는 1이다.
* C 솔루션은 다음 코드를 참조하시오.
입력
입력은 한 줄에 정수 n이 들어온다. n은 1이상 1018 이하의 정수이다.
출력
수열에서의 n번째 원소를 출력한다.
#include <stdio.h>

long long n, sol;

double sqrt(const double d)
{
	/*
	바빌로니아법:
	Xn+1 = (Xn + d / Xn) / 2 에서 n을 계속 증가시키면 Xn은 d의 제곱근에 수렴
	Xn의 초기값 X0는 임의의 양의 실수를 선택하면 되는데 보통 1.0을 사용
	이전 수(Xn)는 x, 다음 수(Xn+1)는 n일 때 코드 구현은 다음과 같음
	*/

	double n = d / 2.0;
	double x = 0.0;

	while (n != x)
	{
		x = n;
		n = (n + d / n) / 2.0;
	}

	return n;
}

int main(void)
{
	long long temp;


	scanf("%lld", &n);


	sol = (long long)((-1 + sqrt((double)1 + 8 * n)) / 2);
	temp = (sol + 1)*sol / 2;
	if (temp < n) sol++;


	printf("%d", sol);

	return 0;
}
#endif

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

#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]합이 가장 큰 행과 열
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 4  해결 문제 수 : 4
	 [제출][채점 상황 열람]
	 문제 설명
	 다음 배열 a에서 합이 가장 큰 행과 열의 번호를 각각 인쇄하라.
	 int a[4][5] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };

1열
2열
3열
4열
5열
1행
3
- 5
12
3
- 21
2행
- 2
11
2
- 7
- 11
3행
21
- 21
- 35
- 93
- 11
4행
9
14
39
- 98
- 1


* C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

int a[4][5] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };
int max_row, max_col;

#define ROW 4
#define COL 5

int main(void)
{
	int i, j;
	int sum = 0, max_sum = 0;



	/* 행 */
	for (i = 0; i<ROW; i++)
	{
		sum = 0;
		for (j = 0; j<COL; j++)
		{
			sum += a[i][j];
		}
		if (i == 0)
		{
			max_sum = sum;
			max_row = 0;
		}
		else if (sum > max_sum)
		{
			max_sum = sum;
			max_row = i;
		}
	}

	/* 열 */
	for (j = 0; j<COL; j++)
	{
		sum = 0;
		for (i = 0; i<ROW; i++)
		{
			sum += a[i][j];
		}
		if (j == 0)
		{
			max_sum = sum;
			max_col = 0;
		}
		else if (sum > max_sum)
		{
			max_sum = sum;
			max_col = j;
		}
	}

	max_row++;
	max_col++;


	printf("%d %d", max_row, max_col);

	return 0;
}
// JAVA 솔루션은 다음 코드를 참조하시오.

/* 1073: 합이 가장 큰 행과 열 */

public class Main {

	static int a[][] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };
	static int maxRow, maxCol;

	public static void main(String[] args) {

		// 여기서부터 작성
		int sum = 0, maxSum = 0;
		/* 행 */
		for (int i = 0; i<4; i++)
		{
			sum = 0;
			for (int j = 0; j<5; j++)
			{
				sum += a[i][j];
			}
			if (i == 0)
			{
				maxSum = sum;
				maxRow = 0;
			}
			else if (sum > maxSum)
			{
				maxSum = sum;
				maxRow = i;
			}
		}

		/* 열 */
		for (int j = 0; j<5; j++)
		{
			sum = 0;
			for (int i = 0; i<4; i++)
			{
				sum += a[i][j];
			}
			if (j == 0)
			{
				maxSum = sum;
				maxCol = 0;
			}
			else if (sum > maxSum)
			{
				maxSum = sum;
				maxCol = j;
			}
		}
		maxCol++;
		maxRow++;

		// 출력하는 부분
		System.out.print(maxRow + " " + maxCol);

	}
}

입력
없음
출력
합이 가장 큰 행의 번호와 열의 번호를 차례로 인쇄한다.
합이 같은 경우 낮은 행이나 열의 번호를 인쇄한다.
출력 예시
2 1
도움말
[제출][채점 상황 열람]

#endif

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

#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]문자사각형1
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 3  해결 문제 수 : 3
	 [제출][채점 상황 열람]
	 문제 설명
	 정사각형의 한 변의 길이 n을 입력 받은 후 다음과 같은 문자로 된 정사각형 형태로 출력하는 프로그램을 작성하시오.

	 < 처리조건 >
	 문자의 진행 순서는 맨 오른쪽 아래에서 위쪽으로 'A'부터 차례대로 채워나가는 방법으로 아래 표와 같이 왼쪽 위까지 채워 넣는다. 'Z' 다음에는 다시 'A'부터 반복된다.



	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 int n;
char str[100 + 10][100 + 10];

int main(void)
{
	int i, j;
	char ch = 'A';


	scanf("%d", &n);


	for (i = n - 1; i >= 0; i--)
	{
		for (j = n - 1; j >= 0; j--)
		{
			str[j][i] = ch;
			if (ch == 'Z') ch = 'A';
			else ch++;
		}

	}


	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			printf("%c ", str[i][j]);
		}
		printf("\n");
	}

	return 0;
}
입력
정사각형 한 변의 길이 n(n의 범위는 1이상 100 이하의 정수)을 입력 받는다.
출력
위의 형식과 같이 한 변의 길이가 n인 숫자 사각형을 출력한다.숫자 사이는 공백으로 구분하여 출력한다.
입력 예시
4
출력 예시
P L H D
O K G C
N J F B
M I E A
도움말
열을 우선으로 하여 바깥 for문을 작성하되 행과 열 모두 n부터 1까지로 순서를 정해서 채워나가면 된다.
채워야 할 배열은 정수가 아닌 문자배열로 선언하고 int num = 1; 대신 char ch = 'A'; 와 같이 문자로 선언하고 초기화 해서 처리하면 된다.

#endif

#if 0

	 //문제 설명
	 //정사각형의 크기를 입력 받은 후, 시계방향으로 돌면서 다음과 같은 형태로 출력하는 프로그램을 작성하시오.

	 //< 처리조건 >
	 //(1) 가장 왼쪽 위의 좌표부터 차례로 숫자를 대입시킨다.
	 //(2) 오른쪽으로 채워 나가다가 끝이면 다시 아래->왼쪽->위->오른쪽의 순으로 모두 채워질 때까지 반복한다.


	 //* C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 int n;
int a[100 + 10][100 + 10];

int xx[] = { 0, 1, 0, -1 };
int yy[] = { 1, 0, -1, 0 };

int main(void)
{
	int i, j;
	int d = 1, m = -1, k, h, l;


	scanf("%d", &n);


	i = 0;
	j = -1;
	l = n;
	for (k = 0; k<n * 2 - 1; k++)
	{
		if (k % 2) l--;
		m = (m + 1) % 4;

		for (h = 0; h<l; h++)
		{
			i += xx[m];
			j += yy[m];
			a[i][j] = d++;
		}
	}


	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
입력
정사각형의 크기 n(1부터 100사이의 정수)을 입력 받는다.
출력
위에서 언급한 형태로 정사각형의 내부 숫자를 차례로 채운 후의 모습을 출력한다.숫자 사이는 공백으로 구분한다.
입력 예시
3
출력 예시
1 2 3
8 9 4
7 6 5
도움말
[제출][채점 상황 열람]


#endif

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

#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]마방진
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 8  해결 문제 수 : 6
	 [제출][채점 상황 열람]
	 문제 설명
	 홀수 정사각형의 크기를 입력 받은 후, 가로 세로 대각선의 합이 일정한 마방진을 출력하는 프로그램을 작성하시오.

	 마방진이란 1부터 N*N까지의 숫자를 한 번씩만 써서 정사각형에 배치하여 가로와 세로, 그리고 대각선의 합이 같도록 하는 것이다.

	 다음의 순서에 따라 각 위치에 차례대로 값을 넣는다.
	 1. 첫 번째 숫자인 1을 넣는 위치는 첫 번째 행 가운데이다.
	 2. 숫자가 N의 배수이면 바로 아래의 행으로 이동하여 다음의 수를 넣고
	 3. 그렇지 않으면 왼쪽 위로 이동하여 다음의 숫자를 넣는다.만약 행이 첫 번째를 벗어나면 마지막 행으로 이동하고, 열이 첫 번째를 벗어나면 마지막 열로 이동한다.



	 1. 첫 번째 행 가운데(1, 2)에 1을 넣는다.
	 2. 왼쪽 위로 이동하면(0, 1)인데 행의 위치가 처음을 벗어났으므로 마지막 행(3, 1)의 위치로 이동하여 2를 넣는다.
	 3. 왼쪽 위로 이동하면(2, 0)인데 열의 위치가 처음을 벗어났으므로 마지막 열(2, 3)의 위치로 이동하여 3을 넣는다.
	 4. 배열에 넣은 값(3)이 N의 배수이므로 바로 아래 행으로(3, 3) 이동하여 4를 넣는다.
	 5. 왼쪽 위로 이동하여(2, 2) 5를 넣는다.
	 6. 왼쪽 위로 이동하여(1, 1) 6를 넣는다.
	 7. 배열에 넣은 값(6)이 N의 배수이므로 바로 아래 행으로(2, 1) 이동하여 7을 넣는다.
	 8. 왼쪽 위로 이동하면(1, 0)인데 열의 위치가 처음을 벗어났으므로 마지막 열(1, 3)의 위치로 이동하여 8을 넣는다.
	 9. 왼쪽 위로 이동하면(0, 2)인데 행의 위치가 처음을 벗어났으므로 마지막 행(3, 2)의 위치로 이동하여 9를 넣는다.
	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 int N;
int a[100 + 10][100 + 10];

int main(void)
{
	int i, j;
	int x, y;


	scanf("%d", &N);


	x = N / 2;
	y = 0;
	a[y][x] = 1;
	for (i = 2; i <= N*N; i++)
	{
		if ((i - 1) % N == 0)
		{
			y++;
		}
		else
		{
			x--;
			y--;
			if (x < 0) x = N - 1;
			if (y < 0) y = N - 1;
		}
		a[y][x] = i;
	}


	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}

// JAVA 솔루션은 다음 코드를 참조하시오.

/* 1078: 마방진 */
import java.util.Scanner;

public class Main {

	static int N;
	static int[][] a;

	public static void main(String[] args) {

		// 입력받는 부분
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		sc.close();

		// 여기서부터 작성
		a = new int[N][N];
		int x = N / 2;
		int y = 0;
		a[y][x] = 1;
		for (int i = 2; i <= N*N; i++)
		{
			if ((i - 1) % N == 0)
			{
				y++;
			}
			else
			{
				x--;
				y--;
				if (x < 0) x = N - 1;
				if (y < 0) y = N - 1;
			}
			a[y][x] = i;
		}

		// 출력하는 부분
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<N; j++)
			{
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
	}
}

입력
정사각형의 크기 n(2부터 100사이의 홀수)을 입력 받는다.
출력
위에서 언급한 형태로 정사각형의 내부 숫자를 차례로 채운 후의 모습을 출력한다.숫자 사이는 공백으로 구분한다.
입력 예시
3
출력 예시
6 1 8
7 5 3
2 9 4
도움말

#endif

#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다. 배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]회전
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 5  해결 문제 수 : 5
	 [제출][채점 상황 열람]
	 문제 설명
	 정사각형의 크기와 각 숫자를 입력 받은 후 시계방향으로 회전하는 프로그램을 작성하시오.
	 (1) 키보드를 통해 아래와 같은 크기 n과 각 행의 숫자를 입력 받는다. (<표>참고)
	 (2) 회전할 각도를 입력 받는다. (90, 180, 270, 360)
	 (3) 입력 받은 배열을 시계방향으로 입력 받은 각도만큼 회전하여 출력한다.
	 (4) 하나의 회전을 마친 후에는 회전된 데이터를 중심으로 다시 각도를 입력 받아서 회전한다.



	 주의 할 것은 처음 입력 받은 배열에서 회전하는 것이 아니라 회전된 상태에서 다시 회전을 해야 한다는 점이다.예를 들어 90도 180도 회전이 입력된 경우 처음 배열에서 90도를 회전한 결과를 인쇄하고 그 결과 배열에서 다시 180도를 회전한 결과를 인쇄해야 하는 것이다.
	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 int n;
int a[50 + 10][50 + 10];
int rotate;

int b[50 + 10][50 + 10];

int main(void)
{
	int i, j;


	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (;;)
	{

		scanf("%d", &rotate);
		if (rotate == 0) break;


		switch (rotate)
		{
		case 90:
			for (i = 0; i<n; i++)
			{
				for (j = 0; j<n; j++)
				{
					b[j][n - i - 1] = a[i][j];
				}
			}
			break;
		case 180:
			for (i = 0; i<n; i++)
			{
				for (j = 0; j<n; j++)
				{
					b[n - i - 1][n - j - 1] = a[i][j];
				}
			}
			break;
		case 270:
			for (i = 0; i<n; i++)
			{
				for (j = 0; j<n; j++)
				{
					b[n - j - 1][i] = a[i][j];
				}
			}
			break;
		case 360:
			for (i = 0; i<n; i++)
			{
				for (j = 0; j<n; j++)
				{
					b[i][j] = a[i][j];
				}
			}
			break;
		default:
			break;
		}

		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}

		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				a[i][j] = b[i][j];
			}
		}

	}

	return 0;
}
*JAVA 솔루션은 다음 코드를 참조하시오.

import java.io.IOException;
import java.util.Scanner;

public class Main
{
	public static void main(String[] arg) throws IOException
	{
		int n;
		int i, j;
		int[][] a;
		int r;

		Scanner sc = new Scanner(System.in);

		//입력받는부분
		n = sc.nextInt();
		a = new int[n][n];

		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++) a[i][j] = sc.nextInt();
		}

		for (;;)
		{
			r = sc.nextInt();
			if (r == 0) break;

			//여기서부터작성
			for (int k = 0; k < (r / 90); k++){
				a = change90_Array(n, a);
			}

			//출력하는부분
			for (i = 0; i<n; i++)
			{
				for (j = 0; j< n; j++)
				{
					System.out.print(a[i][j] + " ");
				}
				System.out.println();
			}
		}
		sc.close();
	}

		static int[][] change90_Array(int n, int[][] a) {
		int[][] temp = new int[n][n];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) {
				temp[i - 1][j - 1] = a[n - j][i - 1];
			}
		}
		return temp;
	}
}
입력
첫 번째 줄에서 사각형의 크기 n(5≤n≤50)을 입력 받은 후 다음 줄부터 왼쪽 위(1, 1)에서 오른쪽 아래(n, n)까지 x, y 좌표 순서로 각 해당 좌표에 들어갈 숫자(9 이하의 자연수)를 입력 받는다.여기서 말하는 x, y 란(가로, 세로)를 의미한다.
다음 줄부터는 회전할 각도(90, 180, 270, 360 중의 하나)를 입력 받는다.
하나의 결과가 나온 후에도 계속 새로운 각도를 입력 받다가, 0이 입력되면 종료한다.
각도의 크기가 주어진 범위를 벗어날 경우는 다시 입력 받는다.
출력
위에서 입력한 형태에 맞춰서 입력된 각도만큼 회전한 결과를 출력한다.
입력 예시
5
3 4 1 2 3
2 3 4 5 6
2 3 4 6 7
1 7 6 5 4
6 8 9 3 4
90
180
270
360
0
출력 예시
6 1 2 2 3
8 7 3 3 4
9 6 4 4 1
3 5 6 5 2
4 4 7 6 3
3 6 7 4 4
2 5 6 5 3
1 4 4 6 9
4 3 3 7 8
3 2 2 1 6
4 3 9 8 6
4 5 6 7 1
7 6 4 3 2
6 5 4 3 2
3 2 1 4 3
4 3 9 8 6
4 5 6 7 1
7 6 4 3 2
6 5 4 3 2
3 2 1 4 3
도움말
[입력 예시 2]

5
2 6 1 1 3
1 5 9 7 5
8 2 8 6 6
3 2 2 7 3
6 3 7 7 2
90
0

[출력 예시 2]
6 3 8 1 2
3 2 2 5 6
7 2 8 9 1
7 7 6 7 1
2 3 6 5 3

-------------------------------------------------------------------------------------------------- -
[입력 예시 3]
10
9 2 6 2 8 9 8 7 2 1
4 5 8 3 3 8 6 8 2 7
1 1 2 3 7 7 8 2 3 5
5 9 6 5 6 4 4 2 7 3
6 3 7 5 7 9 5 4 7 9
6 2 3 1 2 6 9 9 9 9
6 2 4 8 9 7 1 2 6 3
5 7 9 4 1 2 6 6 1 1
7 3 5 5 7 1 2 8 9 4
1 4 1 8 1 8 5 2 3 1
90
360
0

[출력 예시 3]
1 7 5 6 6 6 5 1 4 9
4 3 7 2 2 3 9 1 5 2
1 5 9 4 3 7 6 2 8 6
8 5 4 8 1 5 5 3 3 2
1 7 1 9 2 7 6 7 3 8
8 1 2 7 6 9 4 7 8 9
5 2 6 1 9 5 4 8 6 8
2 8 6 2 9 4 2 2 8 7
3 9 1 6 9 7 7 3 2 2
1 4 1 3 9 9 3 5 7 1
1 7 5 6 6 6 5 1 4 9
4 3 7 2 2 3 9 1 5 2
1 5 9 4 3 7 6 2 8 6
8 5 4 8 1 5 5 3 3 2
1 7 1 9 2 7 6 7 3 8
8 1 2 7 6 9 4 7 8 9
5 2 6 1 9 5 4 8 6 8
2 8 6 2 9 4 2 2 8 7
3 9 1 6 9 7 7 3 2 2
1 4 1 3 9 9 3 5 7 1
[제출][채점 상황 열람]

#endif

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

#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]10글자까지만 거꾸로
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 3  해결 문제 수 : 3
	 [제출][채점 상황 열람]
	 문제 설명
	 알파벳(‘a’~’z’, ‘A’~’Z’) 문자를 최대 10개까지 입력 받은 후 거꾸로 인쇄하라.
	 입력된 문자가 10개 이상(최대 255개)이면 10개까지만 거꾸로 인쇄한다.
	 알파벳 이외에 문자가 입력되면 이전까지만 거꾸로 인쇄한다.
	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 char s[255 + 10];

int main(void)
{
	int i, len, e;


	scanf("%s", s);


	for (i = 0; s[i]; i++);
	len = i;

	if (len>10) e = 10;
	else e = len;

	for (i = 0; i<e; i++)
	{
		if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
		{
			e = i;
			break;
		}
	}

	for (i = e - 1; i >= 0; i--)
	{
		printf("%c", s[i]);
	}

	return 0;
}
입력
문자열을 입력한다.
출력
입력 받은 문자열을 거꾸로 인쇄한다.
입력 예시
ABcde
출력 예시
edcBA
도움말
[입력 예시 2]
abcdefghijk

[출력 예시 2]
jihgfedcba

-------------------------------------------------------------------------------------------------- -
[입력 예시 3]
AbCd1Ef

[출력 예시 3]
dCbA

#endif

#if 0

처음 화면	문제 모음	순위	채점 상황 열람
시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다.배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 : [SOL]문자열 뒤집기Ⅰ
시간 제한 : 1 Sec  메모리 제한 : 128 MB
제출 : 2  해결 문제 수 : 2
	 [제출][채점 상황 열람]
	 문제 설명
	 최대길이가 50이하인 문자열을 입력 받아 뒤집어 출력하는 프로그램을 작성하시오.
	 * C 솔루션은 다음 코드를 참조하시오.

#include <stdio.h>

	 char s[50 + 10];

int main(void)
{
	int i, len;


	gets(s);


	for (i = 0; s[i]; i++);
	len = i;

	for (i = len - 1; i >= 0; i--)
	{
		printf("%c", s[i]);
	}

	return 0;
}
입력
최대 길이가 50이하인 문자열이 입력된다. (주의: C언어에서는 %s로 입력 받으면 공백으로 분리되어 문자열이 입력됨)
출력
그 문자열을 뒤집어서 출력하라.
입력 예시
I love GSHS - OJ.
출력 예시
.JO - SHSG evol I
도움말
scanf("%s", 변수); 는 한 줄 단위로 문자열을 받는 것이 아니라 공백, 엔터, 탭 단위로 구분하여 문자열을 받는다.
gets(변수); 는 엔터가 눌러질 때까지 문자열을 입력 받는 함수이다.
fgets(변수, 최대길이(정수형), stdin); 는 엔터로 구분(줄 단위로 구분된)된 문자열을 입력 받는다.
상기 함수 사용 시, 변수의 크기는 문자열을 저장할 만한 충분한 크기를 가져야 하며 입력 받는 문자열보다 작은 크기를 가졌을 경우 변수 뒷부분에 있는 다른 메모리를 침범할 수 있으므로 문제가 발생할 수 있다.
[제출][채점 상황 열람]

#endif

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