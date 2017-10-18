#include <stdio.h>

int T, N, K, CNT, ESCAPE;
int block[10000000];
int note[10];

int check(int n, int k) {
    int i;

    if (block[k]) return 1;
    for (i=n-1; i>=1; i--) {
        k *= note[i];
        if (block[k]) return 1;
    }
    return 0;
}

void lock(int n, int k) {
    int i;
    block[k] = 1;
    for (i=n-1; i>=1; i--) {
        k *= note[i];
        block[k] = 1;
    }
}

void unlock(int n, int k) {
    int i;
    block[k] = 0;
    for (i=n-1; i>=1; i--) {
        k *= note[i];
        block[k] = 0;
    }
}

void DFS(int n) {
    int k;
    // leaf
    if (n>N) {
        CNT++;
        if (CNT == K) {
            for (k=1; k<=N; k++) printf("%d", note[k]);
            printf("\n");
            ESCAPE = 1;
        }
        return;
    }

    // tree
    for (k=2; k<=9; k++) {

        if (check(n,k)) continue;

        lock(n,k);
        note[n] = k;
        DFS(n+1);
        unlock(n,k);

        if (ESCAPE) return;
    }
}

int main()
{
    int k;
    scanf("%d", &T);
    for (k=1; k<=T; k++) {
        scanf("%d %d", &N, &K);

        if (N==1 && K<=10) {
            printf("%d\n", K-1);
            continue;
        }

        if (N>=9) {
            printf("NONE\n");
            continue;
        }

        ESCAPE = 0;
        CNT = 0;
        DFS(1);

        if (!ESCAPE) printf("NONE\n");
    }
    return 0;
}
