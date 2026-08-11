// Problem: Min number of days to disconnect islands
// Difficulty: Hard
//platform: Leetcode
// Approach: ans ->{0,1,2}-try removing each cell and find islands
// Time: O(N) N-> n^2
// Space: O(N) N-> n^2

class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row,
             int col) {
        vis[row][col] = true;

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == 1 && !vis[nr][nc]) {
                dfs(grid, vis, nr, nc);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(grid, vis, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

public:
    int minDays(vector<vector<int>>& grid) {

        int islands = countIslands(grid);
        if (islands == 0 || islands > 1)
            return 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int islands = countIslands(grid);
                    if (islands > 1 || islands==0)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};