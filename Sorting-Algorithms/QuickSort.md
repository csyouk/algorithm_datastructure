# Quick Sort
- 정렬 알고리즘에서 쓰이는 용어를 먼저 분석해 보자.
  - pivot : 주어진 데이터 목록에서 임의의 원소를 고른다. 이 원소를 **pivot** 이라고 한다.
  정렬이 한 회 이뤄질 때 마다, pivot 요소값 의 최종 위치는, 배열의 최종 위치와 동일하다.
  정렬이 한회 이루어진 후, pivot의 좌측에는 pivot의 값보다 작은 값들이 있고,
  우측에는 pivot보다 큰 값들이 있다.
  pivot이 끝난 후에 pivot은 움직이지 않는다. 그 자리에 고정된다. 그래서 pivot(중심점)이라고 표현한다.
  - left : pivot을 설정한 이후, pivot 좌측의 값들을 left라고 표현한다.
  - target : left의 값들을 순차적으로 탐색하며, 정렬 규칙(오름/내림차순)에 따라서
  pivot보다 작거나/큰 값을 left의 위치와 바꾼다.
  **최종적으로 target 이 가리키는 위치는 pivot이 위치할 곳이다.**
- 퀵 정렬의 아이디어는 다음과 같다.
  - 임의의 pivot을 설정한다.
  - pivot의 좌측의 요소들을 요소수가 작은 것부터 순차적으로 탐색을 하며 pivot과 비교한다.
    - **오름 차순일 경우**
    - 만약 요소수에 해당하는 요소가 pivot과 비교해서 크면, 지나가고 loop의 index를 증가시킨다.
    - pivot위치의 값보다 left요소수에 있는 요소값이 작으면 target위치가 가리키는 요소와 교환한다.
    - 교환이 일어나면, target의 요소수를 하나 증가시킨다.
    - **내림 차순일 경우**
    - 위의 행위와 반대로 하면 된다.
  - pivot이 설정되면, pivot을 기준으로
    - 좌측의 값들을 QuickSort로 정렬한다.
    - 우측의 값들을 QuickSort로 정렬한다.
  - 비교는 left와 pivot의 값을 비교하고
  - 교환은 left와 target의 값을 서로 교환한다.


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
int Sort_Quick(SCORE *d, int order, int start, int end, int(*comp)(SCORE * x, SCORE * y))
parameter분석을 해보자.
- d는 정렬할 대상인 배열의 주소이다.
- order는 내림차순, 오름차순 옵션을 넘긴다.(1 : 오름차순, -1 : 내림차순)
- comp는 포인터 함수이다. 정렬의 기준에 해당하는 함수를 넘겨준다.(Id, Score, Name)
- start는 정렬할 요소수의 첫 위치를 나타낸다.
- end는 정렬할 요소수의 마지막 위치를 나타낸다.


===> 1단계
함수내부에서 사용할 변수들을 선언 및 초기화 한다.
SCORE tmp;
int left, target, pivot;
pivot = end;
left = start;
target = start;


===> 2단계
left 요소수를 순차적으로 늘려 나가며 pivot과 값을 비교한다.

for (left = start; left < pivot; left++) {
  ...
}

===> 3단계
pivot과 left의 값을 비교한다.
left 요소수값이 pivot 요소수 값과 다를때만, target과 left의 위치를 바꿔준다.
주의할 점은, 이때 기준은 left요소라는 것이다.
값이 다를 때, target의 요소수 값을 증가시킨다.

if(comp(&d[pivot], &d[left]) == order)
{
  if(left != target)
  {
    tmp = d[left];
    d[left] = d[target];
    d[target] = tmp;
  }
  target++;
}

===> 4단계
left의 요소수를 pivot-1까지 증가시킨후, loop가 종료된 후, pivot요소와 target요소를 서로 교환한다.
이때, 서로 값이 다를때에만 교환이 가능하다.
if (target < pivot)
{
  tmp = d[pivot];
  d[pivot] = d[target];
  d[target] = tmp;
}

===> 5단계
pivot을 기준으로 start요소부터 pivot-1까지 퀵정렬 함수를 호출한다.
pivot을 기준으로 pivot + 1 요소부터 end 요소수 까지 퀵정렬 함수를 호출한다.



완성된 코드는 다음과 같다.

int Sort_Quick(SCORE *d, int order, int start, int end, int(*comp)(SCORE * x, SCORE * y))
{
	SCORE tmp;
	int left, target, pivot;
	pivot = end;
	target = start;
	if (end == start) return 1; // 정렬이 완료되면 총 요소수를 리턴한다.
	if (end < start) return 0;
	// left는 넘어온 배열의 start요소부터 pivot - 1 요소 까지 돌린다.
	for (int left = start; left < pivot; left++)
	{
		if (comp(&d[pivot], &d[left]) == order){
			if (left != target){
				tmp = d[left];
				d[left] = d[target];
				d[target] = tmp;
			}
			target++;
		}
	}

	// pivot을 기준으로 left를 전부 비교한 후,
	// 마지막 행위로 target과 pivot을 교환한다.
	if (target < pivot)
	{
		tmp = d[pivot];
		d[pivot] = d[target];
		d[target] = tmp;
	}

	return Sort_Quick(d, order, start, target - 1, comp) + Sort_Quick(d, order, target + 1, end, comp) + 1;

}

```
