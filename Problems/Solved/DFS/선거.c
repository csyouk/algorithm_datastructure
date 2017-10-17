#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define DIRS 4

int T, CNT;
int fillcnt;

char map[5][5];
int vis[5][5];

int filltrace[5][5];

int di[DIRS] = {0,-1,0,1};
int dj[DIRS] = {-1,0,1,0};

void Init(void){
	memset(&vis[0][0], 0, sizeof(int[5][5]));
	CNT = 0;
}

void Input_Data(void){
	int i;
	for (i = 0; i < 5; i++){
		scanf("%s", &map[i][0]);
	}
}

void Fill(int i, int j){
	int k, ni, nj;

	filltrace[i][j] = 1;
	for ( k =	0; k < DIRS; k++){
		ni = i + di[k]; nj = j + dj[k];
		if (ni < 0 || ni > 4 || nj < 0 || nj > 4) continue;
		if (filltrace[ni][nj] || vis[ni][nj] == 0) continue;
		Fill(ni, nj);
	}
}

int Start_Fill(void){
	int i, j;
	memset(&filltrace[0][0], 0, sizeof(int[5][5]));
	fillcnt = 0;
	for ( i = 0; i < 5; i++){
		for ( j = 0; j < 5; j++){
			if (vis[i][j] == 0) continue;
			Fill(i, j);
			return;
		}
	}
}

void DFS(int n, int idx){
	int i;
	if (n > 6){
		int area=0, j;
		int J, H;
		J = H = 0;
		Start_Fill();

		for ( i = 0; i < 5; i++)
		{
			for ( j = 0; j < 5; j++)
			{
				if (vis[i][j] && map[i][j] == 'J' && filltrace[i][j]) {
					J++; area++;
				}
				if (vis[i][j] && map[i][j] == 'H' && filltrace[i][j]) {
					H++; area++;
				}
			}
		}
		if (area != 7) return;
		if (J > H) {
			CNT++;
		}
		return;
	}

	for (i = idx; i <25; i++) {
		vis[i / 5][i % 5] = 1;
		DFS(n + 1, i+1);
		vis[i / 5][i % 5] = 0;
	}

}


int main(void){
	int i;
	scanf("%d\n", &T);

	while (T--){
		Init();
		Input_Data();
		DFS(0, 0);

		printf("%d\n", CNT);
	}


	return 0;
}
