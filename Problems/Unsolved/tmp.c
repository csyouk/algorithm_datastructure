int Prim(int start){
  int rep, node, current, min, sum = 0;
  visited[start] = 1;
  cost[start] = 0;
  current = start;

  for(rep = 1; rep <= N-1; rep++){
    for(node = 1; node <= N; node++){
      if(visited[node]) continue;
      if(map[current][node] == 0) continue;
      if(cost[node] > map[current][node]){
        cost[node] = map[current][node];
      }
    }


    min = 0x7fffffff;
    for(node = 1; node <= N; node++){
      if(visited[node]) continue;
      if(cost[node] == 0x7fffffff) continue;
      if(min > cost[node]){
        min = cost[node];
        current = node;
      }


    }
    visited[current] = 1;
  }

  for(nod=1;node<=N;node++){
    sum += cost[node];
  }
  return sum;
}
