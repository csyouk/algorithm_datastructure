#include <stdio.h>
#include <stdlib.h>

int N, C;
int M;

typedef struct st{
	int s;
	int e;
	int box;
}TB;

TB tb[10000];

int truck[2001];

void Input_Data(void)
{
	int i;
	scanf("%d %d", &N, &C);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &tb[i].s, &tb[i].e, &tb[i].box);
	}
}

int comp(const TB* p1, const TB* p2)
{
	return p1->e - p2->e;
}

int Find(void)
{
	int size = 0;
	int i, j, min;


	for ( i = 0; i < M; i++)
	{
		min = ~(1 << 31);
		for ( j = tb[i].s; j < tb[i].e; j++)
		{
			min = min > (C - truck[j]) ? (C - truck[j]) : min;
		}
		
		min = (tb[i].box < min) ? tb[i].box : min;

		size += min;
		for (j = tb[i].s; j < tb[i].e; j++)
		{
			truck[j] += min;
		}

	}


	return size;
}


int main(void)
{
	Input_Data();

	qsort(tb, M, sizeof(TB), comp);

	printf("%d\n", Find());

	return 0;
}