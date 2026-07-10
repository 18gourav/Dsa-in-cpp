//Prims Algo -> It is a type of algo which is used to make min spanning tree(MST)

//Now what is MST?

//Spanning Tree -> When we convert a graph into tree such that it contain "n nodes and n-1 edges" and all nodes should be reachable from every node

//MST -> Among all spanning tree, which have min cost of weight is a MST

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //first create adj list
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        //it is a undirected graph
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    //now for prims algo we need 3 ds

    //1.First a key vector in which we store all nodes incoming edge weight to
    // track min weight to reach that node
    vector<int> key(n+1);

    //2. A mst vector in which we track if a node is included in MST or not
    vector<bool> MST(n+1);

    //3. A parent vector to track all nodes parent
    vector<int> parent(n+1);

    //now initialize all arrays
    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        MST[i] = false;
        parent[i] = -1;
    }

    //Algo:

    //consider first node of graph as src nodr and mark its key as 0 and parent -1
    key[1] = 0;
    parent[1] = -1;

    //now process other nodes
    for(int i=1; i<n; i++){
        //step1 -> sabse pehle ham log key array ma min nikalenge
        int mini = INT_MAX;
        int u = -1;

        for(int v =1; v<=n; v++){
            //ham log uss node ko consider nhi karenge jo mst array ma true marked ho
            if(MST[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        //ab hama sabse min dist vali node pata lg gyi ab usko mst ma true mardo
        MST[u] = true;

        //ab iske adj node pata karo
        for(auto it:adjList[u]){
            int v= it.first;
            int w = it.second;

            //key vali array ma w ko comapare karo agar w kam hai to w ko daldo
            //or parent bhi update kardo
            if(MST[v] == false && w<key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for(int i=2; i<=n; i++){
        result.push_back({{parent[i],i},key[i]});
    }

    return result;

}

//TC : O(n^2)

//ye vala sol optimal hai kyuki jo upar hum log key mai sa O(n) ma min laga raha tha vo isma O(1) ma hogo
#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //first create adj list
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        //it is a undirected graph
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    //now for prims algo we need 3 ds

    //1.First a key vector in which we store all nodes incoming edge weight to
    // track min weight to reach that node
    vector<int> key(n+1);

    //2. A mst vector in which we track if a node is included in MST or not
    vector<bool> MST(n+1);

    //3. A parent vector to track all nodes parent
    vector<int> parent(n+1);

    //4: priority queue --> min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    //now initialize all arrays
    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        MST[i] = false;
        parent[i] = -1;
    }

    //Algo:

    //consider first node of graph as src nodr and mark its key as 0 and parent -1
    key[1] = 0;
    parent[1] = -1;
    pq.push({0,1});

    //now process other node
    while(!pq.empty()){
        //hamna isiliye pq banaya tha taki ham min O(1) la saka
        int w = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if(MST[u]){
            continue;
        }

        MST[u] = true;

        for(auto it:adjList[u]){
            int v = it.first;
            int w = it.second;

            //key vali array ma w ko comapare karo agar w kam hai to w ko daldo
            //or parent bhi update kardo
            if(MST[v] == false && w<key[v]){
                key[v] = w;
                parent[v] = u;

                pq.push({key[v],v});
            }
        }

    }

    vector<pair<pair<int, int>, int>> result;

    for(int i=2; i<=n; i++){
        result.push_back({{parent[i],i},key[i]});
    }

    return result;

}

//TC : O(nlogn)