// Problem: Minimum score of a path between two cities
// Difficulty: Medium
//platform: Leetcode
// Approach: finding connected component having 1 and finding least score among them.
// Time: O(V+E)
// Space: O(V+E)

class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<bool>&vis){
        vis[node] = true;

        for(auto&[v,w] :adj[node]){
            ans = min(ans,w);
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        vector<bool>vis(n+1,false);

        for(auto&e : roads){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        dfs(1,adj,vis);
        return ans;


    }
};