#include <stdio.h>
#include <string.h>


int left_pin, move_cnt;
char map[5][8];

void Init(void){
	left_pin = move_cnt = 0;
}

void Input_Data(void){

}

int main(void){

	int T;
	while (T--)
	{
		Init();
		Input_Data();
		DFS(1);
		printf("%d %d\n", left_pin, move_cnt);
	}
	return 0;
}