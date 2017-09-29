#if 00
#include <stdio.h>

int recur(int n){
	if (n == 1) return 0;
	printf("re!\n");
	return recur(n - 1);
}

int main(int argc, char **argv){

	int b = 5;

	recur(10);
	//getchar();


	printf("%d\n", argc);
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);

	return 0;
}
#endif