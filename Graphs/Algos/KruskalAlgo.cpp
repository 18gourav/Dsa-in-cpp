#include <algorithm>
using namespace std;

// KRUSKAL'S ALGORITHM
// Kruskal's algorithm ka use Minimum Spanning Tree (MST)
// nikalne ke liye hota hai.

// Kruskal's algorithm greedy approach follow karta hai.

// Steps:
// 1. Sabhi edges ko weight ke according sort karo.
// 2. Har node ko alag set me rakho.
// 3. Ek-ek edge uthao.
// 4. Agar edge cycle nahi bana rahi, to MST me add kar do.
// 5. DSU (Disjoint Set Union) ki help se cycle detect karo.

// Time Complexity:

// Sorting: O(E log E)

// DSU operations:
// O(E × α(N))
//
// Overall:
//
// O(E log E)
//
// ============================================================

// Comparator function
// Edges ko unke weight ke basis par sort karega.
// edge = {u, v, w}

bool cmp(vector<int> &a, vector<int> &b) {

    return a[2] < b[2];
}

// MAKE SET

// Initially har node ek alag set me hoti hai.

// Example:

// parent:
// 0 -> 0
// 1 -> 1
// 2 -> 2
// 3 -> 3

// rank:
// [0, 0, 0, 0]
void makeSet(vector<int> &parent, vector<int> &rank, int n) {

    for (int i = 0; i < n; i++) {

        parent[i] = i;

        rank[i] = 0;
    }
}

// ============================================================
// FIND PARENT / FIND SET
// ============================================================

// Kisi node ka ultimate parent return karta hai.

// Example:

// parent:

// 1 -> 2
// 2 -> 3
// 3 -> 3
//
// findParent(1) = 3

// ============================================================
// PATH COMPRESSION
// ============================================================

// Recursive call ke baad saare nodes ko directly
// root se connect kar dete hain.

// Before:
// 1 -> 2 -> 3 -> 4

// After:
//
// 1 ----> 4
// 2 ----> 4
// 3 ----> 4
//
// Isse future find operations fast ho jaate hain.
//
// Time Complexity:
//
// Nearly O(1)
//
// ============================================================

int findParent(vector<int> &parent, int node) {

    if (parent[node] == node) {

        return node;
    }

    return parent[node] =
           findParent(parent, parent[node]);
}

// ============================================================
// UNION BY RANK
// ============================================================
//
// Rank ≈ tree ki height.
//
// Idea:
//
// Chhote rank wale tree ko bade rank wale tree
// ke niche attach karo.
//
// Isse tree balanced rehta hai.
//
// Case 1:
//
// rank[u] < rank[v]
//
//      v
//      |
//      u
//
// parent[u] = v
//
// ------------------------------------------------------------
//
// Case 2:
//
// rank[v] < rank[u]
//
//      u
//      |
//      v
//
// parent[v] = u
//
// ------------------------------------------------------------
//
// Case 3:
//
// rank[u] == rank[v]
//
// Kisi ek ko parent bana do aur uski rank
// ko 1 increase kar do.
//
// ============================================================

void UnionSet(int u,
              int v,
              vector<int> &parent,
              vector<int> &rank) {

    // Ultimate parent nikaal lo

    u = findParent(parent, u);

    v = findParent(parent, v);

    // u ka rank chhota hai

    if (rank[u] < rank[v]) {

        parent[u] = v;
    }

    // v ka rank chhota hai

    else if (rank[v] < rank[u]) {

        parent[v] = u;
    }

    // Dono ki rank equal hai

    else {

        parent[v] = u;

        rank[u]++;
    }
}

// ============================================================
// MINIMUM SPANNING TREE
// ============================================================
//
// Algorithm:
//
// Step 1:
// Edges ko sort karo.
//
// Step 2:
// Har node ke liye set banao.
//
// Step 3:
// Har edge ko process karo.
//
// Step 4:
// Agar dono nodes ke parent alag hain,
// to edge MST me add karo.
//
// Step 5:
// Union operation perform karo.
//
// ============================================================

int minimumSpanningTree(vector<vector<int>> &edges, int n) {

    // Sort according to weight

    sort(edges.begin(), edges.end(), cmp);

    // Parent array

    vector<int> parent(n);

    // Rank array

    vector<int> rank(n);

    // Initialize DSU

    makeSet(parent, rank, n);

    int minWeight = 0;

    // Traverse all edges
    for (int i = 0; i < edges.size(); i++) {

        int u = findParent(parent, edges[i][0]);

        int v = findParent(parent, edges[i][1]);

        int w = edges[i][2];

        // Agar parent different hain
        // to cycle nahi banegi

        if (u != v) {

            // MST me edge add karo

            minWeight += w;

            // Dono sets ko merge karo

            UnionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}