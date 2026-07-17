// Problem: Counting bits
// Difficulty: Easy
// Platform: Leetcode
// Approach: Iteration
// Time: O(nlogn)
// Space: O(1)

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int>ans;
        for(int i=0;i<=n;i++){

            int bits = __builtin_popcount(i);
            ans.push_back(bits);
        }

        return ans;
    }
};