// Problem: Bridge Detection
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: standard bridge algorithm
// Time: O(V+E)
// Space: O(V+E)

class Solution {
  public:
  
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, int& timer){
        
        disc[node]=low[node]=timer++;
        for(auto& v : adj[node]){
            if(v==parent)continue;
            if(disc[v]==-1){
                dfs(v,node, adj,disc,low,timer);
                low[node] = min(low[node],low[v]);
            }else{
                low[node] = min(low[node],disc[v]);
            }
        }
    }
    bool isBridge(int n, vector<vector<int>> &edges, int c, int d) {
        // Code here
        
        vector<vector<int>>adj(n);
        vector<int>disc(n,-1),low(n,0);
        int timer=0;
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(i,-1,adj,disc,low,timer);
            }
        }
        
        if(disc[c]>disc[d]){
            return low[c] > disc[d];
        }else{
            return low[d] > disc[c];
        }
    }
};