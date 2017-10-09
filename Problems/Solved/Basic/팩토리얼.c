// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=589&sca=2070
#include <stdio.h>
#define ULL unsigned long long int
ULL N;

ULL factorial(ULL num){
  if(num==1){
    printf("%llu! = %llu\n", num, num);
    return num;
  }
  printf("%llu! = %llu * %llu!\n", num, num, num-1);
  return num*factorial(num-1);
}

ULL main(void){
  scanf("%llu", &N);
  printf("%llu",factorial(N));
  return 0;
}
