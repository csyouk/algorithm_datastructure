
// 비트방정식
#if 0
int main(void)
{
	unsigned long long int X, K, l = 0, lsb, tmp, i=0;
	scanf("%llu %llu", &X, &K);
	tmp = X;
	while (1)
	{
		lsb = K & 0x1;
		K >>= 1;

		for (;;i++)
		{
			if (((X >> i)&0x1) == 0)
			{
				lsb <<= i;
				X += lsb;
				i++;
				break;
			}
		}
		if (K == 0) break;
	}
	printf("%llu", X - tmp);

	return 0;
}
#endif
