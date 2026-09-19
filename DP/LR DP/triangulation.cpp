// Problem: Minimum Score Triangulation of Polygon
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*n*n)
// Space: O(n*n)

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, vector<int>& values){
        //pruning

        //base case
        if(j-i <2)return 0;

        //cache check
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //compute
        int ans = 1e9;
        for(int k=i+1;k<j;k++){

            int cost = solve(i,k,values)+solve(k,j,values)+values[i]*values[k]*values[j];

            ans = min(ans, cost);
        }

        //save and return
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) { 

        int n = values.size();

        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,values);  
    }
};