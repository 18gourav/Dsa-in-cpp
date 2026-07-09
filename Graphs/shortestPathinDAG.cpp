#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<limits.h>
#include<vector>
using namespace std;

class graph{
    public:
    //key-> node value->{int,weight}
    unordered_map<int,list<pair<int,int>>> adjList;

    //ab adjList banao
    void insertAdge(int u,int v,int weight){
        pair<int,int> p = make_pair(v,weight);

        adjList[u].push_back(p);
    }

    void printAdj(){
        for(auto i : adjList){
            cout<< i.first << "-->";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }
            cout<<endl;
        }
    }

    void dfs(int node,unordered_map<int,bool> &visited,stack<int> &s){
        visited[node] = 1;

        for(auto neighbour: adjList[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first,visited,s);
            }
        }

        s.push(node);
    }

    void getShortestPath(int src,stack<int> &topo,vector<int> &dist)
};

int main() {
    graph g;

    g.insertAdge(0,1,5);
    g.insertAdge(0,2,3);
    g.insertAdge(1,2,2);
    g.insertAdge(1,3,6);
    g.insertAdge(2,3,7);
    g.insertAdge(2,4,4);
    g.insertAdge(2,5,2);
    g.insertAdge(3,4,-1);
    g.insertAdge(4,5,-2);

    g.printAdj();

    //ab topological sort ko print karao
    int n 6;

    unordered_map<int,bool> visited;
    stack<int> topaSort;
    for(int i=0; i<n; i++){
        if(!visited(i)){
            dfs(i,visited,topaSort);
        }
    }

    int src = 1;

    //ab distamce vale array ko int max se initialize karo
    vector<int> dist(n);

    for(int i=0 i<n; i++){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    while(!topaSort.empty()){
        int top = topaSort.top();
        topaSort.pop();

        if(dist)


    }

    return 0;
}