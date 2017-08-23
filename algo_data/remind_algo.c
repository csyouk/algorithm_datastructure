#if 0
#include <stdio.h>
#define MAX 200
#define ULL unsigned long long int
typedef struct{
	int id;
	int score;
	char ssid[20];
} ENTITY;

int cb(int, int);
int Selection_Sort(ENTITY *, int , int(*)(ENTITY *, ENTITY *));
int Bubble_Sort(ENTITY *, int, int(*)(ENTITY *, ENTITY *));

int Selection_Sort(ENTITY *d, int order, int(*comp)(ENTITY *x, ENTITY *y))
{
	int i, j, max, t;
	ENTITY tmp;
	for (max = 0; max < MAX; max++)
	{
		if (d[max].id == 0) break;
	}

	for (i = 0; i < max - 1; i++)
	{
		for (t = 0, j = 0; j < max - 1 - i; j++)
		{
			if (comp(&d[t], &d[j + 1]) == order) t = j + 1;
		}
		if (j != t)
		{
			tmp = d[j];
			d[j] = d[t];
			d[t] = tmp;
		}
	}
	return max;
}


int Bubble_Sort(ENTITY *d, int order, int(*comp)(ENTITY *x, ENTITY *y))
{
	int i, j, max;
	ENTITY tmp;
	for ( max = 0; max < MAX; max++)
	{
		if(d[max].id == 0) break;
	}

	for (i = 0; i < max - 1; i++)
	{
		for ( j = 0; j < max - 1 - i; j++)
		{
			if (comp(&d[j], &d[j+1]) == order)
			{
				tmp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = tmp;
			}
		}
	}
	return max;
}



int threetimes(int x, int y)
{
	ULL ub = 0xffffffff;
	ULL divisor = 0xff;
	for (ULL i = 0; i < ub; i++);
	return x + y;
}

int caller(int cnt, int cb(int, int))
{
	printf("cnt : %d\n", cnt);
	printf("callee : %d\n", cb(cnt, cnt * 2));
}
int main(void)
{

	caller(3, threetimes);

	return 0;
}
#endif


// remind 더블 링크 리스트,
// stack, queue
#if 0


#endif