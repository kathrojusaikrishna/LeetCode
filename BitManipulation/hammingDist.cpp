// Problem: Find hamming distance between x and y
// Difficulty: Easy
// Approach: number of set bits in x^y
// Time: O(1)
// Space: O(1)

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x^y);
    }
};