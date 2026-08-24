// Problem: Minimum path sum
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m) -> for dp

class Solution {
public:
    vector<vector<int>>dp;

    int solve(int r, int c,vector<vector<int>>& grid, int m, int n){
        // max sum ending at this level
        //pruning
        if(r<0 || c<0)return INT_MAX;
        //base case
        if(r==0 && c==0){
            return grid[0][0];
        }
        //caching
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        //compute
        int up = solve(r-1,c,grid,m,n);
        int left = solve(r,c-1,grid,m,n);

        int ans = min(up,left) + grid[r][c];
        //save and return
        return dp[r][c] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m,vector<int>(n,-1));


        return solve(m-1,n-1,grid,m,n);
    }
};