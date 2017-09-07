// 문제 번호 V: [SKKU]참외밭
// http://dyndy.tistory.com/130
#if 0
#include <stdio.h>
#define ABS(x) (((x) > 0)? (x) : -(x))

int main(void)
{
	int a[6+10][2];
	int T, K, sum = 0;
	int tmp = 0;
	int i, maxw = -1, maxh = -1;
	freopen("in.txt", "r", stdin);
	//입력받는부분
	scanf("%d", &T);
	while (T-->0)
	{
		sum = 0, tmp = 0; maxw = -1, maxh = -1;
		scanf("%d", &K);
		for (i = 1; i<=6; i++)
		{
			scanf("%d %d", &a[i][0], &a[i][1]);
			if (a[i][0]  < 3){
				if (maxh < a[i][1]) maxh = a[i][1];
			}
			else{
				if (maxw < a[i][1]) maxw = a[i][1];
			}
		}
		a[i][0] = a[1][0]; a[i][1] = a[1][1];

		//여기서부터작성

		sum = maxh * maxw;
		
		for ( i = 1; i <= 6; i++) tmp += a[i][1] * a[i + 1][1];
		tmp -= 3 * sum;
		sum = sum - ABS(tmp);

		//출력하는부분
		printf("%d\n", sum*K);
	}
	return 0;
}
#endif