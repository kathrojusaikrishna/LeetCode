// Problem: Number of Sets of K Non-Overlapping Line Segments
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*k)
// Space: O(n*k) -> for dp

class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<long long>>dp;
    int solve(int i, int j){

        if(j==0)return 1;
        if(i==0 || j>i)return 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        ans += (solve(i-1,j))%MOD;
        ans += (solve(i-1,j-1))%MOD;

        return dp[i][j] = (ans)%MOD;
    }
    int numberOfSets(int n, int k) {

        int total = n+k-1;
        int need = 2*k;
        dp.assign(total+1,vector<long long>(need+1,-1));
        return solve(total,need);
    }
};