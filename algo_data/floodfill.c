


#if 0
#include <stdio.h>

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, k, chk[26][26], cnt[26 * 26];
char arr[26][26];

void fill(int x, int y) {
	chk[x][y] = k;
	arr[x][y] = '0';
	cnt[k]++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (arr[nx][ny] == '1') fill(nx, ny);
	}
}

int main() {
	int i, j;
	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%s", arr[i]);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++){
			if (arr[i][j] == '1' && !chk[i][j]) {
				k++; fill(i, j);
			}
		}
	}

	printf("%d\n", k);
	for (i = 1; i <= k; i++) printf("%d\n", cnt[i]);

	return 0;
}
#endif

#if 0
#include <stdio.h>
#define SIZE 8
int N, mark = 1;
int c[SIZE][SIZE];
int chk[SIZE][SIZE];
int cnt[SIZE * SIZE / 2];
int di[] = { -1, 1, 0, 0}; // 상하 좌우
int dj[] = { 0, 0, -1, 1 }; // 상하 좌우

void Fill(int i, int j, int mark)
{
	int k, ni, nj;
	if (chk[i][j] == mark) return;
	chk[i][j] = mark;
	cnt[mark]++;
	for ( k = 0; k < 4; k++)
	{
		ni = i + di[k]; nj = j + dj[k];
		if (c[ni][nj] == 1){
			Fill(ni, nj, mark);
		}
	}
}

int main(void)
{
	// 여기서부터 작성
	freopen("in.txt", "r", stdin);
	int i, j, tmp;

	scanf("%d", &N);
	for ( i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%1d", &c[i][j]);
		}
	}

	for ( i = 1; i <=N; i++){
		for ( j = 1; j <=N; j++){
			if (c[i][j] == 1 && chk[i][j] == 0){
				Fill(i, j, mark); mark++;
			}
		}
	}

	for (i = 0; i < mark-1; i++)
	{
		for ( j = i+1; j < mark; j++)
		{
			if (cnt[i] > cnt[j]){
				tmp = cnt[i];
				cnt[i] = cnt[j];
				cnt[j] = tmp;
			}
		}
	}

	printf("%d\n", mark);
	for ( i = 0; i < mark; i++)
	{
		printf("%d\n", cnt[i]);
	}

	return 0;
}
#endif
