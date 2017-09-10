//
//  암소미인대회.c
//  codeground
//
//  Created by youkchangsu on 2017. 8. 30..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 0
#include <stdio.h>
#define DIRS 4
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
typedef struct _pos{
    unsigned char x;
    unsigned char y;
} Pos;
Pos seg1[50 * 50];
Pos seg2[50 * 50];
Pos seg3[50 * 50];
Pos minseg1, minseg2, minseg3;
int seg1cnt, seg2cnt, seg3cnt;
int N, M;
char farm[60][60];
int chk[60][60];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Init(){
    for (int i = 0; i <=N; i++) {
        farm[i][0] = '.';
    }
}
void p_all(void)
{
    printf("check \n");
    for (int i = 1; i <=N; i++) {
        for (int j =0 ; j<=M; j++) {
            printf("%d", chk[i][j]);
        }
        printf("\n");
    }
    
    printf("farm \n");
    for (int i = 1; i <=N; i++) {
        printf("%s\n",farm[i]);
    }
}
void Fill(int i, int j, int mark)
{
    int k, ni, nj;
    if (chk[i][j] != 0) return;
    chk[i][j] = mark;
    if (mark == 1){
        seg1[seg1cnt].x = i;
        seg1[seg1cnt].y = j;
        seg1cnt++;
    }
    else if (mark == 2)
    {
        seg2[seg2cnt].x = i;
        seg2[seg2cnt].y = j;
        seg2cnt++;
    }
    else if (mark == 3)
    {
        seg3[seg3cnt].x = i;
        seg3[seg3cnt].y = j;
        seg3cnt++;
    }
    for ( k = 0; k < DIRS; k++)
    {
        ni = i + di[k]; nj = j + dj[k];
        if (farm[ni][nj] == 'X'){
            Fill(ni, nj, mark);
        }
    }
}
int cal(void)
{
    int i, j,x, y, sum = 0;
    int dis=0x7fffffff;
    for ( i = 0; i <seg1cnt; i++)
    {
        for ( j = 0; j <seg2cnt; j++)
        {
            x = ABS( seg1[i].x - seg2[j].x );
            y = ABS( seg1[i].y - seg2[j].y );
            if (x + y < dis){
                minseg1.x = seg1[i].x;
                minseg1.y = seg1[i].y;
                
                minseg2.x = seg2[j].x;
                minseg2.y = seg2[j].y;
                dis = x + y;
                sum += dis - 1;
            }
        }
    }
    
    
    dis=0x7fffffff;
    for ( i = 0; i <seg2cnt; i++)
    {
        for ( j = 0; j <seg3cnt; j++)
        {
            x = ABS( seg2[i].x - seg3[j].x );
            y = ABS( seg2[i].y - seg3[j].y );
            if (x + y < dis){
                minseg2.x = seg2[i].x;
                minseg2.y = seg2[i].y;
                
                minseg3.x = seg3[j].x;
                minseg3.y = seg3[j].y;
                dis = x + y;
                sum += dis - 1;
            }
        }
    }
    
    dis=0x7fffffff;
    for ( i = 0; i <seg3cnt; i++)
    {
        for ( j = 0; j <seg1cnt; j++)
        {
            x = ABS( seg1[i].x - seg3[j].x );
            y = ABS( seg1[i].y - seg3[j].y );
            if (x + y < dis){
                minseg1.x = seg1[i].x;
                minseg1.y = seg1[i].y;
                
                minseg3.x = seg3[j].x;
                minseg3.y = seg3[j].y;
                dis = x + y;
                sum += dis - 1;
            }
        }
    }
    return sum;
}
int main(void)
{
    freopen("/Users/youk/workspace/scsa/codeground/codeground/in.txt", "r", stdin);
    int i, j, mark = 0;
    // 여기서부터 작성

    scanf("%d %d", &N, &M);
    Init();
    for ( i = 1; i <=N; i++)
    {
        scanf("%s", &farm[i][1]);
    }
    
    for ( i = 1; i <=N; i++)
    {
        for ( j = 1; j <=M; j++)
        {
            if (farm[i][j] == 'X' && chk[i][j] == 0)
            {
                mark++;
                Fill(i, j, mark);
            }
        }
    }
    p_all();
    cal();
    printf("%d", ABS(minseg2.x - minseg1.x) + ABS(minseg2.y - minseg1.y) - 1);
    
    return 0;
}
#endif
