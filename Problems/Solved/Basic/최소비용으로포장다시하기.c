
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
