// 1~n ��
#if 0
#include <stdio.h>
int sum(int n)
{
	if (n == 1) return 1;
	return n + sum(n - 1);
}

int main(void)
{
	// ���⼭���� �ۼ�
	int N;
	scanf("%d", &N);
	
	printf("%d", sum(N));

	return 0;
}
#endif

// �Ǻ���ġ����
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
	// ���⼭���� �ۼ�
	int N;
	scanf("%d", &N);
	printf("%llu", fib(N));
	return 0;
}
#endif

// ���� ��ȣ P: [TST]�ִ��������ּҰ����
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
	// ���⼭���� �ۼ�
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", gcd(a,b));
	printf("%d", lcm(a, b));
	return 0;
}
#endif

// ���� ��ȣ Q: [TST]�������� ���� (������)
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
	// ���⼭���� �ۼ�

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


// ���� ��ȣ R: [TST] ���� ã�� (����Ž��)
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
	// ���⼭���� �ۼ�
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

// ���� ��ȣ S: [TST]�׸�
#if 0
#include <stdio.h>
char d[55];
int main(void)
{
	// ���⼭���� �ۼ�
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

// ���� ��ȣ T: [TST]���� ���� ���ĺ���?
#if 0
#include <stdio.h>
#include <string.h>
int l_alpha[26];
char d[31];
int main(void)
{
	int max = -1, pos = -1;
	// ���⼭���� �ۼ�
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


// ���� ��ȣ U: [TST]�޴�����ȣ ����
#if 1
#include <stdio.h>

int main(void)
{
	// ���⼭���� �ۼ�

	return 0;
}
#endif
