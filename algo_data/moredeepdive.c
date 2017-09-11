// 해당 파일은 VS 2005에서 돌리는 것이 좋다.

/***********************************************************/
// [1-1] 음수의 메모리 표현
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)

{
	int si = -1;
	unsigned int ui = 0xffffffff;

	printf("%d\n", si);
	printf("%u\n", si);
	printf("%#x\n", si);

	printf("%d\n", ui);
	printf("%u\n", ui);
	printf("%#x\n", ui);
}

#endif

/***********************************************************/
// [1-2] char type
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	unsigned char uc = 0xff;
	signed char sc = -1;
	char c = uc;

	printf("%#x\n", uc);
	printf("%#x\n", sc);
	printf("%#x\n", c);
}

#endif

/***********************************************************/
// [1-3] signed int와 unsigned int 
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	int a = 100;
	int b = 0x64;
	int c = 0144;

	int d = -100;
	unsigned int e = -100;

	printf("%#x\n", a);
	printf("%#x\n", b);
	printf("%#x\n", c);
	printf("%#x\n", d);
	printf("%#x\n", e);
}

#endif

/***********************************************************/
// [1-4] 연속 혹은 white space로 연결된 여러 문자열
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	printf("Hello ""Embedded ""C!\n");
	printf("Hello "  "Embedded "  "C!\n");
	printf("%s\n", "Hello ""Embedded ""C!\n");
}

#endif

/***********************************************************/
// [1-5] 실수의 표현범위
/***********************************************************/

#if 0

#include <stdio.h>
#include <limits.h>

void main(void)
{
	printf("a=%.20f\n", 100.f / 3.f);
	printf("b=%.20f\n", 100. / 3.);
}

#endif

/***********************************************************/
// [1-6] 출력 결과를 예측하시오
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	float a = 3.1;
	float b = 3.5;

	if (a == 3.1) printf("TRUE1\n");
	else printf("FALSE1\n");

	if (b == 3.5) printf("TRUE2\n");
	else printf("FALSE2\n");
}

#endif


/***********************************************************/
// [1-7] 10회 반복 루프의 구현
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	int i, cnt;
	float f;

	for (cnt = 0, i = 1; i <= 10; i++) cnt++;
	printf("INT=%d\n", cnt);

	for (cnt = 0, f = 0.1; f <= 1.0; f += 0.1) cnt++;
	printf("FLOAT=%d\n", cnt);
}

#endif

/***********************************************************/
// [1-8] 실수 값의 메모리 dump?
/***********************************************************/

#if 1

#include <stdio.h>

void main(void)
{
	float f = 3.5f;

	printf("%#x\n", *(int*)&f);
}

#endif

/***********************************************************/
// [2-1] 다음의 결과를 예측하라
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	unsigned char c = 0x80;

	printf("%u\n", c);
	printf("%d\n", c);
}

#endif

/***********************************************************/
// [2-2] 다음의 결과를 예측하라
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	signed char c = 0x80;

	printf("%u\n", c);
	printf("%d\n", c);
}

#endif

/***********************************************************/
// [2-3] 다음의 결과를 예측하라
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	unsigned char c = 0xff;

	if (c == 0xff)
		printf("%x\n", c + 1);
	else
		printf("%x\n", c - 1);
}

#endif

/***********************************************************/
// [2-4] 다음의 결과를 예측하라
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	signed char c = 0xff;

	if (c == 0xff)
		printf("%x\n", c + 1);
	else
		printf("%x\n", c - 1);
}

#endif

/***********************************************************/
// [2-5] 다음의 결과를 예측하라
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	int a[4] = { 1, 2, 3, 4 };

	if (a[0] - a[1] < sizeof(a))
		printf("%d\n", a[sizeof(char)]);
	else
		printf("%d\n", a[sizeof(short)]);
}

#endif

/***********************************************************/
// [2-6] 실수의 비교 
// 다음의 실행결과는? 
// 원하는 결과가 나오도록 수정하시오
/***********************************************************/

#if 0


#include <stdio.h>

void main(void)
{
	float  pi = 3.14;

	if (pi == 3.14)
		printf("TRUE\n");
	else
		printf("FALSE\n");
}

#endif

/***********************************************************/
// [2-7] signed short vs. unsigned short
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	signed short ss = -1;
	unsigned short us = -1;

	if (ss < us) printf("UNSIGNED SHORT\n");
	else if (ss > us) printf("SIGNED SHORT\n");
	else printf("SAME\n");
}

#endif

/***********************************************************/
// [3-1] 대치법의 이해
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	int a = 10;
	int b = a + 1;
	int c = b + 2;

	printf("%d\n", c + 3);
}

#endif

#if 0

#include <stdio.h>

int add(int a, int b)
{
	int c = a + b;
	return c;
}

int x[4] = { 10, 20, 30, 40 };

void main(void)
{
	int d = add(x[0], x[2]);
	printf("%d\n", d);
}

#endif

/***********************************************************/
// [3-2] 버퍼의 데이터 수량 계산
/***********************************************************/

#if 0 

#include <stdio.h>

void main(void)
{
	int a[10];

	int *start = &a[0];
	int *p = &a[3];

	printf("%d\n", sizeof(a) / sizeof(a[0]));
	printf("%d\n", (p - start) / sizeof(int));
}

#endif

/***********************************************************/
// [3-3] 포인터는 망원경이다!
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	int a = 10;
	int *p;

	p = &a;

	printf("%#.8x %#.8x\n", p, &a);
	printf("%#.8x %#.8x\n", *p, a);
	printf("%#.8x %#.8x\n", p + 1, p - 1);
	printf("%#.8x %#.8x\n", *(p + 1), *(p - 1));
}

#endif

#if 0

#include <stdio.h>

void main(void)
{
	unsigned char a = 'A';
	unsigned char *p;

	p = &a;

	printf("%#.8x %#.8x\n", p, &a);
	printf("%#.2x %#.2x\n", *p, a);
	printf("%#.8x %#.8x\n", p + 1, p - 1);
	printf("%#.2x %#.2x\n", *(p + 1), *(p - 1));
}

#endif

/***********************************************************/
// [3-4] 주소의 사칙연산
/***********************************************************/

#if 0

void main(void)
{
	int *p, *q;

	p = (int *)0x1008;
	q = (int *)0x1000;

	printf("0x%.8X\n", p*q);
	printf("0x%.8X\n", p / q);
	printf("0x%.8X\n", p + q);
	printf("0x%.8X\n", p - q);

	printf("0x%.8X\n", p * 2);
	printf("0x%.8X\n", p / 2);
	printf("0x%.8X\n", p + 2);
	printf("0x%.8X\n", p - 2);
}

#endif

/***********************************************************/
// [3-5] 주소 offset 연산
/***********************************************************/

#if 0

#include <stdio.h>

typedef unsigned int UI;

void main(void)
{
	int a[10];
	int *p = a;
	int *r = &a[9] + 1;
	int i;

	for (i = 0; i<4; i++)
	{
		*p = i;
		p++;
	}

	printf("SIZE: %d, %d\n", ((UI)r - (UI)a) / sizeof(int), r - a);
	printf("USE: %d, %d\n", ((UI)p - (UI)a) / sizeof(int), p - a);
	printf("REMAIN: %d, %d\n", ((UI)r - (UI)p) / sizeof(int), r - p);
}

#endif

/***********************************************************/
// [3-6] 배열을 함수로 넘긴다
/***********************************************************/

#if 0

#include <stdio.h>

int sum(int b[4])
{
	int i, sum = 0;

	for (i = 0; i<(sizeof(b) / sizeof(b[0])); i++)
	{
		sum += b[i];
	}
	return sum;
}

void main(void)
{
	int a[4] = { 1, 2, 3, 4 };

	printf("%d\n", sum(a));
}

#endif

/***********************************************************/
// [3-7] 함수의 parameter가 배열이면?
/***********************************************************/

#if 0

#include <stdio.h>

void func(int b[5]);

void main(void)
{
	int a[5] = { 10, 20, 30, 40, 50 };

	printf("%x\n", a);
	printf("%x\n", &a[0]);
	printf("%d\n", sizeof(a));
	func(a);
}

void func(int b[5])
{
	printf("%x\n", b);
	printf("%x\n", &b[0]);
	printf("%d\n", sizeof(b));
}

#endif

/***********************************************************/
// [3-8] 함수 parameter의 배열은 다 가짜다!
/***********************************************************/

#if 0

#include <stdio.h>

int sum1(int b[4])
{
	int i, sum = 0;

	for (i = 0; i<(sizeof(b) / sizeof(b[0])); i++)
	{
		sum += b[i];
	}
	return sum;
}

int sum2(int b[100])
{
	int i, sum = 0;

	for (i = 0; i<(sizeof(b) / sizeof(b[0])); i++)
	{
		sum += b[i];
	}
	return sum;
}

int sum3(int b[])
{
	int i, sum = 0;

	for (i = 0; i<(sizeof(b) / sizeof(b[0])); i++)
	{
		sum += b[i];
	}
	return sum;
}

int sum4(int *b)
{
	int i, sum = 0;

	for (i = 0; i<(sizeof(b) / sizeof(b[0])); i++)
	{
		sum += b[i];
	}
	return sum;
}

void main(void)
{
	int a[4] = { 1, 2, 3, 4 };

	printf("%d\n", sum1(a));
	printf("%d\n", sum2(a));
	printf("%d\n", sum3(a));
	printf("%d\n", sum4(a));
}

#endif

/***********************************************************/
// [3-9] 배열이 대치법이 적용되지 않는 경우
/***********************************************************/

#if 0

#include <stdio.h>

#include <stdio.h>

void func(int b[5]);

void main(void)
{
	int a[5] = { 10, 20, 30, 40, 50 };
	int *p;

	p = a;

	printf("%#.8x, %#.8x\n", a, p);
	printf("%#.8x, %#.8x\n", &a[0], &p[0]);
	printf("%#.8x, %#.8x\n", a + 1, p + 1);
	printf("%d, %d\n", *(a + 1), *(p + 1));
	printf("%d, %d\n", a[2], p[2]);

	printf("%d, %d\n", sizeof(a), sizeof(p));
	printf("%#.8x, %#.8x\n", &a, &p);
}

#endif

/***********************************************************/
// [3-10] 함수로 넘어온 배열의 요소수를 구하려면?
/***********************************************************/

#if 0

#include <stdio.h>

int sum1(int *p)
{
	int i, sum = 0;

	for (i = 0; i<4; i++)
	{
		sum += p[i];
	}
	return sum;
}

int sum2(int *p, int num)
{
	int i, sum = 0;

	for (i = 0; i<num; i++)
	{
		sum += p[i];
	}
	return sum;
}

void main(void)
{
	int a[4] = { 1, 2, 3, 4 };

	printf("%d\n", sum1(a));
	printf("%d\n", sum2(a, sizeof(a) / sizeof(a[0])));
}

#endif

/***********************************************************/
// [3-11] [ ]와 * 연산자의 관계
/***********************************************************/

#if 0

#include <stdio.h>

int a[4] = { 1, 2, 3, 4 };
int * p = a;

void main(void)
{
	printf("%d\n", *p);
	printf("%d\n", *(p + 1));
	printf("%d\n", *(p + 4));
	printf("%d\n\n", *(p - 1));

	printf("%d\n", *a);
	printf("%d\n", *(a + 1));
	printf("%d\n", *(a + 4));
	printf("%d\n\n", *(a - 1));

	printf("%d\n", a[0]);
	printf("%d\n", a[1]);
	printf("%d\n", a[4]);
	printf("%d\n\n", a[-1]);
}

#endif

/***********************************************************/
// [3-12] 배열 요소의 액세스
/***********************************************************/

#if 0

#include <stdio.h>

int a[4] = { 1, 2, 3, 4 };

void main(void)
{
	printf("%d\n", a[0]);
	printf("%d\n\n", *a);

	printf("%d\n", a[3]);
	printf("%d\n", *(a + 3));
	printf("%d\n", (a + 1)[2]);
	printf("%d\n\n", (a - 1)[4]);

	printf("%d\n", a[1]);
	printf("%d\n", *(a + 1));
	printf("%d\n", *(1 + a));
	printf("%d\n\n", 1[a]);
}

#endif

/***********************************************************/
// [3-13] 배열을 리턴하는 함수
/***********************************************************/

#if 0

#include <stdio.h>

func(void)
{
	static int a[4] = { 1, 2, 3, 4 };
	return a;
}

void main(void)
{
	printf("%d\n", func());
}

#endif

/***********************************************************/
// [3-14] 조금 복잡한 배열을 리턴하는 함수
/***********************************************************/

#if 0

#include <stdio.h>

func(void)
{
	static int a[4] = { 1, 2, 3, 4 };
	return &a;
}

void main(void)
{
	printf("%d\n", func());
}

#endif

/***********************************************************/
// [3-15] 조금 복잡한 배열을 리턴하는 함수
/***********************************************************/

#if 0

#include <stdio.h>

void  f1()
{
	printf("%d\n", );
}

void  f2()
{
	printf("%d\n", );
}

int a[4] = { 1, 2, 3, 4 };

void main(void)
{
	f1(a);
	f2(&a);
}

#endif

/***********************************************************/
// [3-16] 배열의 요소수도 함께 받을 수 있는 방법?
/***********************************************************/

#if 0

#include <stdio.h>

int sum(int(*p)[4])
{
	int i, sum = 0;

	printf("Number of Element = %d\n", sizeof(*p) / sizeof((*p)[0]));

	for (i = 0; i<sizeof(*p) / sizeof((*p)[0]); i++)
	{
		sum += (*p)[i];
	}

	return sum;
}

void main(void)
{
	int a[4] = { 1, 2, 3, 4 };

	printf("%d\n", sum(&a));
}

#endif

/***********************************************************/
// [3-17] 예제 3-16의 변경, 무엇이 문제일까?
/***********************************************************/

#if 0

#include <stdio.h>

int sum(int(*p)[4])
{
	int i, sum = 0;
	int *q = *p;

	printf("Number of Element = %d\n", sizeof(q) / sizeof(q[0]));

	for (i = 0; i<sizeof(q) / sizeof(q[0]); i++)
	{
		sum += q[i];
	}

	return sum;
}

void main(void)
{
	int a[4] = { 1, 2, 3, 4 };

	printf("%d\n", sum(&a));
}

#endif

/***********************************************************/
// [4-1] C언어의 주소
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	char a[4] = "LEW";
	char *p = a;

	printf("%X:%X \n", p, &p);
	printf("%X:%X \n", a, &a);
	printf("%X:%X \n", main, &main);
	printf("%X:%X \n", "LEW", &"LEW");
}

#endif

/***********************************************************/
// [4-2] 포인터 배열
/***********************************************************/

#if 0

#include <stdio.h> 

int x[4] = { 1, 2, 3, 4 };

void main(void)
{
	int *a[4] = { x + 3, x + 2, x + 1, x };

	printf("%d\n", x[2]);

	// 배열 a를 이용하여 x[2]를 30으로

	= 30;

	printf("%d\n", x[2]);
}

#endif

/***********************************************************/
// [4-3] 대치법 활용
/***********************************************************/

#if 0

#include <stdio.h> 

int x[4] = { 1, 2, 3, 4 };

int *f1(void)
{
	return x;
}

void f2(int *p)
{
	printf("%d == %d == %d == %d\n", x[2], *(x + 2), p[0], *p);
}

void main(void)
{
	int *p;
	int *a[4] = { x + 3, x + 2, x + 1, x };

	p = x;

	printf("%d == %d\n", x[2], p[2]);
	printf("%d == %d == %d == %d\n", x[2], *(x + 2), a[3][2], *a[1]);
	printf("%d == %d == %d == %d\n", x[2], *(x + 2), f1()[2], *(f1() + 2));
	f2(x + 2);
}

#endif

/***********************************************************/
// [4-4] 포인터 배열 활용
/***********************************************************/

#if 0

#include <stdio.h> 

char err[3][25] = { "Speed Error!", "Position Error!", "Unknown Command Error!" };

void main(void)
{
	printf("%s\n", err[1]);
}

#endif

#if 0

#include <stdio.h> 

char *err[3] = { "Speed Error!", "Position Error!", "Unknown Command Error!" };

void main(void)
{
	printf("%s\n", err[1]);
}

#endif

/***********************************************************/
// [4-5] 문자열의 이해
/***********************************************************/

#if 0

#include <stdio.h> 

void main(void)
{
	char a[4] = "LEW";

	printf("%X	%X \n", a, &a);
	printf("%X	%X \n", "LEW", &"LEW");
	printf("%c	%c\n", a[0], a[1]);
	printf("%c	%c\n", "LEW"[0], "LEW"[1]);
	printf("%c	%c \n", *a, *(a + 1));
	printf("%c	%c \n", *"LEW", *("LEW" + 1));
	printf("%X	%X \n", "LEW", "LEW" + 1);
	printf("%X	%X \n", a, a + 1);
}

#endif

/***********************************************************/
// [4-6] 모텔 증축 공사
/***********************************************************/

#if 0

#include <stdio.h> 

void main(void)
{
	char a[] = "Motel";
	char *p = "Motel";

	a[0] = 'H';
	p[0] = 'H';

	printf("%s\n", a);
	printf("%s\n", p);
}

#endif

/***********************************************************/
// [4-7] %s 옵션과 문자열의 이해
/***********************************************************/

#if 0

#include <stdio.h> 

void main(void)
{
	char a[] = "LEW";
	char *p = "%s\n";

	printf("%s\n", "LEW");
	printf("%s\n", a);
	printf("%s\n", *a);
	printf(p, a);
}

#endif

/***********************************************************/
// [4-8] 문자열의 이해
/***********************************************************/

#if 0

#include <stdio.h> 

char * day(int n)
{
	return "SUN\0MON\0TUE\0WED\0THU\0FRI\0SAT\0" + (n * 4);
}

void main(void)
{
	int i;

	for (i = 0; i<7; i++)
	{
		printf("%s\n", day(i));
	}
}

#endif

/***********************************************************/
// [4-9] 함수의 실행
/***********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
	return a + b;
}

void main(void)
{
	printf("%d\n", add(3, 4));
	printf("%d\n", (&add)(3, 4));
	printf("%d\n", (*add)(3, 4));
	printf("%d\n", (**add)(3, 4));
}

#endif

/***********************************************************/
// [4-10] 배열을 가리키는 포인터
/***********************************************************/

#if 0

#include <stdio.h> 

void main(void)
{
	int a[4] = { 10, 20, 30, 40 };
	int(*p)[4] = &a;

	printf("%#x\n", p);
	printf("%#x\n", p + 1);
	printf("%#x\n", *p);
}

#endif

/***********************************************************/
// [4-11] 배열 포인터
/***********************************************************/

#if 0

#include <stdio.h> 

void func(p)
{
	// main의 a[2]를 50으로

	= 50;
}

void main(void)
{
	int a[4] = { 10, 20, 30, 40 };

	printf("%d\n", a[2]);
	func(&a);
	printf("%d\n", a[2]);
}

#endif

/***********************************************************/
// [5-1]2차원 배열을 함수 전달한다
/***********************************************************/

#if 0

#include <stdio.h>

void prt_array(int b[3][4])
//void prt_array(int b[ ][4])
//void prt_array(int b[3][ ])
//void prt_array(int b[ ][ ])
//void prt_array(int b[4][4])
//void prt_array(int b[3][3])
//void prt_array(int b[4][3])
{
	int i, j;

	for (i = 0; i<3; i++)
	{
		for (j = 0; j<4; j++)
		{
			printf("b[%d][%d]=%d\n", i, j, b[i][j]);
		}
	}
}

void main(void)
{
	int a[3][4] = { { 10, 20, 30, 40 }, { 50, 60, 70, 80 }, { 90, 100, 110, 120 } };

	prt_array(a);
}

#endif

/***********************************************************/
// [5-2] 2차원 배열의 교환법칙
/***********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };

void main(void)
{
	printf("%d\n", a[2][3]);
	printf("%d\n", *(*(a + 2) + 3));
	printf("%d\n", (a + 1)[1][3]);
	printf("%d\n", ((a + 1)[1] + 2)[1]);
	printf("%d\n", 3[a[2]]);
	printf("%d\n", 3[2[a]]);
}

#endif

/***********************************************************/
// [5-3] 2차원배열의 이해
/***********************************************************/

#if 0

#include <stdio.h>

char a[3][4] = { "kim", "lew", "seo" };

void main(void)
{
	printf("%s\n", a);
	printf("%s\n", *a);
	printf("%s\n", a[0]);
	printf("%c\n", *a[0]);
	printf("%s\n", a[1]);
	printf("%c\n", *a[1]);
	printf("%s\n", a[2]);
	printf("%c\n", *a[2]);

	// "seo"에 있는 "eo"를 인쇄하는 수식을 작성하라

	// printf("%s\n",         );  
}

#endif

/***********************************************************/
// [5-4] 2차원 배열 요소의 전달
/***********************************************************/

#if 0

#include <stdio.h>

int sum()
{

}

void main(void)
{
	int a[3][4] = { { 10, 20, 30, 40 }, { 50, 60, 70, 80 }, { 90, 100, 110, 120 } };

	printf("%d\n", sum(a[0], sizeof(a[0]) / sizeof(a[0][0])));
	printf("%d\n", sum(a[1], sizeof(a[1]) / sizeof(a[1][0])));
	printf("%d\n", sum(a[2], sizeof(a[2]) / sizeof(a[2][0])));
}

#endif

/***********************************************************/
// [5-5] 2차원 배열 요소의 리턴
/***********************************************************/

#if 0

#include <stdio.h>

char a[][10] = { "Kim", "Song", "Lew", "Moon" };

func(int num)
{
	return a[num];
}

void main(void)
{
	printf("%s\n", func(0));
	printf("%s\n", func(1));
	printf("%s\n", func(2));
	printf("%s\n", func(3));
}

#endif

/***********************************************************/
// [5-6] 2차원 배열을 int *에 전달
/***********************************************************/

#if 0

#include <stdio.h>

void draw_pixel(int y, int x, int value, int *p)
{
	p[y * 3 + x] = value;
}

void main(void)
{
	int a[2][3] = { 1, 2, 3, 4, 5, 6 };

	printf("%d\n", a[1][2]);
	draw_pixel(1, 2, 10, a);
	printf("%d\n", a[1][2]);
}

#endif

/***********************************************************/
// [5-7] 2차원 배열을 받는 함수
/***********************************************************/

#if 0

#include <stdio.h>

void draw_pixel(int y, int x, int value, p)
{
	p[y][x] = value;
}

void main(void)
{
	int a[2][3] = { 1, 2, 3, 4, 5, 6 };

	printf("%d\n", a[1][2]);
	draw_pixel(1, 2, 10, a);
	printf("%d\n", a[1][2]);
}

#endif

/***********************************************************/
// [5-8] 2차원배열의 리턴
/***********************************************************/

#if 0

#include <stdio.h>

func(void)
{
	static int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	return a;
}

void main(void)
{
	printf("%d\n", func());
}

#endif

/***********************************************************/
// [5-9] 다단의 함수 호출
/***********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };

f1(void)
{
	return &a;
}

f2(void)
{
	return *f1();
}

f3(void)
{
	return f2()[1];
}

void main(void)
{
	printf("%d\n", f3()[2]);
}

#endif

/***********************************************************/
// [5-10] 리턴 결과의 활용
/***********************************************************/

#if 0

int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };


f1(void)
{
	return &a;
}

f2(void)
{
	return *f1();
}

f3(void)
{
	return f2()[1];
}

void main(void)
{
	printf("%d\n", f1());
	printf("%d\n", f2());
	printf("%d\n", f3());
}

#endif

/***********************************************************/
// [5-11] 배열의 등가포인터 만들기
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	int a[2][3][4];
	int(*b[3])[4];
	int *(*c[2])(int *);
	int *d[3][4];
	int(*(*e[5])(void))[4];

	// pa ~ pe 포인터 변수 선언
	// 아래에 pa ~ pe 까지 포인터를 선언한다
	// 컴파일시 단 하나의 경고도 발생하지 않아야 한다




	pa = a;
	pb = b;
	pc = c;
	pd = d;
	pe = e;
}

#endif

/***********************************************************/
// [5-12] 등가포인터의 활용
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	char a[5][10] = { "Kim", "Lew", "Kang", "Song", "Park" };
	char(*p)[10];

	p = a;

	printf("%s\n", *p);
	printf("%s\n", *(p + 1));
	printf("%c\n", *(*(p + 2) + 1));

	printf("%s\n", p[0]);
	printf("%s\n", p[1]);
	printf("%c\n", p[2][1]);
}

#endif

/***********************************************************/
// [5-13] void * 를 통한 배열의 간접 전달
/***********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };

int func(void * p, int a, int x)
{
	int(*q)[4] = p;
	return (a + 2)[q[x - 1]];
}

void main(void)
{
	printf("%d\n", func(a, 1, 2));
}

#endif

/***********************************************************/
// [5-14] 2차원 배열 복사 함수
/***********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
int b[3][4];

void array_copy(int * dest, int * src, int num)
{

}

void main(void)
{
	int i, j;

	array_copy((int *)b, (int *)a, (sizeof(a) / sizeof(a[0]))*(sizeof(a[0]) / sizeof(a[0][0])));

	for (i = 0; i< sizeof(a) / sizeof(a[0]); i++)
	{
		for (j = 0; j< sizeof(a[0]) / sizeof(a[0][0]); j++)
		{
			printf("[%d][%d]=%d,%d\n", i, j, a[i][j], b[i][j]);
		}
	}
}

#endif

/***********************************************************/
// [5-15] 2차원 배열과 1차원 배열
/***********************************************************/

#if 0

#include <stdio.h>

int a[12] = { 10, 20, 30, 40, 50, 60, 70, 80, 11, 22, 33, 44 };

void main(void)
{
	int *p = a;
	char * q = (char *)a;
	int(*r)[4] = (int(*)[4])a;
	int(*s)[3] = (int(*)[3])a;
	int(*t)[2][3] = (int(*)[2][3])a;

	printf("%d, %d\n", p[0], p[1]);
	printf("%d, %d\n", q[0], q[1]);
	printf("%#.8x, %#.8x\n", r[0], r[1]);
	printf("%#.8x, %#.8x\n", s[0], s[1]);
	printf("%#.8x, %#.8x\n", t[0], t[1]);
}

#endif

/***********************************************************/
// [5-16] 배열의 억세스
/***********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
int *b[3] = { a[2], a[1], a[0] };

void main(void)
{
	printf("%d\n", a[2][3]);

	//b를 이용하여 배열내의 숫자 12을 인쇄하시오
	printf("%d\n", );
}

#endif


/***********************************************************/
// [5-17] 환산법의 적용
/***********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
int *p = a[0];

void main(void)
{
	printf("%d\n", a[2][3]);

	//p를 이용하여 배열내의 숫자 12을 인쇄하시오
	printf("%d\n", );
}

#endif

/***********************************************************/
// [5-18] 2차원 배열과 1차원 배열
/***********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };

void func(int * p)
{
	= 100;
}

void main(void)
{
	printf("%d\n", a[1][2]);
	func((int *)a);
	printf("%d\n", a[1][2]);
}

#endif

/***********************************************************/
// [5-19] 환산법의 활용
/***********************************************************/

#if 0

#include <stdio.h>

int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

int func(void * p, int a, int x)
{
	int(*q)[4] = p;
	return (a + 4)[q[x - 1]];
}

void main(void)
{
	printf("%d\n", func(a, 1, 2));
}

#endif

/***********************************************************/
// [5-20] 함수 parameter의 직관적 설계
/***********************************************************/

#if 0

#include <stdio.h>

int a[2][3][4] = { { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } }, { { 10, 20, 30, 40 }, { 50, 60, 70, 80 }, { 90, 100, 110, 120 } } };

void f1()
{
	printf("%d\n", );
}

void f2()
{
	printf("%d\n", );
}

void f3()
{
	printf("%d\n", );
}

void f4()
{
	printf("%d\n", );
}

void f5()
{
	printf("%d\n", );
}

void f6()
{
	printf("%d\n", );
}

void main(void)
{
	f1(*(a[0] + 1));
	f2(*(a + 2));
	f3(a);
	f4(a + 3);
	f5(&a);
	f6(&a - 1);
}

#endif

/***********************************************************/
// [5-21] 함수 리턴의 직관적 설계
/***********************************************************/

#if 0

#include <stdio.h>

int a[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
int b[2][3] = { { 10, 20, 30 }, { 40, 50, 60 } };
int(*c[2])[3] = { b, a };
int(**p)[3] = c;

f1(void)
{
	return c[1];
}

f2(void)
{
	return c + 1;
}

f3(void)
{
	return a[0] - 1;
}

f4(void)
{
	return p;
}

f5(void)
{
	return &c;
}

void main(void)
{
	printf("6=%d\n", f1());
	printf("6=%d\n", f2());
	printf("6=%d\n", f3());
	printf("6=%d\n", f4());
	printf("6=%d\n", f5());
}

#endif

/***********************************************************/
// [5-22] 코드의 직관적 해석
/***********************************************************/

#if 0 

#include <stdio.h>

char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
char **cp[] = { c + 3, c + 2, c + 1, c };
char ***cpp = cp;

void main(void)
{
	printf("%s", **++cpp);
	printf("%s ", *--*++cpp + 3);
	printf("%s", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
}

#endif

/***********************************************************/
// [6-1] 함수 등가포인터의 실행
/***********************************************************/

#if 0

#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

void f1(void)
{
	printf("func\n");
}

int * f2(void)
{
	static int a[4] = { 1, 2, 3, 4 };

	return a;
}

void main(void)
{
	// p, q, r 선언

	// p, q, r에 대응 함수 대입

	printf("%d\n", add(3, 4));
	f1();
	printf("%d\n", f2()[2]);

	// 위와 동일한 결과가 나오도록 p, q, r로 실행



}

#endif

/***********************************************************/
// [6-2] 함수 주소 앞에 붙은 *은 다 가짜다
/***********************************************************/

#if 0

#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

void main(void)
{
	int(*p)(int, int);

	p = add;

	printf("%d\n", p(3, 4));
	printf("%d\n", (*p)(3, 4));
	printf("%d\n", (**p)(3, 4));
	printf("%d\n", (***p)(3, 4));
}

#endif

/***********************************************************/
// [6-3] 함수를 함수에 전달하자
/***********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

void func()
{
	printf("%d\n", p(3, 4));
}

void main(void)
{
	func(add);
	func(sub);
}

#endif

/***********************************************************/
// [6-4] Parameter 미지정형 함수 등가포인터
/***********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
	return a + b;
}

int sqr(int a)
{
	return a*a;
}

int func(void)
{
	return 100;
}

// add, sqr, func에 공통적인 함수 등가포인터 p 설계


void main(void)
{
	p = add;
	printf("%d\n", p(3, 4));

	p = sqr;
	printf("%d\n", p(3));

	p = func;
	printf("%d\n", p());
}

#endif

/***********************************************************/
// [6-5] Parameter 미지정형의 주의 사항
/***********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
	return a + b;
}

int sqr(int a)
{
	return a*a;
}

int func(void)
{
	return 100;
}

int(*p)();

void main(void)
{
	p = add;
	printf("%d\n", p(3));

	p = sqr;
	printf("%d\n", p(3, 4));

	p = func;
	printf("%d\n", p(10));
}

#endif

/***********************************************************/
// [6-6] 함수를 배열에 담자
/***********************************************************/

#if 0

#include <stdio.h> 

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a*b;
}

fa[3] = { add, sub, mul };

void main(void)
{
	int i;
	int a = 3, b = 4;

	for (i = 0; i<sizeof(fa) / sizeof(fa[0]); i++)
	{
		printf("%d\n", );
	}
}

#endif

/***********************************************************/
// [6-7] 함수를 리턴하자
/***********************************************************/

#if 0

#include <stdio.h> 

void g(void)
{
	printf("Welcome!\n");
}

f(void)
{
	return g;
}

void main(void)
{

}

#endif

/***********************************************************/
// [6-8] switch에 의한 다중분기
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a*b;
}

int get_key(void)
{
	return rand() % 3;
}

int op(int a, int b)
{
	switch (get_key())
	{
	case 0: return add(a, b);
	case 1: return sub(a, b);
	case 2: return mul(a, b);
	}
}

void main(void)
{
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
}

#endif

/***********************************************************/
// [6-9] 함수 Lookup table
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a*b;
}

int get_key(void)
{
	return rand() % 3;
}

fa[3] = { add, sub, mul };

int op(int a, int b)
{
	return fa[get_key()](a, b);
}

void main(void)
{
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
	printf("%d\n", op(3, 4));
}

#endif

/***********************************************************/
// [6-10] 요청한 함수를 리턴해 주는 함수
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int func(void)
{
	return rand() % 4;
}

int sqr(int a)
{
	return a*a;
}

int add(int a, int b)
{
	return a + b;
}

fa[3] = { func, sqr, add };

op(int num)
{
	return fa[num];
}

void main(void)
{
	printf("%d\n", op(0)());
	printf("%d\n", op(1)(3));
	printf("%d\n", op(2)(3, 4));
}

#endif

/***********************************************************/
// [6-11] 함수를 전달받고 함수를 리턴하는 함수
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a*b;
}

int get_key(void)
{
	return rand() % 3;
}

int(*fa[3])(int, int) = { add, sub, mul };

op(fp)
{
	return fa[fp()];
}

void main(void)
{
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
}

#endif

/***********************************************************/
// [6-12] 배열 기반 sorting의 구현
/***********************************************************/

#if 0

#include <stdio.h> 

struct _st
{
	int num;
	char *name;
};

struct _st book[10] = { { 7, "Kim" }, { 2, "Lew" }, { 10, "Kang" },
{ 3, "Lee" }, { 6, "Seo" }, { 1, "Song" },
{ 5, "Ki" }, { 8, "Moon" }, { 9, "Park" },
{ 4, "Jung" } };

int my_sort(struct _st * p, int n, int width)
{

}

void main(void)
{
	int i;

	for (i = 0; i<10; i++) printf("%d:%s\n", book[i].num, book[i].name);
	printf("\n");

	my_sort(book, sizeof(book) / sizeof(book[0]), sizeof(struct _st));
	for (i = 0; i<10; i++) printf("%d:%s\n", book[i].num, book[i].name);
}

#endif

/***********************************************************/
// [6-13] Sort and Search
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h>

struct _st
{
	int num;
	char *name;
};

struct _st book[10] = { { 7, "Kim" }, { 2, "Lew" }, { 10, "Kang" },
{ 3, "Lee" }, { 6, "Seo" }, { 1, "Song" },
{ 5, "Ki" }, { 8, "Moon" }, { 9, "Park" },
{ 4, "Jung" } };

int compare_num_up(const void * a1, const void * a2)
{
	register const struct _st * p = a1, *q = a2;

	if (p->num > q->num) return 1;
	if (p->num < q->num) return -1;
	return 0;
}

void main(void)
{
	int i; struct _st tmp; struct _st *p;

	for (i = 0; i<10; i++) printf("%d:%s\n", book[i].num, book[i].name);
	printf("\n");
	qsort(book, sizeof(book) / sizeof(book[0]), sizeof(struct _st), compare_num_up);
	for (i = 0; i<10; i++) printf("%d:%s\n", book[i].num, book[i].name);

	tmp.num = 8;
	p = bsearch(&tmp, book, 10, sizeof(struct _st), compare_num_up);
	if (p)	printf("\nSearch Result => %d : %s\n", p->num, p->name);
	else	printf("\nSearch Failed\n");
}

#endif

/***********************************************************/
// [6-14] typedef을 이용한 가독성의 증대
/***********************************************************/

#if 0

#include <stdio.h> 
#include <stdlib.h> 

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a*b;
}

int get_key(void)
{
	return rand() % 3;
}

typedef

FPTR fa[3] = { add, sub, mul };

FPTR op(FPTR fp)
{
	return fa[fp()];
}

void main(void)
{
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
	printf("%d\n", op(get_key)(3, 4));
}

#endif

/***********************************************************/
// [6-15] 직관적 코드 설계 예제 1
/***********************************************************/

// 직접 선언

#if 0

#include <stdio.h> 

f2(void)
{
	static int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	return a;
}

f1(void)
{
	return f2;
}

void main(void)
{
	printf("%d\n", f1());
}

#endif

// typedef 사용

#if 0

typedef FP2
typedef FP1

FP2 f2(void)
{
	static int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	return a;
}

FP1 f1(void)
{
	return &f2;
}

void main(void)
{
	printf("%d\n", f1());
}

#endif

/***********************************************************/
// [6-16] 직관적 코드 설계 예제 2
/***********************************************************/

#if 0 

#include <stdio.h> 

f2(void)
{
	static int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	return a;
}

f1(void)
{
	return f2()[2];
}

void main(void)
{
	printf("%d\n", f1());
}

#endif

/***********************************************************/
// [6-17] 직관적 코드 설계 예제 3
/***********************************************************/

#if 0 

#include <stdio.h> 

f2(void)
{
	static int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	return &a;
}

f1(void)
{
	return f2()[0];
}

void main(void)
{
	printf("%d\n", f1());
}

#endif

/***********************************************************/
// [6-18] 직관적 코드 설계 예제 4
/***********************************************************/

#if 0

struct _st
{
	int num;
	char * name;
};

f2(void)                     // [1]
{
	static struct _st a[2][3] = { { { 1, "KIM" }, { 2, "SONG" }, { 3, "KI" } }, { { 4, "KANG" }, { 5, "PARK" }, { 6, "LEW" } } };
	return a;
}

f1(int num)                   // [2]
{
	return f2()[num];
}

void main(void)
{
	printf("%s\n", f1(0));   // [3]
}

#endif

/***********************************************************/
// [6-19] 직관적 코드 설계 예제 5
/***********************************************************/

#if 0

#include <stdio.h>

int *f1(void)
{
	static int a[4] = { 1, 2, 3, 4 };
	return a;
}

int *f2(void)
{
	static int a[4] = { 10, 20, 30, 40 };
	return a;
}

int *(*fa[2])() = { f1, f2 };

int f4(void)
{
	return 1;
}

func1(void)     // [1]
{
	return fa;
}

func2(p)   // [2]
{
	return func1()[p()];
}

void main(void)
{
	printf("%d\n", func2(f4));   // [3]
}

#endif


/***********************************************************/
// [7-1] 메모리는 변함 없다
/***********************************************************/

#if 0

#include <stdio.h>

int a[12] = { 10, 20, 30, 40, 50, 60, 70, 80, 11, 22, 33, 44 };

void main(void)
{
	int *p = a;
	char * q = (char *)a;
	int(*r)[4] = (int(*)[4])a;
	int(*s)[3] = (int(*)[3])a;
	int(*t)[2][3] = (int(*)[2][3])a;

	printf("%d, %d\n", p[0], p[1]);
	printf("%d, %d\n", q[0], q[1]);
	printf("%#.8x, %#.8x\n", r[0], r[1]);
	printf("%#.8x, %#.8x\n", s[0], s[1]);
	printf("%#.8x, %#.8x\n", t[0], t[1]);
}

#endif

/***********************************************************/
// [7-2] 배열의 요소수를 구한다
/***********************************************************/

#if 0

#include <stdio.h>

int sum(int(*p)[4])
{
	int i, s = 0;

	for (i = 0; i<sizeof(*p) / sizeof((*p)[0]); i++)
	{
		s += (*p)[i];
	}

	return s;
}

void main(void)
{
	int a[4] = { 1, 2, 3, 4 };

	printf("%d\n", sum(&a));
}

#endif

/***********************************************************/
// [7-3] 주소를 리턴하는 함수
/***********************************************************/

#if 0

#include <stdio.h>

int * func(int *p)
{
	int i;

	for (i = 1; i <= p[0]; i++)
	{
		printf("%d\n", p[i]);
	}

	return p + i;
}

void main(void)
{
	int i;
	int a[] = { 1, 10, 2, -5, -20, 3, 100, 200, 300, 4, -10, -20, -30, -40 };
	int *p = a;

	for (i = 0; i<4; i++)
	{
		p = func(p);
	}
}

#endif

/***********************************************************/
// [7-4] 함수의 리턴은 하나뿐이다
/***********************************************************/

#if 0

#include <stdio.h>

int func(int *p)
{
	int i, sum = 0;

	for (i = 1; i <= p[0]; i++)
	{
		sum += p[i];
	}

	return sum;
}

void main(void)
{
	int i;
	int a[] = { 1, 10, 2, -5, -20, 3, 100, 200, 300, 4, -10, -20, -30, -40 };
	int *p = a;

	for (i = 0; i<4; i++)
	{
		printf("SUM=%d\n", func(p));
	}
}

#endif

/***********************************************************/
// [7-5] 주소의 내용을 액세스하는 함수
/***********************************************************/

#if 0

#include <stdio.h>

void func(int *p)
{
	*p = 100;
	p++;
	printf("0x%p\n", p);
}

void main(void)
{
	int a[] = { 1, 2, 3, 4 };
	int *p = a;

	func(p);
	printf("%d\n", *p);
	printf("0x%p, 0x%p\n", a, p);
}

#endif

/***********************************************************/
// [7-6] 주소 값의 업데이트
/***********************************************************/

#if 0

#include <stdio.h>

void func(int **p)
{
	**p = 100;
	(*p)++;
	printf("0x%p\n", (*p));
}

void main(void)
{
	int a[] = { 1, 2, 3, 4 };
	int *p = a;

	func(&p);
	printf("%d\n", a[0]);
	printf("0x%p, 0x%p\n", a, p);
}

#endif 

/***********************************************************/
// [7-7] 다중 포인터의 활용
/***********************************************************/

#if 0

#include <stdio.h>

int func(const int **p)
{
	int i;
	int sum = 0;

	printf("=========%d\n", (*p)[0]);






	return sum;
}

void main(void)
{
	int i;
	int a[] = { 1, 10, 2, -5, -20, 3, 100, 200, 300, 4, -10, -20, -30, -40 };
	const int *p = a;

	for (i = 0; i<4; i++)
	{
		printf("SUM=%d\n", func(&p));
	}
}

#endif

/***********************************************************/
// [7-8] Data Packing
/***********************************************************/

#if 0

#include <stdio.h>

void make_data(char **p, int size, char * data)
{



}

char mem[4 * 4];

void main(void)
{
	int i;	unsigned int data;
	char *p = mem;

	make_data(&p, 4, (data = 0x12345678, (char *)&data));
	make_data(&p, 2, (data = 0xaabb, (char *)&data));
	make_data(&p, 1, (data = 0xcc, (char *)&data));
	make_data(&p, 4, (data = 0x11223344, (char *)&data));
	make_data(&p, 2, (data = 0x5566, (char *)&data));

	for (i = 0; i<4; i++) printf("%#.8X\n", ((int *)mem)[i]);
}

#endif

/***********************************************************/
// [7-9] Argument들을 인쇄하는 코드 설계
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	int i;

	printf("argc = %d\n", argc);

	for (i = 0; i<argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	getchar();
	return 0;
}

#endif

/***********************************************************/
// [7-10] realloc에 의한 공간 조정
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i, *p, *q, *r;

	r = p = malloc(40);
	q = malloc(40);

	for (i = 0; i<10; i++)
	{
		p[i] = i;
	}

	r = realloc(r, 40 * 2);

	for (i = 10; i<20; i++)
	{
		r[i] = i;
	}

	printf("p=%p, r=%p\n", p, r);

	for (i = 0; i<20; i++)
	{
		printf("p[%d]=%d, r[%d]=%d\n", i, p[i], i, r[i]);
	}
}

#endif

/***********************************************************/
// [7-11] 힙에 동적 배열 만들기
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i, j, x;
	int **p;

	x = 3;

	p = malloc(x * sizeof(int *));

	for (i = 0; i<x; i++)
	{
		p[i] = malloc(4 * sizeof(int));
	}

	for (i = 0; i<x; i++)
	{
		for (j = 0; j<4; j++)
		{
			p[i][j] = i * 4 + j;
		}
	}

	for (i = 0; i<x; i++)
	{
		for (j = 0; j<4; j++)
		{
			printf("%d\n", p[i][j]);
		}
	}

	for (i = 0; i<x; i++)
	{
		free(p[i]);
	}

	free(p);
}

#endif

/***********************************************************/
// [7-12] 선형 메모리로 할당한 동적 배열
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i, j, x;
	int **p;

	x = 3;

	p = malloc(x * sizeof(int *));
	p[0] = malloc(x * 4 * sizeof(int));

	for (i = 1; i<x; i++)
	{
		p[i] = p[0] + i * 4;
	}

	for (i = 0; i<x; i++)
	{
		for (j = 0; j<4; j++)
		{
			p[i][j] = i * 4 + j;
		}
	}

	for (i = 0; i<x; i++)
	{
		for (j = 0; j<4; j++)
		{
			printf("%d\n", p[i][j]);
		}
	}

	free(p[0]);
	free(p);
}

#endif

/***********************************************************/
// [7-13] 등가포인터를 이용한 동적 배열
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i, j, x;
	int(*p)[4];

	x = 3;

	p = malloc(x * sizeof(int[4]));

	for (i = 0; i<x; i++)
	{
		for (j = 0; j<4; j++)
		{
			p[i][j] = i * 4 + j;
		}
	}

	for (i = 0; i<x; i++)
	{
		for (j = 0; j<4; j++)
		{
			printf("%d\n", p[i][j]);
		}
	}

	free(p);
}

#endif

/***********************************************************/
// [7-14] 모든 요소수가 가변인 배열
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i, j, m, n;
	int **p;

	m = 3, n = 4;

	p = malloc(m * sizeof(int *));
	p[0] = malloc(m * n * sizeof(int));

	for (i = 1; i<m; i++)
	{
		p[i] = p[0] + i*n;
	}

	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			p[i][j] = i*n + j;
		}
	}

	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			printf("%d\n", p[i][j]);
		}
	}

	free(p[0]);
	free(p);
}

#endif

/***********************************************************/
// [7-15] 2차원 배열을 1차원 배열로 에뮬레이션
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i, j;
	int m = 3, n = 4;
	int *p;

	p = malloc(m * n * sizeof(int));

	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			p[i*n + j] = i*n + j;
		}
	}

	for (i = 0; i<(m*n); i++)
	{
		printf("%d\n", p[i]);
	}

	free(p);
}

#endif

/***********************************************************/
// [7-16] const
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	const int a = 100;

	a = 50;
	printf("%d\n", a);
}

#endif

#if 0

#include <stdio.h>

void main(void)
{
	const int a = 100;
	int *p;

	p = &a;
	*p = 50;

	printf("%d\n", a);
}

#endif

/***********************************************************/
// [7-17] const
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	int a;

	int const * p;			// [A]
	int * const p;			// [B]
	int const * const p;	// [C]
	const int * p;			// [D]

	p = (int *)0x1000;	// [1]
	p++;						// [2]
	*p = 100;				// [3]
	a = *p;					// [4]
}

#endif

/***********************************************************/
// [7-18] const의 용도
/***********************************************************/

#if 0

#include <stdio.h>

int sum(int *p)
{
	int i, s = 0;

	for (i = 0; i<5; i++)
	{
		s += p[i];
		p[i] = 0;
	}

	return s;
}

void main(void)
{
	int r;
	int a[5] = { 1, 2, 3, 4, 5 };

	r = sum(a);
	printf("%d, %d\n", r, a[0]);
}

#endif

#if 0

#include <stdio.h>

int sum(const int *p)
{
	int i, s = 0;

	for (i = 0; i<5; i++)
	{
		s += p[i];
		p[i] = 0;
	}

	return s;
}

void main(void)
{
	int r;
	int a[5] = { 1, 2, 3, 4, 5 };

	r = sum(a);
	printf("%d, %d\n", r, a[0]);
}

#endif

#if 0

#include <stdio.h>

int sum(const int *p)
{
	int i, s = 0;
	int *q = p;

	for (i = 0; i<5; i++)
	{
		s += q[i];
		q[0] = 0;
	}

	return s;
}

void main(void)
{
	int r;
	int a[5] = { 1, 2, 3, 4, 5 };

	r = sum(a);
	printf("%d, %d\n", r, a[0]);
}

#endif

/***********************************************************/
// [7-19] const는 읽기 전용으로 만든다
/***********************************************************/

#if 0

#include <stdio.h>

int a[4] = { 1, 2, 3, 4 };
const int b[4] = { 10, 20, 30, 40 };

void main(void)
{
	a[0] = 100;
	b[0] = 100;

	printf("%d %d\n", a[0], b[0]);
}

#endif

/***********************************************************/
// [8-1] void 리턴
/***********************************************************/

#if 0

#include <stdio.h>

void func(int a)
{
	a;
}

void main(void)
{
	int a = func(3);
	printf("%d\n", a);
}

#endif

#if 0

#include <stdio.h>

void main(void)
{
	int a = printf("Hello!\n");
	int b = printf("%d\n", a);
	printf("%d\n", b);
}

#endif

/***********************************************************/
// [8-2]  argument 전달
/***********************************************************/

#if 0

#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

void main(void)
{
	printf("%d\n", add(3));
}

#endif

#if 0

#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

void main(void)
{
	printf("%d\n", add(3, 4, 5));
}

#endif

#if 0

#include <stdio.h>

void main(void)
{
	int a = 1, b = 2, c = 3;

	printf("남는 Argument : %d %d \n", a, b, c);
	printf("적은 Argument : %d %d %d\n", a, b);
}

#endif

/***********************************************************/
// [8-3]  가변의 인수전달
/***********************************************************/

#if 0

#include <stdio.h>

int my_add(int cnt, ...)
{
	int i, sum = 0;

	for (i = 1; i <= cnt; i++)
	{

	}
	return sum;
}

void main(void)
{
	printf("%d\n", my_add(3, 7, 5, 4));
	printf("%d\n", my_add(5, 1, 2, 6, 9, 10));
}

#endif

/***********************************************************/
// [8-4]  스택을 통한 Argument 전달 규정
/***********************************************************/

#if 0

#include <stdio.h>

void f1(char a, short b, long long int c, int d)
{
	printf("%p %p %p %p\n", &a, &b, &c, &d);
}

void f2(float e, long double f, double g)
{
	printf("%p %p %p\n", &e, &f, &g);
}

void main(void)
{
	char a = 'A';
	short b = 0x1234;
	long long int c = 0x123456789ABCDEF0LL;
	int d = 0xABCDEF01;
	float e = 3.5f;
	long double f = 3.5L;
	double g = 3.5;

	f1(a, b, c, d);
	f2(e, f, g);
}

#endif

/***********************************************************/
// [8-5]  스택으로 전달된 char 변수
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	signed char c = 0x80;

	printf("%#x\n", c);
	printf("%u\n", c);
	printf("%d\n", c);
}

#endif

/***********************************************************/
// [8-6] 실수 메모리의 dump?
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	float f = 3.5f;

	printf("0x%#x\n", f);
}

#endif

/***********************************************************/
// [8-7]  실수 메모리를 제대로 dump하려면?
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	float f = 3.5f;

	printf("float : %#.8x\n", );
}

#endif

/***********************************************************/
// [8-8]  double의 메모리를 dump하려면?
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	double d = 3.5;

	printf("%#x\n", d);
}

#endif

/***********************************************************/
// [8-9]  double 메모리를 제대로 dump하려면?
/***********************************************************/

#if 0

#include <stdio.h>

void main(void)
{
	double d = 3.5;

	printf("double: %#.8x : %.8x\n\n", , );
}

#endif

/***********************************************************/
// [8-10]  서로 다른 타입을 가변인자로 전달하면?
/***********************************************************/

#if 0

#include <stdio.h>

void my_ellipsis(int a, ...)
{
	printf("%d\n", a);
	printf("%u\n", );
	printf("%c\n", );
	printf("%f\n", );
	printf("%f\n", );
}

void main(void)
{
	int a = 10;
	unsigned char b = 100;
	unsigned char c = 'A';
	float d = 3.14f;
	double e = 5.125;

	my_ellipsis(a, b, c, d, e);
}

#endif

/***********************************************************/
// [8-11] 간이  format 지시자의 이용
/***********************************************************/

#if 0

#include <stdio.h>

void my_printf(char * fmt, ...)
{
	int *ap = (int *)&fmt + 1;

	while (*fmt)
	{
		switch (*fmt++)
		{
		case 'u': printf("%u\n", ); break;
		case 'd': printf("%d\n", ); break;
		case 'c': printf("%c\n", ); break;
		case 'f': printf("%f\n", ); break;
		case 's': printf("%s\n", ); break;
		}
	}
}

void main(void)
{
	int a = 10;
	unsigned char b = 100;
	unsigned char b2 = 'A';
	float c = 3.14f;
	double d = 5.125;

	my_printf("ducffsd", a, b, b2, c, d, "Keyseek", 100);
	my_printf("fdsc", -10.75, 100, "Willtek", 'B');
}

#endif

/***********************************************************/
// [8-12] 가변인자 전달용 macro의 활용
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdarg.h>

void my_printf(char * fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	while (*fmt)
	{
		switch (*fmt++)
		{
		case 'u': printf("%X\n", va_arg(ap, unsigned int)); break;
		case 'd': printf("%d\n", va_arg(ap, int)); break;
		case 'c': printf("%c\n", va_arg(ap, char)); break;
		case 'f': printf("%f\n", va_arg(ap, double)); break;
		case 's': printf("%s\n", va_arg(ap, char *)); break;
		}
	}

	va_end(ap);
}

void main(void)
{
	int a = 10; unsigned char b = 100; unsigned char b2 = 'A';
	float c = 3.14f; double d = 5.125;

	my_printf("ducffsd", a, b, b2, c, d, "Keyseek", 100);
	my_printf("fdsc", -10.75, 100, "Willtek", 'B');
}

#endif

/***********************************************************/
// [8-13]  my_add 함수의 재설계
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdarg.h>

int my_add(int cnt, ...)
{
	int i, sum = 0;



	for (i = 1; i <= cnt; i++)
	{

	}


	return sum;
}

void main(void)
{
	printf("%d\n", my_add(3, 7, 5, 4));
	printf("%d\n", my_add(5, 1, 2, 6, 9, 10));
}

#endif

/***********************************************************/
// [8-14]  진짜 printf 처럼 동작하는 함수
/***********************************************************/

#if 0

#include <stdio.h>
#include <stdarg.h>

int my_printf(char * fmt, ...)
{
	int n;
	va_list ap;
	char string[256];

	va_start(ap, fmt);
	n = vsprintf(string, fmt, ap);
	printf(string);
	va_end(ap);
	return n;
}

void main(void)
{
	int a = 10;
	unsigned char b = 100;

	unsigned char b2 = 'A';
	float c = 3.14f;
	double d = 5.125;

	my_printf("ANSWER = %d %u %c %1.2f %1.3f %s %d\n", a, b, b2, c, d, "Keyseek", 100);
}

#endif

/***********************************************************/
// [8-15] Type casting 연습 1
/***********************************************************/

#if 0

#include <stdio.h>

void func(int x)
{
	printf("%f\n", );
	printf("%f\n", );
	printf("%f\n", );
}

void main(void)
{
	double d[3] = { 3.14, 5.125, -7.42 };

	func((int)d);
}

#endif

/***********************************************************/
// [8-16] Type casting 연습 1
/***********************************************************/

#if 0

#include <stdio.h>

void func(int x)
{
	int i;

	for (i = 0; i<3; i++)
	{

	}
}

void main(void)
{
	double d[3] = { 3.14, 5.125, -7.42 };

	func((int)d);
}

#endif

/***********************************************************/
// [8-17] Type casting 연습 2
/***********************************************************/

#if 0

#include <stdio.h>

void func(void * p)
{
	int i;

	for (i = 0; i<3; i++)
	{
		printf("%f\n", );
	}
}

void main(void)
{
	double d[3] = { 3.14, 5.125, -7.42 };
	void *p = d;

	func(&p);
}

#endif

/***********************************************************/
// [8-18] Type casting 연습 3
/***********************************************************/

#if 0

#include <stdio.h>

void func(void *p)
{
	printf("%s\n", );
}

void main(void)
{
	char * p = "Willtek";
	func(&p);
}

#endif

/***********************************************************/
// [8-19] Type casting 연습 4
/***********************************************************/

#if 0

#include <stdio.h>

struct st
{
	int i;
	char c;
};

void func(long long int a)
{
	printf("%d\n", );
	printf("%c\n", );
}

void main(void)
{
	struct st x = { 100, 'A' };

	func(*(long long int *)&x);
}

#endif

/***********************************************************/
// [8-20]  함수포인터 타입캐스팅
/***********************************************************/

#if 0

#include <stdio.h>

int func(int a, int b)
{
	return a + b;
}

void main(void)
{
	int a = (int)func;

	printf("%d\n", func(3, 4));
	printf("%d\n", );
}

#endif

/***********************************************************/
// [8-21] Type casting 연습 5
/***********************************************************/

#if 0

#include <stdio.h>

void func(void * p)
{
	printf("%d\n", );
}

int add(int a, int b)
{
	return a + b;
}

void main(void)
{
	void *p = (void *)add;

	func(&p);
}

#endif

/***********************************************************/
// [8-22] data parsing 1
/***********************************************************/

#if 0

#include <stdio.h>

struct _st
{
	int i;
	char c;
};

void my_test(char c, ...)
{
	printf("%c\n", c);
	printf("%d\n", );
	printf("%c\n", );
	printf("%s\n", );
	printf("%f\n", );
	printf("%f\n", );
	printf("%f\n", );
	printf("%d\n", );
}

int add(int a, int b)
{
	return a + b;
}

void main(void)
{
	char a = 'A';
	struct _st x = { 100, 'B' };
	double d[3] = { 3.14, 5.19, -7.42 };

	my_test(a, x, "Song", d, add);
}

#endif

/***********************************************************/
// [8-23] data parsing 2
/***********************************************************/

#if 0

#include <stdio.h>

void my_test(int a, ...)
{
	// [1] 넘어온 3.14 인쇄
	printf("f => %.2f\n", );
	// [2] 넘어온 배열을 이용하여 f1 함수를 간접호출하여 문자열 BIN 출력
	printf("%s", );
	// [3] 넘어온 배열을 이용하여 f2 함수를 간접호출하여 문자열 GO 출력
	printf("%s\n", );
}

char * f1(void)
{
	return "CABIN";
}

char * f2(void)
{
	return "LOGO";
}

void main(void)
{
	double d = 3.14;
	char * (*fa[2])() = { f1, f2 };

	my_test(1, &d, fa);
}

#endif

/***********************************************************/
// [9-1]  구조체의 메모리 구성
/***********************************************************/

#if 0

#include <stdio.h>

struct _st
{
	short a;
	int b;
	char c;
	int d;
}st = { 0x1111, 0x22222222, 0x33, 0x44444444 };

void main(void)
{
	printf("%d\n", sizeof(st));
}

#endif

/***********************************************************/
// [9-2]  구조체의 메모리 절감
/***********************************************************/

#if 0

struct _st
{
	short a;
	char b;
	int c;
	int d;
}st = { 0x1111, 0x33, 0x22222222, 0x44444444 };

void main(void)
{
	printf("%d\n", sizeof(st));
}

#endif

/***********************************************************/
// [9-3]  구조체 데이터의 parsing
/***********************************************************/

#if 0

#include <stdio.h>

//#define  BUF	 ((unsigned char *)0x100)

unsigned char buf[] = { 0x4d, 0x4d, 0x55, 0x5f, 0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x44, 0x43, 0x61, 0x63, 0x68, 0x65 };

#define  BUF	 (buf)

struct st
{
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

void main(void)
{
	struct st info;

	info.x = *BUF;
	info.y = *(BUF + 1);
	info.length = *(unsigned short *)(BUF + 2);

	printf("0x%x, 0x%x, 0x%x\n", info.x, info.y, info.length);
}

#endif

/***********************************************************/
// [9-4]  구조체 포인터의 활용
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] = { 0x4d, 0x4d, 0x55, 0x5f, 0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x44, 0x43, 0x61, 0x63, 0x68, 0x65 };

#define  BUF	 (buf)

struct st
{
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

void main(void)
{
	struct st *info;

	info = (struct st *)BUF;
	printf("0x%x, 0x%x, 0x%x\n", info->x, info->y, info->length);

	info++;
	printf("0x%x, 0x%x, 0x%x\n", info->x, info->y, info->length);
}
#endif

/***********************************************************/
// [9-5]  값을 변경할 필요가 없는 포인터
/***********************************************************/

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] = { 0x4d, 0x4d, 0x55, 0x5f, 0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x44, 0x43, 0x61, 0x63, 0x68, 0x65 };

#define  info	 ((struct st *)buf)

struct st
{
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

void main(void)
{
	printf("0x%x, 0x%x, 0x%x\n", info->x, info->y, info->length);
	printf("0x%x, 0x%x, 0x%x\n", (info + 1)->x, (info + 1)->y, (info + 1)->length);
}

#endif

/***********************************************************/
// [9-6]  연속한 구조체 데이터
/***********************************************************/

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] = { 0x4d, 0x4d, 0x55, 0x5f, 0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x44, 0x43, 0x61, 0x63, 0x68, 0x65 };

#define  info	 ((struct st *)buf)

struct st
{
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

void main(void)
{
	int i;

	for (i = 0; i<4; i++)
	{
		printf("0x%x, 0x%x, 0x%x\n", );
	}
}

#endif

/***********************************************************/
// [9-7]  연속한 구조체는 구조체 배열이다
/***********************************************************/

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] = { 0x4d, 0x4d, 0x55, 0x5f, 0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x44, 0x43, 0x61, 0x63, 0x68, 0x65 };

#define  info	 ((struct st *)buf)

struct st
{
	unsigned char x;
	unsigned char y;
	unsigned short length;
};

void main(void)
{
	int i;

	for (i = 0; i<4; i++)
	{
		printf("0x%x, 0x%x, 0x%x\n", );
	}
}

#endif

/***********************************************************/
// [9-8]  구조체를 이용한 모델링의 문제점
/***********************************************************/

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] = { 0x4d, 0x4d, 0x55, 0x5f, 0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x44, 0x43, 0x61, 0x63, 0x68, 0x65 };

#define  info	 ((struct st *)buf)

struct st
{
	unsigned char x;
	unsigned char y;
	unsigned int length;
};

void main(void)
{
	printf("0x%x, 0x%x, 0x%x\n", info[0].x, info[0].y, info[0].length);
	printf("0x%x, 0x%x, 0x%x\n", info[1].x, info[1].y, info[1].length);
}

#endif

/***********************************************************/
// [9-9]  구조체 멤버 alignment 규정
/***********************************************************/

#if 0

#include <stdio.h>

struct _s1
{
	short a;
}s1 = { 0x1234 };

struct _s2
{
	short a;
	int b;
	char c;
	double d;
}s2 = { 0x1234, 0x56789abc, 0xfe, 3.14 };

struct _s3
{
	char a;
	short b;
	int c[2];
}s3 = { 0x12, 0x3456, { 0xfedcba98, 0x13579bdf } };

void main(void)
{
	printf("%d, %p\n", sizeof(s1), &s1.a);
	printf("%d, %p, %p, %p, %p\n", sizeof(s2), &s2.a, &s2.b, &s2.c, &s2.d);
	printf("%d, %p, %p, %p, %p\n", sizeof(s3), &s3.a, &s3.b, &s3.c[0], &s3.c[1]);
}

#endif

/***********************************************************/
// [9-10] pack을 사용한 구조체 멤버 alignment 규정
/***********************************************************/

#if 0

#include <stdio.h>

#pragma pack(1)

struct _s1
{
	short a;
}s1 = { 0x1234 };

#pragma pack(4)

struct _s2
{
	short a;
	int b;
	char c;
	double d;
}s2 = { 0x1234, 0x56789abc, 0xfe, 3.14 };

#pragma pack(1)

struct _s3
{
	char a;
	short b;
	int c[2];
}s3 = { 0x12, 0x3456, { 0xfedcba98, 0x13579bdf } };

#pragma pack(8)

void main(void)
{
	printf("%d, %p\n", sizeof(s1), &s1.a);
	printf("%d, %p, %p, %p, %p\n", sizeof(s2), &s2.a, &s2.b, &s2.c, &s2.d);
	printf("%d, %p, %p, %p, %p\n", sizeof(s3), &s3.a, &s3.b, &s3.c[0], &s3.c[1]);
}

#endif

/***********************************************************/
// [9-11] pack과 label 옵션의 사용
/***********************************************************/

#if 0

#include <stdio.h>

#pragma pack(1)
#pragma pack(show)
#pragma pack(push, l1, 4)
#pragma pack(show)
#pragma pack(push, l2, 2)
#pragma pack(show)
#pragma pack(pop)
#pragma pack(show)
#pragma pack(8)
#pragma pack(show)
#pragma pack(pop, l1)
#pragma pack(show)

void main(void)
{
	printf("Hello\n");
}

#endif 

#if 0

#include <stdio.h>

#pragma pack(1)
#pragma pack(show)
#pragma pack(push, l1, 4)
#pragma pack(show)
#pragma pack(push, l2, 2)
#pragma pack(show)
#pragma pack(pop, l1)
#pragma pack(show)
#pragma pack(8)
#pragma pack(show)
#pragma pack(pop, l2)
#pragma pack(show)

void main(void)
{
	printf("Hello\n");
}

#endif

/***********************************************************/
// [9-12] 특정 위치의 pack 상태로 돌려 놓기
/***********************************************************/

#if 0

#include <stdio.h>

#pragma pack(2)

struct _s1
{
	short a;
}s1 = { 0x1234 };

#pragma pack(push, op1, 4)

struct _s2
{
	short a;
	int b;
	char c;
	double d;
}s2 = { 0x1234, 0x56789abc, 0xfe, 3.14 };

#pragma pack(push, op2, 1)

struct _s3
{
	char a;
	short b;
	int c[2];
}s3 = { 0x12, 0x3456, { 0xfedcba98, 0x13579bdf } };

#pragma pack(pop, op1)

struct _s4
{
	short a;
	int b;
	char c;
	double d;
}s4 = { 0x1234, 0x56789abc, 0xfe, 3.14 };

void main(void)
{
	printf("%d, %p\n", sizeof(s1), &s1.a);
	printf("%d, %p, %p, %p, %p\n", sizeof(s2), &s2.a, &s2.b, &s2.c, &s2.d);
	printf("%d, %p, %p, %p, %p\n", sizeof(s3), &s3.a, &s3.b, &s3.c[0], &s3.c[1]);
	printf("%d, %p, %p, %p, %p\n", sizeof(s4), &s4.a, &s4.b, &s4.c, &s4.d);
}

#endif

/***********************************************************/
// [9-13]  구조체 멤버 pack 옵션
/***********************************************************/

#if 0

#include <stdio.h>

//#define  info	 ((struct st *)0x100)

unsigned char buf[] = { 0x4d, 0x4d, 0x55, 0x5f, 0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x44, 0x43, 0x61, 0x63, 0x68, 0x65 };

#define  info	 ((struct st *)buf)

#pragma pack(              )

struct st
{
	unsigned char x;
	unsigned char y;
	unsigned int length;
};

#pragma pack(pop)

void main(void)
{
	printf("0x%x, 0x%x, 0x%x\n", info[0].x, info[0].y, info[0].length);
	printf("0x%x, 0x%x, 0x%x\n", info[1].x, info[1].y, info[1].length);
}

#endif

/***********************************************************/
// [9-14]  flag 변수들의 사용
/***********************************************************/

#if 0

#include <stdio.h>

#define NO		0
#define YES		1

int opr_mode;
int err_flag = NO;
int steprun_flag = NO;
int autorun_flag = NO;
int allstop_flag = NO;

void main(void)
{
	opr_mode = 1;

	switch (opr_mode)
	{
	case 0: steprun_flag = YES;	break;
	case 1: autorun_flag = YES;	break;
	case 2: allstop_flag = YES;		break;
	default: err_flag = YES;
	}
}

#endif

#if 0

#include <stdio.h>

#define NO		0
#define YES		1

int mode = 0;

void main(void)
{
	mode = (mode & 0x7) | (1);

	switch (mode & 0x7)
	{
	case 0: mode |= 0x10;	break;
	case 1: mode |= 0x20;	break;
	case 2: mode |= 0x40;	break;
	default: mode |= 0x08;
	}
}

#endif

#if 0

#include <stdio.h>

#define NO		0
#define YES		1

struct _flags
{
	unsigned int opr_mode : 3;
	unsigned int err_flag : 1;
	unsigned int steprun_flag : 1;
	unsigned int autorun_flag : 1;
	unsigned int allstop_flag : 1;
}flags = { YES, NO, NO, NO, 1 };

void main(void)
{
	flags.opr_mode = 1;

	switch (flags.opr_mode)
	{
	case 0: flags.steprun_flag = YES;	break;
	case 1: flags.autorun_flag = YES;	break;
	case 2: flags.allstop_flag = YES;		break;
	default: flags.err_flag = YES;
	}
}

#endif

/***********************************************************/
// [9-15]  비트필드 구조체의 특징
/***********************************************************/

#if 0

#include <stdio.h>

struct _st1
{
	unsigned char a : 2;
	unsigned char b : 3;
	unsigned char c : 2;
}x;

struct _st2
{
	unsigned int a : 2;
	unsigned int b : 3;
	unsigned int c : 2;
}y;

void main(void)
{
	y.a = x.a = 0x2;
	y.b = x.b = 0x5;
	y.c = x.c = 0x1;

	printf("%d %d\n", sizeof(x), sizeof(y));
	printf("0x%X 0x%X 0x%X 0x%X\n", x.a, x.b, y.a, y.b);
	printf("0x%.2X 0x%.8X\n", *(unsigned char *)&x, *(unsigned int *)&y);
}

#endif

/***********************************************************/
// [9-16]  FAT16 파일시스템의 파일 생성 시간
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] = { 0x52, 0x7a };

struct fat_time
{
	unsigned char sec;
	unsigned char min;
	unsigned char hour;
};

void main(void)
{
	struct fat_time time;
	unsigned short temp = *(unsigned short *)buf;

	time.hour = (temp >> 11) & 0x1f;
	time.min = (temp >> 5) & 0x3f;
	time.sec = (temp >> 0) & 0x1f;

	printf("Time=%d:%d:%d\n", time.hour, time.min, time.sec * 2);
}

#endif

/***********************************************************/
// [9-17]  비트필드 구조체의 활용
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] = { 0x52, 0x7a };

struct fat_time
{



};

void main(void)
{
	struct fat_time * time = (struct fat_time *)buf;

	printf("Time=%d:%d:%d\n", time->hour, time->min, time->sec * 2);
	printf("Sizeof Time=%d\n", sizeof(struct fat_time));
}

#endif

/***********************************************************/
// [9-18]  비트필드의 컨테이너
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] = { 0x52, 0x7a };

struct fat_time1
{
	unsigned int sec : 5;
	unsigned int min : 6;
	unsigned int hour : 5;
};

struct fat_time2
{
	unsigned char sec : 5;
	unsigned char min : 6;
	unsigned char hour : 5;
};

void main(void)
{
	struct fat_time1 * time1 = (struct fat_time *)buf;
	struct fat_time2 * time2 = (struct fat_time *)buf;

	printf("Time=%d:%d:%d\n", time1->hour, time1->min, time1->sec * 2);
	printf("Sizeof Time=%d\n", sizeof(struct fat_time1));
	printf("Time=%d:%d:%d\n", time2->hour, time2->min, time2->sec * 2);
	printf("Sizeof Time=%d\n", sizeof(struct fat_time2));
}

#endif

/***********************************************************/
// [9-19]  비트필드의 멤버의 데이터 타입
/***********************************************************/

#if 0

#include <stdio.h>

struct st
{
	int a1 : 3;
	int a2 : 2;
	int a3 : 1;
}x;

void main(void)
{
	x.a3 = -1;

	if (x.a3 == -1) printf("TRUE\n");
	else printf("FALSE\n");

	x.a3 = 1;

	if (x.a3 == 1) printf("TRUE\n");
	else printf("FALSE\n");
}

#endif

/***********************************************************/
// [9-20]  Unnamed 비트필드 멤버
/***********************************************************/

#if 0

#include <stdio.h>

volatile struct st
{
	unsigned short LSEON : 1;
	unsigned short LSERDY : 1;
	unsigned short LSEBYP : 1;
	unsigned short rsvd1 : 5;
	unsigned short RTCSEL : 2;
	unsigned short rsvd2 : 5;
	unsigned short RTCEN : 1;
}RTC_CR;

void main(void)
{
	printf("%d\n", sizeof(RTC_CR));
}

#endif

#if 0

#include <stdio.h>

volatile struct st
{
	unsigned short LSEON : 1;
	unsigned short LSERDY : 1;
	unsigned short LSEBYP : 1;
	unsigned short : 5;
	unsigned short RTCSEL : 2;
	unsigned short : 5;
	unsigned short RTCEN : 1;
}RTC_CR;

void main(void)
{
	printf("%d\n", sizeof(RTC_CR));
}

#endif

/***********************************************************/
// [9-21]  Zero Size Width 비트필드
/***********************************************************/

#if 0

#include <stdio.h>

volatile struct st
{
	unsigned int a1 : 5;
	unsigned int a2 : 25;
	unsigned int a3 : 3;
	unsigned int a4 : 4;
}x = { 0x1f, 0x0, 0x7, 0x0 };

void main(void)
{
	printf("%d\n", sizeof(x));
	printf("0x%.8x\n", ((unsigned int *)&x)[0]);
	printf("0x%.8x\n", ((unsigned int *)&x)[1]);
}

#endif

#if 0

#include <stdio.h>

volatile struct st
{
	unsigned int a1 : 5;
	unsigned int : 0;
	unsigned int a2 : 25;
	unsigned int : 0;
	unsigned int a3 : 3;
	unsigned int : 2;
	unsigned int a4 : 4;
}x = { 0x1f, 0x1fffff, 0x7, 0xf };

void main(void)
{
	printf("%d\n", sizeof(x));
	printf("0x%.8x\n", ((unsigned int *)&x)[0]);
	printf("0x%.8x\n", ((unsigned int *)&x)[1]);
	printf("0x%.8x\n", ((unsigned int *)&x)[2]);
}

#endif

/***********************************************************/
// [9-22] 공용체와 메모리 구성
/***********************************************************/

#if 0

#include <stdio.h>

union uni
{
	unsigned int a;
	unsigned char b;
}test = { 0 };

void main(void)
{
	printf("%d\n", sizeof(union uni));
	test.a = 0x12345678;
	test.b = 0xef;
	printf("%x\n", test.a);
}

#endif

/***********************************************************/
// [9-23] 공용체의 활용
/***********************************************************/

#if 0

#include <stdio.h>

union dbl_data
{
	unsigned int x[2];
	double d;

}d_data;

void main(void)
{
	d_data.d = 13.625;

	printf("%x:%x\n", d_data.x[1], d_data.x[0]);
	printf("%f\n", d_data.d);
}

#endif

/***********************************************************/
// [9-24] 공용체와 구조체
/***********************************************************/

#if 0

#include <stdio.h>

union float_data
{
	float f;

	struct
	{



	}bit;
}fdata;

void main(void)
{
	fdata.f = 13.625;

	printf("%f\n", fdata.f);
	printf("sign(1bit):%x\n", fdata.bit.sign);
	printf("exponent(8bit):%x\n", fdata.bit.exp);
	printf("mantissa(23bit):%x\n", fdata.bit.mant);

	fdata.bit.sign = 1;
	printf("%f\n", fdata.f);
}

#endif

/***********************************************************/
// [9-25] double의 인쇄
/***********************************************************/

#if 0

#include <stdio.h>

union double_data
{
	double d;

	struct
	{



	}bit;
}ddata;

void main(void)
{
	ddata.d = 13.625;

	printf("%f\n", ddata.d);
	printf("sign(1bit):%x\n", ddata.bit.sign);
	printf("exponent(11bit):%x\n", ddata.bit.exp);
	printf("mantissa(52bit):%llx\n", ddata.bit.mant);

	ddata.bit.sign = 1;
	printf("%f\n", ddata.d);
}

#endif

/***********************************************************/
// [9-26]  공용체의 비트필드 멤버
/***********************************************************/

#if 0

#include <stdio.h>

volatile union st
{
	unsigned int a1 : 5;
	unsigned int : 0;
	unsigned int a2 : 25;
	unsigned int : 0;
	unsigned int a3 : 3;
	unsigned int : 2;
	unsigned int a4 : 4;
}x = { 0x1f };

void main(void)
{
	printf("%d\n", sizeof(x));
	printf("0x%.8x\n", *(unsigned int *)&x);

	x.a2 = 0x1fffff;
	printf("0x%.8x\n", *(unsigned int *)&x);

	x.a3 = 0x2;
	x.a4 = 0xc;
	printf("0x%.8x\n", *(unsigned int *)&x);
	printf("0x%x, 0x%x, 0x%x, 0x%x\n", x.a1, x.a2, x.a3, x.a4);
}

#endif

#if 0

#include <stdio.h>

volatile union st
{
	unsigned int a1 : 5;
	unsigned int : 0;
	unsigned int a2 : 25;
	unsigned int : 0;

	struct
	{
		unsigned int a3 : 3;
		unsigned int : 2;
		unsigned int a4 : 4;
	}b;
}x = { 0x1f };

void main(void)
{
	printf("%d\n", sizeof(x));
	printf("0x%.8x\n", *(unsigned int *)&x);

	x.a2 = 0x1fffff;
	printf("0x%.8x\n", *(unsigned int *)&x);

	x.b.a3 = 0x2;
	x.b.a4 = 0xc;
	printf("0x%.8x\n", *(unsigned int *)&x);
	printf("0x%x, 0x%x, 0x%x, 0x%x\n", x.a1, x.a2, x.b.a3, x.b.a4);
}

#endif

/***********************************************************/
// [9-27]  FAT의 파일 종류 분석
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] = { 0x25, 0x0f };

struct fat_file
{
	unsigned char r : 1;
	unsigned char h : 1;
	unsigned char s : 1;
	unsigned char v : 1;
	unsigned char d : 1;
	unsigned char a : 1;
};

#define fn	((struct fat_file *)buf)

void main(void)
{
	int i;

	for (i = 0; i<2; i++)
	{
		if () printf("Long File Name\n");
		else printf("A[%d]D[%d]V[%d]S[%d]H[%d]R[%d]\n", fn[i].a, fn[i].d, fn[i].v, fn[i].s, fn[i].h, fn[i].r);
	}
}

#endif

/***********************************************************/
// [9-28]  효율적인 long file name의 판단
/***********************************************************/

#if 0

#include <stdio.h>

unsigned char buf[] = { 0x25, 0x0f };

struct fat_file
{
	unsigned char r : 1;
	unsigned char h : 1;
	unsigned char s : 1;
	unsigned char v : 1;
	unsigned char d : 1;
	unsigned char a : 1;
};

union file
{
	struct fat_file n;
	unsigned char l;
};

#define fn	((union file *)buf)

void main(void)
{
	int i;

	for (i = 0; i<2; i++)
	{
		if () printf("Long File Name\n");
		else printf("A[%d]D[%d]V[%d]S[%d]H[%d]R[%d]\n", fn[i].n.a, fn[i].n.d, fn[i].n.v, fn[i].n.s, fn[i].n.h, fn[i].n.r);
	}
}

#endif