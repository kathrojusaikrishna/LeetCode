// Problem: Longest palindromic subsequnce
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*n)
// Space: O(n*n)


class Solution {
public:
    vector<vector<int>>dp;

    int solve(int l, int r, string& s){
        //longeset palindrome from [L...R]
        //pruning
        if(l>r)return 0;

        //base case
        if(l==r)return 1;
        if(s[l]==s[r]) return 2 + solve(l+1,r-1,s);

        //cache
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        //compute
        
        int left = solve(l+1,r,s);
        int right = solve(l,r-1,s);

        //save and return
        return dp[l][r] =max(left,right);
    }
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,n-1,s);
    }
};