// Problem: Longest cycle in a graph
// Difficulty: Hard
//platform: Leetcode
// Approach: topo to remove unwanted nodes, and find longest by doing dfs to find the cycle
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> inDegree(n, 0);
        vector<bool> vis(n, false);
        int ans = -1;

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                inDegree[edges[i]]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (edges[node] != -1) {
                inDegree[edges[node]]--;
                if (inDegree[edges[node]] == 0)
                    q.push(edges[node]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (inDegree[i] > 0 && !vis[i]) {
                int curr = i;
                int len = 0;
                while(!vis[curr]){
                    vis[curr]=true;
                    len++;
                    curr = edges[curr];
                }
                ans = max(ans,len);
            }
        }

        return ans;
    }
};