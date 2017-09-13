
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
