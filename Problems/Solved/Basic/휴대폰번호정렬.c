
//	휴대폰번호 정렬
#if 01
#include <stdio.h>
typedef struct{
	int n1, n2, n3, digit;
}P_t;
P_t a[50 + 10];
int N, p[10 + 10];
int cmp(int i, int j){
	if (p[a[i].n1 % 10] < p[a[j].n1 % 10]) return -1;
	if (p[a[i].n1 % 10] > p[a[j].n1 % 10]) return 1;

	if (a[i].digit > a[j].digit) return -1;
	if (a[i].digit < a[j].digit) return 1;

	if (a[i].n2 < a[j].n2) return -1;
	if (a[i].n2 > a[j].n2) return 1;

	if (a[i].n3 < a[j].n3) return -1;
	if (a[i].n3 > a[j].n3) return 1;

	return 0;
}
char str[50 + 10][13 + 10];
int main(void){
	int i, j, d;
	P_t t;
	scanf("%d", &N);
	for (i = 1; i <= 6; i++){
		scanf("%d", &d);
		p[d] = i;
	}
	for (i = 0; i < N; i++) scanf("%s", &str[i][0]);
	for (i = 0; i < N; i++){
		sscanf(str[i], "%d-%d-%d", &a[i].n1, &a[i].n2, &a[i].n3);
		if (str[i][12] == '\0') a[i].digit = 3;
		else a[i].digit = 4;
	}
	for (i = 0; i < N - 1; i++){	//	오름차순 정렬
		for (j = i + 1; j < N; j++){
			if (cmp(i, j) == 1){
				t = a[i]; a[i] = a[j]; a[j] = t;
			}
		}
	}
	for (i = 0; i < N; i++){
		if (a[i].digit == 3) printf("%03d-%03d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
		else printf("%03d-%04d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
	}
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
