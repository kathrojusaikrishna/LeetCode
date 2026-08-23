// Problem: Partition sum
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*sum)
// Space: O(n*sum) -> for dp

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int level , int left, vector<int>& nums, int n){

        //pruning
        if(left <0)return 0;

        //base case
        if(left==0)return 1;
        if(level==n)return 0;

        //caching
        if(dp[level][left]!=-1){
            return dp[level][left];
        }

        //compute
        int ans=0;

        //skip
        if(solve(level+1,left,nums,n)){
            return 1;
        }else if(solve(level+1,left-nums[level],nums,n)){
            return 1;
        }

        //save and return
        return dp[level][left]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n= nums.size();
        for(auto& x : nums){
            sum += x;
        }
        if(sum%2!=0)return false;
        else{
            dp.assign(n+1,vector<int>(sum/2+1,-1));
            return solve(0,sum/2,nums,n);
        }
    }
};