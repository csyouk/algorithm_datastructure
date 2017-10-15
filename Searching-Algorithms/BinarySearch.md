# 이진탐색(Binary Search)
- **정렬** 된 데이터에서 탐색을 진행해야 한다.
- 예제 코드를 통해서 이해를 한다.

## 정렬된 데이터가 1단위 간격으로 순차적인 경우.
- 1부터 1,000,000 까지의 데이터가 있다고 하자. 만약 찾고자 하는 데이터가 79202 라고 하자.
- 만약 찾아나가는 방법이 순차적인 탐색법이라면, 1부터 시작해서 순차적으로 숫자를 증가시켜서 찾아나가야 한다.
- 하지만 이진탐색으로 찾아나가면, 탐색 횟수를 줄일 수 있다.
- 방법을 확인해보자.


- 먼저 데이터를 정의하자.

```cpp
int data[] = {1,2,...1000000};
```

- 이진 탐색 함수의 인자는
- 1. 찾고자 하는 범위 데이터의 첫 요소의 인덱스
- 2. 찾고자 하는 범위 데이터의 마지막 요소의 인덱스
- 3. 찾고자 하는 데이터,
- 4. 데이터 배열의 주소

``` cpp
int Binary_Search(int s, int e, int target, int * d);
```

- 함수 내부의 지역변수들은 첫 요소와 마지막 요소의 중간값을 의미하는 **m**
- 최종 m의 위치를 저장하는 sol 변수. 만약 sol 변수가 업데이트 되지 않는다면, 실패를 의미하는 -1값이 리턴되도록 설계한다.

```cpp
#define FAILED (-1)
int m, sol;
sol = FAILED;
```

- s 인덱스가 e 인덱스보다 작거나 같을 동안 이진탐색을 진행한다.
- 첫 요소의 값과 마지막 요소의 값을 더해서 반으로 나눈 값을 중간값(m)에 저장한다.
- 찾고자 하는값(**target**)이 중간값보다 작거나 같으면, sol변수에 m값을 업데이트 하고,
마지막 요소의 값을 중간값이전의 값, m-1로 업데이트 한다.
**즉, 앞의 절반의 영역에서 다시 탐색을 진행한다.**
- 찾고자 하는 값이 중간값보다 크면, 뒤의 절반에서 탐색을 진행한다.
- 계속 탐색을 진행하다가, 첫 요소의 값이 마지막 요소의 값보다 커지는 순간, 탐색을 종료한다.
- 그리고 찾은값 sol을 반환한다.

```cpp
while(s <= e){
  m = (s + e)/2;
  if(target <= m){
    sol = m;
    e = m - 1;
  }
  else
  {
    s = m + 1;
  }
}
return sol;
```

- 위에서 설명한 코드를 모두 합치면 다음과 같다.

```cpp
#define FAILED (-1)
int data[] = {1,2,...1000000};
int Binary_Search(int s, int e, int target, int * d){
  int m, sol;
  sol = FAILED;  
  while(s <= e){
    m = (s + e)/2;
    if(target <= m){ sol = m; e = m - 1; }
    else { s = m + 1; }
  }
  return sol;
}

Binary_Search(0, 1000000-1, 79202, data); // return 79202. 탐색회수는 20회 이하이다.

```


## 정렬된 데이터의 간격이 불규칙적인 경우.
- 이 경우는 데이터들을 선형구조의 배열에 넣고, 배열의 인덱스를 통해서 원하는 데이터의 **위치** 를 추출해 낸다.
즉, 배열의 인덱스를 찾아내는 방식이다.
- 예를 들어보면 다음과 같다.
- 데이터가 아래와 같이 불규칙적으로 들어가 있다고 해보자.

```cpp
int data[] = {-2,3,15,2,-193,-23,53,-661,-4,3,1,6,7,8,9,10,22,35,57,57,51,72,45,81,24,-46,-75};
```

- 이진 탐색을 통해서 원하는 값을 추출하기 위해서, 데이터를 정렬시켜야 한다.

```cpp
#include <stdlib.h>

int comp(const int * p1, const int * p2){ return *p1 - *p2;}
qsort(data, sizeof(data)/sizeof(data[0]), sizeof(int), comp);
```

- 그 후, 이진 탐색을 진행한다. 나머지 과정을 위의 케이스와 동일하나, 다른점이 있다면, 다음 부분이다.
- 찾고자 하는 값이 데이터의 앞 절반에 있는지 비교하는 과정에서 단순히 인덱스 m이 아닌, 데이터의 중앙에 해당하는 값, 즉 d[m]에 있는지를 비교하는 것이다.

```cpp
  if(target <= d[m])
```

- 완성된 코드는 다음과 같다.

```cpp
#include <stdlib.h>
#define FAILED (-1)
#define DATA_SIZE sizeof(data)/sizeof(data[0])

int data[] = {-2,3,15,2,-193,-23,53,-661,-4,3,1,6,7,8,9,10,22,35,57,57,51,72,45,81,24,-46,-75};

int comp(const int * p1, const int * p2){ return *p1 - *p2;}
qsort(data, sizeof(data)/sizeof(data[0]), sizeof(int), comp);


int Binary_Search(int s, int e, int target, int \* d){
  int m, sol;
  sol = FAILED;  
  while(s <= e){
    m = (s + e)/2;
    if(target <= d[m]){ sol = m; e = m - 1; }
    else { s = m + 1; }
  }
  return sol;
}

Binary_Search(0, DATA_SIZE - 1, 35, data); // 탐색횟수 20회 이하.
```

- 데이터가 커질수록, 이진탐색음 매우 효율적이다.
- 10억개의 데이터가 정렬되어 있다고 가정 하였을 때, 임의의 값 X를 찾기 위해서 완전탐색은 O(n)의 시간이 걸리지만,
- 이진 탐색은 O(log2(n))의 시간이 걸린다.
