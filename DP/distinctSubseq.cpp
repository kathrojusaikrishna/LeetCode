// Problem: Number of distinct non empty subsequences II
// Difficulty: Hard
//platform: Leetcode
// Approach: DP
// Time: O(n)
// Space: O(n) 

class Solution {
public:
    int distinctSubseqII(string s) {

        const int MOD = 1e9+7; 
        int n = s.size();

        vector<int>dp(n+1,-1);
        vector<int>last(26,-1);

        dp[0] = 1;

        for(int i=0;i<n;i++){
            int x = s[i]-'a';

            dp[i+1] = 2*dp[i] % MOD;
            if(last[x]>=0){
                dp[i+1] -= dp[last[x]];
                dp[i+1] %= MOD;

            }
            last[x]=i;
        }
        dp[n]--;
        if(dp[n]<0){
            dp[n] += MOD;
        }

       return  dp[n];
    }
};