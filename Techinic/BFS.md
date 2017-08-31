# Breadth First Search(BFS)
- 이 알고리즘은 기준점으로부터 연결된 장소들을 연결해 가며 목적지에 도달하는 가장 최단경로를 파악하는 알고리즘이다.

- Q에 초기데이터를 삽입한다.
- Q에 데이터가 있는 동안
  - Q에서 데이터 1개를 Read
  - 꺼낸 데이터 처리 -> 조건 맞으면 Q에 삽입



-------
### 문제
미로탈출 로봇 대회를 개최하였다. 대회에 사용되는 미로는 가로(X), 세로(Y) 100이하의 크기이며,
미로를 한 칸 이동하는 데는 1초가 걸린다.
로봇이 출발점에서 도착점까지 가장 빨리 이동할 경우 걸리는 시간을 구하는 프로그램을 작성하시오.
![문제 이미지]()
첫 줄에 미로의 크기 X, Y(1≤X, Y≤100)가 주어진다.
둘째 줄에 출발점 x, y 좌표와 도착점 x, y 좌표가 공백으로 구분하여 주어진다.
셋째 줄부터 미로의 정보가 길은 0, 벽은 1로 공백이 없이 들어온다.
주의 사항으로, 좌표는 좌측상단이 가장 작은 위치이며 이 위치의 좌표는 (1,1)이다.

입력 예시
8 7
1 2 7 5
11111111
00000111
10110011
10111001
10111101
10000001
11111111

출력 예시
9
--------

```cpp
  #include <stdio.h>
  #define EMPTY 0
  #define SIZE 110
  #define DIRS 4

Q에 들어갈 데이터이다. 행열에서 행과 열의 정보, 기준점으로부터의 거리를 저장한다.
  typedef struct _data{
  	int x;
  	int y;
  	int dis;
  } QData;

큐를 만들고 넉넉하게 공간을 만들어 준다.
  QData Q[SIZE * SIZE];
  QData S, E;

방향을 정한다.
  int di[DIRS] = { 0, -1, 0, 1 };
  int dj[DIRS] = { -1, 0, 1, 0 };


미로의 지도를 저장할 배열.
  int map[SIZE][SIZE];

경로를 탐색하며 탐색여부를 저장해 놓는 체크 배열.
  int chk[SIZE][SIZE];

  int WP = EMPTY;
  int RP = EMPTY;

  int X, Y;

  int BFS(int x, int y, int d)
  {
  	QData tmpQ;
  	int k, ni, nj;
  	// 초기화,  체크 배열에 방문을 했다는 것을 표시한다. WP를 증가시킨다.
  	// 오류를 줄이기 위해서 한 줄에 다 적는다.
  	Q[WP].x = x; Q[WP].y = y; Q[WP].dis = d; chk[x][y] = 1; WP++;

    // 큐에 데이터가 존재하는 동안 큐에서 데이터를 1개 읽어서 데이터값이 종단조건에 맞는지 확인한다.
  	while (RP < WP)
  	{
  		tmpQ.x = Q[RP].x; tmpQ.y = Q[RP].y; tmpQ.dis = Q[RP].dis; RP++;
  		if (tmpQ.x == E.x && tmpQ.y == E.y) {
  			return tmpQ.dis;
  		}

  		// x,y를 중심으로 상하좌우를 체크해본다.
  		for ( k = 0; k < DIRS; k++){
  			ni = tmpQ.x + di[k]; nj = tmpQ.y + dj[k];
  			// 배열 밖인지 체크한다.
  			if (ni < 1 || ni > X || nj < 1 || nj > Y) continue;
  			if (map[ni][nj] != 0 || chk[ni][nj] != 0) continue;
  			Q[WP].x = ni;  Q[WP].y = nj;  Q[WP].dis = tmpQ.dis + 1;  chk[ni][nj] = 1; WP++;

  		}
  	}
  }


  int BFS(int x, int y, int d){
    QData tmp;
    int k, ni, nj;
    Q[WP].x = x; Q[WP].y =y; Q[WP].dis = d; chk[x][y] = 1; WP++;

    while (RP<WP) {
      tmp <- Q[RP]
      if(tmp == E) return tmp.dis;
      for (k = 0; k < 4; k++) {
        if (예외조건)
        Q[WP] <- ni; chk[i][j] = 1; WP++;
      }
    }
  }


  int main(void)
  {
  	int x, y,i,j,d = 0;
  	scanf("%d %d", &Y, &X);

  	scanf("%d %d %d %d", &S.y, &S.x, &E.y, &E.x);

  	for (i = 1; i <= X; i++)
  	{
  		for (j = 1; j <= Y; j++)
  		{
  			scanf("%1d", &map[i][j]);
  		}
  	}
  	printf("%d", BFS(S.x,S.y, d));
  	return 0;
  }  
```
