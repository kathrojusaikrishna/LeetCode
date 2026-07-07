// Problem: No of Islands
// Difficulty: Medium
//platform: Leetcode
// Approach: Connected components
// Time: O(n*n)
// Space: O(n*n)

class Solution {
public:

    void dfs(vector<vector<bool>>& vis, int row, int col,vector<vector<char>>& grid){
        vis[row][col]=true;

        if(row>0 && grid[row-1][col]=='1' && !vis[row-1][col]){
            dfs(vis, row-1,col,grid);
        }

        if(row<grid.size()-1 && grid[row+1][col]=='1' && !vis[row+1][col]){
            dfs(vis, row+1,col,grid);
        }

        if(col>0 && grid[row][col-1]=='1' && !vis[row][col-1]){
            dfs(vis, row,col-1,grid);
        }

        if(col<grid[0].size()-1 && grid[row][col+1]=='1' && !vis[row][col+1]){
            dfs(vis, row,col+1,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands =0;

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    islands++;
                    dfs(vis,i,j,grid);
                }
            }
        }
        return islands;
    }
};