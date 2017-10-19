//
//#include <stdio.h>
//int N, M, a[10 + 10][10 + 10], b[10 + 10], chk[10 + 10], s[10 + 10];
//int Check(int n, int m){
//	int i;
//	for (i = 1; i < n; i++){
//		if (a[n][i] == 1 && m <= s[i]) return 0;	//	부하직원
//		if (a[i][n] == 1 && m >= s[i]) return 0;	//	상사
//	}
//	return 1;
//}
//
//int DFS(int n){
//	int i;
//	if (n > N)	return 1;
//	for (i = 1; i <= N; i++){
//		if (chk[i] || Check(n, b[i]) == 0) continue;
//		chk[i] = 1; s[n] = b[i];
//		if (DFS(n + 1) == 1) return 1;
//		chk[i] = 0;
//	}
//	return 0;
//}
//
//int main(void){
//	int i, k, l, max = 0, maxi;
//	scanf("%d %d", &N, &M);
//	for (i = 1; i <= M; i++){
//		scanf("%d %d", &k, &l);
//		a[k][l] = 1;
//	}
//	for (i = 1; i <= N; i++){
//		scanf("%d", &b[i]);
//		if (max < b[i]) {
//			max = b[i]; maxi = i;
//		}
//	}
//
//	s[1] = max; chk[maxi] = 1;
//	if (DFS(2) == 1){
//		for (i = 1; i <= N; i++) printf("%d ", s[i]);
//	}
//
//	else printf("-1");
//	return 0;
//}