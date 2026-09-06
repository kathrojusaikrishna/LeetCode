// Problem: Number of distinct subsequence which equals t
// Difficulty: Hard
//platform: Leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, string& s, string& t){
        //number of distinct subsequences from [L..N]


        //base case

        if(j==t.size())return 1;
        if(i==s.size())return 0;

        //cache
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //compute
        int ans =0;

        ans += solve(i+1,j,s,t);
        if(s[i]==t[j]){
            ans += solve(i+1,j+1,s,t);
        }

        //save and return
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        if(s.size()<t.size())return 0;

        int n = s.size();
        int m = t.size();

        dp.assign(n,vector<int>(m,-1));

        return solve(0,0,s,t);


    }
};