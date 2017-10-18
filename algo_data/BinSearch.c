#if 0
#include <stdio.h>
#define LAST_INDEX ((sizeof(data)/sizeof(data[0])) -1)
int data[] = { -10, -3, -1, 3, 6, 7, 7, 15, 30, 100 };

int Binsearch(int s, int e, int k){
	int m, sol = -1;
	while (s <= e)
	{
		m = (s + e) / 2;
		if (k <= data[m]){
			sol = m;
			e = m - 1;
		}
		else { s = m + 1; }
	}
	return sol;
}

int Binsearch_Lower_Bound(int s, int e, int lower){
	int m, sol = -1;
	// 찾고자 하는 값 이상이 처음 나올때의 위치.
	while (s <= e)
	{
		m = (s + e) / 2;
		if (lower <= data[m]){
			e = m - 1;
			sol = m;
		}
		else{ s = m + 1; }
	}
	return sol;
}

int Binsearch_Upper_Bound(int s, int e, int upper){
	int m, sol = -1;
	// 찾고자 하는 값 이하가 처음 나오는 위치.
	while (s<=e)
	{
		m = (s + e) / 2;
		if (data[m] <= upper){
			sol = m;
			s = m + 1;
		}
		else { e = m - 1; }
	}
	return sol;
}

int main(void){

	printf("Binary search : %d\n", Binsearch(0, LAST_INDEX, -3));
	printf("Binary search Lower : %d\n", Binsearch_Lower_Bound(0, LAST_INDEX, -2));
	printf("Binary search Upper : %d\n", Binsearch_Upper_Bound(0, LAST_INDEX, 15));

	return 0;
}
#endif