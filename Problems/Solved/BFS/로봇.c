#include <stdio.h>

#define WALL 1
#define ALREADY_TRAVERSED 1

int R, C;
int map[100 + 2][100 + 2];

int sr, sc, sdir;
int er, ec, edir;

int chk[4][102][102];

typedef struct {
	int r, c, dir, cnt;
} QUEUE;

QUEUE queue[4 * 100 * 100];
int rp, wp;

#define Enqueue(X) (queue[wp++] = (X))
#define Dequeue(X) ((X) = queue[rp++])
#define QueueNotEmpty (rp < wp)

void Input_Data(){
	int r,c;
	int lut[] = { 0, 1, 3, 2, 0 };
	scanf("%d %d", &R, &C);

	for ( r = 1; r <=R; r++)
	{
		for ( c = 1; c <=C; c++)
		{
			scanf("%d", &map[r][c]);
		}
	}
	scanf("%d %d %d", &sr, &sc, &sdir);
	scanf("%d %d %d", &er, &ec, &edir);
	sdir = lut[sdir];
	edir = lut[edir];

	for ( r = 1; r <= R; r++)
	{
		map[r][0] = 1;
		map[r][C + 1] = 1;
	}
	for (c = 1; c <= C; c++)
	{
		map[0][c] = 1;
		map[R + 1][c] = 1;
	}
}

int BFS(void){
	QUEUE data, ndata;
	// 변위 데이터를 방향에 맞춰서 만든다.
	static int dr[5] = { -1, 0, 1, 0};
	static int dc[5] = {  0, 1, 0, -1};
	int k;

	data.r = sr;
	data.c = sc;
	data.dir = sdir;
	data.cnt = 0;
	Enqueue(data);
	chk[sdir][sr][sc] = 1;

	while (QueueNotEmpty)
	{
		Dequeue(data);

		// Go 1,2,3
		ndata = data;
		ndata.cnt += 1;
		for ( k = 1; k <=3; k++)
		{
			ndata.r += dr[data.dir];
			ndata.c += dc[data.dir];
			if (map[ndata.r][ndata.c] == WALL) break;
			if (chk[ndata.dir][ndata.r][ndata.c] == ALREADY_TRAVERSED) continue;

			// 마지막 여부
			if (ndata.r == er && ndata.c == ec && ndata.dir == edir) return ndata.cnt;

			Enqueue(ndata);
			chk[ndata.dir][ndata.r][ndata.c] = 1;
		}

		ndata = data;
		ndata.cnt += 1;
		// Turn left
		ndata.dir = (data.dir + 3) % 4;
		if (chk[ndata.dir][ndata.r][ndata.c] == 0) {
			// 마지막 여부
			if (ndata.r == er && ndata.c == ec && ndata.dir == edir) return ndata.cnt;
			Enqueue(ndata);
			chk[ndata.dir][ndata.r][ndata.c] = 1;
		}

		// Turn Right
		ndata.dir = (data.dir + 1) % 4;
		if (chk[ndata.dir][ndata.r][ndata.c] == 0) {
			// 마지막 여부
			if (ndata.r == er && ndata.c == ec && ndata.dir == edir) return ndata.cnt;
			Enqueue(ndata);
			chk[ndata.dir][ndata.r][ndata.c] = 1;
		}
	}
	return -1;
}



int main(void){

	Input_Data();
	printf("%d", BFS());

	return 0;
}
