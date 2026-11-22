// Problem: Number of dominants
// Difficulty: Easy
// Platform : Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int countDominantElements(vector<int>& nums) {

        int n = nums.size();
        int ans=0;
        if(n==1)return 1;
        for(int i=1;i<n-1;i++){

            double avg = (nums[i-1]+nums[i+1])/2.0;
            if(nums[i] >= avg)ans++;
        }

        if(nums[0]>=nums[1])ans++;
        if(nums[n-1]>=nums[n-2])ans++;

        return ans;
    }
};