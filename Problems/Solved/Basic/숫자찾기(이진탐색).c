// 문제 번호 R: [TST] 숫자 찾기 (이진탐색)
#if 0
#include <stdio.h>
int N, T;
int data[50000 + 10];
int target[10000 + 10];
int BinSearch(int *d, int t, int s, int e)
{
	int mid = (s + e) / 2;
	if (mid == s) return mid;
	if (t < d[mid])
	{
		BinSearch(d, t, s, mid);
	}
	else
	{
		BinSearch(d, t, mid, e);
	}
}
int main(void)
{
	//freopen("test.txt", "r", stdin);
	// 여기서부터 작성
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &data[i]);
	}

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &target[i]);
	}


	for (int i = 0; i < T; i++)
	{
		int result = BinSearch(data, target[i], 0, N - 1);
		//printf("%d, %d, %d\n", result, data[result], target[i]);
		printf("%d\n", (data[result] == target[i])? result+1 : 0);
	}

	return 0;
}
#endif
