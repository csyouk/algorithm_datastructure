// 메모에제이션 기법
#if 01
#include <stdio.h>
#define MAX_Q 20000
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


	while (RP < WP)
	{
		out = Q[RP++];
		if (out.p == E) return out.cnt;
		for ( i = 0; i < total_primes; i++)
		{
			if (out.p == primes[0][i] || primes[1][i]) continue;
			if (diff(out.p, primes[0][i]) != 1) continue;
			Q[WP].p = primes[0][i]; Q[WP++].cnt = out.cnt + 1;
			primes[1][i] = 1;
		}
	}
	return -1;
}

int main(void){
	int tmp;
	scanf("%d %d", &S, &E);
	Init();
	printf("%d", BFS());
	return 0;
}
#endif


// 선생님 풀이
#if 1
#include <stdio.h>
#include <math.h>

#define MAX (9999)

typedef struct
{
    int prime;
    int level;
}QUEUE;

QUEUE Queue[10000];
int Wr,Rd;

int Not_Prime[10000];
int Visited[10000];

int Prime_Tour(int S,int E)
{
    int i,j;
    int tens;
    int num;
    int base;
    QUEUE data,newdata;


    data.prime = S;
    data.level = 0;
    Queue[Wr++] = data;

    while(Rd != Wr)
    {
        tens = 10;
        num = 1;
        data = Queue[Rd++];
        newdata.level = data.level+1;
        for(i=0;i<4;i++)
        {
            base = data.prime - (data.prime%tens/num)*num;
            for(j=(i==3)?1:0;j<=9;j++)
            {
                newdata.prime = base + j*num;
                if(!Not_Prime[newdata.prime] && !Visited[newdata.prime])
                {
                    if(newdata.prime == E) return newdata.level;
                    Queue[Wr++] = newdata;
                    Visited[newdata.prime] = 1;
                }
            }
            num *= 10;
            tens *= 10;

        }
    }
    return -1;
}




void Make_PrimeTable(void)
{
    int limit = sqrt(MAX);
    int i,j;

    Not_Prime[0] = 1;
    Not_Prime[1] = 1;
    for(i=2;i<=limit;i++)
    {
        if(!Not_Prime[i])
        {
            for(j=i+i;j<=MAX;j+=i) Not_Prime[j] = 1;
        }
    }
}

int main(void)
{
    int S,E;
    int ret;

    Make_PrimeTable();

    scanf("%d %d",&S,&E);

    ret = Prime_Tour(S,E);

    printf("%d\n",ret);
    return 1;
}
#endif
