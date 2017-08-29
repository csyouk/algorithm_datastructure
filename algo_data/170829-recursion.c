// 1~n 합
#if 0
#include <stdio.h>
int sum(int n)
{
	if (n == 1) return 1;
	return n + sum(n - 1);
}

int main(void)
{
	// 여기서부터 작성
	int N;
	scanf("%d", &N);
	
	printf("%d", sum(N));

	return 0;
}
#endif

// 피보나치수열
#if 0
#define ULL unsigned long long int
ULL memo[50];
ULL fib(n)
{
	if (n == 1) return 1;
	else
	{
		if (memo[n-1]) return memo[n-1];
		else
		{
			memo[n-1] = fib(n - 1);
			return memo[n - 1] + memo[n-2];
		}
	}
}
int main(void)
{
	// 여기서부터 작성
	int N;
	scanf("%d", &N);
	printf("%llu", fib(N));
	return 0;
}
#endif

// 문제 번호 P: [TST]최대공약수와최소공배수
#if 0
int gcd(a, b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
int lcm(a, b)
{
	return a*b / gcd(a, b);
}
int main(void)
{
	// 여기서부터 작성
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", gcd(a,b));
	printf("%d", lcm(a, b));
	return 0;
}
#endif

// 문제 번호 Q: [TST]오름차순 정렬 (퀵정렬)
#if 0
int N;
unsigned int nums[30000 + 10];
void quick_sort(unsigned int *d, int s, int e)
{
	int pivot, left, target, tmp;
	target = s;
	pivot = e;

	if (e <= s) return;

	for (left = s; left < e; left++)
	{
		if (d[left] < d[pivot])
		{
			if (left != target)
			{
				tmp = d[left];
				d[left] = d[target];
				d[target] = tmp;
			}
			target++;
		}
	}

	if (target < pivot)
	{
		tmp = d[target];
		d[target] = d[pivot];;
		d[pivot] = tmp;
	}


	quick_sort(d, s, target - 1);
	quick_sort(d, target + 1, e);
}

int main(void)
{
	// 여기서부터 작성

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lu", &nums[i]);
	}

	quick_sort(nums,0,N-1);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", nums[i]);
	}

	return 0;
}
#endif


// 문제 번호 R: [TST] 숫자 찾기 (이진탐색)
#if 0
#include <stdio.h>
int N, T;
int data[50000 + 10];
int target[10000 + 10];
int BinSearch(int *d, int t, int s, int e)
{
	int mid = (s + e) / 2;
	if (mid == s) return mid;
	if (t < d[mid])
	{
		BinSearch(d, t, s, mid);
	}
	else
	{
		BinSearch(d, t, mid, e);
	}
}
int main(void)
{
	//freopen("test.txt", "r", stdin);
	// 여기서부터 작성
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &data[i]);
	}

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &target[i]);
	}


	for (int i = 0; i < T; i++)
	{
		int result = BinSearch(data, target[i], 0, N - 1);
		//printf("%d, %d, %d\n", result, data[result], target[i]);
		printf("%d\n", (data[result] == target[i])? result+1 : 0);
	}

	return 0;
}
#endif

// 문제 번호 S: [TST]그릇
#if 0
#include <stdio.h>
char d[55];
int main(void)
{
	// 여기서부터 작성
	char *prev = d + 54;
	char *p = d;
	int h = 0;
	//freopen("test.txt", "r", stdin);
	scanf("%s", d);

	while (*p)
	{
		if (*prev == *p)
		{
			h += 5;
		}
		else
		{
			h += 10;
		}
		prev = p;
		p++;
	}

	printf("%d", h);


	return 0;
}
#endif

// 문제 번호 T: [TST]가장 많은 알파벳은?
#if 0
#include <stdio.h>
#include <string.h>
int l_alpha[26];
char d[31];
int main(void)
{
	int max = -1, pos = -1;
	// 여기서부터 작성
	scanf("%s", d);

	for (int i = 0; i < strlen(d); i++)
	{
		if ('a' <= d[i] && d[i]<= 'z')
		{
			l_alpha[d[i] - 'a']++;
		}
	}

	for (char s = 'a'; s < 'z'+1; s++)
	{
		if (max < l_alpha[s - 'a'])
		{
			max = l_alpha[s - 'a'];
			pos = s - 'a';
		}
	}

	printf("%c", pos+'a');

	return 0;
}
#endif


// 문제 번호 U: [TST]휴대폰번호 정렬
#if 0
#include <stdio.h>
#include <assert.h>
#define O_SIZE 6
#define ASCENDING 1
typedef struct _user
{
	unsigned short base;
	unsigned short middle;
	unsigned char m_digit;
	unsigned short last;
	char b_origin[5];
	char m_origin[5];
	char l_origin[5];
} User;
User users[50];
char phone[50][15];
int o_cnt[O_SIZE];
int N;
int order[O_SIZE];
int strlen(char *p)
{
	int len = 0;
	while (*p) { len++; p++; }
	return len;
}
void strcpy(char *s, int start, int end, char *d)
{
	s = s + start;
	for (int i = start; i < end+1; i++)
	{
		*d = *s;
		s++; d++;
	}
}
int strcmp(char *p, char *q)
{
	while (*p || *q)
	{
		if (*p == *q) { p++; q++; continue; }
		return (*p > *q) ? 1 : -1;
	}
	return 0;
}
int stoi(char *p, int s, int e)
{
	int r = 0;
	p = p + s;
	while (s != (e+1))
	{
		r = (*p-'0') + r * 10;
		s++; p++;
	}
	return r;
}
void tokenize(char * phones, int i)
{
	unsigned short b, m, l, d, len;
	len = strlen(phones);
	if (len == 13) // 13자리
	{
		b = stoi(phones, 0, 2);
		m = stoi(phones, 4, 7);
		l = stoi(phones, 9, 12);
		strcpy(phones, 0, 2, users[i].b_origin);
		strcpy(phones, 4, 7, users[i].m_origin);
		strcpy(phones, 9, 12, users[i].l_origin);
		d = 4;
	}
	else // 12자리
	{
		b = stoi(phones, 0, 2);
		m = stoi(phones, 4, 6);
		l = stoi(phones, 8, 11);
		strcpy(phones, 0, 2, users[i].b_origin);
		strcpy(phones, 4, 6, users[i].m_origin);
		strcpy(phones, 8, 11, users[i].l_origin);

		d = 3;
	}
	users[i].base = b; users[i].middle = m; 
	users[i].last = l; users[i].m_digit = d;
}
int accum(int n)
{
	if (n < 0) return 0;
	int r = 0;
	for (int i = 0; i < n+1; i++)
	{
		r += o_cnt[i];
	}
	return r;
}
void sort_base()
{
	int pos = 0, cnt;
	User tmp;
	for (int i = 0; i < O_SIZE; i++)
	{
		cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (order[i] == users[j].base % 10)
			{
				tmp = users[pos];
				users[pos] = users[j];
				users[j] = tmp;
				pos++; cnt++;
			}
		}
		o_cnt[i] = cnt;
	}
}

void sort_middle(void)
{
	int s,e;
	User tmp;
	for (int i = 0; i < O_SIZE; i++)
	{
		s = accum(i - 1); 
		e = accum(i);
		for (int j = s; j < e-1; j++)
		{
			for (int k = j+1; k < e; k++)
			{
				if (users[j].m_digit < users[k].m_digit)
				{
					tmp = users[k];
					users[k] = users[j];
					users[j] = tmp;
				}
				if (users[j].m_digit == users[k].m_digit && strcmp(users[j].m_origin, users[k].m_origin) == ASCENDING)
				{
					tmp = users[k];
					users[k] = users[j];
					users[j] = tmp;
				}
			}
		}
	}
}

void sort_last(void)
{
	int s, e;
	User tmp;
	for (int i = 0; i < O_SIZE; i++)
	{
		s = accum(i - 1);
		e = accum(i);
		for (int j = s; j < e - 1; j++)
		{
			for (int k = j + 1; k < e; k++)
			{
				if (strcmp(users[j].m_origin, users[k].m_origin) == 0 && strcmp(users[j].l_origin, users[k].l_origin) == 1)
				//if (users[j].middle == users[k].middle && users[j].last > users[k].last)
				{
					tmp = users[k];
					users[k] = users[j];
					users[j] = tmp;
				}
			}
		}
	}
}
void test0829(void)
{
	char test[] = "012-467-8892";
	assert(12 == stoi(test, 0, 2));
	assert(467 == stoi(test, 4, 6));
	assert(8892 == stoi(test, 8, 11));
}
int main(void)
{
	//test0829();
	 //여기서부터 작성
	//freopen("test.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &order[i]);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%s", phone[i]);
		tokenize(phone[i], i);
	}

	sort_base();
	sort_middle();
	sort_last();

	for (int i = 0; i < N; i++)
	{
		printf("%s-%s-%s\n", users[i].b_origin, users[i].m_origin, users[i].l_origin);
	}
	return 0;
}
#endif


// 문제 번호 U: [TST]문자열 압축
#if 0
#include <stdio.h>
int N;
char d[110];
int main(void)
{
	char *prev = d + 109;
	char *p = d;
	int cnt = 0;
	//freopen("test.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%s", d);

	while (*p)
	{
		if (*prev != *p)
		{
			if (cnt >= N) printf("%c(%d)", *prev, cnt);
			else
			{
				for (int i = 0; i < cnt; i++)
				{
					printf("%c", *prev);
				}
			}
			cnt = 0;
		}
		*prev = *p;
		p++;
		cnt++;
	}
	if (cnt >= N) printf("%c(%d)", *prev, cnt);
	else
	{
		for (int i = 0; i < cnt; i++)
		{
			printf("%c", *prev);
		}
	}

	return 0;
}
#endif


// 문제 번호 V: [TST]주차요금
#if 0
#include <stdio.h>
int n;
int rule(int min)
{
	if (min < 10) return 0;
	if (min <= 30) return 500;
	int t = 500;
	min -= 31;
	t += (min / 10 + 1)*300;

	if (t > 50000) t = 50000;
	return t;
}
int main(void)
{
	// 여기서부터 작성
	int fee = 0, d;
	//freopen("test.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d);
		fee += rule(d);
	}
	printf("%d", fee);
	return 0;
}
#endif


// 문제 번호 W: [TST]분수의 합 구하기
#if 0
#include <stdio.h>
typedef struct _fraction
{
	short numerator;
	unsigned short delimeter;
} Frac;

Frac fractions[100];
int n;

int gcd(a, b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
int lcm(a, b)
{
	if (a == 0 || b == 0) return 0; 
	return a*b / gcd(a, b);
}
int main(void)
{
	// 여기서부터 작성
	int D=1, N=0, _gcd=0;

	freopen("test.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &fractions[i].numerator, &fractions[i].delimeter);
	}

	for (int i = 0; i < n; i++)
	{
		D = lcm(D, fractions[i].delimeter);
	}
	for (int i = 0; i < n; i++)
	{
		if (fractions[i].numerator == 0) continue;
		N += (D / fractions[i].delimeter) * fractions[i].numerator;
	}

	_gcd = gcd(D,N);

	if (_gcd == 0 || N/_gcd==0) printf("%d", 0);
	else {
		if (D / _gcd < 0) { printf("%d/%d", -N / _gcd, -D / _gcd); }
		else{ printf("%d/%d", N / _gcd, D / _gcd); }
	}

	return 0;
}
#endif


// 문제 번호 Z: [TST]예산
#if 0
#include <stdio.h>
int N;
unsigned int budget[10000];
unsigned int upper_bound(unsigned int total_budget, int n)
{
	unsigned int tmp, tmp_b=0xffffffff, ub, max_ub=0, i = 1, backup, flag=0;
	if (n == 1) return total_budget;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (budget[i] > budget[j])
			{
				tmp = budget[i];
				budget[i] = budget[j];
				budget[j] = tmp;
			}
		}
	}

	while (1)
	{
		backup = total_budget;
		for (int j = 0; j < i; j++)
		{
			total_budget -= budget[j];
		}
		ub = total_budget / (n - i);
		for (int j = 0; j < i; j++)
		{
			if (budget[j] > ub) { flag = !flag; break; }
		}
		if (flag) break;
		for (int j = i; j < n; j++)
		{
			int b;
			if (ub < budget[j]) 
			{ 
				b = ub; 
			}
			else
			{ 
				b = budget[j]; 
			}
			total_budget -= b;
		}
		


		if (tmp_b > total_budget)
		{
			tmp_b = total_budget;
			max_ub = ub;
		}
		total_budget = backup;
		i++;
		if (n == i) break;
	}
	return max_ub;
}
int main(void)
{
	// 여기서부터 작성
	unsigned int total, max=0, sum=0;

	freopen("test.txt", "r", stdin);

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%u", &budget[i]);
		sum += budget[i];
		if (max < budget[i]) max = budget[i];
	}
	scanf("%u", &total);

	if (total > sum)
	{
		printf("%u", max);
	}
	else
	{
		max = upper_bound(total, N);
		printf("%u", max);
	}

	return 0;
}
#endif

