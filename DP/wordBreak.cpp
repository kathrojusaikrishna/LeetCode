// Problem: word break
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        vector<int>dp(n+1,0);
        unordered_set<string>f(wordDict.begin(),wordDict.end());

        dp[0]=true;

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && f.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[n];
    }
};