// Problem: Bellman-Ford
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: Standard Bellman-ford algo
// Time: O(V*E)
// Space: O(V)

class Solution {
  public:
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
        // Code here
        
        vector<int>dist(n,INT_MAX);
        
        dist[src]=0;
        
        for(int i=1;i<=n-1;i++){
            
            for(auto& e : edges){
                int u = e[0];
                int v = e[1];
                
                int w = e[2];
                
                if(dist[u]!= INT_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        for(auto& e :edges){
            int u = e[0];
            int v = e[1];
            
            int w = e[2];
            
            if(dist[u]!= INT_MAX && dist[u] + w < dist[v]){
                return {-1};
            }
        }
        
        for(auto& d : dist){
            if(d==INT_MAX){
                d = 1e8;
            }
        }
        
        return dist;
        
    }
};
