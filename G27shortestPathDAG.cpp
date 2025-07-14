// shortest path in directed acyclic graph
// prepare toposort stack
// pop node and compare adj elements weight/distance
// if dist is min update it

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<pair<int, int>>>& adj) {
        vis[node] = 1;  // Mark as visited (in current path)
        for (auto it : adj[node]) {
            if (vis[it.first] == 1) return true; // Cycle detected
            if (vis[it.first] == 0 && dfs(it.first, vis, st, adj)) return true;
        }
        vis[node] = 2;  // Mark as fully processed
        st.push(node);
        return false;
    }

    stack<int> topo_sort(int V, vector<vector<pair<int, int>>> &adj) {
      vector<int> vis(V, 0);  // 0=unvisited, 1=in current path, 2=processed
      stack<int> st, empty;
      for (int i = 0; i < V; i++) {
          if (!vis[i] && dfs(i, vis, st, adj)) {
              return empty; // Return empty stack if cycle detected
          }
      }

      return st;
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
      // node: neighbor, weight
      vector<vector<pair<int, int>>> adj(V);
      for (auto i: edges) {
        int u = i[0];
        int v = i[1];
        int w = i[2];
        adj[u].push_back({v, w});
      }

    // topo sort
    stack<int> st = topo_sort(V, adj);
    if (st.empty()) return {};

    // poping nodes and dist check
    vector<int> dist(V, INT_MAX);
    dist[0] = 0; // setting starting node as 0 CAN CHANGE THIS ACCORDING TO THE QUESTION
    while(!st.empty()) {
      int node = st.top();
      st.pop();
      int curr_dist = dist[node];
      if (curr_dist == INT_MAX) continue;

      for (auto it: adj[node]) {
        // it : {1, 3}, {2, 4} {neighbor, weight}
        int next = it.first;
        int weight = it.second;

        if (curr_dist + weight < dist[next]) {
          dist[next] = curr_dist + weight;
        }
      }
    }

    // if any node is impossible to reach set -1
    for (int i=0; i<V; i++) {
      if (dist[i] == INT_MAX) dist[i] = -1;
    }

    return dist;
  }
};

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edges(E, vector<int>(3));
  for (int i=0; i<E; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }
  Solution sol;
  vector<int> res = sol.shortestPath(V, E, edges);
  for (int i = 0; i < V; i++) cout << res[i] << " ";
  cout << endl;
}

/*
10
24
0 2 6
0 3 7
0 4 9
0 6 8
0 7 6
1 2 6
1 3 7
1 5 10
1 6 1
1 7 4
2 3 3
2 6 10
2 8 8
2 9 10
3 5 3
3 6 10
3 7 5
5 6 9
5 7 7
6 7 7
6 8 8
6 9 8
7 9 1
8 9 6

*/