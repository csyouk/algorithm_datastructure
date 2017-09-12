//
//  둘레(Bronze).c
//  codeground
//
//  Created by youkchangsu on 2017. 8. 30..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 0
#include <stdio.h>
#define DIRS 4
#define LEN 120
char a[LEN][LEN];
char chk[LEN][LEN];
int N,x,y;
int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void init()
{
    int i,j;
    for (i=0; i<LEN; i++) {
        for (j=0; j<LEN; j++) {
            a[i][j] = '.';
            chk[i][j] = '0';
        }
    }
}
void pprint(void)
{
    int i;
    printf("area\n");
    for (i=0; i<LEN; i++) {
        printf("%s\n", a[i]);
    }
    
    printf("check\n");
    for (i=0; i<LEN; i++) {
        printf("%s\n", chk[i]);
    }
}
void Fill(int i, int j, int mark)
{
    int ni,nj,k;
    if(chk[i][j] == '0'+mark) return;
    chk[i][j] = mark + '0';
    
    
    for (k=0; k<DIRS; k++) {
        ni = i + di[k]; nj = j + dj[k];
        if(a[ni][nj] == '.'){
            Fill(ni,nj,mark);
        }
    }
}
void start_check(void)
{
    int i,j, mark=0;
    for (i=1; i<LEN-2; i++) {
        for (j=1; j<LEN-2; j++) {
            if(a[i][j] == '.' && chk[i][j] == '0')
            {
                mark++;
                Fill(i,j,mark);
            }
        }
    }

}
int main(void)
{
    // 여기서부터 작성
    freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);
    int i,j, cnt=0;
    scanf("%d", &N);
    init();
    for (i =0; i<N; i++) {
        scanf("%d %d",&x, &y);
        a[x][y] = 'X';
    }
    
    
    
    start_check();
    
//    pprint();
    
    for (i = 1; i<LEN; i++) {
        for (j=1; j<LEN; j++) {
            if(chk[i][j] == '1') continue;
            if(chk[i][j] == '0'){
                if(chk[i-1][j] == '1') cnt++;
                if(chk[i+1][j] == '1') cnt++;
                if(chk[i][j-1] == '1') cnt++;
                if(chk[i][j+1] == '1') cnt++;
            }
        }
    }
    
    printf("%d", cnt);
    return 0;
}
#endif
