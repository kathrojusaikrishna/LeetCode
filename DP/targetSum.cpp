// Problem: Target sum
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*2002)
// Space: O(n*2002)

class Solution {
public:
    vector<vector<int>>dp;

    int solve(int level, int sum, vector<int>& nums, int& target){
        //sum equals target
        //pruning

        //base case
        if(level == nums.size()){
            if(sum==target)return 1;
            else return 0;
        }

        // cache
        if(dp[level][sum+1000]!=-1){
            return dp[level][sum+1000];
        }
        //compute
        int ans=0;
        ans += solve(level+1,sum+nums[level],nums,target);
        ans += solve(level+1,sum-nums[level],nums,target);

        //save and return
        return dp[level][sum+1000] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum=0;
        for(auto& x : nums)sum += x;
        dp.assign(n,vector<int>(2001+1,-1));

        return solve(0,0,nums,target);
    }
};