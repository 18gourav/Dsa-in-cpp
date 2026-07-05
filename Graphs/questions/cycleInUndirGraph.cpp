#include<unordered_map>
#include<list>
#include<queue>

//this is the approach using bfs
bool isCycleBfs(int node,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited){
    //first we have to make a ds to keep parent of node
    unordered_map<int,int> parent;
    queue<int> q;

    q.push(node);
    parent[node] = -1;
    visited[node] = true;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour: adjList[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //first make adjcemcy list
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    //now for disconnected graph we have to run loop

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCycleBfs(i,adjList,visited);

            if(ans){
                return "Yes";
            }
        }
    }

    return "No";
}


//this is the approach using dfs
bool isCycleDfs(int node,int parent,unordered_map<int,list<int>> &adjList,
unordered_map<int,bool> &visited){
    visited[node] = 1;

    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            bool ans = isCycleDfs(neighbour,node,adjList,visited);
            if(ans){
                return true;
            }
        }
        else if(neighbour != parent){
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //first make adjcemcy list
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    //now for disconnected graph we have to run loop

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCycleDfs(i,-1,adjList,visited);

            if(ans){
                return "Yes";
            }
        }
    }

    return "No";
}
