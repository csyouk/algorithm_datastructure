//// 문제 번호 : [TST]마을 위성사진II
//// 재귀함수로 짠다.
//// 코드를 간단하게 만드는 방법.
//// flood fill 알고리즘을 쓰는 방법이다.
//// 빠르진 않지만, 간단한 방법이다.
////5
////00001
////00100
////10000
////00100
////00001
//
#if 0
#include <stdio.h>
int N, a[100 + 10][100 + 10], chk[100 + 10][100 + 10], sol;
int di[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; // 상하 좌우, 밑2개 위 2개
int dj[] = { 0, 0, -1, 1, -1, 1, -1, 1 }; // 상하 좌우, 밑2개 위 2개

void Fill(int i, int j){
	// 재귀함수를 구현할 때는, top down방식의 사고방식이 필요하다.
	// i,j 기준으로 바로 위부터 시계방향으로 체크해 나간다.
	// 3. 사용변수 선언
	int k, ni, nj;
	// 1. 일단 종료조건부터 작성한다.
	if (chk[i][j] == 1) return;
	// 2. 방문 표시.
	chk[i][j] = 1;
	// 4. 8방향 체크
	for ( k = 0; k < 8; k++){
		ni = i + di[k]; nj = j + dj[k];
		// 5. 호수일 때만, flood fill 호출
		if (a[ni][nj] == 1) {
			Fill(ni, nj);
		}
	}



	//int k, ni, nj;
	//for (k = 0; k < 8; k++)
	//{
	//	ni = i + di[k]; nj = j + dj[k];
	//	if (a[ni][nj] == 1 && chk[ni][nj] == 0)
	//	{
	//		chk[ni][nj] = 1;
	//		Fill(ni, nj);
	//	}
	//}

	//
	//int k, ni, nj;
	//if (chk[i][j] == 1) return;
	//chk[i][j] = 1;
	//for (k = 0; k < 8; k++)
	//{
	//	ni = i + di[k]; nj = j + dj[k];
	//	if (ni<1 || ni > N || nj < 1 || nj > N) continue;
	//	if (a[ni][nj] != 1)continue;
	//	Fill(ni, nj);
	//}

}
int main(void)
{
	// 여기서부터 작성
	freopen("in.txt", "r", stdin);

	int i, j;
	scanf("%d", &N);

	// 가능하면 이런 좌표는 1부터 받는다.
	// 최악의 경우에도 범위를 벗어나지 않기 때문이다.
	for ( i = 1; i <=N; i++){
		for (j = 1; j <= N; j++) scanf("%1d", &a[i][j]);
	}

	for ( i = 1; i <=N; i++){
		for ( j = 1; j <=N; j++){
			if (a[i][j] == 1 && chk[i][j] == 0){
				Fill(i, j);
				sol++;
			}
		}
	}

	printf("%d", sol);
	return 0;
}
#endif
