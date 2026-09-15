// Problem: Best time to buy and sell stock II
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n)
// Space: O(n) -> for dp

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int level, int buy, vector<int>& prices){

        if(level==prices.size())return 0;

        if(dp[level][buy]!=-1){
            return dp[level][buy];
        }
        int ans =0;
        if(buy){
            ans = max(ans, -prices[level] + solve(level+1,0,prices));
            ans = max(ans, solve(level+1,1,prices));

        }else{

            ans = max(ans, prices[level] + solve(level+1,1,prices));
            ans = max(ans, solve(level+1,0,prices));

        }

        return dp[level][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.assign(n,vector<int>(2,-1));
        return solve(0,1,prices);
    }
};