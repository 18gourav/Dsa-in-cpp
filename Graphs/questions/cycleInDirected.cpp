#include<list>
bool cycleUsingDfs(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,
unordered_map<int,list<int>> &adjList){
  visited[node] = true;
  dfsVisited[node] = true;

  for(auto neighbour: adjList[node]){
    if(!visited[neighbour]){
      bool cyclePresent = cycleUsingDfs(neighbour,visited,dfsVisited,adjList);
      if(cyclePresent){
        return true;
      }
    }
    else if(dfsVisited[neighbour]){
      return true;
    }
  }

  dfsVisited[node] = false;

  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // first make adjacency list
  unordered_map<int,list<int>> adjList;

  for(int i=0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adjList[u].push_back(v);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsVisited;
  for(int i=0; i<n; i++){
    if(!visited[i]){
      bool ans = cycleUsingDfs(i,visited,dfsVisited,adjList);
      if(ans){
        return 1;
      }
    }
  }

  return 0;
}