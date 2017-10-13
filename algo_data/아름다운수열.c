#include <stdio.h>
int T, N, K;

int B(int n, int k){}


int main(void){
	int i, sol;
	scanf("%d", &T);
	for ( i = 1; i <=T; i++)
	{
		scanf("%d %d", &N, &K);
		sol = B(N, K);
		if (sol) printf("%d\n", sol);
		else printf("NONE\n");
	}



	return 0;
}