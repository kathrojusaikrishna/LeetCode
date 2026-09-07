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

    int solve(int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n)return 0;
        //base case
        if(i==m-1 && j==n-1)return 1;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans =0;

        ans += (solve(i+1,j,m,n))%MOD;
        ans += (solve(i,j+1,m,n))%MOD;

        return dp[i][j] = ans;
    }
    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n,-1));

        return solve(0,0,m,n);
    }
};