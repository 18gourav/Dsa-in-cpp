void dfs(int node,unordered_map<int,bool> &visited,vector<int> &temp,unordered_map<int,list<int>> &adjList){
            
    temp.push_back(node);
    visited[node] = true;

    //FOR EVERY CONNECTED NODE MAKE RECURSIVE CALL
    for(auto i : adjList[node]){
        if(!visited[i]){
            dfs(i,visited,temp,adjList);
        }
    }

}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;

    //prepare adjacency list
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        //make connection bw (u and v) and (v and u)
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int,bool> visited;

    //in case of disconnected  so that none of node remain unvisited

    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(i,visited,temp,adjList);
            ans.push_back(temp);
        }
    }

    return ans;
}

//TC and SC are linear