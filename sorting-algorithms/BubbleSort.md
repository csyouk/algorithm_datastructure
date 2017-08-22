# Bubble Sort
- 버블 정렬의 아이디어는 다음과 같다.
  - 가장 큰 값을 뒤로 보내면서 정렬을 시키거나(오름차순)
  - 가장 작은 값을 뒤로 보내면서 정렬을 시키거나(내림차순)
- 즉, 정렬을 시키는 기준이 데이터의 종단점이다.

```cpp

다음과 같은 데이터가 있다고 가정해보자.
typedef struct {
  int id;
  int score;
  char name[10];
} SCORE;
#define MAX_ST 20
SCORE exam[MAX_ST];

함수의 원형은 다음과 같다.
int Sort_Bubble(SCORE *d, int order, int(*comp)(SCORE * x, SCORE * y));
parameter분석을 해보자.
- d는 정렬할 대상인 배열의 주소이다.
- order는 내림차순, 오름차순 옵션을 넘긴다.(1 : 오름차순, -1 : 내림차순)
- comp는 포인터 함수이다. 정렬의 기준에 해당하는 함수를 넘겨준다.(Id, Score, Name)

함수를 정렬하기에 앞서, 몇개의 데이터를 정렬해야하는지, 데이터의 크기를 알아야한다.
int max;
for (max = 0; max < MAX_ST; max++) {
  if(!d[max].id) break; // d배열의 id값이 0이 들어오면, 더이상 데이터가 존재하지 않는다고 생각한다.  
}

버블 정렬은 배열의 뒷부분부터 정렬된 값을 넣는다.
정렬을 하기 위해서는 기본적으로 2가지의 값을 비교해서, 그 2가지의 값의 대소에 따라서 자리를 이동시킨다.
2중 loop이 필요한데,

바깥 loop의 범위는 데이터 길이의 전 단계 만큼만 설정해주면 된다.
index는 0부터 시작하므로 -1을 추가로 빼준다.
이를 식으로 나타내면 다음과 같다.

for (int i = 0; i < max - 1; i++) {
  ...
}

혹은
for (int i = 0; i <= max - 2; i++) {
  ...
}

첫번째 loop가 회전수를 설정해주었다면, 두 번째 loop은 첫 요소부터 정렬이 완료된 요소의 이전까지를 비교한다.
이를 코드로 나타내면 다음과 같다.
for (int j = 0; j < max - 1 - i; j++) {
  ...
}

for (int j = 0; j <= max - 1 -1 - i; j++) {
  ...
}


두 번째 loop의 안쪽에서는 index j를 기준으로 j와 j+1의 요소를 비교해서 자리를 교체한다.
if(comp(d[j], d[j+1]) == order)
{
  tmp = d[j];
  d[j] = d[j+1];
  d[j+1] = tmp;
}
이때 유심히 봐야할 점은 comp함수를 통해서 두 비교대상의 대소의 상태를 3가지 상태로
표현했다는 점이다.
- 1 : 함수 호출 시, 인자로 넘긴 비교대상의 앞 데이터가 더 크다.
- 0 : 함수 호출 시, 인자로 넘긴 비교대상의 데이터가 동일하다.
- -1 : 함수 호출 시, 인자로 넘긴 비교대상의 뒤 데이터가 더 크다.

- 비교대상의 상태를 숫자로 대응 시키고, 이 숫자를 오름/내림 차순의 옵션으로 설정했다는 점이 인상적이다.
- 위와 같이 함으로써 정렬 알고리즘의 재활용성을 높였다.

위의 코드를 전부 완성시키면 다음과 같다.


int Sort_Bubble(SCORE *d, int order, int (* comp)(SCORE *x, SCORE *y))
{
  SCORE tmp; // 순서를 바꿀시에, 임시로 값을 넣어놓을 공간이 필요.
  int max;
  for (max = 0; max < MAX_ST; max++) {
    if(d[max].id == 0) break;
  }

  for (int i = 0; i < max - 1; i++) {
    for (int j = 0; j < max - 1 - i; j++) {
      if(comp(d[j], d[j+1]) == order)
      {
        tmp = d[j];
        d[j] = d[j+1];
        d[j+1] = tmp;
      }
    }
  }

  return max;
}

























```
