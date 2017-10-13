#include <stdio.h>
#include <string.h>
int sol[18];
int table[6][3];
int possibility;
void Init(void){
	memset(table, 0, sizeof(int));
	possibility = 0;
}
void DFS(int n){
	int i, j = 0;
	if (n >= 5){
		for (i = 0; i<18; i++){
			if (sol[i] != table[j][i]) return;
			if (i % 6 == 0) j++;
		}
		possibility = 1;
		return;
	}
	for (i = n + 1; i < 6; i++){
		for (j = 0; j<3; j++){
			if (j == 0){
				table[n][j]++;
				DFS(n + 1);
				table[n][j]--;
			}
			if (j == 1){
				table[n][j]++; table[i][j]++;
				DFS(n + 1);
				table[n][j]--; table[i][j]--;
			}
			if (j == 2){
				table[i][j]++;
				DFS(n + 1);
				table[i][j]--;
			}
		}
	}
}
int main(void){
	int i, j;
	for (i = 0; i<4; i++){
		Init();
		for (j = 0; j < 18; j++) {
			scanf("%d ", &sol[j]);
		}
		DFS(0);
		printf("%d\n", possibility);
	}
	return 0;
}