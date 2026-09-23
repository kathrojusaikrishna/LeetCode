// Problem: Minimum operations to reduce X to zero
// Difficulty: Medium
// Approach: maximum subarray length
// Time: O(n)
// Space: O(1) 

class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
        
        int left=0;
        int ans =0;
        int n = nums.size();
        int total =0;
        int curr=0;
        for(auto& x : nums)total += x;

        int req = total-x;

        for(int right=0;right<n;right++){
            curr += nums[right];

            while(curr > req && left <= right){
                curr -= nums[left];
                left++;
            }

            if(curr==req){
                ans = max(ans, right-left+1);
            }
        }

        if(ans ==0 && ans!=req)return -1;

        return n-ans;
    }
};