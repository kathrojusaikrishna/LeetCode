// Problem: edit distance
// Difficulty: Medium
//platform: Leetcode
// Approach: DP - form 3
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, string word1, string word2){
        //pruning
        //base case
        if(i==word1.size()){
            return word2.size()-j;
        }
        if(j==word2.size()){
            return word1.size()-i;
        }

        //cache check
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //compute
        if(word1[i]==word2[j]){
            return dp[i][j] = solve(i+1,j+1,word1,word2);
        }
        int ans = 1e9;

        ans = min(ans, 1+ solve(i,j+1,word1,word2));
        ans = min(ans, 1+solve(i+1,j,word1,word2));
        ans = min(ans, 1+solve(i+1,j+1,word1,word2));

        //save and return
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        
        dp.assign(word1.size(), vector<int>(word2.size(),-1));

        int ans = solve(0,0,word1, word2);

        return ans==1e9 ? 0 : ans;
    }
};