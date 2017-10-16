#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int i, a, h, w;
} BRICK;

BRICK b[101];
int D[101], path[101];
int N, lastidx;

int comp(const BRICK * p1, const BRICK * p2){ return p1->w - p2->w;}

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &b[i].a, &b[i].h, &b[i].w); b[i].i = i;
	}
	qsort(b + 1, N, sizeof(BRICK), comp);
}

void Find_LIS(void){
	int maxheight = 0, n, k;

	D[0] = 0;

	b[0].a = b[0].w = b[0].h = b[0].i = 0;

	for (n = 1; n <= N; n++){
		for (k = 0; k < n; k++){
			if ((b[k].a < b[n].a) && (D[n] < D[k] + b[n].h)){
				D[n] = D[k] + b[n].h;
				path[n] = k;
			}
		}
		if (maxheight < D[n]){
			maxheight = D[n];
			lastidx = n;
		}
	}
}



void Find_Path(int idx){
	static int invoke_cnt;
	if (idx == 0) { 
		printf("%d\n", invoke_cnt); 
		return;
	}
	invoke_cnt++;
	Find_Path(path[idx]);
	printf("%d\n", b[idx].i);
}

int main(void){

	Input_Data();
	Find_LIS();
	Find_Path(lastidx);

	return 0;
}
#endif