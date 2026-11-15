// Problem: Add digits
// Difficulty: Easy
// Platform: Leetcode
// Approach: direct formula - wikipedia
// Time: O(1)
// Space: O(1) 

class Solution {
public:
    int addDigits(int num) {

        if(num==0)return 0;

        return 1 + ((num-1)%(9));

    }
};