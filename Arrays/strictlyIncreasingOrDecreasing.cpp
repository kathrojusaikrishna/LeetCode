// Problem: Longest Strictly Increasing or Strictly Decreasing Subarray
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int ans=1;
        int temp=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])temp++;
            else temp=1;

            ans= max(ans,temp);
        }

        temp=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])temp++;
            else temp=1;

            ans= max(ans,temp);
        }
        return ans;
    }
};