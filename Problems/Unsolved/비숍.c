
#include <stdio.h>
#pragma warning (disable:4996)

int a[20 + 10][20 + 10];
int N, N21;
int MAX;
int block[20 + 10];

void DFS(int n, int num) {
    int k;

    // cut.
    if (num + N - n/2 <= MAX) return;

    // leaf.
    if (n > N21) {
        if (MAX < num) MAX = num;
        return;
    }

    // tree.

    // 두는 경우
    for (k = 1; k <= N; k++) {
        if (!(n + 1 - k)) break;
        if (!a[n+1-k][k]) continue;
        if (block[20 - (n + 1 - k) + k]) continue;

        block[20 - (n + 1 - k) + k] = 1;
        DFS(n + 2, num + 1);
        block[20 - (n + 1 - k) + k] = 0;
    }

    // 안두는 경우.
    DFS(n + 2, num);
}

int main(void) {
    int i, j, tmp;
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    N21 = N * 2 - 1;

    tmp = 0;
    DFS(1,0);
    tmp += MAX;
    MAX = 0;
    DFS(2,0);
    tmp += MAX;
    printf("%d", tmp);
    return 0;
}
