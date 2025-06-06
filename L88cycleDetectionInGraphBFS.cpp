#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

// queue
// child-parent
// visited bool

bool cycleDetection(vector<vector<int>> &edges, int n, int m)
{ // no of node, no of edges
  // create adjancy list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}