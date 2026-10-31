// Problem: Twisted mirror count paths
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(m*n(m+n))
// Space: O(m*n)

class Solution {
public:
    const int MOD = 1e9 + 7;

    int m, n;
    vector<vector<int>> dp;

    vector<vector<int>> grid;

    int solve(int i, int j) {

        if (i >= m || j >= n) return 0;

        if (i == m-1 && j == n-1) return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;


        int dr[] = {0, 1};
        int dc[] = {1, 0};

        for (int k = 0; k < 2; k++) {

            int ni = i + dr[k];
            int nj = j + dc[k];

            int r = dr[k];
            int c = dc[k];


            while (ni < m && nj < n &&
                   grid[ni][nj] == 1 &&
                   !(ni == m-1 && nj == n-1)) {

                
                if (r == 0) {
                    r = 1;
                    c = 0;
                }
                else {
                    r = 0;
                    c = 1;
                }

                ni += r;
                nj += c;
            }

            ans = (ans + solve(ni, nj)) % MOD;
        }

        return dp[i][j] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        this->grid = grid;

        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0);
    }
};