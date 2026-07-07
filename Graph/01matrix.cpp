// Problem: 01 Matrix
// Difficulty: Medium
//platform: Leetcode
// Approach: BFS traversal
// Time: O(n*m)
// Space: O(n*m)- queue

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = mat[i][j];

                if (val == 0)
                    q.push({i, j});
                else mat[i][j]=INT_MAX;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    mat[nr][nc] == INT_MAX) {
                    mat[nr][nc] = mat[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
            return mat;
    }

};