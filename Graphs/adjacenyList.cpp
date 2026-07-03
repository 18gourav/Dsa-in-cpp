//in this we will make Adjacency list

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class graph{
    public:
    //this is thr Adjacency list
    unordered_map<int,list<int>> adjList;

    void addEdge(int u,int v,bool direction){
        // u and v -> edges
        //direction -> 0 meand undirected graph
        //direction -> 1 means directed graph

        //first we make connection bw u and v edge
        adjList[u].push_back(v);

        //now to make connection bw v and u whe have to check if its directed or undirected
        if(direction == 0){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adjList){
            cout<<i.first<<"-> ";
            for(auto j: i.second){
                cout<<j<<",";
            }

            cout<<endl;
        }

    }
};

int main(){

    int n;
    cout<<"enter no of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"enter no of edges"<<endl;
    cin>>m;

    graph g;

    //now take input all nodes and orint graph
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;

        //we are making undirected graph
        g.addEdge(u,v,0);
    }

    g.printAdjList();


    return 0;
}