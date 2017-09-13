// 이진탐색으로 예산문제 풀기
#if 0
#include <stdio.h>
#define MIN(x,y) (((x)<(y)) ? (x):(y))
int N, a[10000 + 10], M;
int Check(int m)
{
	// m 받은 예산.
	int i, sum = 0;
	for ( i = 1; i <=N; i++)
	{
		sum += MIN(a[i], m);
	}
	if (sum <= M) return 1;
	return 0;
}

int main(void)
{
	int i, s, e, m, sol, max=0;
	scanf("%d", &N);
	for ( i = 1; i <=N; i++)
	{
		scanf("%d", &a[i]);
		if (max < a[i]) max = a[i];
	}

	scanf("%d", &M);
	s = 0; e = max;

	while (s <= e){
		m = (s + e) / 2;
		if (Check(m)){ sol = m; s = m + 1; }
		else e = m - 1;
	}

	printf("%d", sol);
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
