// Problem: LCS
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string& text1, string& text2) {
        // longest common subsequence from A[i..N] and B[j..M].
        // pruning

        // base case
        if (i >= text1.size() || j >= text2.size())
            return 0;
        // caching
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // compute
        int ans = 0;
        ans = max(ans, solve(i + 1, j, text1, text2));
        ans = max(ans, solve(i, j + 1, text1, text2));
        if (text1[i] == text2[j]) {
            ans = max(ans, 1 + solve(i + 1, j + 1, text1, text2));
        }

        // save and return
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        dp.assign(n, vector<int>(m, -1));

        return solve(0, 0, text1, text2);
    }
};