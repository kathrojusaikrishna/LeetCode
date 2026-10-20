// Problem: Third maximum element
// Difficulty: Easy
// Platform: Leetcode
// Approach: sort + set
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        unordered_set<int>st;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        if(n<3)return nums[n-1];
        
        int i=n-1;
        int ans = INT_MAX;
        while(i>=0 && st.size()<3){
            st.insert(nums[i]);
            ans = min(ans,nums[i]);
            i--;
        }
        return st.size()==3 ? ans : nums[n-1];
    }
};