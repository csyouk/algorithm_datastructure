#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int h, w;
} Paper;
Paper p[101];
int D[101];
int N;

int comp(const Paper * p1, const Paper * p2){
	if (p1->h == p2->h) return p1->w - p2->w;
	return p1->h - p2->h;
}

void Input_Data(){
	int i, tmp;
	scanf("%d", &N);
	for ( i = 1; i <= N; i++)
	{
		scanf("%d %d", &p[i].h, &p[i].w);
		if (p[i].h > p[i].w){
			tmp = p[i].h;
			p[i].h = p[i].w;
			p[i].w = tmp;
		}
	}
	qsort(&p[1], N, sizeof(Paper), comp);
};

int Find_LIS(void){
	int n, k, maxlen=0;
	D[0] = 0;
	p[0].h = p[0].w = 0;

	for (  n = 1; n <= N; n++){
		for ( k = 0; k < n; k++){
			if (p[k].h <= p[n].h && p[k].w <= p[n].w){
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
	printf("%d", Find_LIS());
	return 0;
}
