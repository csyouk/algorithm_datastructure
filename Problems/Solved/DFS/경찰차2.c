#include <stdio.h>
int N;//도로 개수
int W;//사건 개수
int col[20+10];//사건 가로 위치
int row[20+10];//사건 세로 위치
int sol;//답
int ABS(int a){
  if(a > 0) return a;
  return -a;
}
int CAL(int a, int b){
  return ABS(col[a]-col[b]) + ABS(row[a]-row[b]);
}
void DFS(int p1, int p2, int dist){//경찰차1, 경찰차2, 이동거리
  int incident = ((p1 > p2) ? p1 : p2) + 1;
  if(incident > W){//모든사건처리
    if(sol > dist) sol = dist;
    return;//종료
  }
  DFS(incident, p2, dist+CAL(incident, p1));//경찰차1이 처리
  DFS(p1, incident, dist+CAL(incident, p2));//경찰차2가 처리
}
int main(void){
  int i;
  scanf("%d", &N);
  scanf("%d", &W);
  col[0]=row[0]=1;//경찰차1 위치
  col[1]=row[1]=N;//경찰차2 위치
  W++;//0,1은 경찰차 위치, 2부터 사건위치이므로1 증가시킴
  for(i=2;i<=W;i++){
    scanf("%d %d", &col[i], &row[i]);
  }

  sol = 0x7FFFFFFF;//최소값 찾으므로 최대값으로 초기화
  DFS(0, 1, 0);//경찰차1, 경찰차2, 이동거리

  printf("%d\n", sol);
  return 0;
}
