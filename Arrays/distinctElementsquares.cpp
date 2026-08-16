// Problem: Subarrays distinct element sum of squares I
// Difficulty: Easy
// Platform : Leetcode
// Approach: Bruteforce + hashset
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int>st;
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                ans += (st.size() * st.size());
            }

            st.clear();
        }
        return ans;
    }
};