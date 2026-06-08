class Solution
{
private:
  vector<vector<int>> floydWarshall(int V, vector<vector<int>> &edges)
  {
    int E = edges.size();
    // Initialize distance matrix
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    // Set distance from each vertex to itself as 0
    for (int i = 0; i < V; ++i)
      dist[i][i] = 0;

    // Set distances based on edges
    for (const auto &edge : edges)
    {
      int u = edge[0];
      int v = edge[1];
      int weight = edge[2];
      dist[u][v] = min(dist[u][v], weight); // Handle multiple edges
      dist[v][u] = min(dist[v][u], weight); // If graph is undirected
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k)
    {
      for (int i = 0; i < V; ++i)
      {
        for (int j = 0; j < V; ++j)
        {
          if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
          {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }

    return dist;
  }

public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {
    vector<vector<int>> dist = floydWarshall(n, edges);
    int minCity = n; // Initialize to maximum possible city count
    int ans = -1;    // To store the city index with minimum reachable cities

    for (int i = 0; i < n; ++i)
    {
      int cityCount = 0;
      for (int j = 0; j < n; ++j)
      {
        if (dist[i][j] <= distanceThreshold)
        {
          cityCount++;
        }
      }
      if (cityCount < minCity || (cityCount == minCity && i > ans))
      {
        minCity = cityCount;
        ans = i;
      }
    }
    return ans;
  }
};