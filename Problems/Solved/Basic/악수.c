// 악수
#if 0
char m[50 + 5][50 + 5];
int R, C, max=0x80000000, maxi=54, maxj=54, shake;
int main(void)
{
	//freopen("test.txt", "r", stdin);
	scanf("%d %d", &R, &C);

	for (int i = 1; i < R+1; i++)
	{
		scanf("%s", &m[i][1]);
	}

	for (int i = 1; i < R+1; i++)
	{
		for (int j = 1; j < C+1; j++)
		{
			shake = 0;
			if (m[i][j] == 'o') continue;
			if ( m[i - 1][j - 1] == 'o') shake++;
			if (m[i - 1][    j] == 'o') shake++;
			if ( m[i - 1][j + 1] == 'o') shake++;
			if ( m[i    ][j + 1] == 'o') shake++;
			if (m[i    ][j - 1] == 'o') shake++;
			if ( m[i + 1][j - 1] == 'o') shake++;
			if ( m[i + 1][j    ] == 'o') shake++;
			if (m[i + 1][j + 1] == 'o') shake++;
			if (max < shake)
			{
				max = shake;
				maxi = i; maxj = j;
			}
		}
	}
	//printf("%d %d\n", maxi, maxj);

	m[maxi][maxj] = 'o';

	shake = 0;
	for (int i = 1; i < R + 1; i++)
	{
		for (int j = 1; j < C + 1; j++)
		{
			if (m[i][j] == 'o')
			{
				if (m[i - 1][j - 1] == 'o') shake++;
				if (m[i - 1][j] == 'o') shake++;
				if (m[i - 1][j + 1] == 'o') shake++;
				if (m[i][j + 1] == 'o') shake++;
				if (m[i][j - 1] == 'o') shake++;
				if (m[i + 1][j - 1] == 'o') shake++;
				if (m[i + 1][j] == 'o') shake++;
				if (m[i + 1][j + 1] == 'o') shake++;
				m[i][j] = '.';

			}
		}
	}

	printf("%d", shake);

	return 0;
}
#endif

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
