# Merge Sort(병합 정렬)
- 이름 그대로, 2개이 상의 것을 Merge, 즉, 합치는 일을 수행하는 정렬 방식이다.

- MergeSort의 아이디어는 정렬하고자 하는 데이터를 하나단위가 될때까지 분할 한 후, 분할한 원소를 다시
병합하는 정렬의 방식이다.
- MergeSort의 구현은 크게 2부분으로 나뉘는데,
  - 첫 번째 부분은 데이터를 분할해 나가는 방식의 **분할함수**
  - 두 번째 부분은 분할한 데이터를 합치는 부분의 **병합함수** 이다.

- MergeSort의 성능은 O(n*log(n)) 이 나온다.
- 하지만 단점이 있으니, 바로 메모리 공간을 많이 차지한다는 점이다.
- 정렬을 하고자 하는 데이터가 있으면, 정렬과정에서 데이터를 잠시 다른 곳으로 벡업해야 하기 때문에, 임시 공간이 필요하다.
- 즉, 메모리가 2배로 많이 필요한 작업이다.

- MergeSort의 프로토타입은 다음과 같다.
- 함수의
  - 첫 번째 인자는 정렬하고자 하는 데이터의 첫 요소의 인덱스를 넘긴다.
  - 두 번째 인자는 정렬하고자 하는 데이터의 마지막 요소의 인덱스를 넘긴다.
  - 세 번째 인자는 정렬하고자 하는 데이터 배열의 첫 요소의 주소를 넘긴다.

```cpp
void MergeSort(int s, int e, int * data);
```

- MergetSort의 구현은 다음과 같다.
- 첫 요소와 마지막 요소의 인덱스를 받아서, 둘을 합한 후 2로 나눠서 절반의 값을 얻는다.
- 첫 요소부터 중간까지의(s ~ m) 데이터에대해서 MergeSort 함수를 호출한다.
- 중간 다음 값부터, 마지막 요소까지의(m+1 ~ e) 데이터에 대해서 MergeSort 함수를 호출한다.
- 분할해 나가는 과정은 재귀적으로 이루어진다. 이 과정에서 실질적으로 데이터가 쪼개지는 것은 아니고,
정렬 범위의 인덱스만 반으로 쪼개지며 다음 함수의 인자로 넘어간다.
- 인덱스의 쪼갬이 완료되면, 이제 **병합** 과정을 진행한다.
즉, Merge함수를 호출한다는 뜻이다.

```cpp
void MergeSort(int s, int e, int * data){

  int m;
  if(s >= e) return;
  m = (s + e)/2;
  MergeSort(s, m, data);
  MergeSort(m + 1, e, data);

  Merge(s, e, m, data);
}
```

- Merge함수의 프로토타입은 다음과 같다.
  - 첫 요소의 인덱스
  - 마지막 요소의 인덱스
  - 중간 요소의 인덱스
  - 데이터배열

```cpp
void Merge(int s, int e, int m, int * data);
```

- 실질적으로 병합부분이 이 알고리즘의 백미이다. 한번 자세히 알아보자.
- 분할된 데이터를 합칠때는,

- 먼저 필요한 지역변수들을 선언해보자.
- 2개의 부분으로 분할된 데이터를 탐색해 나가기 위해서 idx1 변수와 idx2 변수가 필요하다.
- 그리고 첫 요소의 위치를 벡업해두기 위한 idxtmp 변수를 만들어 놓는다.
- 첫 요소의 위치를 벡업해 두는 이유는 임시공간에 데이터를 넣을 때, **넣을 위치** 를 알아야 하는데, 그 위치를 기록해 두기 위한 용도이다.

```cpp
  int idx1, idx2, idxtmp;
  idx1 = s; idx2 = m + 1; idxtmp = s;
```

- 데이터의 형태가 다음과 같다고 했을 때, 다음과 같이 데이터를 훑게 된다
- {9, 10, 7, 8}  { 3, 4, 1, 2}
- ^ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;^&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ^ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;^
- idx1 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;m&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; idx2 &nbsp;&nbsp; e

- 앞쪽 절반과 뒤쪽 절반을 훑어나가면서 더 작은 값을 임시 공간에 이동시킨다.

```cpp
while(idx1 <= m && idx2 <= e){
    if(data[idx1] < data[idx2]){
      tmp[idxtmp++] = data[idx1++];
    }else {
      tmp[idxtmp++] = data[idx2++];
    }
}
```

- 분할된 데이터의 앞쪽 절반의 값이 아직 임시 공간으로 다 옮겨가지 않았으면, 인덱스를 증가시키면서 임시공간으로 나머지 데이터들을 이동시킨다.

```cpp
if(idx1 <= m){
  while (idx1 <= m) tmp[idxtmp++] = data[idx1++];
}else{
  while (idx2 <= e) tmp[idxtmp++] = data[idx2++];
}
```

- 마지막으로 임시공간에 정렬시켜놓은 데이터를 원본 데이터에 옮긴다.

```cpp
for (idxtmp=s; idxtmp<=e; idxtmp++) {
  data[idxtmp] = tmp[idxtmp];
}
```

- 이 모든 코드를 합쳐 보면 다음과 같다.

```cpp

// 정렬시킬 데이터
int data[10] = {10,9,8,7,6,5,4,3,2,1};

// 임시로 정렬된 데이터를 만들어 놓을 공간
int tmp[10];

int MergeSort(int s, int e, int * data);
int Merge(int s, int e, int m, int * data);

int Merge(int s, int e, int m, int * data){
  int idx1, idx2, idxtmp;
  idx1 = s; idx2 = m+1; idxtmp = s;

  // 앞쪽 절반, 뒤쪽 절반의 요소를 하나씩 비교해나가면서 더 작은 녀석을 임시 공간에 대피시켜놓는다.
  while(idx1 <= m && idx2 <= e){
    if(data[idx1] < data[idx2]){
      tmp[idxtmp++] = data[idx1++];
    } else {
      tmp[idxtmp++] = data[idx2++];
    }
  }

  // 아직 정렬 시킬 데이터가 전부 이동하지 않았다면, 나머지 데이터들을 임시공간에 순차적으로 넣는다.
  if(idx1 <= m){
    while(idx1 <= m) tmp[idxtmp++] = data[idx1++];
  } else{
    whlie(idx2 <= e) tmp[idxtmp++] = data[idx2++];
  }

  // 임시공간의 내용을 원본데이터에 넣는다.
  for(idxtmp = s; idxtmp <= e; idxtmp++){
    data[idxtmp] = tmp[idxtmp];
  }
}

int MergeSort(int s, int e){
  int m;
  // 인덱스가 같아지거나 역전이 생기면 분할을 할필요가 없다.
  if( e <= s) return;

  // 중간 위치의 인덱스를 찾는다.
  m = (s + e)/2;

  // 앞쪽 절반을 병합정렬 시킨다.
  MergeSort(s, m, data);

  // 뒤쪽 절반을 병합정렬 시킨다.
  MergeSort(m + 1, e, data);

  // 쪼갠 데이터를 합친다.
  Merge(s, e, m, data);
}

```
