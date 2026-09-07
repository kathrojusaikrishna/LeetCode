// Problem: Min deletion to make the strings same
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, string& word1, string& word2){

        //base case
        if(i>=word1.size() || j>=word2.size()){
            return 0;
        }

        //cache
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //compute
        int ans =0;

        ans = max(ans, solve(i+1,j,word1,word2));
        ans = max(ans, solve(i,j+1,word1, word2));
        if(word1[i]==word2[j]){
            ans = max(ans, 1+solve(i+1,j+1,word1,word2));
        }

        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        dp.assign(n,vector<int>(m,-1));

        int ans = solve(0,0,word1,word2);

        return n+m- 2*ans;
    }
};