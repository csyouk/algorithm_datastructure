//
//  ntoh.c
//  codeground
//
//  Created by youkchangsu on 2017. 8. 13..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 0
#include <stdio.h>
int hton(int n, int h)
{
    int d = 0, m = 1;
    while (h)
    {
        d += (h % 16) * m;
        h /= 16;
        m *= n;
    }
    return d;
}


int ntoh(int n, int num)
{
    int h = 0, m = 1;
    while(num)
    {
        h += (num % n) * m;
        num /= n;
        m *= 16;
    }
    return h;
}

void main(void)
{
    int n, a, b, s;
    printf("진법 입력 : ");
    scanf("%d", &n);
    printf("피연산자 2개 입력 : ");
    scanf("%x %x", &a, &b);
    a = hton(n, a);
    b = hton(n, b);
    printf("%d %x\n", a + b, ntoh(n, a + b));
}

#endif
