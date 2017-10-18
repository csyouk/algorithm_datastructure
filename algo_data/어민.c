#if 0
#include <stdio.h>
#define MIN(X,Y) ((X) > (Y) ? (Y) : (X))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
int N;
int min = (~(1<<31)), max = (1<<31);
typedef struct
{
	int pos;
	int fish;
}TOWN;

TOWN town[100000];

void Input_Data(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i<N; i++)
	{
		scanf("%d %d", &town[i].pos, &town[i].fish);
		min = MIN(town[i].fish, min);
		max = MAX(town[i].fish, max);
	}
}

int Check(int child)
{
	int i;
	// ���������� �������� ������ ���¾� Ȥ�� ������ ���� ����Ѵ�.
	// carry �� ����. ���°� +, �������� ���� -
	long long int c = 0;

	// ù �������� ������������.
	for (i = 0; i<(N - 1); i++){
		if ((town[i].fish + c) < child){
			// ���ڶ� ���� ���� �������� ����.
			c = -(child - (town[i].fish + c) + (town[i + 1].pos - town[i].pos));
		} else {
			// ���� ���� ���� ������ �ѱ�.
			c = (town[i].fish + c - child) - (town[i + 1].pos - town[i].pos);
			if (c < 0) c = 0;
		}
	}
	
	// ������ ������ ���ؼ� �˻�.
	if (town[N-1].fish + c < child) return 0;
	else return 1;
}



int Find_Max(void)
{
	int s, e, m;
	int sol;

	// ������ ������ �� ����ϴ� �ڵ��̴�.
	//e = 1;
	//while (Check(e)) e *= 2;
	//// s �� ������ ������ ��.
	//s = e / 2;

	s = min; e = max;

	while (s <= e)
	{
		m = (s + e) / 2;

		if (Check(m))
		{
			sol = m;
			s = m + 1;
		}
		else
		{
			e = m - 1;
		}
	}
	return sol;
}




int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		Input_Data();
		printf("%d\n", Find_Max());
	}

	return 0;
}
#endif
