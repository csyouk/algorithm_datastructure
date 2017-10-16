#include <stdio.h>
#define ABS(X,Y) (((X) > (Y)) ? ((X) - (Y)):((Y) - (X)))
typedef struct {
	int ai, bi;
} LINE;
int N;
LINE l[101];
int D[101];

int comp1(const LINE * p1, const LINE * p2){
	return p1->ai - p2->ai;
}

void Input_Data(){
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		scanf("%d %d", &l[i].ai, &l[i].bi);
	}
	qsort(l + 1, N, sizeof(LINE), comp1);
}

int Find_LIS(void){
	int n, k, maxlen=0;


	for ( n = 1; n <= N; n++)
	{
		for ( k = 0; k < n; k++)
		{
			if (l[k].bi < l[n].bi){
				if (D[n] < D[k] + 1){
					D[n] = D[k] + 1;
				}
			}
		}
		if (maxlen < D[n]) maxlen = D[n];
	}

	return maxlen;
}

int main(void){
	Input_Data();
	printf("%d", N- Find_LIS());

	return 0;
}
