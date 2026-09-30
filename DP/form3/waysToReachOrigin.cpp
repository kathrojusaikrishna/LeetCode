// Problem: Count ways to reach origin
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: DP
// Time: O(x*y)
// Space: O(x*y)

class Solution {
  public:
    vector<vector<int>>dp;
    const int MOD = 1e9+7;
    int solve(int i, int j, int x, int y){
        //pruning
        if(i>x || j>y)return 0;
        //basecase
        if(i==x && j==y){
            return 1;
        }
        //cache
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        //compute
        int ans=0;
        ans += (solve(i+1,j,x,y))%MOD;
        ans += (solve(i,j+1,x,y))%MOD;
        
        //save and return
        return dp[i][j] = (ans)%MOD;
        
    }
    int ways(int x, int y) {
        // code here
        dp.assign(x+1,vector<int>(y+1,-1));
        
        return solve(0,0,x,y);
    }
};