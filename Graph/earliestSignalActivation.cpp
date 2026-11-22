// Problem: Earliest signal activation
// Difficulty: Medium
//platform: Leetcode
// Approach: Dijkstras algorithm
// Time: O((V+E)logE)
// Space: O(V+E)

class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges,
                                              vector<int>& requiredSignals) {

        vector<long long> ans(n, -1);

        vector<vector<pair<long long, int>>> adj(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            int delay = e[2];

            adj[u].push_back({v, delay});
        }

        requiredSignals[0]=1;
        pq.push({0, 0});

        while (!pq.empty()) {

            auto [delay, node] = pq.top();
            pq.pop();

            if (ans[node] != -1)
                continue;

            requiredSignals[node]--;

            if(requiredSignals[node]==0){
                ans[node] = delay;
                for(auto [nextNode,nextDelay] : adj[node]){
                    if(ans[nextNode]==-1){
                       pq.push({delay+nextDelay,nextNode});
                    }
                }
            }
        }

        return ans;
    }
};