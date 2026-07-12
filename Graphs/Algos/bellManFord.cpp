//We use bellman ford algo to find the shortest path bw src and dest node
//But here is a catch ---> we can use it for -ve weights also
//But in case of -ve cycle it does not get applied

//But dijkstra fails in -ve weight case
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    //create a dist array, initially all have infinity and set src node dist to 0
    vector<int> dist(n+1,1e8);
    dist[src] = 0;

    //now in this algo we have update the weight in full graph (n-1) times
    for(int j=1;j<n; j++){
        //now traverse edges vector
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            //now apply the formula
            if(dist[u] != 1e9 && ((dist[u] + w ) < dist[v])){
                dist[v]= dist[u] + w;
            }
        }
    }

    //ye wala part isliye commented hai kyuki ques ma mention tha ki -ve cycle are not present

    // bool flag = 0;
    // //now we have to repeat upper step one more time to ensure there is no -ve cycles
    // for(int i=0; i<edges.size(); i++){
    //         int u = edges[i][0];
    //         int v = edges[i][1];
    //         int w = edges[i][2];

    //         //now apply the formula
    //         if(dist[u] != 1e9 && ((dist[u] + w ) < dist[v])){
    //             flag = 1;
    //         }
    //     }

    return dist;

    
}