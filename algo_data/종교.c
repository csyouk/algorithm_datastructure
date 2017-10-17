#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int p1, p2, i;
} Pair;
Pair pair[100001];
int N, M;
int cnt = 1;
int religion[50001];
	
int comp(const Pair * a1, const Pair * a2){
	if (a1->p1 == a2->p1) return a1->p2 - a2->p2;
	else return a1->p1 - a2->p1;
}

void Input_Data(void){
	int i, tmp;
	scanf("%d %d", &N, &M);
	for ( i = 1; i <=M; i++){
		scanf("%d %d", &pair[i].p1, &pair[i].p2);
		if (pair[i].p1 > pair[i].p2){
			tmp = pair[i].p1;
			pair[i].p1 = pair[i].p2;
			pair[i].p2 = tmp;
		}
	}
	qsort(pair + 1, M, sizeof(Pair), comp);
}

void Find(){
	int i;
	for ( i = 1; i <= M; i++)
	{
		if (religion[pair[i].p1] == 0 && religion[pair[i].p2] == 0){
			religion[pair[i].p1] = religion[pair[i].p2] = cnt;
			cnt++;
		}	else {
			if (religion[pair[i].p1]){
				religion[pair[i].p2] = religion[pair[i].p1];
			} else {
				religion[pair[i].p1] = religion[pair[i].p2];
			}
		}
	}


}


int main(void){
	Input_Data();
	Find();
	if (!(cnt - 1))
		printf("%d", N);
	else
		printf("%d", cnt-1);

	return 0;
}