// Problem: Palindromic Substrings
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*n)
// Space: O(n*n)

class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int l, int r, string& s){
        //whether the string from [L...R] is a palindrome
        //pruning
        if(l>=r)return true;

        //cache
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        //compute

        if(s[l]!=s[r])return false;

        //save and return
        return dp[l][r] = s[l]==s[r] && solve(l+1,r-1,s);
    }
    int countSubstrings(string s) {
        int n =s.size();
        dp.assign(n,vector<int>(n,-1));

        int counter=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s))counter++;
            }
        }
        return counter;
    }
};