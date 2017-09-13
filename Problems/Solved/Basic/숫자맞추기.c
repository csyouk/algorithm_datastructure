
// 숫자맞추기
#if 0

int main(void)
{
	int a = 0, b = 0;
	char x[5], y[5];
	scanf("%s %s", &x, &y);

	for (int i = 0; i < sizeof(x)-1; i++)
	{
		if (x[i] == y[i])
		{
			a++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j) continue;
			if (x[i] == y[j])
			{
				b++;
			}
		}
	}


	printf("%dA%dB", a, b);

}
#endif
