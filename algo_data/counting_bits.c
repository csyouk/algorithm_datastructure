#include <stdio.h>

int coutung_1bit(unsigned int x){
	x = x - ((x >> 1) & 0x55555555);
	x = (x &  0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0f0f0f0f;
	x = x + (x >> 8);
	x = x + (x >> 16);
	return x & 0x0000003f;
}

int main(void){

	printf("1 : %d / 0 : %d", coutung_1bit(0xbc637eff), 32 - coutung_1bit(0xbc637eff));
	return 0;
}