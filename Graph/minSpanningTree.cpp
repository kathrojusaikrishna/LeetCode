// Problem: Minimum spanning tree using prim algo
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: Standard Prim algo
// Time: O(Elogv)
// Space: O(V+E)

class Solution {
  public:
    int spanningTree(int n, vector<vector<int>>& edges) {
        // code here
        
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<bool>vis(n,false);
        
        vector<vector<pair<int,int>>>adj(n);
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        pq.push({0,0});
        
        int weight=0;
        
        while(!pq.empty()){
            
            auto top = pq.top();
            pq.pop();
            
            int wt = top.first;
            int node = top.second;
            
            if(vis[node])continue;
            
            vis[node]=true;
            weight += wt;
            
            for(auto& [nextNode, nextWeight] : adj[node]){
                if(!vis[nextNode]){
                    pq.push({nextWeight,nextNode});
                }
            }
        }
        
        return weight;
    }
};