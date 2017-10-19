#include <stdio.h>
#include <string.h>
#define DIRS 4

int T;
int N, min_left, min_move;
char map[5 + 2][9 + 2];

void Init(void){
	memset(map, 'X', sizeof(map));
	min_left = (~(1 << 31));
	min_move = 0;
	N = 0;
}

void Input_Data(void){
	int i, j;
	for ( i = 1; i <= 5; i++)
	{
		scanf("%s", &map[i][1]);
		for ( j = 1; j <= 9; j++)
		{
			if (map[i][j] == 'o') N++;
		}
	}
}

int Find_Left_Pin(void){
	int i, j, cnt = 0;
	for ( i = 1; i <= 5; i++)
	{
		for ( j = 1; j <= 9; j++)
		{
			if (map[i][j] == 'o') cnt++;
		}
	}
	return cnt;
}

void DFS(int n, int move){
	int flag, i, j, k;
	static int dr[] = { 0, 0, 1, -1 };
	static int dc[] = { 1, -1, 0, 0 };

	flag = 0;
	for ( i = 1; i <= 5; i++)
	{
		for ( j = 1; j <= 9; j++)
		{
			if (map[i][j] == 'o'){
				for ( k = 0; k < DIRS; k++)
				{
					if (map[i + dr[k]][j + dc[k]] == 'o' &&
						map[i + 2 * dr[k]][j + 2 * dc[k]] == '.'){

						flag = 1;

						map[i][j] = '.';
						map[i + dr[k]][j + dc[k]] = '.';
						map[i + 2 * dr[k]][j + 2 * dc[k]] = 'o';
						DFS(n - 1, move + 1);

						map[i][j] = 'o';
						map[i + dr[k]][j + dc[k]] = 'o';
						map[i + 2 * dr[k]][j + 2 * dc[k]] = '.';

					}
				}
			}
		}
	}

	if (flag == 0){

		if (min_left > n) {
			min_left = n;
			min_move = move;
		}
		else if (min_left == n){
			if (min_move > move){
				min_move = move;
			}

		}
	}
}

int main(void){
	scanf("%d", &T);
	while (T--)
	{
		Init();
		Input_Data();
		DFS(N, 0);
		printf("%d %d\n", min_left, min_move);
	}

	return 0;
}
