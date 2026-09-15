// Problem: Maximum number of non-overlapping palindromic substrings
// Difficulty: Hard
//platform: Leetcode
// Approach: DP
// Time: O(n*n)
// Space: O(n*n) -> for dp

class Solution {
public:
    vector<int>dp;
    vector<vector<int>>pl;
    bool isPalindrome(int l, int r, string& s){

        //base case
        if(l>=r)return true;

        //cache
        if(pl[l][r]!=-1){
            return pl[l][r];
        }
        //compute

        if(s[l]!=s[r]) return pl[l][r] = false;
        return pl[l][r] = isPalindrome(l+1,r-1,s);
        //save and return 
    }
    int solve(int level, string& s, int k){
        //pruning
        if(level > s.size())return 0;

        //base case
        if(level==s.size())return 0;

        //cache
        if(dp[level]!=-1){
            return dp[level];
        }

        //compute
        int ans=0;
        ans = max(ans, solve(level+1,s,k));

        for(int j=level+k-1;j<s.size();j++){

            if(isPalindrome(level,j,s)){

                ans = max(ans, 1+solve(j+1,s,k));
            }
        }

        //save and return
        return dp[level] = ans;
    }
    int maxPalindromes(string s, int k) {
        
        int n = s.size();

        dp.assign(n+1,-1);
        pl.assign(n,vector<int>(n,-1));

        return solve(0,s,k);
    }
};