//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//#define MAX(a,b) ((a)>(b)?(a):(b))
//#define MIN(a,b) ((a)<(b)?(a):(b))
//
//struct Point
//{
//	int r, c;
//	Point() {}
//	Point(int r, int c) : r(r), c(c) {}
//}man[10], stair[2];
//
//int N, M, S;
//int map[10][10];
//int match[10];
//
//int tc;
//int ans;
//
//int abs(int a)
//{
//	if (a >= 0)  return a;
//	else return -a;
//}
//
//int dist(int man_index, int stair_index)
//{
//	int dx = abs(man[man_index].r - stair[stair_index].r);
//	int dy = abs(man[man_index].c - stair[stair_index].c);
//	return dx + dy;
//}
//
//void update()
//{
//	int total_min_time = 0;
//
//	for (int stair_index = 0; stair_index < 2; stair_index++)
//	{
//		Point &now_stair = stair[stair_index];
//		int arr_t[20] = { 0, };
//		int cur_stair[120] = { 0, };
//		for (int man_index = 0; man_index < M; man_index++)
//		{
//			if (match[man_index] == stair_index)
//			{
//				arr_t[dist(man_index, stair_index) + 1]++;
//			}
//		}
//
//		int now_min_time = 0;
//
//		for (int time = 1; time <= 20; time++)
//		{
//			while (arr_t[time] > 0)
//			{
//				arr_t[time]--;
//
//				int remain_time = map[now_stair.r][now_stair.c];
//				for (int walk_time = time; walk_time < 120; walk_time++){
//					if (cur_stair[walk_time] < 3){
//						cur_stair[walk_time]++;
//						remain_time--;
//					}
//					if (remain_time == 0){
//						now_min_time = MAX(now_min_time, walk_time + 1);
//						break;
//					}
//				}
//			}
//		}
//		total_min_time = MAX(total_min_time, now_min_time);
//	}
//	ans = MIN(ans, total_min_time);
//}
//
//void DFS(int man_index)
//{
//	if (man_index == M)
//	{
//		update();
//		return;
//	}
//	for (int stair_index = 0; stair_index < 2; stair_index++)
//	{
//		match[man_index] = stair_index;
//		DFS(man_index + 1);
//	}
//}
//
//int main(){
//	scanf("%d", &tc);
//	for (int t = 1; t <= tc; t++)
//	{
//		// 데이터 초기화 및 입력
//
//		M = 0;
//		S = 0;
//		scanf("%d", &N);
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				map[i][j] = 0;
//				scanf("%d", &map[i][j]);
//				if (map[i][j] == 1) man[M++] = Point(i, j);
//				if (map[i][j] >= 2) stair[S++] = Point(i, j);
//			}
//		}
//		// 알고리즘 시작
//		ans = 1 << 20;
//		DFS(0);
//
//		// 결과 값 출력
//		printf("#%d %d\n", t, ans);
//	}
//	return 0;
//}