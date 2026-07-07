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

//###########################
//This is the approach using BFS(kanh algo)
//###########################

#include<list>
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create adjacency list
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adjList[u].push_back(v);
    }

    //now find indegree of all vertices
    vector<int> indDegree(n);
    for(auto i:adjList){
        for(auto j:i.second){
            indDegree[j]++;
        }
    }

    //0 indegree valo ko push kardo queue ma
    queue<int> q;
    for(int i=0; i<indDegree.size(); i++){
        if(indDegree[i] == 0){
            q.push(i);
        }
    }

    //ab normal bfs karo
    int count = 0;

    while(!q.empty()){
        int top = q.front();
        q.pop();

        count++;

        for(auto neighbour: adjList[top]){
            indDegree[neighbour]--;

            if(indDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    if(count != n){
      return 1;
    }

    return 0;
}