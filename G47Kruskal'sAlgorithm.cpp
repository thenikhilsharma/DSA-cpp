// Kruskal's Algorithm
// Time Complexity: O(E log E)
// Space Complexity: O(V + E)
// sort all the edges according to their weights
// use disjoint set to check if adding an edge creates a cycle
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> parent, rank;
  public:
    DisjointSet(int n) {
      rank.resize(n+1, 0);
      parent.resize(n+1);
      for (int i=0; i<=n; i++) {
        parent[i] = i;
      }
    }

    int findUPar(int node) {
      if (node == parent[node]) return node;
      return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
      int ultimate_parent_u = findUPar(u);
      int ultimate_parent_v = findUPar(v);
      if (ultimate_parent_u == ultimate_parent_v) return;
      if (rank[ultimate_parent_u] < rank[ultimate_parent_v]) {
        parent[ultimate_parent_u] = ultimate_parent_v;
      } else if (rank[ultimate_parent_v] < rank[ultimate_parent_u]) {
        parent[ultimate_parent_v] = ultimate_parent_u;
      } else {
        parent[ultimate_parent_u] = ultimate_parent_v;
        rank[ultimate_parent_u]++;
      }
    }
    bool unionBySize(int u, int v) {
      int ultimate_parent_u = findUPar(u);
      int ultimate_parent_v = findUPar(v);
      if (ultimate_parent_u == ultimate_parent_v) return false;
      parent[ultimate_parent_u] = ultimate_parent_v;
      return true;
    }
};

int main() {
    int n = 6; // Number of vertices
    vector<vector<int>> edges = {
        {1, 4, 1},
        {1, 2, 2},
        {2, 3, 3},
        {2, 4, 3},
        {1, 5, 4},
        {3, 4, 5},
        {2, 6, 7},
        {3, 6, 8},
        {4, 5, 9}
    };

    // Sort edges based on weight
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    DisjointSet ds(n);
    vector<vector<int>> mst; // Minimum Spanning Tree
    int totalWeight = 0;

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        if (ds.unionBySize(u, v)) {
            mst.push_back(edge);
            totalWeight += weight;
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : mst) {
        cout << edge[0] << " -- " << edge[1] << " == " << edge[2] << endl;
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}