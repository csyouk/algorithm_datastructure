#if 0
#include <stdio.h>
int N;
// 역추적을 위한 인덱스
int lastidx;


int num[201];
int D[201];
int path[201];

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &num[i]);
}

int Find_LIS(void){
	int n, k, maxlen = 0;
	
	// 가상의 index에 값을 넣어놓는다.
	num[0] = 0; 
	D[0] = 0;

	// dynamic table 채우기
	for ( n = 1; n <= N; n++)
	{
		for ( k = 0; k < n; k++)
		{
			if (num[k] < num[n]){
				if (D[n] < D[k] + 1){
					// n 번 인덱스 앞에 k 번 인덱스를 넣겠다는 결정을 함.
					D[n] = D[k] + 1;

					path[n] = k;
				}
			}
		}
		// 가장 큰 값을 업데이트.
		if (maxlen < D[n]) {
			maxlen = D[n];
			lastidx = n;
		}
	}




	return maxlen;
}

void Print_Path(int idx){
	if (idx == 0) return;
	Print_Path(path[idx]);
	printf("%d->", num[idx]);
}

int main(void){

	Input_Data();
	printf("%d\n", N - Find_LIS());
	
	Print_Path(lastidx);

	return 0;
}
#endif