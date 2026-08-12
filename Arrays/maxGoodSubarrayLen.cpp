// Problem: Length of longest subarray with at most K frequency
// Difficulty: Medium
// platform : Leetcode
// Approach: Slinding window
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int left=0;
        int len=0;
        unordered_map<int,int>a;

        for(int right=0;right < nums.size();right++){
            a[nums[right]]++;

            while(a[nums[right]]>k){
                a[nums[left]]--;
                left++;
            }

            len = max(len, right-left+1);
        }

        return len;
    }
};