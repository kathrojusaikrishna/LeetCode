// Problem: Minimum falling path sum
// Difficulty: Medium
//platform: Leetcode
// Approach: Dp
// Time: O(n^2 )
// Space: O(n*n)

class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<bool>>visited;
    int solve(int i, int j,vector<vector<int>>& mat){

        if(j<0 || j>=mat.size())return 1e9;
        if(i==mat.size())return 0;

        if(visited[i][j]){
            return dp[i][j];
        }

        int ans = 1e9;
        visited[i][j] = true;
        ans = min(ans, mat[i][j] + solve(i+1,j+1,mat));
        ans = min(ans, mat[i][j] + solve(i+1,j-1,mat));
        ans = min(ans, mat[i][j] + solve(i+1,j,mat));

        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {

        int n = mat.size();

        visited.assign(n,vector<bool>(n,false));
        dp.assign(n,vector<int>(n,0));

        int mini = INT_MAX;

        for(int j=0;j<n;j++){
            mini = min(mini, solve(0,j,mat));
        }
        return mini;
    }
};