// Problem: Longest increasing path
// Difficulty: Hard
//platform: Geeksforgeeks
// Approach: using DP
// Time: O(n*m)
// Space: O(n*m) -> for dp

class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int i, int j,vector<vector<int>> &mat){
        //pruning
        
        //base case
        
        //cache
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //compute
        int ans = 1;
        
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr = i+dr[k];
            int nc = j + dc[k];
            
            if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && mat[nr][nc]>mat[i][j]){
                ans = max(ans,1+solve(nr,nc,mat));
            }
        }
        
        //save and return
        return dp[i][j] = ans;
    }
    int longIncPath(vector<vector<int>> &mat, int n, int m) {
        // code here
        
        dp.assign(n,vector<int>(m,-1));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,solve(i,j,mat));
            }
        }
        
        return ans;
        
    }
};