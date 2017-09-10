//
//  자리올림횟수찾기.c
//  codeground
//
//  Created by youkchangsu on 2017. 9. 2..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//
#if 0
#include <stdio.h>
int L,R;
int main(void)
{
  int carry = 0, flag = 0;
  int L_lsd = 0, R_lsd = 0;
  int sum;
  scanf("%d %d", &L, &R);
  
  
  while (L + R) {
    L_lsd = L % 10;
    R_lsd = R % 10;
    sum = L_lsd + R_lsd + flag;
    L /= 10;
    R /= 10;
    if(sum/10) {
      carry++;
      flag = 1;
    }else{
      flag = 0;
    };
  }
  
  
  
  if(carry == 1){ printf("%d carry operation.", carry);}
  else if(carry > 1){ printf("%d carry operations.", carry);}
  else{printf("No carry operation.");}
  
  return 0;
}
#endif


