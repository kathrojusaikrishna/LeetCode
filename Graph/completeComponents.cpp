// Problem: count the number of complete components
// Difficulty: Medium
//platform: Leetcode
// Approach: DFS traversal and comparing the actual edges count with found ones.
// Time: O(V+E)
// Space: O(V+E)

class Solution {
public:
    pair<int,int> dfs(vector<vector<int>>& adj, vector<bool>& vis, int node){

        int nodes=0;
        int edges=0;
        vis[node]=true;
        nodes ++;

        edges += adj[node].size();

        for(auto &v : adj[node]){
            if(!vis[v]){
                auto child = dfs(adj,vis,v);
                nodes += child.first;
                edges += child.second;
            }
        }

        return {nodes,edges};

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        int ans=0;
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                auto [ nodes, edges ] = dfs(adj,vis,i);
                long long total = 1LL * nodes * (nodes-1)/2;
                if(total == edges/2)ans++;
            }

        }

        return ans;
    }
};