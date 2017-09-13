
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
