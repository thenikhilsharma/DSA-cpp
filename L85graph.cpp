#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class graph
{

public:
  unordered_map<int, list<int>> adj;

  void addEdge(int u, int v, bool direction)
  {
    // 0 for undirected 1 for directed graph

    // create an edge from u to v
    adj[u].push_back(v);
    // v from u can only be created when direction == 0
    if (direction == 0)
    {
      adj[v].push_back(u);
    }
  }

  void printAdjList()
  {
    for (auto i : adj)
    {
      cout << i.first << "-> ";
      for (auto j : i.second)
      {
        cout << i.second << " ";
      }
    }
    cout << endl;
  }
};

int main()
{
  int n, m; // no. of nodes, edges
  cout << "Enter the no. of Nodes and Edges: ";
  cin >> n >> m;
  int u, v;
  graph g;

  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    g.addEdge(u, v, 0);
  }
  g.printAdjList();

  return 0;
}