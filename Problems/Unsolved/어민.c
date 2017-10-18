#include <stdio.h>

int N;

typedef struct
{
    int pos;
    int fish;
}TOWN;

TOWN town[100000];

void Input_Data(void)
{
    int i;
    scanf("%d", &N);
    for (i = 0; i<N; i++)
    {
        scanf("%d %d", &town[i].pos, &town[i].fish);
    }
}

int Check(int child)
{
    int i;
    //carry 의 개념. 남는건 +, 빌려오는 것은 -
    long long int c = 0;

    // 첫 마을부터 이전마을까지.
    for (i = 0; i<N - 1; i++){
        if ((town[i].fish + c) < child){
            // 부족한 양 만큼 빌려온다. + 세금 양 추가.
            c = -(child - (town[i].fish + c) + (town[i + 1].pos - town[i].pos));
        } else {
            // 물고기가 많다. 물고기가 많으니 다음 마을에 넘겨준다. + 세금 추가
            c = ((town[i].fish + c) - child - (town[i + 1].pos - town[i].pos));
            // 세금이 음수가 나오면 안 주는 것이 낫다.
            if (c<0) c = 0;
        }
    }
    // 마지막 마을에 대해서 검사.
    if ((town[N - 1].fish + c) >= child) return 1;
    else return 0;
}



int Find_Max(void)
{
    int s, e, m;
    int sol;

    // 범위를 설정할 때 사용하는 코드이다.
    e = 1;
    while (Check(e)) e *= 2;
    // s 는 가능한 범위의 값.
    s = e / 2;

    while (s <= e)
    {
        m = (s + e) / 2;

        if (Check(m))
        {
            sol = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return sol;
}




int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        Input_Data();
        printf("%d\n", Find_Max());
    }

    return 0;
}
