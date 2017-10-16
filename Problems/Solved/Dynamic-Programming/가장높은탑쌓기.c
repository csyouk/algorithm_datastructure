#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int i, a, h, w;
} BRICK;

BRICK b[101];
int D[2][101];
int path[101];
int N;
int lastidx;

int comp(const BRICK * p1, const BRICK * p2){
	return p1->w - p2->w;
}

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &b[i].a, &b[i].h, &b[i].w);
		b[i].i = i;
	}
	qsort(b + 1, N, sizeof(BRICK), comp);
}

int Find_LIS(void){
	int maxlen = 0, maxheight = 0, n, k;

	D[0][0] = 0;
	D[1][0] = 0;

	b[0].a = b[0].w = b[0].h = b[0].i = 0;

	for (n = 1; n <= N; n++){
		for (k = 0; k < n; k++){
			if (b[k].a < b[n].a){
				if (D[0][n] < D[0][k] + b[n].h){
					D[0][n] = D[0][k] + b[n].h;
					D[1][n] = D[1][k] + 1;
					path[n] = k;
				}
			}
		}
		if (maxheight < D[0][n]){
			maxheight = D[0][n];
			lastidx = n;
		}
		if (maxlen < D[1][n]){
			maxlen = D[1][n];
		}
	}
	return maxlen;
}



void Find_Path(int idx){
	if (idx == 0) return;
	Find_Path(path[idx]);
	printf("%d\n", b[idx].i);
}

int main(void){

	Input_Data();
	printf("%d\n", Find_LIS());
	Find_Path(lastidx);

	return 0;
}



// 최적화
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int i, a, h, w;
} BRICK;

BRICK b[101];
int D[101];
int path[101];
int N;
int lastidx;

int comp(const BRICK * p1, const BRICK * p2){
	return p1->w - p2->w;
}

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &b[i].a, &b[i].h, &b[i].w);
		b[i].i = i;
	}
	qsort(b + 1, N, sizeof(BRICK), comp);
}

void Find_LIS(void){
	int maxheight = 0, n, k;

	D[0] = 0;

	b[0].a = b[0].w = b[0].h = b[0].i = 0;

	for (n = 1; n <= N; n++){
		for (k = 0; k < n; k++){
			if (b[k].a < b[n].a){
				if (D[n] < D[k] + b[n].h){
					D[n] = D[k] + b[n].h;
					path[n] = k;
				}
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
	if (idx == 0) { printf("%d\n", invoke_cnt); return; }
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
