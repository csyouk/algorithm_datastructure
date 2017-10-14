

// 합이 가장 큰 행과 열
#if 01
int a[4][5] = { { 3, -5, 12, 3, -21 }, { -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 }, { 9, 14, 39, -98, -1 } };
int row, col, s_r = 0x80000000, s_c = 0x80000000;
int main(void)
{

	for (int i = 0; i < 4; i++)
	{
		int r_tmp = 0;
		for (int j = 0; j < 5; j++)
		{
			r_tmp += a[i][j];
		}
		if (r_tmp > s_r)
		{
			row = i;
			s_r = r_tmp;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		int c_tmp = 0;
		for (int j = 0; j < 4; j++)
		{
			c_tmp += a[j][i];
		}
		if (c_tmp > s_c)
		{
			col = i;
			s_c = c_tmp;
		}
	}


	printf("%d %d", row+1, col+1);

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
