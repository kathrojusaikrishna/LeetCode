// Problem: Coins change II
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*amount)
// Space: O(n*amount)

class Solution {
public:
    vector<vector<int>>dp;

    int solve(int level, int left, vector<int>& coins){
        //amount left at present level
        //pruning
        if(level==coins.size())return 0;
        if(left <0)return 0;

        //base case
        if(left==0)return 1;

        //caching
        if(dp[level][left]!=-1){
            return dp[level][left];
        }
        //compute
        int ans=0;

        int dont = solve(level,left-coins[level],coins);
        int take = solve(level+1,left,coins);

        ans = take + dont;
        //save and return

        return dp[level][left] = ans;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};