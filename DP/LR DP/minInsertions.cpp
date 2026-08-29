// Problem: Minimum insertion steps to make a string palindrome
// Difficulty: Hard
//platform: Leetcode
// Approach: DP
// Time: O(n*n)
// Space: O(n*n)


class Solution {
public:
    vector<vector<int>>dp;

    int solve(int l, int r, string &s){
        //minimum insertions from [L....R]
        //pruning
        if(l>=r)return 0;

        //base case
        if(s[l]==s[r]){
            return dp[l][r] = solve(l+1,r-1,s);
        }
        //cache
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        //compute
        int left = solve(l+1,r,s);
        int right = solve(l,r-1,s);

        //save and return
        return dp[l][r] = 1+min(left,right);
    }
    int minInsertions(string s) {

        int n = s.size();
        dp.assign(n,vector<int>(n,-1));

        return solve(0,n-1,s);
    }
};