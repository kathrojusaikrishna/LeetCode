// Problem: Negative weight cycle
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: Standard Bellman-ford algo with distance of all as 'zero'
// Time: O(V*E)
// Space: O(V)

class Solution {
  public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        // Code here
        
        vector<int>dist(n,0);
        
        dist[0]=0;
        
        for(int i=1;i<=n-1;i++){
            
            for(auto& e :edges){
                int u = e[0];
                int v = e[1];
                
                int w = e[2];
                
                if(dist[u]+ w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        for(auto& e :  edges){
            int u = e[0];
            int v= e[1];
            int w = e[2];
            
            if(dist[u] + w < dist[v]){
                return 1;
            }
        }
        
        return 0;
    }
};