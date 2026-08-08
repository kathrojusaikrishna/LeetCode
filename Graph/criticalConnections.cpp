// Problem: Critical Connections
// Difficulty: Hard
//platform: Leetcode
// Approach: Tarjans method
// Time: O(V+E)
// Space: O(V+E)

class Solution {
public:

    void dfs(int node, int parent, vector<vector<int>>& adj,vector<int>& disc, vector<int>& low, int& timer, vector<vector<int>>& ans){

        disc[node]=low[node]=timer++;

        for(auto& v : adj[node]){
            if(v==parent)continue;
            if(disc[v]==-1){

                dfs(v,node,adj,disc,low,timer,ans);

                low[node] = min(low[node],low[v]);

                if(low[v] > disc[node]){
                    ans.push_back({node,v});
                }
            }else{
                low[node] = min(low[node],disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> disc(n,-1), low(n,0);
        int timer=0;

        vector<vector<int>>ans;

        for (auto& e : connections) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if(disc[i]==-1){
                dfs(i,-1,adj,disc,low,timer, ans);
            }
        }

        return ans;

    }
};