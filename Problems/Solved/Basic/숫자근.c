#if 0
#include <stdio.h>
#define ULL unsigned long long int
int N;
typedef struct _digit
{
    ULL origin;
    int root;

} Digit;
Digit digit = { 0xFFFFFFFFFFFFFFFF, 0};

int main(void)
{
    ULL digit_root;
    ULL tmp;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {

        scanf("%llu", &digit_root);
        tmp = digit_root;
        while (digit_root / 10)
        {
            digit_root = digit_root / 10 + digit_root % 10;
        }
        if (digit.root < (int)digit_root)
        {
            digit.origin = tmp;
            digit.root = (int)digit_root;
            continue;
        }
        if(digit.root == (int)digit_root && tmp < digit.origin)
        {
            digit.origin = tmp;
        }
//        printf("\n%llu %llu %d %d\n", digit.origin, tmp,digit.root, digit_root);
    }

    printf("%llu\n", digit.origin);
    return 0;
}
#endif


#include <stdio.h>
#include <string.h>
// JUNG 1260
#if 0
int N;
unsigned long long int data;

int main(void)
{
	int digit_root = 0;
	int tmp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		data = 0;
		scanf("%llu", &data);
		tmp = data;
		while (data / 10)
		{
			data = data / 10 + data % 10;
		}
		if (digit_root < data) digit_root = tmp;
	}

	printf("result=%d\n", digit_root);
}
#endif

//	숫자근
#if 0
#include <stdio.h>
int N, sol;
int Root(int n){
	int sum;
	for (;;){
		sum = 0;
		while (n > 0){ sum += n % 10;				n /= 10; }
		if (sum < 10)	break;
		n = sum;
	}
	return sum;
}
int main(void){
	int i, n, root, max = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &n);
		root = Root(n);
		if (max < root){
			max = root;	sol = n;
		}
		else if (max == root){
			if (sol > n) sol = n;
		}
	}
	printf("%d", sol);
	return 0;
}
#endif
