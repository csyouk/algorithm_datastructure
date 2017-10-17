#if 01
#include <stdio.h>
#include <string.h>

#define DIRS 4

int T, combo, combo_detect;
int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

char map[12][6];
int vis[12][6];

char buffer[20];

void Init_Vis(void){
	memset(&vis[0][0], 0, sizeof(int[12][6]));
}

void Replace_Vis_As_None(){
	int i, j;
	for ( i = 11; i > 0; i--)
	{
		for ( j = 0; j < 6; j++)
		{
			if (vis[i][j]) { map[i][j] = '.'; }
		}
	}
}

int Fill(int i, int j){
	int k, ni, nj;

	vis[i][j] = 1;

	for ( k = 0; k < DIRS; k++){
		ni = i + di[k];  nj = j + dj[k];
		if (ni < 0 || ni > 11 || nj < 0 || nj > 5) continue;
		if (map[ni][nj] != map[i][j] || vis[ni][nj]) continue;

		Fill(ni, nj);
	}


}

int Cal_Area(){
	int i, j, area = 0;
	for (i = 11; i >= 0; i--)
	{
		for (j = 0; j < 6; j++)
		{
			if (vis[i][j]) { area++; }
		}
	}
	return area;
}

void Gravity(){
	int i, j, k, l, flag=0, empty=0, wp, rp;
	for (j = 0; j < 6; j++)
	{
		wp = 0; rp = 0;
		for (i = 11; i >= 0; i--)
		{
			if (map[i][j] == '.') continue;
			buffer[wp++] = map[i][j];
		}

		i = 11;
		while (rp < wp){
			map[i][j] = buffer[rp++];
			i--;
		}

		for ( l = i; l >=0; l--)
		{
			map[l][j] = '.';
		}
	}
}



void Find_Puyo(){
	int i, j, area, flag = 0;
	char tmp;

	while (1){
		flag = 0; combo_detect = 0;
		for ( i = 11; i >= 0; i--)
		{
			for ( j = 0; j < 6; j++)
			{
				if (map[i][j] == '.') continue;
				Init_Vis();
				Fill(i,j);
				area = Cal_Area();
				if (area >= 4){
					Replace_Vis_As_None();
					combo_detect = 1;
					flag = 1;
				}
			}
		}

		Gravity();
		// 중력작용 후 다시 첫줄부터 검사.
		Init_Vis();
		if (combo_detect) combo++;

		if (flag == 0) return;
	}
}

int main(void){
	int i, j;
	scanf("%d", &T);

	for ( i = 1; i <=T; i++){
		combo = 0;
		for ( j = 0; j < 12; j++){
			scanf("%s", &map[j][0]);
		}
		Find_Puyo();
		printf("%d\n", combo);
	}
	return 0;
}
#endif
