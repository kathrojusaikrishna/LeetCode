// Problem: Longest increasing subsequence
// Difficulty: Medium
//platform: Leetcode
// Approach: using DP
// Time: O(n*n)
// Space: O(n) -> for dp

class Solution {
public:
    vector<int>dp;

    int solve(int level, vector<int>& nums, int n){
        // best fit at this level.

        //pruning
        if(level < 0)return 0;
        //base case

        //caching
        if(dp[level]!=-1){
            return dp[level];
        }
        //compute
        int ans = 1;
        for(int prev_item = 0;prev_item<level;prev_item++){
            if(nums[prev_item]<nums[level]){
                ans = max(ans,1 + solve(prev_item,nums,n));
            }
        }
        //save and return
        return dp[level] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,-1);
        solve(0,nums ,n);

        int best = 0;
        for(int i=0;i<n;i++){
            best = max(best,solve(i,nums,n));
        }
        return best;
    }
};