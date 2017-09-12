
//	휴대폰번호 정렬
#if 0
#include <stdio.h>
typedef struct{
	int n1, n2, n3, digit;
}P_t;
P_t a[50 + 10];
int N, p[10 + 10];
int cmp(int i, int j){
	if (p[a[i].n1 % 10] < p[a[j].n1 % 10]) return -1;
	if (p[a[i].n1 % 10] > p[a[j].n1 % 10]) return 1;

	if (a[i].digit > a[j].digit) return -1;
	if (a[i].digit < a[j].digit) return 1;

	if (a[i].n2 < a[j].n2) return -1;
	if (a[i].n2 > a[j].n2) return 1;

	if (a[i].n3 < a[j].n3) return -1;
	if (a[i].n3 > a[j].n3) return 1;

	return 0;
}
char str[50 + 10][13 + 10];
int main(void){
	int i, j, d;
	P_t t;
	scanf("%d", &N);
	for (i = 1; i <= 6; i++){
		scanf("%d", &d);
		p[d] = i;
	}
	for (i = 0; i < N; i++) scanf("%s", &str[i][0]);
	for (i = 0; i < N; i++){
		sscanf(str[i], "%d-%d-%d", &a[i].n1, &a[i].n2, &a[i].n3);
		if (str[i][12] == '\0') a[i].digit = 3;
		else a[i].digit = 4;
	}
	for (i = 0; i < N - 1; i++){	//	오름차순 정렬
		for (j = i + 1; j < N; j++){
			if (cmp(i, j) == 1){
				t = a[i]; a[i] = a[j]; a[j] = t;
			}
		}
	}
	for (i = 0; i < N; i++){
		if (a[i].digit == 3) printf("%03d-%03d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
		else printf("%03d-%04d-%04d\n", a[i].n1, a[i].n2, a[i].n3);
	}
	return 0;
}
#endif
