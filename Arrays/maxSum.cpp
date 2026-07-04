// Problem: Maximum total sum of K selected elements
// Difficulty: Medium
// Approach: sorting
// Time: O(nlog n)
// Space: O(1)

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        
        sort(nums.begin(),nums.end());
        long long ans=0;
        int n = nums.size();

        for(int i=n-1;i>=n-k;i--){
            if(mul>1)ans += 1LL*nums[i]*mul;
            else ans += nums[i];

            mul--;
        }

        return ans;
    }
};