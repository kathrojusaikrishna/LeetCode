// Problem: Jump game 2
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*max(nums))
// Space: O(n)


class Solution {
public:
    vector<int>dp;
    
    int solve(int level, vector<int>& nums){
        //min jumps to reach [L...N]
        //pruning

        if(level >= nums.size())return 1e9;

        //base case
        if(level == nums.size()-1)return 0;

        //caching
        if(dp[level]!=-1){
            return dp[level];
        }
        //compute
        int ans = 1e9;
        for(int step=1;step<=nums[level];step++){
            ans = min(ans, 1 + solve(level+step,nums));
        }

        //save and return
        return dp[level] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,-1);

        int ans = solve(0,nums);

        return ans >= 1e9 ? -1 :ans;

    }
};