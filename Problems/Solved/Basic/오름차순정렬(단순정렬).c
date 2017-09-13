//	오름차순 정렬 (단순정렬)
#if 0
#include <stdio.h>

int N;
int a[5000 + 10];
int main(void){
	int i, j, tmp;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &a[i]);
	for (i = 0; i < 4; i++){
		for (j = i + 1; j < N; j++){
			if (a[i]>a[j]){
				tmp = a[i]; a[i] = a[j]; a[j] = tmp;
			}
		}
	}
	for (i = 0; i < N; i++) printf("%d ", a[i]);
	return 0;
}
#endif
