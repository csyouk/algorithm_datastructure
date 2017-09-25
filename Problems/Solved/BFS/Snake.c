#define _CRT_SECURE_NO_WARNINGS
// 이 문제에서 다시 생각해봐야할 점은
// 큐를 rp와 wp로 고정시켜서 생각하지 말자라는 점이다.
// 그리고 문제를 잘 읽자!!!
문제 설명
“Snake” 라는 도스 게임이 있다. 이 게임에는 뱀이 나와서 기어다니는데, 과일을 먹으면 뱀의 길이가 늘어난다. 뱀이 상하좌우로 기어다니다가 벽 또는 자기자신과 부딪히면 게임이 끝난다.

게임은 N*N 정사각형 격자에서 진행되며, 몇 개의 칸에는 과일이 놓여있다. 격자 상하좌우 가장자리 끝은 벽이다. 게임 시작 시 뱀 위치는 좌상단, 즉 (1, 1)에서 시작하며 뱀 길이는 1이고 오른쪽을 향해 있다.

매 초마다 이동을 하는데 다음과 같은 규칙이 있다
1.    먼저 뱀은 몸길이를 늘려 머리를 다음 칸으로 이동한다.
2.    만약 이동한 칸에 과일이 있다면 이 상태가 유지된다. 즉, 몸길이가 1 증가한 것이다.
3.    만약 이동한 칸에 과일이 없다면 몸길이가 원상태로 돌아와야 한다. 이때 꼬리가 위치한 칸을 비우게 된다.

정사각형 격자의 크기 N과 과일의 위치, 뱀의 이동경로가 주어졌을 때, 이 게임이 몇 초 후에 끝나는지 구하시오

입력
첫 번째 줄에는 정사각형 격자의 크기 N(2≤N≤100)이 입력된다.
두 번째 줄에는 과일의 개수 K(0≤K≤100)가 입력된다.
다음 줄부터 K줄에 걸쳐 과일 정보가 r(세로), c(가로) 순으로 공백으로 구분되어 입력된다. 시작위치인 (1, 1) 위치에는 과일이 없다.
다음 줄에 뱀 이동경로 개수 L(1≤L≤100)이 입력된다.
다음 줄부터 L줄에 걸쳐 뱀 이동 경로가 정수 X(1≤X≤10,000), 문자 C(‘L’ or ‘D’)가 공백으로 구분되어 입력된다. X초 후에 C 방향으로 전환한다는 의미이다. ‘L’은 왼쪽으로 90도, ‘D’는 오른쪽 90 전환을 의미한다.
출력
몇 초 후에 이 게임이 끝나는지 출력한다.
입력 예시
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
출력 예시
9


#if 01
#include <stdio.h>
#define DIRS 4

typedef struct {
	int t;
	char dir;
} Command;

enum Object{w=0,n,e,s,SNAKE=1,FRUIT=8};


typedef struct {
	int i, j;
} Snake;

Command CommandQ[10000 + 10];

// Circular Queue를 쓴다. 끊김 없이 계속 돌아다닐 수 있으므로.
Snake SnakeQ[10000];
Snake sout, sin;
Command cout, cin;


int N, K, L;
int fi, fj;
int RP, WP;
int head, tail;
int time = 0;

int snake_dir = 2;

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

int map[100 + 10][100 + 10];


int conv(char dir){

	if (dir == 'D'){ return 1; }
	return  -1;
}

void Game(void){
	int i, fruit_flag = 0, b_time;

	// init
	sin.i = 1;  sin.j = 1;
	SnakeQ[head] = sin;
	map[1][1] = 1;


	while (RP < WP){
		cout = CommandQ[RP++];
		while (1)
		{
			if (time == cout.t) break;
			sout = SnakeQ[head];

			sin.i = sout.i + di[snake_dir]; sin.j = sout.j + dj[snake_dir];
			time++;

			//몸통 부딪힐 시 게임 끝
			if (map[sin.i][sin.j] == SNAKE) return;
			//가장자리 침범시 게임 끝
			if (sin.i < 1 || sin.i > N || sin.j < 1 || sin.j > N) return;


			SnakeQ[++head] = sin;

			// 이동한 곳에 과일이 있다면 더 이상할 일이 없음.
			if (map[sin.i][sin.j] == FRUIT) {
				// 무사히 게임 종료 조건을 지나친 후. 머리부분 표시.
				map[sin.i][sin.j] = 1;
				continue;
			}
			// 과일이 없었다면, 꼬리를 지움. 꼬리는 rp로 관리.
			sout = SnakeQ[tail++];
			map[sin.i][sin.j] = 1;
			map[sout.i][sout.j] = 0;

		}
		snake_dir += conv(cout.dir);
		if (snake_dir > 3){ snake_dir = 0; }
		if (snake_dir < 0) { snake_dir = 3; }

	}
	time++;
}

int main(void){
	int i;
	scanf("%d", &N);
	scanf("%d", &K);
	for ( i = 1; i <= K; i++)
	{
		scanf("%d %d", &fi, &fj);
		map[fi][fj] = FRUIT;
	}

	scanf("%d", &L);
	for (i = 1; i <= L; i++) {
		scanf("%d %c", &CommandQ[WP].t, &CommandQ[WP].dir);
		WP++;
	}

	Game();

	printf("%d", time);

	return 0;
}

#endif
