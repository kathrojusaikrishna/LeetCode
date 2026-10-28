// Problem: Score of string
// Difficulty: Easy
//platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int scoreOfString(string s) {

        int n = s.size();
        int ans=0;
        for(int i=1;i<n;i++){
            ans += abs((s[i]-'0')-(s[i-1]-'0'));
        }
        return ans;
    }
};