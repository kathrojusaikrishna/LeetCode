// Problem: Cheapest flight with atmost k stops
// Difficulty: Medium
//platform: Leetcode
// Approach: Modified Dijkstras algo
// Time: O(ElogV)
// Space: O(n*k)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        for (auto& e : flights) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            adj[u].push_back({v, cost});
        }

        pq.push({0, src, 0});
        dist[src][0] = 0;

        while (!pq.empty()) {

            auto current = pq.top();
            pq.pop();

            int cost = current[0];
            int node = current[1];
            int stops = current[2];

            if (cost > dist[node][stops])
                continue;

            for (auto& [nextNode, nextCost] : adj[node]) {

                if (stops + 1 < k + 2) {
                    if (cost + nextCost < dist[nextNode][stops + 1]) {
                        dist[nextNode][stops + 1] = cost + nextCost;

                        pq.push(
                            {dist[nextNode][stops + 1], nextNode, stops + 1});
                    }
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < k + 2; i++) {
            ans = min(ans, dist[dst][i]);
        }

        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};