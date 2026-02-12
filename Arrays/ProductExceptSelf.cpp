// Problem: Product Array Except self
// Difficulty: Medium
// Approach: Prefix and Suffix method
// Time: O(n)
// Space: O(n)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int prefix = 1;
        int suffix = 1;

        //preffix
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        //suffix
        for(int i=n-2 ; i>=0 ; i--){
            suffix *= nums[i+1];
            ans[i] *=suffix;
        }

        return ans;
    }
};