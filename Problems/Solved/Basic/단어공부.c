// 출처 백준
#include <stdio.h>

char an[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int memo[sizeof(an)-1];
char input[1000001];

int ctoi(char c)
{
    if('a'<=c && c<='z') return c-'a';
    if('A'<=c && c<='Z') return c-'A';
    return sizeof(an); // non alphanumeric case
}

int main(void)
{
    int max=0, max_i=-1;
    int i =0;

    scanf("%s", input);


    while(input[i])
    {
        memo[ctoi(input[i])]++;
        i++;
    }

    for (i =0; i<(sizeof(memo)/sizeof(int)); i++) {
        if(memo[i] > max)
        {
            max = memo[i];
            max_i = i;
            continue;
        }
        if(memo[i] == max){
            max_i = sizeof(an) - 1;
        }
    }

    if(max_i <sizeof(an)-1){
        printf("%c", an[max_i]);
    }else{
        printf("?");
    }

    return 0;
}
