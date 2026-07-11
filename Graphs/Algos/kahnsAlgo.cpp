//It is a topological sort using BFS

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    //create adjacency list
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    //now find indegree of all vertices
    vector<int> indDegree(v);
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
    vector<int> ans;

    while(!q.empty()){
        int top = q.front();
        q.pop();

        ans.push_back(top);

        for(auto neighbour: adjList[top]){
            indDegree[neighbour]--;

            if(indDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return ans;

}