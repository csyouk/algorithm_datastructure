#if 0
#include <stdio.h>
#include <stdlib.h>

#define DIR_UP (1<<0)
#define DIR_DOWN (1<<1)
#define DIR_LEFT (1<<2)
#define DIR_RIGHT (1<<3)


int R, C;
int map[25 + 2][25 + 2];

char pipe_bitpattern[16] = {
	0, 0, 0, '|',
	0, '3', '4', 0,
	0, '2', '1', 0,
	'-', 0, 0, '+' };

void Input_Data(void){
	int r, c;
	char str[27];
	memset(map, 0, sizeof(map));

	scanf("%d %d", &R, &C);
	for (r = 1; r <= R; r++){
		scanf("%s", &str[1]);
		for (c = 1; c <= C; c++){
			switch (str[c]){
			case '1': map[r][c] = (DIR_DOWN | DIR_RIGHT); break;
			case '2': map[r][c] = (DIR_UP | DIR_RIGHT); break;
			case '3': map[r][c] = (DIR_UP | DIR_LEFT); break;
			case '4': map[r][c] = (DIR_DOWN | DIR_LEFT); break;
			case '|': map[r][c] = (DIR_DOWN | DIR_UP); break;
			case '-': map[r][c] = (DIR_LEFT | DIR_RIGHT); break;
			case '+': map[r][c] = (DIR_LEFT | DIR_RIGHT | DIR_UP | DIR_DOWN); break;
			default: map[r][c] = 16; break; // M, Z
			}
		}
	}
}

void Find_Deleted_Position(int *pr, int *pc, char *pp){
	int r, c, k, i, nr, nc, flag;
	static int dr[] = { -1, 1, 0, 0 };
	static int dc[] = { 0, 0, -1, 1 };

	for (r = 1; r <= R; r++)
	{
		for (c = 1; c <= C; c++)
		{
			if (map[r][c] == 0){
				// flag에 어떤 위치로 뻗어져 나가야하는지가 체크된다.
				flag = 0;
				for (k = 0; k < 4; k++) {
					nr = r + dr[k]; nc = c + dc[k];
					if (map[nr][nc] == 16){
						for (i = 0; i < 4; i++)
						{
							if (map[r + dr[i]][c + dc[i]] != 0) break;
						}
						if (i == 4) flag |= (1 << i);
					}
					else{
						if (map[r + dr[k]][c + dc[k]] & (1 << (k ^ 1))) flag |= (1 << k);
					}
				}
				if (pipe_bitpattern[flag]){
					*pr = r; *pc = c; *pp = pipe_bitpattern[flag];
					return;
				}
			}
		}
	}
}


int main(void){

	int T;
	int r, c;
	char p;
	scanf("%d", &T);

	while (T--)
	{
		Input_Data();
		Find_Deleted_Position(&r, &c, &p);
		printf("%d %d %c\n", r, c, p);
	}


	return 0;
}
#endif