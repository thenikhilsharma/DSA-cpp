// Disjoint Set | Union by rank and Path Compression
// Time Complexity: O(α(N)), where α is the inverse Ackermann function
// Space Complexity: O(N)
// findParent(), Union() -> rank & size
/*
pseudo code
1. find ultimate parent of u and v (pu, pv)
2. find rank of ultimate rank
3. connect smaller rank to larger rank always
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> rank, parent, size;
  public:
    DisjointSet(int n) {
      rank.resize(n+1, 0);
      parent.resize(n+1);
      size.resize(n+1);
      for (int i=0; i<=n; i++) {
        parent[i] = i;
        size[i] = 1;
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
      }
      else if (rank[ultimate_parent_v] < rank[ultimate_parent_u]) {
        parent[ultimate_parent_v] = ultimate_parent_u;
      } else {
        parent[ultimate_parent_u] = ultimate_parent_v;
        rank[ultimate_parent_u]++;
      }
    }
    void unionBySize(int u, int v) {
      int ultimate_parent_u = findUPar(u);
      int ultimate_parent_v = findUPar(v);
      if (ultimate_parent_u == ultimate_parent_v) return;
      if (size[ultimate_parent_u] < size[ultimate_parent_v]) {
        parent[ultimate_parent_u] = ultimate_parent_v;
        size[ultimate_parent_v] += size[ultimate_parent_u];
      } else {
        parent[ultimate_parent_v] = ultimate_parent_u;
        size[ultimate_parent_u] += size[ultimate_parent_v];
      }
    }
};

int main() {
  DisjointSet ds(7);
  ds.unionBySize(1, 2);
  ds.unionBySize(2, 3);
  ds.unionBySize(4, 5);
  ds.unionBySize(6, 7);
  ds.unionBySize(5, 6);

  if (ds.findUPar(3) == ds.findUPar(7)) cout << 1 << endl;
  else cout << 0 << endl;
  
  ds.unionBySize(3, 7);

  if (ds.findUPar(3) == ds.findUPar(7)) cout << 1 << endl;
  else cout << 0 << endl;
}