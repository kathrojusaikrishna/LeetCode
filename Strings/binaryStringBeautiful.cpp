// Problem: Minimum changes to make binary string beautiful
// Difficulty: Medium
// Platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1) 

class Solution {
public:
    int minChanges(string s) {

        int ans=0;
        int n = s.size();
        for(int i=0;i<n;i+=2){
            int zero=0;
            int one=0;

            if(s[i]=='0')zero++;
            else one++;

            if(s[i+1]=='0')zero++;
            else one++;

            if(zero==1 || one==1)ans++;
        }
        return ans;
    }
};