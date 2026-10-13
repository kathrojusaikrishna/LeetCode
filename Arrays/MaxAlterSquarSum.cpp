// Problem: Maximum alternating squared sum
// Difficulty: Medium
// Platform: Leetcode
// Approach: square , sort , subtract , add
// Time: O(nlogn)
// Space: O(1)

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        long long ans=0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(),nums.end());

        for(int i=0;i<n/2;i++){
            ans -= nums[i];
        }
        for(int i=n/2;i<n;i++){
            ans += nums[i];
        }
        return ans;

    }
};