#include <stdio.h>
//#include <time.h>
#include <assert.h>

#if 1
int val[200][3] = { 0 };
int player[200];
int main(void)
{
	//0
	//84
	//99
	//120
	//46
	//133
	//61
	//132
	//184
	//74
	freopen("test170814-3.txt", "r", stdin);
	int N;
	scanf("%d", &N);


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &val[i][j]);
		}
	}

	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < N; k++)
		{
			if (val[0][j] == val[0][k]) continue;
			if (val[0][j] == val[0][k]) continue;
			//player[j] += val[j];
		}
		//if (val[j][0] != val[j][1] && val[j][0] != val[j][2])
		//{
		//	player[j] += val[j][0];
		//}
		//if (val[j][1] != val[j][0] && val[j][1] != val[j][2])
		//{
		//	player[j] += val[j][1];
		//}
		//if (val[j][2] != val[j][0] && val[j][2] != val[j][1])
		//{
		//	player[j] += val[j][2];
		//}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", player[i]);
	}

	return 0;
}

#endif

#if 0
int memo[90];
unsigned long long int f(int n)
{
	if (n == 1 || n == 2) return memo[n] = 1;
	if (memo[n] != 0) return memo[n];

	return memo[n] = f(n - 1) + f(n - 2);
}

int main(void)
{
	// 여기서부터 작성
	int N;
	scanf("%d", &N);
	printf("%llu", f(N));
	//printf("%d", f(N));
	return 0;
}

#endif

#if 0
int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		if (i % 2) // 홀수
		{
			for (int j = N; j > 0; j--)
			{
				printf("%d ", i*N + j);
			}
		}
		else
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d ", i*N + 1 + j);
			}
		}
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int val[10];
int main(void)
{
	int N;
	int *p = val;
	p++;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &val[i]);
	}

	while (p != &val[0])
	{
		if (p == &val[N]) {
			p = &val[0];
			printf("%d", *p);
			break;
		}
		printf("%d ", *p);
		p++;
	}



	return 0;
}
#endif

#if 0
typedef struct{
	char id;
	int cnt;
} ALPHA;
ALPHA alpha[26];
char val[31];

int main(void)
{
	ALPHA tmp;
	char *p = val;
	scanf("%s", val);

	for (int i = 0; i < 26; i++)
	{
		(alpha + i)->id = 'a' + i;
	}

	while (*p)
	{
		if ('a' <= *p && *p <= 'z'){
			(alpha + (*p) - 'a')->cnt++;
		}
		p++;
	}


	for (int i = 0; i < 25; i++)
	{
		for (int j = i; j < 26; j++)
		{
			if (alpha[i].cnt < alpha[j].cnt)
			{
				tmp = alpha[i];
				alpha[i] = alpha[j];
				alpha[j] = tmp;

			}
		}
	}

	//for (int i = 0; i < 26; i++)
	//{
	//	printf("%c %d\n", alpha[i].id, alpha[i].cnt);
	//}
	printf("%c", alpha[0].id);


	return 0;
}

#endif


#if 0
int digits(int a)
{
	int length = 0;
	while (a)
	{
		a /= 10;
		length++;
	}
	return length;
}
int nums[100000];
int main(void)
{
	int N;
	int total1 = 0, total2 = 0, total3 = 0;

	`
		scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &nums[i]);
	}

	for (int i = 0; i < N; i++)
	{
		switch (digits(nums[i]))
		{
		case 1: total1 += nums[i]; break;
		case 2: total2 += nums[i]; break;
		case 3: total3 += nums[i]; break;
		}
	}

	printf("%d %d %d", total3, total2, total1);

	return 0;
}

#endif

#if 0
int main(void)
{
	int N;
	int total = 0;
	int i = 0;
	scanf("%d", &N);

	while (total < 10000)
	{
		i++;
		total += N*i;
	}
	printf("%d", N*(i - 1));

	return 0;
}

#endif


#if 0

#include <stdio.h>
typedef struct {
	int id;
	int total;
	int ping;
	int bad;
	int ball;
	int pocket;

} P;
P p[10];

int main(void)
{
	int N;

	//freopen("test170814-3.txt", "r",stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d%d%d", &p[i].id, &p[i].ping, &p[i].bad, &p[i].ball, &p[i].pocket);
	}



	for (int i = 0; i < N; i++)
	{
		p[i].total = p[i].ping + p[i].bad + p[i].ball + p[i].pocket;
	}


	P tmp;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (p[i].total < p[j].total)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i; j < N; j++)
		{
			if ((p[i].total == p[j].total) && (p[i].id > p[j].id))
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}


	//for (int i = 0; i < N; i++)
	//{
	//	printf("%d %d %d %d %d %d\n", p[i].id, p[i].ping, p[i].bad, p[i].ball, p[i].pocket, p[i].total);
	//}
	int gold_p = 0, silver_p = 0, bronze_p = 0;

	printf("GOLD :");
	while (1)
	{
		if (p[0].total == p[gold_p].total){
			printf(" %d", p[gold_p].id);
			gold_p++;
			continue;
		}
		break;
	}
	printf("\n");





	printf("SILVER :");
	while (1)
	{
		if (gold_p + silver_p >= N) break;
		if (p[gold_p].total == p[gold_p + silver_p].total){
			printf(" %d", p[gold_p + silver_p].id);
			silver_p++;
			continue;
		}
		break;
	}
	printf("\n");


	printf("BRONZE :");
	while (1)
	{
		if (gold_p + silver_p + bronze_p >= N) break;
		if (p[gold_p + silver_p].total == p[gold_p + silver_p + bronze_p].total){
			printf(" %d", p[gold_p + silver_p + bronze_p].id);
			bronze_p++;
			continue;
		}
		break;
	}


	return 0;
}

#endif

#if 0

#include <stdio.h>
int sum(int n)
{
	int total = 0;
	while (n)
	{
		total += n;
		n--;
	}
	return total;
}


int find_k(int sum, int given, int N)
{
	// return -1 when error
	int diff = sum - given;
	if ((diff + 1) % 4) return -1;
	if ((diff + 1) / 2 > N) return -1;
	int k = (diff + 1) / 4;
	return k;
}

void test()
{
	assert(55 == sum(10));
	assert(66 == sum(11));
	assert(1 == sum(1));
	assert(5050 == sum(100));
	assert(406 == sum(28));
	assert(3 == find_k(sum(10), 44, 10));
	assert(-1 == find_k(sum(150), 11028, 150));

	assert(1 == find_k(sum(10), 52, 10));
	assert(50 == find_k(sum(100), 4851, 100));
	assert(-1 == find_k(sum(100), 4852, 100));
	assert(-1 == find_k(sum(28), 347, 28));
}
int main(void)
{
	int N, given_sum;
	scanf("%d %d", &N, &given_sum);
	int k = find_k(sum(N), given_sum, N);

	if (k == -1)
	{
		printf("Error");
	}
	else
	{
		printf("%d %d", 2 * k - 1, 2 * k);
	}

	test();




	return 0;
}

#endif


#if 0

#include <stdio.h>


int gcd_two(int a, int b)
{
	int r = 1;
	while (r)
	{
		r = a % b;
		if (r == 0) return b;
		a = b;
		b = r;
	}

}

int lcm_two(int a, int b)
{
	int gcd = gcd_two(a, b);
	return gcd*(b / gcd)*(a / gcd);
}

int lcm(int gcd, int *p, int cnt)
{
	int r = p[0];
	for (int i = 1; i < cnt; i++)
	{
		if (!(r%p[i])) continue;
		r = lcm_two(r, p[i]);

	}

	return r;
}

int gcd(int *val, int cnt)
{
	int i;
	int size = cnt;
	int gcd = 0;

	for (i = 0; i < size - 1; i++)
	{
		if (!gcd)
		{
			gcd = gcd_two(val[i], val[i + 1]);
		}
		else
		{
			gcd = gcd_two(gcd, val[i + 1]);
		}
	}
	return gcd;
}
void test()
{
	assert(27 == lcm_two(27, 9));
	assert(9 * 9 * 10 == lcm_two(81, 90));

	int test1[] = { 243, 270, 270 };
	assert(27 * 9 * 10 == lcm(27, test1, 3));

	int test2[] = { 243, 270, 270, 108 };
	assert(27 * 9 * 10 * 2 == lcm(27, test2, 4));

	int test3[] = { 243, 270, 270, 108, 54, 189, 297 };
	assert(27 * 9 * 10 * 2 * 7 * 11 == lcm(27, test3, 7));
}

int main(void)
{
	int n;
	int val[10];

	//freopen("test170814-3.txt", "r",stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val[i]);
	}

	test();
	int gcdr = gcd(val, n);
	int lcdr = lcm(gcdr, val, n);

	printf("%d %d", gcdr, lcdr);

	return 0;
}

#endif



#if 0


#include <stdio.h>

int main(void)
{
	int a, b;
	int gcd, lcm;
	scanf("%d%d", &a, &b);

	for (gcd = b / 2; gcd > 0; gcd--)
	{
		if (b % gcd == 0 && a % gcd == 0) break;
	}

	if (a == b)
	{
		printf("%d\n", a);
		printf("%d", a);
	}
	else
	{
		printf("%d\n", gcd);
		printf("%d", gcd*(b / gcd)*(a / gcd));
	}




	return 0;
}


#endif

#if 0
#include <malloc.h>
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

double get_std(int *price, int avg, int cnt)
{
	double sqrsum_of_deviation = 0;

	for (int i = 0; i < cnt; i++)
	{
		int tmp = (price[i] - avg);
		sqrsum_of_deviation += (double)tmp*tmp;
	}

	return sqrt(sqrsum_of_deviation / cnt);
}

void pprint(double d)
{
	int digit = (d + 0.05) * 10;
	if (digit % 10)
	{
		printf("%.1lf\n", d);
	}
	else
	{
		printf("%.lf\n", d);
	}
}

int main(void)
{
	//freopen("test170814-3.txt", "r", stdin);

	int num;

	int total = 0;
	double avg = 0;
	double std = 0;

	scanf("%d", &num);


	int * price = malloc(num*sizeof(int));


	for (int i = 0; i < num; i++)
	{
		scanf("%d", &price[i]);
	}

	for (int i = 0; i < num; i++)
	{
		total += price[i];
	}

	avg = (double)total / num;

	std = get_std(price, avg, num);


	printf("%d\n", total);

	pprint(avg);
	pprint(std);
	//printf("%.1lf\n", avg);
	//printf("%.1lf", std);


	return 0;
}


#endif

#if 0
int main(void)
{
	freopen("test170814-3.txt", "r", stdin);

	int	l1s, l1e, l2s, l2e, tmp;

	scanf("%d%d", &l1s, &l1e);
	scanf("%d%d", &l2s, &l2e);


	if (l1s > l1e)
	{
		tmp = l1s;
		l1s = l1e;
		l1e = tmp;
	}

	if (l2s > l2e)
	{
		tmp = l2s;
		l2s = l2e;
		l2e = tmp;
	}

	if (l1s > l2s)
	{
		tmp = l1s;
		l1s = l2s;
		l2s = tmp;

		tmp = l2e;
		l2e = l1e;
		l1e = tmp;
	}


	if ((l1s <= l2s && l2s <= l1e) && ((1 <= l2e && l2e <= l1s) || l1e <= l2e))
	{
		printf("cross");
	}
	else {
		printf("not cross");
	}


	return 0;
}

#endif

#if 0
//1. 5일간의 시간외 근무 시작 시각 s와 종료 시각 e가 주어진다. (16.0 <= s <= e <= 24.0)
//2. 30분 단위로 입력이 가능하며, 30분은 0.5로 입력된다. (예를 들어, 16시 30분은 16.5로 표기)
#define WEEK 5
#define BONUS 5000
int cal(double *p)
{
	double work_time = 0;
	double total_t = 0;
	double reward = 0;

	for (int i = 0; i < WEEK; i++)
	{
		work_time = p[2 * i + 1] - p[2 * i];
		if (work_time< 1.0) continue;
		if ((work_time) >= 5.0) {
			total_t += 4.0;
			continue;
		}
		total_t += p[2 * i + 1] - p[2 * i] - 1.0;
	}

	//printf("%f", work_time);

	if (total_t >= 15.0)
	{
		reward = ((total_t * 2) * BONUS)*(0.95);
	}
	if (total_t <= 5.0)
	{
		reward = ((total_t * 2) * BONUS)*(1.05);
	}
	if (5.0 < total_t && total_t < 15.0)
	{
		reward = ((total_t * 2) * BONUS);
	}

	return (int)reward;
}

int main(void)
{
	double times[WEEK * 2] = { 0 };
	double *p = times;


	freopen("test170814-3.txt", "r", stdin);

	for (int i = 0; i < WEEK; i++)
	{
		scanf("%lf %lf", &times[2 * i], &times[2 * i + 1]);
	}

	//for (int i = 0; i < WEEK*2; i++)
	//{
	//	printf("%lf", times[i]);
	//}

	printf("%d", cal(p));


	return 0;
}


#endif

#if 0

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
	int a, b;
	scanf("%d %d", &a, &b); // 4 10

	//printf("%d", find_divisors_cnt(a, b));

	printf("%d", b - a + 1 - (int)sqrt(b) + (int)sqrt(a - 1));

	//printf("%d %d %d", (int)sqrt(b), (int)sqrt(a), (int)sqrt(a - 1));

	return 0;
}
#endif


#if 0
int N;
int sol;

double sqrt_bruteforce(const double d)
{
	double i = 1;
	while (1)
	{
		if (i*i <= d && d < (i + 1)*(i + 1))
		{
			break;
		}
		i++;
	}
	return i;
}

double sqrt_bibilonia(const double d)
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
	clock_t begin;
	clock_t end;
	double time_spent;

	scanf("%d", &N);



	begin = clock();
	sol = (int)sqrt_bruteforce(N);
	printf("%d", sol);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("brute force, time spent : %f\n", time_spent);



	begin = clock();
	sol = (int)sqrt_bibilonia(N);
	printf("%d", sol);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("sqrt_bibilonia, time spent : %f\n", time_spent);



	return 0;

}

#endif