// Problem: reverse the degree of a string
// Difficulty: Easy
//platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int reverseDegree(string s) {
        
        int ans =0;
        for(int i=0;i<s.size();i++){
            ans += (26-(s[i]-'a'))*(i+1);
        }

        return ans;
    }
};