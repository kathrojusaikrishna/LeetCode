// Problem: Find the difference
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration
// Time: O(max(s,t))
// Space: O(1) 


class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        for(auto& ch : s)ans += (ch-'a');

        for(auto& ch : t){
            ans -= (ch-'a');
        }
        return abs(ans) + 'a';
    }
};