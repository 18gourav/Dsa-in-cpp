//iss algo ko ham tarjan's algo bhi bolte hai

#include<list>
void dfs(int node,int parent,int &timing,unordered_map<int,list<int>> &adjList,
vector<int> &disc,vector<int> &low,unordered_map<int,bool> &visited,vector<vector<int>> &result){
    //first mark the node visited
    //and set their low and disc time

    visited[node]= true;
    low[node] = disc[node] = timing++;

    //now visit its adj
    for(auto adj:adjList[node]){
        if(adj == parent){
            continue;
        }
        if(!visited[adj]){
            dfs(adj,node,timing,adjList,disc,low,visited,result);
            low[node] = min(low[node],low[adj]);
            //ab check karo vo node bridge hai ya nhi
            if(low[adj] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(adj);
                result.push_back(ans);
            }
        }
        else{
            //isma ham tab ayenge jab koi node parent bhi na ho or vsisted ho
            //iska mtlb vo BACK EDGE hai
            low[node] = min(low[node],disc[adj]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // make adj list
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //now we need three ds for this ques

    //1. vector named disc
    //in this we store timing at which we reached node first time
    vector<int> disc(v);

    //2. vector named low
    //in this we store the leasr time to reach a node
    vector<int> low(v);

    //3. visited
    unordered_map<int,bool> visited;

    int parent = -1;
    int timing = 0;

    //initialise all array
    for(int i=0; i<v; i++){
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;

    //now visit all nodes
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i,parent,timing,adjList,disc,low,visited,result);
        }
    }

    return result;

}

//TC : O(V+E)
//SC : O(V)