// 하노이
//void Hanoi(int n, int s, int t, int e)
//{
//	if (n < 1) return;
//	Hanoi(n - 1, s, e, t);
//	printf("%d : %d -> %d\n", n, s, e);
//	Hanoi(n - 1, t, s, e);
//}




// 문제 번호 : [TST]미로 탈출 로봇
#if 0
#include <stdio.h>
#define SIZE 110
#define DIRS 4
typedef struct _pos{
	int x;
	int y;
} Pos;

Pos S, E;

int map[SIZE][SIZE];
int chk[SIZE][SIZE];
int di[DIRS] = { 0, -1, 0, 1 };
int dj[DIRS] = { -1, 0, 1, 0 };
int X, Y, min = 0x80000000;
void Init(void)
{
	int i, j;
	for (i = 0; i <SIZE; i++)
	{
		for (j = 0; j <SIZE; j++)
		{
			map[i][j] = -1;
		}
	}
}

//void Find(int i, int j, int dis)
//{
//	int ni, nj, k;
//	if (i == E.x && j == E.y) {
//		if (chk[i][j] == 0){
//			chk[i][j] = dis;
//		}
//		if (dis < chk[i][j]){
//			chk[i][j] = dis;
//		}
//		return;
//	}
//	map[i][j] = -1;
//	chk[i][j] = dis;
//
//
//	for ( k = 0; k < DIRS; k++)
//	{
//		ni = i + di[k]; nj = j + dj[k];
//		if (map[ni][nj] == 0 && chk[ni][nj] == 0)
//		{
//			Find(ni, nj, dis + 1);
//		}
//		if (chk[ni][nj] != 0 && chk[ni][nj] > chk[i][j])
//		{
//			Find(ni, nj, chk[i][j]+1);
//		}
//	}
//
//}

void Find_BruteForce(int x, int y)
{

}
int main(void)
{
	// 여기서부터 작성
	freopen("in.txt", "r", stdin);
	int x, y,i,j, dis= 0;
	Init();
	scanf("%d %d", &Y , &X);

	scanf("%d %d %d %d", &S.y, &S.x, &E.y, &E.x);

	for ( i = 1; i <=X; i++)
	{
		for ( j = 1; j <=Y; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}


	//Find(S.x, S.y, dis);
	Find_BruteForce(S.x, S.y);


	printf("%d", chk[E.x][E.y]);
	return 0;
}

#endif


// 문제 번호 : [TST]3이 없는 나라
#if 0
#include <stdio.h>
#define ULL unsigned long long int
#define DIGITS 13
#define SIZE 11
ULL table[DIGITS][SIZE+3];


ULL pow(int b, int e)
{
	ULL r = 1;
	while (e)
	{
		r *= b;
		e--;
	}
	return r;
}
void create_lookuptable(void)
{
	ULL tmp;
	int i, j;
	table[1][1] = 1;
	table[1][SIZE] = 1;
	for ( i = 2; i < DIGITS; i++)
	{
		for ( j = 1; j < SIZE; j++)
		{
			table[i][j] = table[i - 1][SIZE];
			if (j == 3+1) table[i][j] = pow(10, i - 1);
			table[i][SIZE] += table[i][j];
		}
	}
}
ULL conv(ULL num)
{
	int w = 1, add = 0, digit = 1, quot, r, c;
	int first = num % 10;
	if (first > 2) add++;
	num -= first; w = pow(10, digit);
	while (num)
	{
		quot = num / w % 10;
		digit++;

		for (c = 1; c <=quot; c++)
		{
			add += table[digit][c];
			//printf("%d %d\n", digit, c);
		}
		num -= pow(10, digit - 1)*quot;
		w = pow(10, digit);
	}


	return add;
}
int main(void)
{
	// 여기서부터 작성
	ULL num;
	create_lookuptable();
	scanf("%llu", &num);

	printf("%llu", num - conv(num));
	
	return 0;
}
#endif

