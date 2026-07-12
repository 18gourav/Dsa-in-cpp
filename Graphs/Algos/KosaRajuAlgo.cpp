//This is KoasaRaju Algo
// Kosaraju's Algorithm ka use Strongly Connected Components (SCC) nikalne ke liye hota hai. 
// SCC directed graph mein nodes ka aisa group hota hai jahan har node se har doosre node tak pahunch sakte hain.

#include<unordered_map>
#include<vector>
#include<list>
#include<stack>
void dfs(int node,unordered_map<int,bool> &vis,stack<int> &s,
unordered_map<int,list<int>> &adjList){
	vis[node] = true;

	for(auto adj: adjList[node]){
		if(!vis[adj]){
			dfs(adj,vis,s,adjList);
		}
	}

	s.push(node);
}

void revDfs(int node,unordered_map<int,list<int>> &transpose,
unordered_map<int,bool> &vis){
	vis[node] = true;

	for(auto adj:transpose[node]){
		if(!vis[adj]){
			revDfs(adj,transpose,vis);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//create a adjcency list
	unordered_map<int,list<int>> adjList;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adjList[u].push_back(v);
	}

	//now create the topological sort stack
	unordered_map<int,bool> vis;
	stack<int> s;

	for(int i=0; i<v; i++){
		if(!vis[i]){
			dfs(i,vis,s,adjList);
		}
	}

	vis.clear();
	//now transpose the graph
	//Ex if a edge 1--->2 the after transposing 1<---2
	unordered_map<int,list<int>> transpose;
	for(int i=0; i<edges.size(); i++){
		vis[i] = false;
		int u = edges[i][0];
		int v = edges[i][1];

		transpose[v].push_back(u);
	}

	//call dfs using topological Sort
	int count = 0;
	while(!s.empty()){
		int top = s.top();
		s.pop();

		if(!vis[top]){
			count++;
			revDfs(top,transpose,vis);
		}
	}

	return count;

}

// TC: O(V+E)
// SC: O(V)