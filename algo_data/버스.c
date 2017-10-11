//
//  버스갈아타기.c
//  codeground
//
//  Created by youkchangsu on 2017. 10. 10..
//  Copyright © 2017년 youkchangsu. All rights reserved.
//

#include <stdio.h>
#define MAX ~(1<<31)
#define Enqueue(X) (queue[wp++] = (X))
#define Dequeue(X) ((X) = queue[rp++])
#define QueueNotEmpty (wp > rp)
typedef struct {
	int sx, sy;
	int ex, ey;
} BUS;
typedef struct {
	int bus_n;
	int cnt;
} QUEUE;

BUS bus[5000];
QUEUE queue[5000];
int chk[5000];
int rp, wp;
int M, N, K;
int sx, sy, ex, ey;

void Input_Data(void){
	int i, tmp;

	scanf("%d %d", &M, &N);
	scanf("%d", &K);

	for (i = 0; i < K; i++) {
		scanf("%*d %d %d %d %d", &bus[i].sx, &bus[i].sy, &bus[i].ex, &bus[i].ey);
		if (bus[i].sx == bus[i].ex){
			if (bus[i].sy > bus[i].ey){
				tmp = bus[i].ey;
				bus[i].ey = bus[i].sy;
				bus[i].sy = tmp;
			}
		}
		else if (bus[i].sy == bus[i].ey){
			if (bus[i].sx > bus[i].ex){
				tmp = bus[i].ex;
				bus[i].ex = bus[i].sx;
				bus[i].sx = tmp;
			}
		}
	}

	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

}

int BFS(){
	QUEUE data, ndata;
	// init
	int i;
	for (i = 0; i < K; i++)
	{
		if (((bus[i].sx <= sx) && (sx <= bus[i].ex)) && ((bus[i].sy <= sy) && (sy <= bus[i].ey))){
			data.bus_n = i;
			data.cnt = 1;
			Enqueue(data);
			chk[i] = 1;
		}
	}


	// bfs
	while (QueueNotEmpty){
		Dequeue(data);
		if (((bus[data.bus_n].sx <= ex) && (ex <= bus[data.bus_n].ex)) &&
			 ((bus[data.bus_n].sy <= ey) && (ey <= bus[data.bus_n].ey)))
		{
			return data.cnt;
		}

		for ( i = 0; i < K; i++)
		{
			if (chk[i]) continue;
			if (!((bus[i].sx <= bus[data.bus_n].sx && bus[data.bus_n].sx <= bus[i].ex) ||
				(bus[data.bus_n].sx <= bus[i].sx && bus[i].sx <= bus[data.bus_n].ex))) continue;
			if (!((bus[i].sy <= bus[data.bus_n].sy && bus[data.bus_n].sy <= bus[i].ey) ||
				(bus[data.bus_n].sy <= bus[i].sy && bus[i].sy <= bus[data.bus_n].ey))) continue;
			ndata.bus_n = i;
			ndata.cnt = data.cnt + 1;
			Enqueue(ndata);
			chk[i] = 1;
		}
	}

	return -1;
}

int main(void){
	Input_Data();
	
	printf("%d", BFS());
	return 0;
}