#include <stdio.h>
#define ABS(X,Y) (((X) > (Y)) ? ((X) - (Y)):((Y) - (X)))
typedef struct {
	int ai, bi, cnt, removed;
} LINE;
int N;
LINE l[101];
int D[101];

int comp1(const LINE * p1, const LINE * p2){
	return p1->ai - p2->ai;
}
int comp2(const LINE * p1, const LINE * p2){
	return p2->cnt - p1->cnt;
}

void Input_Data(){
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		scanf("%d %d", &l[i].ai, &l[i].bi);
	}
	qsort(l + 1, N, sizeof(LINE), comp1);
	for ( i = 1; i <= N; i++)
	{
		for ( j = i+1; j <= N; j++)
		{
			if (i == j) continue;
			if (l[i].bi > l[j].bi) { l[i].cnt++; }
		}
	}
	qsort(l + 1, N, sizeof(LINE), comp2);
}

int Find_LIS(void){
	int n, k, maxlen=0;


	for ( n = 1; n <= N; n++)
	{
		for ( k = 0; k < n; k++)
		{
		}
	}

	return maxlen;
}

int main(void){
	Input_Data();
	printf("%d", Find_LIS());

	return 0;
}