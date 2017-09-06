# Dijkstra
- **Directed, Weight Graph** 문제에서 임의의 점 n에서 임의의 점 m으로 갈 때의 비용을
계산하는 문제이다.
- Prim 알고리즘과 형태는 유사한, cost배열의 쓰임새가 완전히 다르다.
- Prim 알고리즘에서 cost배열은 Node와 Node사이의 최소/최대 값을 저장해 놓는 용도 였다면,
- Dijkstra 알고리즘에서 cost배열은 임의의 점에서 임의의 점까지의 최소/최대 비용을 저장해놓는 용도이다.

## 용어
- cost : 각 노드별 연결 비용을(최소 혹은 최대) 기록해 놓는다.
이때 기록 되는 비용은 기준점으로부터의 비용이다.(예를 들어서 기준점이 1이였다면, 1에서 부터 2까지 가는 비용,
  1에서 3까지 가는 비용, 1에서 4... 이런식이다.)
- visited : 각 노드에 대한 계산이 끝났는지 체크를 한다.


```cpp

#include <stdio.h>
#define E_SIZE 10 + 10
#define INF 0x7fffffff
#define VISITED 1
#define NO_PATH 0

int map[E_SIZE][E_SIZE];
int cost[E_SIZE], visited[E_SIZE];

int N;

int Dijkstra(int start, int total_node){
	int cur, node, rep, min;
	cur = start; cost[cur] = 0; visited[cur] = VISITED;

	for ( rep = 1; rep <=N-1; rep++){
		for (node = 1; node <= N; node++){
			if (visited[node] || map[cur][node] == NO_PATH) continue;

      // 프림과 비슷하지만, 이 부분이 차이가 있다. 기준점(start)에서 node 까지 가는 비용을
      // 경유점(cur)을 거쳐서 가는 비용보다 적다면, node까지 가는 비용을
      // 경유점을 거쳐서 가는 비용으로 갱신한다.
			if (cost[node] > cost[cur] + map[cur][node]){
				cost[node] = cost[cur] + map[cur][node];
			}
		}

		min = INF;
		for ( node = 1; node <= total_node; node++){
			if (visited[node] || cost[node] == INF) continue;
			if (min > cost[node]){
				min = cost[node];
				cur = node;
			}
		}
		visited[cur] = VISITED;
	}

	return cost[total_node];
}

int main(void){
	int i, j;
	scanf("%d", &N);

	for ( i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%d", &map[i][j]);
		}
		cost[i] = INF;
	}

	printf("%d", Dijkstra(1, N));

	return 0;
}
```


- 지하철 문제를 통해서 경로 추적하는 법을 배워보자.
- path배열을 통해서 각 노드가 어디서부터 오게되었는지(root)를 찾아보자.

> 지방에서 서울에 관광 온 성수는 지하철 노선을 보고 깜짝 놀랐다. 노선이 엄청나게 복잡하기 때문이었다. 각 노선들이 서로 얽혀있어서 잘못하면 10분도 안 걸리는 거리를 1시간 동안 갈 수도 있는 상황이었다. 어쩔 수 없이 성수는 현재 숙소에서 관광할 목적지까지 가장 짧은 시간에 도착할 수 있는 경로와 시간을 표로 만들려고 한다.
단, 각 지하철역에서 관광지가 있고, 지하철을 갈아타는데 소요되는 시간은 없다고 가정한다.
입력
첫 줄에 N(3<= N <= 100), M(1<= M <= N)을 입력 받는다. N은 지하철역의 수, M은 원하는 목적역의 번호를 입력 받는다.
둘째 줄부터 N개의 줄이 나오고, 각 줄에는 N개의 수 S가 입력된다.
i번째 줄에서 j번째 수 Sij는 i번 역에서 j번 역까지 가는데 걸리는 시간이다. 1번 역이 숙소가 있는 역이고, Sij에서 i=j 일 때는 항상 0이다. (0<= S <=100)
출력
목적 역까지 가는데 걸리는 최소 시간과 최소시간으로 가는 최단 경로를 출력한다.

> 입력 예시
5 5    
0 2 2 5 9  
2 0 3 4 8  
2 3 0 7 6  
5 4 7 0 5  
9 5 6 5 0  

>출력 예시  
8  
1 3 5  

> 아래 문제에서 path배열에 담긴값은 다음과 같다.

|index|0|1|2|3|4|5|  
|-|-|-|-|-|-|-|
|value|0|0|1|1|1|3|

의미를 해석해보면,
>1번 노드는 0번으로 부터 왔다  
>2번 노드는 1번으로 부터 왔다  
>3번 노드는 1번으로 부터 왔다  
>4번 노드는 1번으로 부터 왔다  
>5번 노드는 3번으로 부터 왔다  

> 1번 숙소부터 5번 목적지까지 가는 경로는  
> 5 <- 3 <- 1 이런식이다.

```cpp
#include <stdio.h>
#define SIZE 110
#define INF 0x7fffffff
#define START 0

int map[SIZE][SIZE];
int visited[SIZE];
int cost[SIZE];
int path[SIZE];

int N, M;
void Find_Path(M){
	int prev = path[M];
	if (M == START) return;
	Find_Path(prev);
	printf("%d ", M);
}

int Dijkstra(int start){
	int rep, node, min, cur = start, sum = 0;
	visited[cur] = 1; cost[cur] = 0; path[cur] = cost[cur];

	for ( rep = 1; rep <= N-1; rep++)
	{
		for ( node = 1; node <= N; node++)
		{
			if (visited[node]) continue;
			if (map[cur][node] == 0) continue;
			if (cost[node] > cost[cur] + map[cur][node]){
				cost[node] = cost[cur] + map[cur][node];

				path[node] = cur;
			}
		}

		min = INF;
		for ( node = 1; node <= N; node++)
		{
			if (visited[node]) continue;
			if (cost[node] == INF) continue;
			if (min > cost[node]){
				min = cost[node];
				cur = node;
			}
		}
		visited[cur] = 1;
	}

	return cost[M];
}

int main(void){

	freopen("in.txt", "r", stdin);

	int i, j;
	scanf("%d %d", &N, &M);

	for ( i = 1; i <=N; i++)
	{
		for ( j = 1; j <=N; j++)
		{
			scanf("%d ", &map[i][j]);
		}
		cost[i] = INF;
	}


	printf("%d\n", Dijkstra(1));

	Find_Path(M);
	return 0;
}
```
