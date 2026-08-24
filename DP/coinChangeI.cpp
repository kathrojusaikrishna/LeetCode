// Problem: Coins change I
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*amount)
// Space: O(n*amount)

class Solution {
public:
    vector<vector<int>>dp;

    int solve(int level, int left,vector<int>& coins){
        //min steps for the sum from [L...N]
        //pruning
        if(level==coins.size())return 1e9;
        //base case
        if(left==0)return 0;

        //caching
        if(dp[level][left]!=-1){
            return dp[level][left];
        }
        //compute
        int ans =0;
        int dont = solve(level+1,left, coins);

        int take = 1e9;
        if(coins[level] <= left){
            take = 1 + solve(level,left-coins[level],coins);
        }
        ans = min(take,dont);

        return dp[level][left] = ans;
        //save and return


    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        int ans = solve(0,amount,coins);
        return ans>=1e9? -1 :ans;
    }
};