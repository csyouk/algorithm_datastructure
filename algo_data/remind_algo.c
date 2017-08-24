#include <stdio.h>
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


// Selection Sort
#if 0
#define MAX_ST 20
int main(void)
{
	int i, j,t, max;

	for (max = 0; max < MAX_ST; max++);

	for (i = 0; i < max - 1; i++)
	{
		for (t = 0 j = 0; j < max - 1 - i; j++)
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
	return 0;
}
#endif

// Insertion Sort
#if 0
int main(void)
{
	int i, j, k;

	for ( i = 0; i < MAX_ST; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (comp(&d[j], &d[i]) == order) break;
		}
		tmp = d[i];
		for (k = i; k > j; k--)
		{
			d[k] = d[k - 1];
		}
		d[j] = tmp;

	}
}
#endif

// Quick Sort
#if 0
typedef struct{ int id; }SCORE;
int QS(SCORE *d, int s, int e, int o, int(*comp)(SCORE *x, SCORE *y))
{
	int left = s;
	int pivot = e;
	int target = s;
	SCORE tmp;
	for ( left = s; left < pivot; left++)
	{
		if (comp(&d[pivot], &d[left]) == o)
		{
			if (left != target)
			{
				tmp = d[left];
				d[left] = d[target];
				d[target] = tmp;
			}
			target++;
		}
	}
	if (target != pivot)
	{
		tmp = d[pivot];
		d[pivot] = d[target];
		d[target] = tmp;
	}
}
#endif

// Hash Table - Open Addressing

// doubly linked list in heap
#if 1
#include <malloc.h>
typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next;
	struct _score  * prev;
}SCORE;
int Insert_Node(SCORE *head, SCORE *d)
{
	while (1)
	{
		if (head->next == NULL || head->next->id >d->id)
		{
			SCORE *p = calloc(1, sizeof(SCORE));
			*p = *d;
			p->next = head->next;
			p->prev = head;
			if (head->next)head->next->prev = p;
			head->next = p;
		}
		if (head->next->id == d->id) return -2;
		head = head->next;
	}
}
int main(void)
{


	return 0;
}
#endif
