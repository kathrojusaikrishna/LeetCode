// Problem: Combination sum 4
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*target)
// Space: O(target)

class Solution {
public:
    vector<int> dp;

    int solve(int target, vector<int>& nums) {
        int n = nums.size();

        if(target==0)return 1;
        if(target<0)return 0;

        if(dp[target]!=-1){
            return dp[target];
        }

        int ans=0;

        for(auto& x : nums){
            if(target-x>=0){
                ans += solve(target-x,nums);
            }
        }

        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {

        int n = nums.size();
        dp.assign(target+1,-1);

        return solve(target, nums);
    }
};