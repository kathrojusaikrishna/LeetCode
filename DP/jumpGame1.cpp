// Problem: Jump game 1
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*max(nums))
// Space: O(n)


class Solution {
public:
    vector<int>dp;
    int solve(int level, vector<int>& nums){

        //base case
        if(level == nums.size()-1)return true;

        //cache
        if(dp[level]!=-1){
            return dp[level];
        }

        //compute

        for(int i=1;i<=nums[level];i++){
            if(level+i < nums.size()){
                if(solve(level+i,nums)){
                    return true;
                }
            }
        }

        //save and return
        return dp[level] = false;
    }
    bool canJump(vector<int>& nums) {
        //your code goes here

        int n = nums.size();

        dp.assign(n+1,-1);

        int ans= solve(0,nums);
        return ans==-1 ? false : ans;
    }
};