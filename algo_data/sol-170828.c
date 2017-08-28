#define _CRT_SECURE_NO_WARNINGS

//	악수
#if 0
#include <stdio.h>
int R, C, sol;
char a[50 + 10][50 + 10];
//8방향
int Count(int i, int j){
	int ni, nj, k, ret = 0;
	static di[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
	static dj[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
	for (k = 0; k < 8; k++){
		ni = i + di[k];	nj = j + dj[k];
		if (a[ni][nj] == 'o') ret++;
	}
	return ret;
}
int main(void){
	int i, j, cnt;
	scanf("%d %d", &R, &C);
	for (i = 1; i <= R; i++){
		scanf("%s", &a[i][1]);
	}

	for (i = 1; i <= R; i++){		//	민혁악수(max)
		for (j = 1; j <= C; j++){
			if (a[i][j] != '.') continue;
			cnt = Count(i, j);
			if (sol < cnt) sol = cnt;
		}
	}
	for (i = 1; i <= R; i++){		//	기존사람 악수
		for (j = 1; j <= C; j++){
			if (a[i][j] != 'o')	continue;
			sol += Count(i, j);
			a[i][j] = '.';					//	중복방지(원본삭제)
		}
	}
	printf("%d", sol);
	return 0;
}
#endif

//	연속부분최대곱
#if 0
#include <stdio.h>
int N;
double a[10000 + 10], sol = 0.0;
int main(void){
	int i, j;
	double mul = 1.0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%lf", &a[i]);
	for (i = 0; i < N; i++){
		if (mul < 1.0)	mul = a[i];
		else mul *= a[i];
		if (sol < mul)	sol = mul;
	}
	printf("%.3lf", sol);
	return 0;
}
#endif

//	숫자근
#if 0
#include <stdio.h>
int N, sol;
int Root(int n){
	int sum;
	for (;;){
		sum = 0;
		while (n > 0){ sum += n % 10;				n /= 10; }
		if (sum < 10)	break;
		n = sum;
	}
	return sum;
}
int main(void){
	int i, n, root, max = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &n);
		root = Root(n);
		if (max < root){
			max = root;	sol = n;
		}
		else if (max == root){
			if (sol > n) sol = n;
		}
	}
	printf("%d", sol);
	return 0;
}
#endif

//	색종이(중)
#if 0
#include <stdio.h>
int N, sol;
int a[100 + 10][100 + 10];
int main(void){
	int i, j, k, si, sj;
	scanf("%d", &N);
	for (k = 0; k < N; k++){
		scanf("%d %d", &sj, &si);
		for (i = si; i < si + 10; i++){
			for (j = sj; j < sj + 10; j++){
				a[i][j] = 1;
			}
		}
	}
	for (i = 1; i <= 100; i++){
		for (j = 1; j <= 100; j++){
			if (a[i][j] != 1) continue;
			if (a[i - 1][j] == 0) sol++;
			if (a[i + 1][j] == 0) sol++;
			if (a[i][j - 1] == 0) sol++;
			if (a[i][j + 1] == 0) sol++;
		}
	}
	printf("%d", sol);
	return 0;
}
#endif

//	색종이(초)
#if 0
#include <stdio.h>
int N, sol;
int a[100 + 10][100 + 10];
int main(void){
	int i, j, k, si, sj;
	scanf("%d", &N);
	for (k = 0; k < N; k++){
		scanf("%d %d", &sj, &si);
		for (i = si; i < si + 10; i++){
			for (j = sj; j < sj + 10; j++){
				a[i][j] = 1;
			}
		}
	}
	for (i = 1; i <= 100; i++){
		for (j = 1; j <= 100; j++){
			if (a[i][j] == 1) sol++;
		}
	}
	printf("%d", sol);
	return 0;
}
#endif

//	행과열의 큰값
#if 0
#include <stdio.h>
int a[4][5] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };
int maxi, maxj;
int main(void){
	int i, j, max, sum;
	max = 0x80000000;
	for (i = 0; i < 4; i++){
		sum = 0;
		for (j = 0; j < 5; j++){
			sum += a[i][j];
		}
		if (max < sum){
			max = sum;	maxi = i + 1;
		}
	}
	max = 0x80000000;
	for (j = 0; j < 5; j++){
		sum = 0;
		for (i = 0; i < 4; i++){
			sum += a[i][j];
		}
		if (max < sum){
			max = sum;	maxj = j + 1;
		}
	}
	printf("%d %d", maxi, maxj);
	return 0;
}
#endif

//	모범생
#if 0

#include <stdio.h>
int N;
typedef struct {
	int id;
	int n;
}st;
st a[30000 + 10];
int main(void){
	int i, j;
	st tmp;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i].n);
		a[i].id = i + 1;
	}
	for (i = 0; i < 3; i++){
		for (j = i + 1; j < N; j++){
			if (a[i].n < a[j].n){
				tmp = a[i]; a[i] = a[j]; a[j] = tmp;
			}
		}
	}
	for (i = 0; i < 3; i++) printf("%d ", a[i].id);
	return 0;
}
#endif

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

//	
#if 0
#include <stdio.h>

int main(void){

	return 0;
}
#endif
