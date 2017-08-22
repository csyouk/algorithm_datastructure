# Selection Sort
- 선택 정렬의 아이디어는 다음과 같다.
  - 정렬의 기준점은 버블 정렬과 같다.(데이터의 종단점부터 정렬이 된다.)
  - 버블 정렬처럼 데이터의 모든 메모리를 접근하는 것은 동일하다.
  - 하지만, 차이점이라면, 정렬을 하기 위해 데이터를 지속적으로 스캔하면서 가장 큰 데이터의 값의 **index**
  값을 가지고 있다는 뜻이다. 즉, 가장 큰 데이터 값의 **index** 값을 **선택** 해서 가지고 있어야 한다.


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
int Sort_Select(SCORE *d, int order, int (*comp)(SCORE *x, SCORE *y))
parameter분석을 해보자.
- d는 정렬한 대상의 첫 요소 주소가 들어간다.
- order는 내림차순, 오름차순 옵션을 넘긴다.(1 : 오름차순, -1 : 내림차순)
- comp는 포인터 함수이다. 정렬의 기준에 해당하는 함수를 넘겨준다.(Id, Score, Name)

함수를 정렬하기에 앞서, 몇개의 데이터를 정렬해야하는지, 데이터의 크기를 알아야한다.
int max;
for (max = 0; max < MAX_ST; max++) {
  if(!d[max].id) break; // d배열의 id값이 0이 들어오면, 더이상 데이터가 존재하지 않는다고 생각한다.  
}

선택 정렬은 버블 정렬과 마찬가지로 배열의 뒷부분부터 정렬된 값을 넣는다.
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

선택 정렬

두 번째 loop의 안쪽에서는 가장 최대의 값을 지시하고 있는 index t와 비교대상 j+1의 요소를 비교해서
j+1의 요소의 값이 t의 요소의 값보다 크다면, t의 값을 갱신한다.
if(comp(d[t], d[j+1]) == order)  t = j + 1;


두 번째 loop를 빠져나오고 난 후에는, 데이터 배열의 끝 부분에 최대/최소 값을 넣어주어야 한다.
물론, 그 지점에 있던 값은 인덱스 t의 값의 위치에 있어야 한다. 이를 표현하면 다음과 같다.
2번째 loop를 돌고 빠져나온 인덱스 j의 값은 정렬이 완료된 요소의 값을 가지고 있게 된다.
값을 업데이트 해주는 코드는 다음과 같다.
tmp = d[j];
d[j] = d[t];
d[t] = tmp;

이를 좀 더 뜯어고치면 다음과 같이 할 수 있다. 만약 최대값이 배열의 끝에 있었다면 궂이 자리를 교체할 필요가 없다.
if(j != t)
{
  tmp = d[j];
  d[j] = d[t];
  d[t] = tmp;
}

완성된 코드는 다음과 같다.

int Sort_Select(SCORE *d, int order, int (* comp)(SCORE *x, SCORE *y))
{
  int i, j, max, t;
  for (max = 0; max < MAX_ST; max++) {
    if(d[max].id == 0) break;
  }

  for (i = 0; i < max - 1; i++) {
    for (t = 0, j = 0; j < max - 1 - i; j++) {
      if(comp(d[t], d[j+1]) == order) t= j+1;
    }
    if(j != t)
    {
      tmp = d[j];
      d[j] = d[t];
      d[t] = tmp;
    }
  }

  return max;
}



```