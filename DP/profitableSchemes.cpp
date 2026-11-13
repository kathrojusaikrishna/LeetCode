// Problem: Profitable schemes
// Difficulty: Hard
//platform: Leetcode
// Approach: using DP 
// Time: O(n*m*minProfit)
// Space: O(n*m*minProfit) -> for dp

class Solution {
public:
    vector<vector<vector<int>>>dp;
    int minProfit;
    vector<int>group;
    vector<int>profit;
    int n;
    int MOD = 1e9+7;

    int solve(int level, int curr, int people){

        int m = group.size();
        if(level==m)return curr >= minProfit;


        if(dp[level][people][curr]!=-1){
            return dp[level][people][curr];
        }

        int ans=0;

        ans += (solve(level+1,curr,people))%MOD;
        if(people + group[level] <= n){
            int newP = min(minProfit, curr + profit[level]);
            ans += solve(level+1,newP,people+group[level])%MOD;
        }

        return dp[level][people][curr] =( ans)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        this->minProfit = minProfit;
        this->group = group;
        this->profit = profit;
        this->n = n;

        int m = group.size();

        dp.assign(m,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));

        return solve(0,0,0);
    }
};