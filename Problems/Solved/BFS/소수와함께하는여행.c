#if 0
#include <stdio.h>
#define MAX_Q 1000000
typedef struct {
	int p, cnt;
} BUS;

BUS Q[MAX_Q];

int S, E;
int primes[2][2000];
int RP, WP;
int total_primes;

int is_prime(int);




int diff(int p1, int p2){
	int i, rep = 0;
	for ( i = 0; i < 4; i++)
	{
		if ((p1 % 10) != (p2 % 10)) rep++;
		p1 /= 10; p2 /= 10;
	}
	return rep;
}

void Init(void){
	int i;
	int s = 1009; 
	int e = 9973;

	for ( i = s; i <= e; i++)
	{
		if (is_prime(i)) {
			primes[0][total_primes++] = i;
		}
	}

}

int is_prime(int n){
	int i;
	if (n == 2 || n == 3) return 1;
	for ( i = 2; i <= (n/2 + 1); i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}

int BFS(){
	BUS out, in;
	int i;
	in.p = S; in.cnt = 0;
	Q[WP++] = in;


	while (RP != WP)
	{
		out = Q[RP++];
		if (RP % MAX_Q == 0) RP = 0;
		if (out.p == E) return out.cnt;
		for ( i = 0; i < total_primes; i++)
		{
			if (out.p == primes[0][i] || primes[1][i]) continue;
			if (diff(out.p, primes[0][i]) != 1) continue;
			Q[WP].p = primes[0][i]; Q[WP++].cnt = out.cnt + 1;
			primes[1][i] = 1;
			if (WP % MAX_Q == 0) WP = 0;
		}
	}
	return -1;
}

int main(void){
	int tmp;
	scanf("%d %d", &S, &E);
	if (S >= E){
		tmp = E;
		E = S; 
		S = tmp;
	}

	Init();

	printf("%d", BFS());


	return 0;
}
#endif