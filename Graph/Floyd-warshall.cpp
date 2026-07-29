// Problem: Floyd-warshall
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: standard floyd warshall algorithm
// Time: O(V*V*V)
// Space: O(1)

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        
        const int INF = 1e8;
        int n = dist.size();
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    
                    if(dist[i][k]!=INF && dist[k][j]!=INF){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    
    }
};