#include <stdio.h>


#if 0

unsigned int d[5000];

int main(void)
{
	// 여기서부터 작성
	int N, tmp;

	//freopen("test.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &d[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (d[i] > d[j])
			{
				tmp = d[i];
				d[i] = d[j];
				d[j] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", d[i]);
	}

	return 0;
}

#endif

// 작은 수 4개 찾기
#if 0

unsigned int d[30000];
int main(void)
{
	int N, tmp;

	//freopen("test.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &d[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (d[i] > d[j])
			{
				tmp = d[i];
				d[i] = d[j];
				d[j] = tmp;
			}
		}
	}


	for (int i = 0; i < 4; i++)
	{
		printf("%d ", d[i]);
	}

	return 0;
}

#endif


// 모범생
#if 0

typedef struct st
{
	int id;
	unsigned int score;
} ST;

ST sts[30000];

int main(void)
{
	// 여기서부터 작성

	int N;
	ST tmp;

	//freopen("test.txt", "r", stdin);

	scanf("%d", &N);


	for (int i = 0; i < N; i++)
	{
		sts[i].id = i + 1;
		scanf("%d", &sts[i].score);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (sts[i].score < sts[j].score)
			{
				tmp = sts[i];
				sts[i] = sts[j];
				sts[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", sts[i].id);
	}


	return 0;
}

#endif


// 합이 가장 큰 행과 열
#if 0
int a[4][5] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };
int row, col, s_r = 0x80000000, s_c = 0x80000000;
int main(void)
{

	for (int i = 0; i < 4; i++)
	{
		int r_tmp = 0;
		for (int j = 0; j < 5; j++)
		{
			r_tmp += a[i][j];
		}
		if (r_tmp > s_r)
		{
			row = i;
			s_r = r_tmp;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		int c_tmp = 0;
		for (int j = 0; j < 4; j++)
		{
			c_tmp += a[j][i];
		}
		if (c_tmp > s_c)
		{
			col = i;
			s_c = c_tmp;
		}
	}


	printf("%d %d", row+1, col+1);

	return 0;
}
#endif


// 색종이(초)
#if 0
#include <stdio.h>
#define SIZE 10
int canvas[100][100];
int N, area;
int main(void)
{
	// 여기서부터 작성
	//freopen("test.txt", "r", stdin);
	scanf("%d", &N);
	int x, y;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		for (int _x = 0; _x < SIZE; _x++)
		{
			for (int _y = 0; _y < SIZE; _y++)
			{
				canvas[x + _x][y + _y] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			area += canvas[i][j];
		}
	}

	printf("%d", area);

	return 0;
}
#endif


// 색종이(중)
#if 0
#include <stdio.h>
//#define _CRT_SECURE_NO_WARINIGS
#define SIZE 10
#define WIDTH 100
#define HEIGHT 100
int N;
int canvas[WIDTH + 10][HEIGHT + 10];
int cnt;
int main(void)
{
	//freopen("test.txt", "r", stdin);
	scanf("%d", &N);
	int x, y;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		for (int _x = 0; _x < SIZE; _x++)
		{
			for (int _y = 0; _y < SIZE; _y++)
			{
				canvas[x + _x][y + _y] = 1;
			}
		}
	}


	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (canvas[i][j])
			{
				if (canvas[i - 1][j] == 0) cnt++;
				if (canvas[i][j - 1] == 0) cnt++;
				if (canvas[i + 1][j] == 0) cnt++;
				if (canvas[i][j + 1] == 0) cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
#endif


// 숫자근
#if 0
typedef struct _root
{
	int origin;
	int root;
}Digit;

Digit digit[1000], min = {-1,-1};
int N;
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &digit[i].origin);
	}

	for (int i = 0; i < N; i++)
	{
		int tmp = digit[i].origin;
		while (digit[i].origin / 10)
		{
			digit[i].origin = digit[i].origin / 10 + digit[i].origin % 10;
		}
		digit[i].root = digit[i].origin;
		digit[i].origin = tmp;
		if (min.root < digit[i].root)
		{
			min = digit[i];
		}
		if (min.root == digit[i].root && min.origin > digit[i].origin)
		{
			min = digit[i];
		}
	}

	printf("%d", min.origin);

	return 0;
}
#endif


// 연속부분최대곱
#if 0
int N;
double d[10000 + 10];
double max;
int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &d[i]);
	}

	for (int i = 0; i < N; i++)
	{
		double tmp = 1.0;
		for (int j = i; j < N; j++)
		{
			tmp *= d[j];
			if (max < tmp)
			{
				max = tmp;
			}
		}
	}

	printf("%.3f", max);

	return 0;
}
#endif


#if 0
char m[100 + 10][100 + 10];
char p[100 + 10][100 + 10];
int S, P, cnt;
int match(int i, int j)
{
	for (int k = 0; k < P; k++)
	{
		for (int l = 0; l < P; l++)
		{
			if (m[i + k][j + l] != p[k][l]) return 0;
		}
	}
	return 1;
}
int main(void)
{
	//freopen("test.txt", "r", stdin);
	scanf("%d", &S);
	for (int i = 0; i < S; i++)
	{
		scanf("%s", m[i]);
	}

	scanf("%d", &P);
	for (int i = 0; i < P; i++)
	{
		scanf("%s", p[i]);
	}

	for (int i = 0; i < S-(P-1); i++)
	{
		for (int j = 0; j < S-(P-1); j++)
		{
			if (m[i][j] == p[0][0])
			{
				if (match(i, j)) cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
#endif

// 100만들기
#if 0
int d[9];
int main(void)
{

	int sum = 0, flag = 0, tmp = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &d[i]);
		sum += d[i];
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if (d[i] > d[j])
			{
				tmp = d[i];
				d[i] = d[j];
				d[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		int diff = 0;
		diff += d[i];
		for (int j = i+1; j < 9; j++)
		{
			diff += d[j];
			if ((sum - diff) == 100)
			{ 
				flag = !flag; 
				d[i] = 0;
				d[j] = 0;
				break; 
			}
			diff -= d[j];
		}
		if (flag) break;
	}

	

	for (int i = 0; i < 9; i++)
	{
		if (d[i] == 0) continue;
		printf("%d\n", d[i]);
	}

	return 0;
}
#endif


// 악수
#if 0
char m[50 + 5][50 + 5];
int R, C, max=0x80000000, maxi=54, maxj=54, shake;
int main(void)
{
	//freopen("test.txt", "r", stdin);
	scanf("%d %d", &R, &C);

	for (int i = 1; i < R+1; i++)
	{
		scanf("%s", &m[i][1]);
	}

	for (int i = 1; i < R+1; i++)
	{
		for (int j = 1; j < C+1; j++)
		{
			shake = 0;
			if (m[i][j] == 'o') continue;
			if ( m[i - 1][j - 1] == 'o') shake++;
			if (m[i - 1][    j] == 'o') shake++;
			if ( m[i - 1][j + 1] == 'o') shake++;
			if ( m[i    ][j + 1] == 'o') shake++;
			if (m[i    ][j - 1] == 'o') shake++;
			if ( m[i + 1][j - 1] == 'o') shake++;
			if ( m[i + 1][j    ] == 'o') shake++;
			if (m[i + 1][j + 1] == 'o') shake++;
			if (max < shake)
			{
				max = shake;
				maxi = i; maxj = j;
			}
		}
	}
	//printf("%d %d\n", maxi, maxj);

	m[maxi][maxj] = 'o';

	shake = 0;
	for (int i = 1; i < R + 1; i++)
	{
		for (int j = 1; j < C + 1; j++)
		{
			if (m[i][j] == 'o')
			{
				if (m[i - 1][j - 1] == 'o') shake++;
				if (m[i - 1][j] == 'o') shake++;
				if (m[i - 1][j + 1] == 'o') shake++;
				if (m[i][j + 1] == 'o') shake++;
				if (m[i][j - 1] == 'o') shake++;
				if (m[i + 1][j - 1] == 'o') shake++;
				if (m[i + 1][j] == 'o') shake++;
				if (m[i + 1][j + 1] == 'o') shake++;
				m[i][j] = '.';

			}
		}
	}

	printf("%d", shake);

	return 0;
}
#endif

// 최소 비용으로 포장 다시 하기
#if 0
int N, cost;
int ni[5000 + 50];

void sort(int s, int e)
{
	int tmp;
	for (int i = s; i < s+2; i++)
	{
		for (int j = i + 1; j < e; j++)
		{
			if (ni[i] > ni[j])
			{
				tmp = ni[i];
				ni[i] = ni[j];
				ni[j] = tmp;
			}
		}
	}
}
int Cost(int s, int e)
{
	if (s + 1 == e) 
	{
		cost += ni[0];
		return cost;
	}

	for (;;)
	{
		if (s == e - 1) break;
		sort(s, e);
		cost += (ni[s] + ni[s + 1]);
		ni[s + 1] += ni[s];
		ni[s] = 0;
		s++;
	}
	return cost;
}

int main(void)
{
	int s=0, e;
	//freopen("test.txt", "r", stdin);
	scanf("%d", &N);
	e = N;
	for (int i = 0; i < e; i++)
	{
		scanf("%d", &ni[i]);
	}

	cost = Cost(s, e);

	printf("%d", cost);

	return 0;
}
#endif


// 경비원
#if 0
#define ABS(a) (((a) < (0))?-(a):(a))
int W, H, S, round, sum;
typedef struct
{
	int x;
	int y;
} Pos;
Pos positions[110];
int square[110][110];
int pos, len;
int x, y;
void check(int pos, int len, int i)
{
	switch (pos)
	{
		case 1:
			x = 0; y = len;
			break;
		case 2:
			x = H; y = len;
			break;
		case 3:
			x = len; y = 0;
			break;
		case 4:
			x = len; y = W;
			break;
		default:
			break;
	}

	square[x][y] = 1;

	positions[i].x = x;
	positions[i].y = y;
}

int main(void)
{
	//freopen("test.txt", "r", stdin);
	scanf("%d %d", &W, &H);
	scanf("%d", &S);
	round = 2 * (W + H);

	for (int i = 0; i < S + 1; i++)
	{
		scanf("%d %d", &pos, &len);
		check(pos, len, i);
	}

	for (int i = 0; i < S; i++)
	{
		int len = 0, other = 0;

		if (ABS(positions[i].x - x) == H)
		{
			len = y + positions[i].y + H;
		}
		else if (ABS(positions[i].y - y) == W)
		{
			len = x + positions[i].x + W;
		}
		else
		{
			len = ABS(positions[i].x - x) + ABS(positions[i].y - y);
		}
		other = round - len;
		sum += (len > other)? other : len;
	}

	printf("%d", sum);

	return 0;
}
#endif

// 추가문제
// 고기잡이
#if 0
#include <stdio.h>

int N, l, M;
int x[100 + 10], y[100 + 10];
int max;

int main(void)
{
	int i;

	// 입력받는 부분
	scanf("%d %d %d", &N, &l, &M);

	for (i = 0; i<M; i++)
	{
		scanf("%d %d", &y[i], &x[i]);
	}

	// 여기서부터 작성

	// 출력하는 부분
	printf("%d", max);
	return 0;
}
#endif

//분수 정렬
#if 0
int N;
typedef struct fraction
{
	unsigned char numerator;
	unsigned char delimeter;
	double r;
}Frac;
Frac fracs[161*161], tmp;
int gcd(int a, int b)
{
	if (a%b == 0) return b;
	return gcd(b, a%b);
}
int main(void)
{
	double cursor = -1.0;
	// 입력받는 부분
	scanf("%d", &N);

	// 여기서부터 작성
	for (int i = 0; i < N+1; i++)
	{
		for (int j = 0; j < N+1; j++)
		{
			fracs[i*(N + 1) + j].numerator = i;
			fracs[i*(N + 1) + j].delimeter = j;
			if (fracs[i*(N + 1) + j].delimeter != 0) fracs[i*(N + 1) + j].r = (double)i / j;
		}
	}

	for (int i = 0; i < (N + 1)*(N + 1) - 1; i++)
	{
		for (int j = i + 1; j < (N + 1)*(N + 1); j++)
		{
			if (fracs[i].r > fracs[j].r)
			{
				tmp = fracs[i];
				fracs[i] = fracs[j];
				fracs[j] = tmp;
				if (fracs[i].numerator > fracs[j].delimeter);
			}
		}
	}


	for (int i = 0; i < (N+1)*(N+1); i++)
	{
		if (fracs[i].delimeter == 0) continue;
		if (fracs[i].r > cursor && fracs[i].r <1.0)
		{
			cursor = fracs[i].r;
			printf("%d/%d\n", fracs[i].numerator / gcd(fracs[i].numerator, fracs[i].delimeter), fracs[i].delimeter / gcd(fracs[i].numerator, fracs[i].delimeter), fracs[i].r);
		}
		if (fracs[i].r == 1.0)
		{
			printf("1/1\n");
			break;
		}
	}

	return 0;
}
#endif

// 회전 초밥(중)
#if 0

#endif

// 문제 번호 A: [LAB]고기잡이
#if 1
#include <stdio.h>

int N, l, M;
char monun[10010][10010];
unsigned short r[100 + 10], c[100 + 10];
int max=0x80000000;

int find_match_cnt(int minr, int minc, int maxr, int maxc, int h, int w)
{
	int cnt, max = 0x80000000;
	int i, j, k, l;
	for (i = minr; i < maxr - (h-1); i++)
	{
		for (j = minc; j < maxc + 1 - (w-1); j++)
		{
			if (!monun[i][j]) continue;
			cnt = 0;
			for ( k = i; k < i+h+1; k++)
			{
				for ( l = j; l < j+w+1; l++)
				{
					if (monun[k][l]) cnt++;
				}
			}

			if (max < cnt) max = cnt;
		}
	}

	for (i = maxr - (h - 1); i < maxr + 1 - (h - 1); i++)
	{
		for (j = minc; j < maxc + 1 - (w - 1); j++)
		{
			cnt = 0;
			for (k = i; k < i + h + 1; k++)
			{
				for (l = j; l < j + w + 1; l++)
				{
					if (monun[k][l]) cnt++;
				}
			}

			if (max < cnt) max = cnt;
		}
	}

	return max;
}

int main(void)
{
	int i, h, w, sum, cnt, minr = 0x7fffffff, minc = 0x7fffffff;
	int maxr = 0x80000000, maxc = 0x80000000;
	//freopen("test.txt", "r", stdin);
	
	// 입력받는 부분
	scanf("%d %d %d", &N, &l, &M);

	for (i = 0; i<M; i++)
	{
		scanf("%d %d", &r[i], &c[i]);
	}

	// 좌표 표시하기.
	for (int i = 0; i < M; i++)
	{
		monun[r[i]][c[i]] = 1;
		if (minr > r[i]) minr = r[i];
		if (minc > c[i]) minc = c[i];
		if (maxr < r[i]) maxr = r[i];
		if (maxc < c[i]) maxc = c[i];
	}


	// 여기서부터 작성
	sum = l / 2;
	h = 1; w = sum - h;
	while (1)
	{
		cnt = find_match_cnt(minr, minc, maxr,maxc, h, w);
		if (max < cnt)
		{
			max = cnt;
			// 가장 넓은 영역에 매치할 때 멈춤. 
			if (max == (sum / 2 * (sum - sum / 2))) break;
		}
		h++; w = sum - h;
		if (h == sum) break;
	}



	// 출력하는 부분
	printf("%d", max);
	return 0;
}
#endif