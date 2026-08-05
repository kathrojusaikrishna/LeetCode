// Problem: Kosaraju for strongly connected components
// Difficulty: Medium
//platform: No source
// Approach: DFS traversal + reverse + dfs traversal
// Time: O(V+E)
// Space: O(V+E) - for reversed adj list

class Solution {
  public:
    void dfs1(int node, vector<vector<int>>& adj, stack<int>& st, vector<bool>& vis){
        vis[node]=true;
        
        for(auto& v : adj[node]){
            if(!vis[v]){
                dfs1(v,adj,st,vis);
            }
        }
        
        st.push(node);
    }
    
    void dfs2(int node, vector<vector<int>>& rev, vector<bool>& vis){
        vis[node]=true;
        
        for(auto& v : rev[node]){
            if(!vis[v]){
                dfs2(v,rev,vis);
            }
        }
    }
    vector<vector<int>> tarjans(int n, vector<vector<int>>& adj) {
        // code here
        
        stack<int>st;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs1(i,adj,st,vis);
            }
        }
        
        vector<vector<int>>rev(n);
        
        for(int i=0;i<n;i++){
            
            for(auto& v : adj[i]){
                rev[v].push_back(i);
            }
        }
        
        vis.assign(n,false);
        int scc=0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(vis[node])continue;
            
            dfs2(node,rev,vis);
            scc++;
        }
        
        return scc;
    }
};