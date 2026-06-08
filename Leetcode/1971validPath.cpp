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

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      DisjointSet ds(n);
      for (const auto& edge : edges) {
        ds.unionBySize(edge[0], edge[1]);
      }

      return ds.findUPar(source) == ds.findUPar(destination);
    }
};