#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& f : flights) {
            adj[f[0]].emplace_back(f[1], f[2]);
        }

        // Min-heap: {total_price, node, stops_used}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        // To store the minimum stops needed to reach each node
        vector<int> min_stops(n, INT_MAX);

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int price = curr[0], node = curr[1], stops = curr[2];

            // If we reached destination, return price
            if (node == dst) return price;

            // If we've used all stops or found a better path with fewer stops
            if (stops > k || stops >= min_stops[node]) continue;

            min_stops[node] = stops;

            // Explore neighbors
            for (const auto& [neighbor, cost] : adj[node]) {
                pq.push({price + cost, neighbor, stops + 1});
            }
        }

        return -1;
    }
};