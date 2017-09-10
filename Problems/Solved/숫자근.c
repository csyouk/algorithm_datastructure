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
