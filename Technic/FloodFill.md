# Flood Fill
- 이 알고리즘은 임의의 좌표를 기준으로 그와 근접한 사인들을 풀어나가는 방법의 알고리즘이다.
- 먼저 원본배열이 있다.
- 그리고 원본 배열과 동일한 크기의 체크 배열이 존재한다.


```cpp

데이터 배열이 있다고 하자.
int data[10][10];

데이터 배열의 연결상태를 표시할 체크 배열을 만든다.
int chk[10][10];

임의의 점에 대해서 8방향의 픽셀 방향을 배열로 나타낸다. (혹은 더 적어도 된다.)
(-1, -1) | (-1,  0) | (-1,  1)
( 0, -1) | ( 0,  0) | ( 0,  1)
( 1, -1) | ( 1,  0) | ( 1,  1)    
#define DIRECTIONS 8
int di[DIRECTIONS] = {0,-1,-1,-1,0,1,1,1};
int dj[DIRECTIONS] = {-1,-1,0,1,1,1,0,-1};

원본 데이터는 아마도 이런식으로 받을 것이다.
한변의 사이즈를 받는다.
scanf("%d", &N);

데이터를 기입할 때의 테크닉을 유심히 살펴보자. 1행, 1열부터 넣는다.
for ( i = 1; i <= N; i++) {
  for ( j = 1; j <=N; j++) {
    scanf("%1d", &data[i][j]);
  }
}

이제 체크배열에 원본 배열의 상태를 나타내는 행위를 하러 가보자.
mark 변수에는 원본 배열의 데이터 상태를 나타내는 값을 넣어준다.
unchecked 변수에는 체크 배열에서 체킹이 안됨 상태의 값을 넣어놓는다.
2가지 조건을 통과했다는 것은, 해당 픽셀의 체크배열이 업데이트 되지 않았음을 의미한다.
따라서, Fill함수를 호출해서 체크 배열을 채워나간다.
Fill함수의 인자로 해당 픽셀의 좌표를 넣어준다.
checked 변수에는 체크 배열에 업데이트가 끝났을 시에 넣는 값을 넘겨준다.
for ( i = 1; i <=N; i++) {
  for (j = 1; j <=N; j++) {
    if(data[i][j] == mark && chk[i][j] == unchecked){
      Fill(i,j, checked);
    }
  }
}

이제 대망의 Fill함수를 만들어보자.
void Fill(int i, int j, int checked){

  int k, ni,nj;

  먼저 종료 조건을 채워넣는다.
  체크배열에는 해당 위치가 이미 체크되어있을시에는 재귀함수의 호출을 종료시킨다.
  if(chk[i][j] == checked) return;

  체크배열에 마킹을 한다.
  chk[i][j] = checked;

  8방향에 대한 값 연산을 루프를 통해서 표기한다.
  원본 데이터 체크 배열에서 ni, nj 위치에 해당하는 값이 우리가 마킹하는 하고자 하는 값으로 마킹되어 있다면,
  Fill함수를 재귀적으로 호출해서 체크배열에 표시를 해주자.
  for (int k = 0; k < DIRECTIONS; k++) {
    ni = i + di[k]; nj = j + dj[k];
    if(data[ni][nj] == marked){
      Fill(ni,nj);
    }
  }
}
























```
