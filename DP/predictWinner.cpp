// Problem: Predict the winner
// Difficulty: Medium
//platform: Leetcode
// Approach: using DP 
// Time: O(n*n)
// Space: O(n*n) -> for dp

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int l, int r,vector<int>& nums){
        //choosing max score in [L....R]

        //pruning
        if(r<l)return 0;
        //base case
        if(l==r)return nums[l];

        //cache
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        //compute
        int ans = 0;
        int left = nums[l] - solve(l+1,r,nums);
        int right = nums[r] - solve(l,r-1,nums);
        ans = max(left,right);

        //save and return
        return dp[l][r] = ans;
    }
    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,n-1,nums)>=0;
        
    }
};