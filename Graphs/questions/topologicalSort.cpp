//This can be only applied to Directed Acyclic Graph(DAG)
//It is a linear ordering of vertices such that -> For every edge if there is a edge " u -> v " then in ans " u always before v "

//In this approach we did it using DFS
#include <bits/stdc++.h>
#include <stack>
#include <unordered_map> 
#include <list> 

void topSort(int i,unordered_map<int,list<int>> &adjList,
vector<bool> &visited,stack<int> &s){
    visited[i] = 1;

    for(auto neighbour: adjList[i]){
        if(!visited[neighbour]){
            topSort(neighbour,adjList,visited,s);
        }
    }

    s.push(i);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adjacency list
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            topSort(i,adjList,visited,s);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}