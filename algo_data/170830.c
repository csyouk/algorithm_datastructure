//// 이진탐색으로 예산문제 풀기
//#if 0
//#include <stdio.h>
//#define MIN(x,y) (((x)<(y)) ? (x):(y))
//int N, a[10000 + 10], M;
//int Check(int m)
//{
//	// m 받은 예산.
//	int i, sum = 0;
//	for ( i = 1; i <=N; i++)
//	{
//		sum += MIN(a[i], m);
//	}
//	if (sum <= M) return 1;
//	return 0;
//}
//
//int main(void)
//{
//	int i, s, e, m, sol, max=0;
//	scanf("%d", &N);
//	for ( i = 1; i <=N; i++)
//	{
//		scanf("%d", &a[i]);
//		if (max < a[i]) max = a[i];
//	}
//
//	scanf("%d", &M);
//	s = 0; e = max;
//
//	while (s <= e){
//		m = (s + e) / 2;
//		if (Check(m)){ sol = m; s = m + 1; }
//		else e = m - 1;
//	}
//
//	printf("%d", sol);
//	return 0;
//}
//#endif
//
//// 문제 번호 : [TST] 연결된 세포
//#if 0
//#include <stdio.h>
//int R, C, mark=1;
//int cell[12][12];
//int chk[12][12];
//int di[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; // 상하 좌우, 밑2개 위 2개
//int dj[] = { 0, 0, -1, 1, -1, 1, -1, 1 }; // 상하 좌우, 밑2개 위 2개
//int cnt[12*12/2];
//
//void Fill(int i, int j, int mark)
//{
//	int k, ni, nj;
//	if (chk[i][j] == 1) return;
//	chk[i][j] = 1;
//	cnt[mark]++;
//	for ( k = 0; k < 8; k++)
//	{
//		ni = i + di[k]; nj = j + dj[k];
//		if (cell[ni][nj] == 1){
//			Fill(ni, nj, mark);
//
//		}
//	}
//}
//int main(void)
//{
//	//freopen("in.txt", "r", stdin);
//	int i, j, max=0x80000000;
//	scanf("%d %d", &R, &C);
//	for (i = 1; i <= R; i++){
//		for ( j = 1; j <= C; j++){
//			scanf("%d", &cell[i][j]);
//		}
//	}
//
//	for ( i = 1; i <= R; i++){
//		for ( j = 1; j <= C; j++){
//			if (cell[i][j] == 1 && chk[i][j] == 0){
//				Fill(i, j, mark); mark++;
//			}
//		}
//	}
//
//	for ( i = 1; i <= mark; i++)
//	{
//		if (max < cnt[i]) max = cnt[i];
//	}
//
//	printf("%d", max);
//
//	return 0;
//}
//#endif
//
//// [TST]단지 번호붙이기
//#if 0
//#include <stdio.h>
//int N, mark;
//int c[30][30];
//int chk[30][30];
//int cnt[30 * 30 / 2];
//int di[] = { -1, 1, 0, 0}; // 상하 좌우
//int dj[] = { 0, 0, -1, 1 }; // 상하 좌우
//
//void Fill(int i, int j, int mark)
//{
//	int k, ni, nj;
//	if (chk[i][j] == 1) return;
//	chk[i][j] = 1;
//	cnt[mark]++;
//	for ( k = 0; k < 4; k++)
//	{
//		ni = i + di[k]; nj = j + dj[k];
//		if (c[ni][nj] == 1){
//			Fill(ni, nj, mark);
//		}	
//	}
//}
//
//int main(void)
//{
//	// 여기서부터 작성
//	freopen("in.txt", "r", stdin);
//	int i, j, tmp;
//
//	scanf("%d", &N);
//	for ( i = 1; i <= N; i++){
//		for (j = 1; j <= N; j++){
//			scanf("%1d", &c[i][j]);
//		}
//	}
//
//	for ( i = 1; i <=N; i++){
//		for ( j = 1; j <=N; j++){
//			if (c[i][j] == 1 && chk[i][j] == 0){
//				Fill(i, j, mark); mark++;
//			}
//		}
//	}
//
//	for (i = 0; i < mark-1; i++)
//	{
//		for ( j = i+1; j < mark; j++)
//		{
//			if (cnt[i] > cnt[j]){
//				tmp = cnt[i];
//				cnt[i] = cnt[j];
//				cnt[j] = tmp;
//			}
//		}
//	}
//
//	printf("%d\n", mark);
//	for ( i = 0; i < mark; i++)
//	{
//		printf("%d\n", cnt[i]);
//	}
//
//	return 0;
//}
//#endif
//
//// 문제 번호 : [TST]쇠막대기
//#if 0
//#include <stdio.h>
//#define MAX 100010
//char d[MAX];
//
//int main(void)
//{
//	// 여기서부터 작성
//	int sum = 0, stick = 0;
//	freopen("in.txt", "r", stdin);
//
//	scanf("%s", &d[1]);
//	fflush(stdin);
//	
//	for (int i = 1; i < MAX; i++){
//		if (d[i] == 0) break;
//		if (d[i] == '(') stick++;
//		if (d[i] == ')') stick--;
//		if (d[i - 1] == '(' && d[i] == ')'){
//			sum += stick;
//		}
//		if (d[i - 1] == ')' && d[i] == ')'){
//			sum++;
//		}
//	}
//
//	printf("%d", sum);
//	return 0;
//}
//#endif
//
//// 문제 번호 : [TST]미술관람 대회
#if 0

#endif
//
// 문제 번호 : [TST]비트방정식
#if 0
#include <stdio.h>

int main(void)
{
	// 여기서부터 작성
	int X, K, l=0;
	scanf("%d %d", &X, &K);
	for (int i = 1; ; i++)
	{
		if ((X + i) == (X | i))
		{
			l++;
			if (l == K) { printf("%d\n", i); break; }
		}
	}
	return 0;
}
#endif


// 비트방정식
#if 0
int main(void)
{
	unsigned long long int X, K, l = 0, lsb, tmp, i=0;
	scanf("%llu %llu", &X, &K);
	tmp = X;
	while (1)
	{
		lsb = K & 0x1;
		K >>= 1;

		for (;;i++)
		{
			if (((X >> i)&0x1) == 0)
			{
				lsb <<= i;
				X += lsb;
				i++;
				break;
			}
		}
		if (K == 0) break;
	}
	printf("%llu", X - tmp);

	return 0;
}
#endif


#if 0
int N;
void move(int n, int from, int to)
{
	printf("%d : %d -> %d\n", n, from, to);
}

void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		move(n, from, to);
	}
	else
	{
		hanoi(n - 1, from, to, by);
		move(n, from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main(void)
{
	scanf("%d", &N);
	hanoi(N, 1, 2, 3);
	return 0;
}
#endif