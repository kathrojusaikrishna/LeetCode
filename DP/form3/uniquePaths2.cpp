// Problem: Unique paths II
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>>dp;
    const int MOD = 2*1e9;
    int solve(int i, int j, vector<vector<int>>& grid){
        //pruning
        if(i<0 || i>= grid.size() || j<0 || j>= grid[0].size())return 0;
        if(grid[i][j]==1)return 0;

        //base case
        if(i==grid.size()-1 && j==grid[0].size()-1)return 1;

        //cache
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //compute
        int ans=0;
        ans += (solve(i+1,j,grid))%MOD;
        ans += (solve(i,j+1,grid))%MOD;

        //save and return
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n,vector<int>(m,-1));

        return solve(0,0,grid);
    }
};