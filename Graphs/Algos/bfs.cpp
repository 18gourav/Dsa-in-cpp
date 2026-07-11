// Function to perform Breadth First Search (BFS)
void bfs(vector<int> &ans, unordered_map<int,bool> &visited,
         vector<vector<int>> &adj, int node){

    // Queue is used because BFS follows FIFO (First In First Out)
    queue<int> q;

    // Push the starting node into the queue
    q.push(node);

    // Mark the starting node as visited
    visited[node] = true;

    // Continue until all reachable nodes are visited
    while(!q.empty()){

        // Take the front node from the queue
        int topNode = q.front();
        q.pop();

        // Store the node in the BFS traversal answer
        ans.push_back(topNode);

        // Traverse all neighbours of the current node
        for(auto i : adj[topNode]){

            // If the neighbour has not been visited
            if(!visited[i]){

                // Push it into the queue for future processing
                q.push(i);

                // Mark it as visited immediately to avoid
                // inserting the same node multiple times
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    // Vector to store the BFS traversal
    vector<int> ans;

    // Keeps track of visited nodes
    unordered_map<int,bool> visited;

    // Start BFS from node 0
    // (Assuming the graph is connected)
    bfs(ans, visited, adj, 0);

    // Return the BFS traversal
    return ans;
}

//TC: O(V+E)