// Problem: Count commas
// Difficulty: Easy
// Platform: Leetcode
// Approach: if-else
// Time: O(1)
// Space: O(1)

class Solution {
public:
    int countCommas(int n) {
        if(n<1000)return 0;
        return n-999;
    }
};