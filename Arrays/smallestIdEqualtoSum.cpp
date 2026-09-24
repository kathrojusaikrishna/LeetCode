// Problem: Smallest index with sum of digtis equal to the index
// Difficulty: Easy
// Platform: Leetcode
// Approach: brute force
// Time: O(n*MaxLen(num))
// Space: O(1)

class Solution {
public:
    int solve(int num){
        int ans =0;

        while(num>0){
            int digit = num%10;
            ans += digit;
            num /= 10;
        }

        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(solve(nums[i])==i)return i;
        }
        return -1;
    }
};