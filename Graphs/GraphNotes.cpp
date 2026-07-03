// 1. What is a Graph?

// A graph is a non-linear data structure consisting of:
// -> Vertices (Nodes) --> Entity to store data
// -> Edges (Connections between nodes) -> connection bw nodes 

// G = (V, E)
// V = Set of Vertices
// E = Set of Edges

// 2. Types of Graphs

// (a) Undirected Graph
// Edge has no direction.
// Example:
// 1 ----- 2(there is two dir (1 to 2) and (2 to 1))
// |       |
// 3 ----- 4

// (b) Directed Graph (Digraph)
// Edge has direction.
// Example:
// 1 ---> 2 ---> 3(in this only (1 to 2) not (2 to 1))

// (c) Weighted Graph
// Each edge has a weight/cost.
// Example:
// 1 --5--> 2

// (d) Unweighted Graph
// No edge weights.

// (e) Connected Graph
// Every node can be reached from every other node.

// (f) Disconnected Graph
// Some nodes cannot be reached.

// (g) Cyclic Graph
// Contains at least one cycle.
// Cycle --> means we reach starting node after traversing full graph

// (h) Acyclic Graph
// No cycles present.

// (i) Tree
// Connected + Acyclic Graph.

// 3. Degree
// Number of edges connected to a node.

// Indegree
// Number of incoming edges.

// Outdegree
// Number of outgoing edges.


// 5. Graph Representation


// (A) Adjacency Matrix
// (B) Adjacency List

// 6. Adjacency Matrix:

// Matrix of size V x V.

// matrix[i][j] = 1 if i connected to j
// otherwise 0

// Example:
//
// 0---1
// |  /
// | /
// 2
//
// Matrix:
//
//   0 1 2
//0  0 1 1
//1  1 0 1
//2  1 1 0

// Space Complexity = O(V²)

// Pros:
// Easy to check edge.

// Cons:
// Wastes space for sparse graphs.

// 7. Adjacency List:

// Each vertex stores its neighbours.
//Condidering upper graph

// Example:
//
// 0 -> [1 , 2]
// 1 -> [0 , 2]
// 2 -> [0 , 1]

// Space Complexity = O(V + E)

// Preferred in competitive programming.