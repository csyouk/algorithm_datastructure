#include <stdio.h>
#include <string.h>
enum State{WIN, DRAW, LOSE};
int sol[6][3];
int table[6][4];
int possibility;
void Init(void){
    memset(&table[0][0], 0, sizeof(int [6][4]));
    possibility = 0;
}
int is_match(int t1, int t2){
    int i;
    for (i = 0; i < 3; i++)
    {
        if (table[t1][i] != sol[t1][i]) return 0;
    }
    return 1;
}
void DFS(int n, int o, int cmp){
    int i, j, k, origin = o;
    if (n == 15){
        for ( i = 0; i < 6; i++)
        {
            for ( j = 0; j < 3; j++)
            {
                if (table[i][j] != sol[i][j]) return;
            }
        }
        possibility = 1;
        return;
    }
    for ( i = 0; i < 3; i++)
    {
        table[origin][i]++; table[cmp][2 - i]++; table[origin][3]++; table[cmp][3]++;
        if (cmp > 4) {
            if (is_match(origin, cmp)) { DFS(n + 1, origin + 1, origin + 2); }
        } else {
            DFS(n + 1, origin, cmp + 1);
        }
        table[origin][i]--; table[cmp][2 - i]--; table[origin][3]--; table[cmp][3]--;
        if (possibility) return;
    }
}
int main(void){
    int i, j, k;
    for (i = 0; i<4; i++){
        Init();
        for ( j = 0; j < 6; j++)
        {
            for ( k = 0; k < 3; k++)
            {
                scanf("%d ", &sol[j][k]);
            }
        }
        DFS(0, 0, 1);
        printf("%d ", possibility);
    }
    return 0;
}
