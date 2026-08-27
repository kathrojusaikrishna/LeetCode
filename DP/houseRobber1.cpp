// Problem: House Robber I
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n)
// Space: O(1)

class Solution{
public:
    int rob(vector<int>& nums){

        int n = nums.size();
        vector<int>dp(n,-1);

        dp[0]=nums[0];

        if(n>1){
            dp[1] = max(nums[0],nums[1]);
            for(int i=2;i<n;i++){
                dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            }
        }

        return dp[n-1];
    }
};


// class Solution {
// public:

//     int f(int i, vector<int>& dp, vector<int>& nums){

//         if(i==0)return nums[0];

//         if(i==1){
//             return max(nums[0],nums[1]);
//         }

//         if(dp[i]!=-1){
//             return dp[i];
//         }

//         return dp[i] = max(f(i-1,dp,nums),f(i-2,dp,nums)+nums[i]);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n,-1);

//         return f(n-1,dp,nums);

//     }
// };