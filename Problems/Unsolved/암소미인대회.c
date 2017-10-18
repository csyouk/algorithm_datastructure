#if 01
#pragma warning (disable:4996)
#include <stdio.h>

#define abs(a) ( ((a)>0) ? (a) :(-(a)) )
#define DOTS 3
#define MAX(a,b) ( ((a)>(b))?(a):(b) )

int a[50 + 10][50 + 10];
int ch[50 + 10][50 + 10];
int R, C;
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int start_index;

int dots[DOTS][2500 + 10][2]; // groups, pts, [x,y];
int dot_index;
int dot_cnt[DOTS];

//void ch_clear(void);
void ch_print(void);

// fill map & dots array.
void fill(int x, int y, int index) {
    int i, xi, yi;

    ch[x][y] = 1;
    dots[index][dot_cnt[index]][0] = x;
    dots[index][dot_cnt[index]][1] = y;
    dot_cnt[index]++;

    for (i = 0; i < 4; i++) {
        xi = x + dir[i][0];
        yi = y + dir[i][1];
        if (a[xi][yi] == 1 && ch[xi][yi] == 0) fill(xi, yi, index);
    }
}

int dist(int index1, int index2) {
    int min = 100;
    int i, j, tmp;
    for (i = 0; i < dot_cnt[index1]; i++) {
        for (j = 0; j < dot_cnt[index2]; j++) {
            tmp = abs(dots[index1][i][0] - dots[index2][j][0]) + \
                abs(dots[index1][i][1] - dots[index2][j][1]);
            if (tmp < min) min = tmp;
        }
    }
    return min;
}

int dot_dist(int x, int y) {
    int min[DOTS] = { 100, 100, 100 };
    int i, k, tmp, sum;

    sum = 0;
    for (k = 0; k < DOTS; k++) {
        for (i = 0; i < dot_cnt[k]; i++) {
            tmp = abs(dots[k][i][0] - x) + \
                abs(dots[k][i][1] - y);
            if (tmp < min[k]) min[k] = tmp;
        }
        sum += min[k];
    }
    return sum-2;
}

int main(void) {
    int i, j, tmp, tmp2;
    char input;
    scanf("%d %d", &R, &C);
    for (i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++) {
            scanf(" %c", &input);
            if (input == 'X') a[i][j] = 1;
        }
    }

    // find start pts
    start_index = 0;
    for (i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++) {
            if (a[i][j] == 1 && ch[i][j] == 0) {
                fill(i, j, start_index);
                start_index++;
            }
        }
    }

    //CASE1 : minimum dist (two brideges)
    tmp = MAX( dist(0, 1), dist(1, 2) );
    tmp = MAX(tmp, dist(0, 2)) - 1;
    tmp = dist(0, 1) - 1 + dist(1, 2) - 1 + dist(0, 2) - 1 - tmp;

    //CASE2: minimun dist (third bridges)
    tmp2 = 100;
    for (i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++) {
            if (a[i][j] == 0) {
                tmp2 = dot_dist(i,j);
                if (tmp2 < tmp) tmp = tmp2;
            }
        }
    }

    printf("%d", tmp);
    //ch_print();
    //ch_clear();
    return 0;
}

//
// helper functions.
//
//void ch_clear(void) {
//  int i, j;
//  for (i = 1; i <= R; i++) {
//      for (j = 1; j <= C; j++) {
//          a[i][j] = 0;
//      }
//  }
//}
//
//void ch_print(void) {
//  int i, j;
//  for (i = 1; i <= R; i++) {
//      for (j = 1; j <= C; j++) {
//          printf("%d ", ch[i][j]);
//      }
//      printf("\n");
//  }
//}
#endif
