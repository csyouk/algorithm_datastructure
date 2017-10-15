#include <stdio.h>

int is_prime(int n){
		int i;
		if (n == 1 || n == 2) return 1;
		for ( i = 3; i*i <= n; i++)
		{
				if (!(n%i)) return 0;
		}
		return 1;
}



// 에라토스테네스의 체
// 배열을 만들어 놓고, 소수의 배수들은 소수가 아니니, 표시를 해놓는다.
#include <math.h>
#define MAX 10000000
#define PRIME 0
#define NOT_PRIME 1

int nums[MAX]; 
int Eratos(){
// 작은 숫자들부터 순차적으로 확인을 하면서 
//  소수면 0, 소수가 아니면 1을 nums 배열에 체크해놓는다.
// 만약에 탐색범위가 10000000이라면, 탐색 범위를 sqrt(10000000) 까지만 하면 된다.
		int i, j;
		nums[0] = nums[1] = 1;
		for (i = 2; i <= sqrt(MAX); i++)
		{
				if (!nums[i]){
						for (j = 2 * i; j <= MAX; j += i)
						{
								nums[j] = 1;
						}
				}
		}
}

int main(void){
	
  printf("%d", is_prime(324161900711111));

	Eratos();
	return 0;
}