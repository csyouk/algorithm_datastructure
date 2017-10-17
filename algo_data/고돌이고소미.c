#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ABS(X,Y) (((X) > (Y)) ? ((X)-(Y)):((Y)-(X)))
#define GDARRIVE (ndata.gdi == Godol.ei && ndata.gdj == Godol.ej)
#define GSARRIVE (ndata.gsi == Gosol.ei && ndata.gsj == Gosol.ej)
#define DIRS 9
#define MAPSIZE 26 // change as 26

typedef struct {
	int si, sj, ei, ej;
} Pos;
typedef struct {
	int gdi, gdj;
	int gsi, gsj;
	int dis;
} GG;

GG Q[MAPSIZE*MAPSIZE*MAPSIZE*MAPSIZE];
Pos Godol, Gosol;

int N, RP, WP;
int map[MAPSIZE][MAPSIZE];
int vis[MAPSIZE][MAPSIZE][MAPSIZE][MAPSIZE];

int di[DIRS] = { 0, -1, -1, -1, 0, 1, 1, 1, 0 };
int dj[DIRS] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };

void Input_Data(){
	int i, j;
	GG in;
	scanf("%d", &N);
	scanf("%d %d %d %d", &Godol.si, &Godol.sj, &Godol.ei, &Godol.ej);
	scanf("%d %d %d %d", &Gosol.si, &Gosol.sj, &Gosol.ei, &Gosol.ej);
	for ( i = 1; i <= N; i++){
		for ( j = 1; j <= N; j++){
			scanf("%d", &map[i][j]);
		}
	}

	in.gdi = Godol.si; in.gdj = Godol.sj; 
	in.gsi = Gosol.si; in.gsj = Gosol.sj; 
	in.dis = 0;
	
	vis[in.gdi][in.gdj][in.gsi][in.gsj] = 1;
	Q[WP++] = in;

}

int Find(){
	int gdk,gsk, gdni, gdnj, gsni, gsnj;
	int gdarrive, gsarrive;
	gdarrive = gsarrive = 0;
	GG data, ndata;

	while (RP < WP)
	{
		data = Q[RP++];
		ndata = data;
		ndata.dis += 1;
		if (GDARRIVE && GSARRIVE){
			return data.dis;
		}
		for ( gdk = 0; gdk < DIRS; gdk++)
		{
			ndata.gdi = gdni = data.gdi + di[gdk]; 
			ndata.gdj = gdnj = data.gdj + dj[gdk];
			
			if (map[gdni][gdnj]) continue;
			if (gdni < 1 || gdni > N || gdnj < 1 || gdnj > N) continue;
			
			for ( gsk = 0; gsk < DIRS; gsk++){
				ndata.gsi = gsni = data.gsi + di[gsk]; 
				ndata.gsj = gsnj = data.gsj + dj[gsk];
				if (map[gsni][gsnj]) continue;
				if (gsni < 1 || gsni > N || gsnj < 1 || gsnj > N) continue;
				if (ABS(gdni, gsni) <= 1 && ABS(gdnj, gsnj) <= 1) continue;
				if (vis[gdni][gdnj][gsni][gsnj]) continue;
				if (GDARRIVE && GSARRIVE){
					return ndata.dis;
				}
				vis[gdni][gdnj][gsni][gsnj] = 1;
				 
				Q[WP++] = ndata;
			}
		}
	}
	return -1;
}

int main(void){

	Input_Data();
	printf("%d", Find());

	return 0;
}