vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    //first we create a vector in which we store [u to v] and [v to u]\
    //u,v -> any nodes

    // this means we create an array of n vectors
    vector<int> ans[n];

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adjList(n);

    //in a row first we insert present node then its neighbours
    for(int i=0; i<n; i++){
        //all node data are o to n-1
        adjList[i].push_back(i);

        for(int j=0;j<ans[i].size(); j++){
            adjList[i].push_back(ans[i][j]);
        }
    }

    return adjList;

}