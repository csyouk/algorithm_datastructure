
#if 0
정사각형은 4개의 꼭지점을 갖는다.하나의 정사각형에서 가로 줄과 세로 줄을 1개씩 추가하여 같은 크기의 정사각형 4개로 나누면 꼭지점의 개수는 9개가 된다.이 상태에서 4개로 나누어진 각각의 정사각형에 가로줄과 세로줄을 1개씩 추가하면 16개의 정사각형으로 나누어지고 꼭지점의 개수는 25개가 된다.이와 같은 상황에 대한 그림이 아래에 있다.

아래 그림에서 검은 색 점은 가로 줄과 세로줄을 추가할 때 새로 생기는 점들이다.



초기 정사각형에서 위와 같은 방법으로 가로줄과 세로줄을 추가하여 나누는 것을 1 - iteration이라고 하자.iteration 의 수 N을 입력 받아 N번의 iteration 후의 꼭지점의 총 개수를 출력하는 프로그램을 작성하시오.
* C 솔루션은 다음 코드를 참조하시오.
입력
iteration 의 수 N(1 ≤ N ≤ 15)이 입력된다.
출력
N-iteration 후 꼭지점의 총 수를 출력하시오.
#include <stdio.h>

int N;
int sol;

int main(void)
{

	scanf("%d", &N);


	sol = ((1 << N) + 1) * ((1 << N) + 1);


	printf("%d", sol);

	return 0;
}
#endif
