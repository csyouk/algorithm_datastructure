#include <stdio.h>
#define CHAR_BIT 8

int main(void){


	// compute sign of the integer
	int v;
	int sign;
	
	scanf("%d", &v);

	sign = + 1 | ( v >> (sizeof(int) * CHAR_BIT - 1));

	printf("compute sign of the integer : %d \n", sign);


	// detect if two integers have opposite integers
	int x, y;
	x = 2; y = 3;
	printf("detect if two integers have opposite integers : %d \n",
		((x ^ y) < 0 ) );

	x = 1<<31; y = (~(1<<31));
	printf("detect if two integers have opposite integers : %d \n",
		((x ^ y) < 0));


	// compute the absolute value without branching
	// Not work
	//int k;
	//unsigned int r;

	//k = -100020;

	//int const mask = ((k >> sizeof(int)) * CHAR_BIT) - 1;

	//r = (k + mask) ^ mask;

	//printf("compute the absolute value without branching : %d \n", r);

	//r = (k ^ mask) - mask;

	//printf("compute the absolute value without branching : %d \n", r);


	return 0;
}