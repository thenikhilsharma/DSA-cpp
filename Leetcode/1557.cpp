// 1557. Minimum Number of Vertices to Reach All Nodes

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> inDegree(n, 0), res;
    for (const auto& edge : edges) inDegree[edge[1]]++; // calc in degree
    for (int i = 0; i < n; i++) { // if in degree == 0 -> ANS.PUSH_BACK
      if (inDegree[i] == 0) res.push_back(i);
    }
    return res;
  }
};

int main() {
  int n = 6;
  vector<vector<int>> edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};
  Solution sol;
  vector<int> res = sol.findSmallestSetOfVertices(n, edges);
  for (int i=0; i<res.size(); i++) {
    cout << res[i] << " ";
  }
}