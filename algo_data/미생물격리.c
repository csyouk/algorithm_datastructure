//#include <stdio.h>
//#include <string.h>
//#define DIRS 4
//
//typedef struct {
//	int r, c;
//	int amount;
//	int dir;
//	int removed;
//} Cell;
//
//Cell cells[1001];
//
//// 순서대로 0, 북,남,서,동
//int dr[] = {0,-1,1,0,0};
//int dc[] = {0,0,0,-1,1};
//
//int T, N, K, M;
//int LeftSum;
//int DangerZoneRowFirst;
//int DangerZoneRowLast;
//int DangerZoneColFirst;
//int DangerZoneColLast;
//
//void Init(void){
//	memset(cells, 0, sizeof(cells));
//	LeftSum = 0;
//	N = K = M = 0;
//}
//
//void Input_Data(void){
//	int i;
//	scanf("%d %d %d", &N, &M, &K);
//	DangerZoneRowFirst = DangerZoneColFirst = 0;
//	DangerZoneRowLast = DangerZoneColLast = N - 1;
//
//	for ( i = 0; i < K; i++)
//	{
//		scanf("%d %d %d %d", &cells[i].r, &cells[i].c, &cells[i].amount, &cells[i].dir);
//	}
//}
//
//void Move(void){
//	int i;
//	for (i = 0; i < K; i++){
//		if (cells[i].removed) continue;
//		cells[i].r += dr[cells[i].dir];
//		cells[i].c += dc[cells[i].dir];
//	}
//}
//
//void SwitchDir(Cell * cell){
//	switch (cell->dir)
//	{
//	case 1:
//		cell->dir = 2;
//		return;
//	case 2:
//		cell->dir = 1;
//		return;
//	case 3:
//		cell->dir = 4;
//		return;
//	case 4:
//		cell->dir = 3;
//		return;
//	default:
//		break;
//	}
//}
//
//void CheckDangerZone(void){
//	int i;
//	for (i = 0; i < K; i++){
//		if (cells[i].removed) continue;
//		if (cells[i].r == DangerZoneRowFirst ||
//			cells[i].r == DangerZoneRowLast){
//			cells[i].amount /= 2;
//			SwitchDir(&cells[i]);
//			if (cells[i].amount == 0) { cells[i].removed = 1; }
//			continue;
//		}
//		if (cells[i].r == DangerZoneColFirst ||
//			cells[i].r == DangerZoneColLast){
//			cells[i].amount /= 2;
//			SwitchDir(&cells[i]);
//			if (cells[i].amount == 0) { cells[i].removed = 1; }
//			continue;
//		}
//	}
//}
//
//void Update(void){
//	int i, j, flag, biggest_amount, biggest_cell_index;
//	for (i = 0; i < K; i++){
//		if (cells[i].removed) continue;
//		flag = 0;
//		biggest_amount = cells[i].amount;
//		biggest_cell_index = i;
//		for ( j = i+1; j < K; j++)
//		{
//			if (cells[j].removed) continue;
//			if (cells[i].r != cells[j].r || cells[i].c != cells[j].c) continue;
//			if (biggest_amount < cells[j].amount) {
//				biggest_amount = cells[j].amount;
//				biggest_cell_index = j;
//			}
//		}
//		if (biggest_cell_index != i) {
//			cells[i].removed = 1;
//			cells[biggest_cell_index].amount += cells[i].amount;
//			cells[i].amount = 0;
//		}
//		for (j = i + 1; j < K; j++)
//		{
//			if (cells[j].removed) continue;
//			if (cells[i].r != cells[j].r || cells[i].c != cells[j].c) continue;
//			cells[biggest_cell_index].amount += cells[j].amount;
//			cells[j].amount = 0;
//			cells[j].removed = 1;
//		}
//	}
//}
//
//void Simulation(void){
//	while (M--)
//	{
//		Move(); // 미생물 움직이기.
//		CheckDangerZone(); // 약품 위치에 있는지 확인. 미생물 파기
//		Update(); // 미생물 합치고, 방향 체크, 미생물 파기 
//	}
//}
//
//void SumUpLeft(void){
//
//	int i;
//	for (i = 0; i < K; i++){
//		if (cells[i].removed) continue;
//		LeftSum += cells[i].amount;
//	}
//	
//}
//
//int main(void){
//	int test_case = 1;
//	scanf("%d", &T);
//	while (T--)
//	{
//		Init();
//		Input_Data();
//		Simulation();
//		SumUpLeft();
//		printf("#%d %d\n", test_case, LeftSum);
//		test_case++;
//	}
//	
//	return 0;
//}