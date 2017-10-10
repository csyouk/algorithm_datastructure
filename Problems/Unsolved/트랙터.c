시스템 운영 문의 : keyseek@naver.com, 코드 리뷰 및 정답 요청은 사양합니다. 배열명으로 "end" 사용 금지 = 채점 시스템 예약어로 segmentation fault 발생
문제 번호 G: [TST] 트랙터
시간 제한: 1 Sec  메모리 제한: 128 MB
제출: 290  해결 문제 수: 110
[제출][채점 상황 열람]
문제 설명
농부 존의 들판은 높은 곳이 많아서 그 주위를 돌아다니기 위해 새로운 트랙터를 구입하려고 한다. 들판은 N*N 크기 격자이고 각 격자에는 높이를 표시하는 음이 아닌 정수 값이 있다 (1≤N≤500). 트랙터는 인접한 격자(동서남북)로 이동할 수 있는데, 높이 차이(D)가 나는 곳으로 이동 하려면 D만큼 이동 할 수 있는 성능을 가져야 하는데 그 만큼 비싸진다.

농부 존은 그의 들판의 어느 곳에서 출발했을 때 적어도 들판의 절반이상을 돌아다닐 수 있는 트랙터를 구입하고 싶다. 만약 들판의 총 격자수가 홀 수 이면, 반 올림 개수만큼 방문한다. 즉, 3*3이면 총 9격자이므로 적어도 5곳은 방문할 수 있어야 한다.

농부 존을 도와서 그가 원하는 일을 할 수 있는 트랙터를 최소 비용으로 구매할 수 있게 하자.
* C 제출은 다음 Template을 복사하여 코드를 작성하시오.

#include <stdio.h>

int main(void)
{
      // 여기서부터 작성

      return 0;
}
* C++ 제출은 다음 Template을 복사하여 코드를 작성하시오.

#include <iostream>
using namespace std;

int main(void)
{
      // 여기서부터 작성

      return 0;
}
* JAVA 제출은 다음 Template을 복사하여 코드를 작성하시오.

import java.util.Scanner;

public class Main {

      public static void main(String[] args) {

            // 여기서부터 작성

      }
}
입력
첫 번째 줄에 N이 입력된다. (1≤N≤500)
두 번째 줄부터 N줄에 걸쳐 N개씩 공백으로 구분되어, 1,000,000 이하의 음이 아닌 정수 값으로 높이가 입력된다.
출력
농부 존이 들판을 적어도 반 이상 돌아다닐 수 있는 트랙터의 최소 성능 D를 출력하라.
입력 예시
5
0 0 0 3 3
0 0 0 0 3
0 9 9 3 3
9 9 9 3 3
9 9 9 9 3
출력 예시
3
도움말
[입력 예시 2]
4
8 8 8 8
6 6 7 7
3 3 3 6
2 2 1 5

[출력 예시 2]
1


#include <stdio.h>

int N;
int map[502][502];
int chk[502][502];

void Input_Data(void)
{
    int r, c;
    scanf("%d",&N);
    for (r = 1; r <= N;r++)
    {
        for (c = 1; c <= N;c++)
        {
            scanf("%d",&map[r][c]);
        }
    }

    for (r = 0; r <= N + 1;r++)
    {
        chk[0][r] = 1;
        chk[N+1][r] = 1;
        chk[r][0] = 1;
        chk[r][N+1] = 1;
    }
}

int ff_cnt;


#define ABS(X) (((X)<0)?(-(X)):(X))


void Flood_Fill(int r, int c, int power)
{
    int i, nr, nc;
    static int dr[] = { 0, 0, 1, -1 };
    static int dc[] = { 1, -1, 0, 0 };

    chk[r][c] = 1;
    ff_cnt++;

    for (i = 0; i < 4;i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if (chk[nr][nc] == 0 && ABS(map[r][c] - map[nr][nc]) <= power)
        {
            Flood_Fill(nr, nc, power);
        }
    }
}


void Init_Check(void)
{
    int r, c;

    for (r = 1; r <= N;r++)
    {
        for (c = 1; c <= N;c++)
        {
            chk[r][c] = 0;
        }
    }
}


int Check(int power)
{
    int r, c;
    int threhold = N*N/2+(N%2);

    Init_Check();

    for (r = 1; r <= N;r++)
    {
        for (c = 1; c <= N;c++)
        {
            if (chk[r][c] == 0)
            {
                ff_cnt = 0;
                Flood_Fill(r, c, power);
                if (threhold <= ff_cnt) return 1;
            }
        }
    }
    return 0;


}



int Find_Solution(void)
{
    int s, e, m,sol;

    s = 0; e = 1000000;

    while (s<=e)
    {
        m = (s + e) / 2;
        if (Check(m))
        {
            sol = m;
            e = m - 1;
        }
        else s = m + 1;
    }

    return sol;
}




int main(void)
{
    Input_Data();

    printf("%d\n",Find_Solution());

    return 0;
}
