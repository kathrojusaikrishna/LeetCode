// Problem: Triangle
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*n)
// Space: O(n*n)

class Solution {
public:
    
    vector<vector<int>>dp;
    vector<vector<bool>>visited;
    int solve(int i, int j,vector<vector<int>>& t){

        if(i>t.size())return 1e9;
        if(i==t.size()){
            return 0;
        }

        if(visited[i][j]){
            return dp[i][j];
        }

        int ans = 1e9;

        visited[i][j] = true;
        ans = min(ans, t[i][j] + solve(i+1,j,t));
        ans = min(ans, t[i][j] + solve(i+1,j+1,t));

        return dp[i][j] = ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();

        dp.assign(n,vector<int>(n,0));
        visited.assign(n,vector<bool>(n,false));

        return solve(0,0,triangle);
    }
};