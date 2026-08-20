// Problem: To Lower
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1) 

class Solution {
public:
    string toLowerCase(string s) {
        
        for(int i=0;i<s.size();i++){
            s[i] = tolower(s[i]);
        }

        return s;
    }
};