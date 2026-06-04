// Problem: Substring with Max Zero-One Diff
// Difficulty: Medium
// Approach: kadanes algo
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int sum=0;
        int ans = INT_MIN;
        for(auto ch : s){
            
            int val = (ch=='0') ? 1 : -1;
            
            sum = max(val,val+sum);
            
            ans = max(ans,sum);
        }
        return ans;
    }
};