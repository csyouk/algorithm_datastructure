#include <stdio.h>
#include <stdlib.h>
#define FAILED (-1)
int M, N, L;
int shoot[100000];
typedef struct
{
	int x;
	int y;
}ANIMAL;
ANIMAL animal[100000];

void Input_Data(void)
{
	int i;
	scanf("%d %d %d",&M,&N,&L);
	for (i = 0; i < M;i++)
	{
		scanf("%d",&shoot[i]);
	}
	for (i = 0; i < N;i++)
	{
		scanf("%d %d", &animal[i].x, &animal[i].y);
	}
}

int comp_shoot(const int* p1, const int* p2)
{
	return *p1 - *p2;
}

int comp_animal(const ANIMAL *p1, const ANIMAL *p2)
{
	return p1->x - p2->x;
}


int Binary_Search_Upper(int s, int e, int d)
{
	int m, sol = -1;

	while (s<=e)
	{
		m = (s + e) / 2;
		if (shoot[m] <= d)
		{
			sol = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	return sol;
}

int Binary_Search_Lower(int s, int e, int d)
{
	int m, sol = -1;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (shoot[m] >= d)
		{
			sol = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	return sol;
}

/*
int Solve2(void)
{
	int i,right=0;
	int cnt = 0;
	for (i = 0; i < N;i++)
	{
		while (right<M && shoot[right] < animal[i].x) right++;
		if (right < M && animal[i].y + shoot[right] - animal[i].x <= L)
			cnt++;
		else if (right>0 && animal[i].y + animal[i].x - shoot[right - 1] <= L)
			cnt++;
	}

	return cnt;
}
*/

int Solve1(void)
{
	int i;
	int cnt = 0,ret;

	for (i = 0; i < N;i++)
	{
		ret = Binary_Search_Upper(0, M - 1, animal[i].x);
		if (ret != FAILED && animal[i].y + animal[i].x - shoot[ret] <= L)
		{
			cnt++;
		}
		else
		{
			ret = Binary_Search_Lower(0, M - 1, animal[i].x);
			if (ret != FAILED && animal[i].y + shoot[ret] - animal[i].x <= L)
			{
				cnt++;
			}
		}
	}
	return cnt;

}


int main(void)
{
	Input_Data();

  //
	qsort(shoot, M, sizeof(int), comp_shoot);
	printf("%d\n",Solve1());

	/*
	qsort(animal, N, sizeof(ANIMAL), comp_animal);
	printf("%d\n",Solve2());
	*/

	return 0;
}
