#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

void dfs(int node,int parent,vector<int> &low,vector<int> &disc,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjList,int &timer,vector<int> &ans){
    
    visited[node] = true;
    low[node] = disc[node] = timer++;
    
    int child = 0;

    for(auto adj: adjList[node]){
        if(adj == parent){
            continue;
        }
        else if(!visited[adj]){
            dfs(adj,node,low,disc,visited,adjList,timer,ans);
            low[node] = min(low[node],low[adj]);
            //check if that node is Articulation Point
            if((low[adj] >= disc[node]) && parent != -1){
                ans[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node],disc[adj]);
        }

        if(parent == -1 && child >1){
            ans[node] = 1;
        }
    }
}

int main(){

    int n = 5;
    int e = 5;
    vector<pair<int,int>> edges;

    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    unordered_map<int,list<int>> adjList;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> low(n);
    vector<int> disc(n);
    unordered_map<int,bool> visited;
    int timer = 0;
    vector<int> ans(n,0);

    for(int i=0; i<n; i++){
        low[i] = -1;
        disc[i] = -1;
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i,-1,low,disc,visited,adjList,timer,ans);
        }
    }

    for(int i=0; i<n; i++){
        if(ans[i] != 0){
            cout<<i<<" ";
        }
    }
}

//TC : O(V+E)
//SC : O(V)