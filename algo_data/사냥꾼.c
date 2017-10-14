#include <stdio.h>
#include <stdlib.h>
#define ABS(X) ((X) > 0 ? (X) : (-(X)))

typedef struct{
	int i, j, chk;
} Pos;

int N, M, L, total, FIRST = 1, LAST;
Pos shot[100000];
Pos animals[100000];

int comp(const Pos * p1, const Pos * p2){
	return p1->i - p2->i;
}


void Input_Data(void){
	int i;
	scanf("%d %d %d", &M, &N, &L);

	for ( i = 0; i <M; i++)
	{
		scanf("%d", &shot[i].i);
	}

	for ( i = 0; i < N; i++)
	{
		scanf("%d %d", &animals[i].i, &animals[i].j);
	}
	qsort(shot, M, sizeof(Pos), comp);
	qsort(animals, N, sizeof(Pos), comp);
	if (shot[M - 1].i > animals[N - 1].i){
		LAST = shot[M - 1].i;
	} else {
		LAST = animals[N - 1].i;
	}
}

Pos Find_Animal_Pos(int min, int max){
	int i, j;
	Pos pos;
	for ( i = 0; i < N; i++)
	{
		if (animals[i].i < min) continue;
		pos.i = animals[i].i; break;
	}

	for ( j = i ; j < N; j++)
	{
		if (animals[j].i > max) continue;
		pos.j = animals[j-1].j; break;
	}

	return pos;
}

void Catch(void){
	int i, j, k;
	int min, max;
	Pos pos;

	for ( i = 0; i < M; i++)
	{
		min = shot[i].i - L;
		max = shot[i].i + L;
		if (min < FIRST) min = 1;
		if (max > LAST) max = LAST;

		pos = Find_Animal_Pos(min, max);

		// 사대거리 최소 ~ 최대 중 찾는다.
		for ( j = min ; j <= max; j++)
		{
			for (k = pos.i; k <= pos.j; k++)
			{
				if ((animals[k].chk != 1) && ((ABS(j - animals[k].i) + animals[k].j) <= L)){
					animals[k].chk = 1;
					total++;
				}
			}
		}


	}
}

int main(void){

	Input_Data();
	Catch();
	printf("%d", total);
	return 0;
}