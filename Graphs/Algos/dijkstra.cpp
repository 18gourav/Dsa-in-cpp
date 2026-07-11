#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // make adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        //it is undirected graph so we have edge from v to u and u to v
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //now for dijkstra algo we need two data struct

    //1.Set to identigy node with min dist
    //set<dist,node>
    set<pair<int,int>> st;

    //2. a vector of dist 
    vector<int> dist(vertices);

    for(int i=0; i<vertices;i++){
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    st.insert(make_pair(0,0));

    while(!st.empty()){

        //fetch the top record
        auto top = *(st.begin());

        int nodeDist = top.first;
        int node = top.second;

        //now erase this data
        st.erase(st.begin());

        //now traverse neighbours
        for(auto i:adj[node]){
            if(nodeDist + i.second < dist[i.first]){

                //sabse pehle to agar jo node ham dalna vala hai or vo pehle hi set mai ho to nikalo usko
                auto record = st.find(make_pair(dist[i.first],i.first));
                //agar record mil gaya
                if(record != st.end()){
                    st.erase(record);
                }

                //ab distance update karo or set ma dalo
                dist[i.first] = nodeDist + i.second;
                st.insert(make_pair(dist[i.first],i.first));
            }
        }

    }

    return dist;


}
//TC : O(ElogV)
//SC: O(N+E)