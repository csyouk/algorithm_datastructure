# Prim
- 임의의 노드에서 시작해서 간선을 추가하는 방식이다.
- 프림기법은 그리디 기법과 같이 현재 상태에서 최선의 선택을 하는 방법이다.
- 임의로 선택한 노드에서 연결된 노드를 연결해 나아갈 때, 가장 최소/최대의 비용의 연결방법을 계산하는 기법이다.
- 프림기법을 통해서 나온 결과물로 알수 있는 것은, 어떠한 노드를 선택하던, 모든 노드를 연결하는
가장 최소/최대의 비용은 동일하다는 것이다.



## 용어
- cost : 각 노드별 연결 비용을(최소 혹은 최대) 기록해 놓는다.
- visited : 각 노드에 대한 계산이 끝났는지 체크를 한다.

- 문제를 통해서 기법을 이해해보자.

```cpp


#include <stdio.h>
#define SIZE 100+10
#define VISIT 1
#define NO_PATH 0
#define INF 0x7fffffff

int map[SIZE][SIZE];
int cost[SIZE], visited[SIZE];
int N;

int Prim(int start, int total_node){
	int rep, node, current_node, min, sum=0;
	visited[start] = VISIT; cost[start] = 0;
	current_node = start;

  // 처음 선택한 노드를 제외한 모든 노드에 대해서 연산을 수행한다.
	for (rep = 1; rep <= total_node - 1; rep++)
	{
    // >>>>> 비용을 갱신하는 부분이다. <<<<<
    // 선택한 특정노드가 어떠한 노드와 연결상태를 가지고 있을지 모르므로, 모든 노드에
    // 대해서 검사를 한다.
		for (node = 1; node <= total_node; node++)
		{

      // 이미 비용에 대한 연산이 끝난 노드는 제외한다.
			if (visited[node]) continue;

      // 현재 노드에서 연결되지 않은 노드들을 무시한다.
			if (map[current_node][node] == NO_PATH) continue;

      // 현재 노드와 연결한 노드 중, 기존 연결비용보다 저렴한 것이 있다면, 갱신한다.
			if (cost[node] > map[current_node][node]) {
				cost[node] = map[current_node][node];
			}
		}

    // >>>>> 새로 연결된 노드 중, 가장 최소의 비용을 가지는 노드를 선택한다. <<<<<
		min = INF;
		for ( node = 1; node <= total_node; node++)
		{
      // 이미 계산이 끝난 노드라면 마찬가지로 검사가 필요 없다.
			if (visited[node]) continue;

      // 아직 길이 연결되지 않은 노드라면, 검사가 필요 없다.
			if (cost[node] == INF) continue;

      //
			if (min > cost[node]){
				min = cost[node];
				current_node = node;
			}
		}
		visited[current_node] = VISIT;
	}


	for (node = 1; node <=N; node++)
	{
		sum += cost[node];
	}
	return sum;
}
void Init(void){
	int i, j;
	// 연결 상태 저장.
	for (i = 1; i <= N; i++)
	{
		for ( j = 1; j <=i; j++)
		{
			scanf("%d", &map[i][j]);
			map[j][i] = map[i][j];
		}
		cost[i] = INF;
	}
}

int main(void){
	//freopen("in.txt", "r", stdin);
	int sel = 1;
	scanf("%d", &N);
	Init();

	printf("%d", Prim(sel, N));

	return 0;
}
```
