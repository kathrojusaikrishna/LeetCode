// Problem: Maximum area of island
// Difficulty: Medium
//platform: Leetcode
// Approach: connected components + return type
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:

    int dfs(vector<vector<bool>>& vis, int row, int col, vector<vector<int>>& grid){

        vis[row][col]=true;

        int up= (row>0 && grid[row-1][col] && !vis[row-1][col]) ? dfs(vis,row-1,col,grid) : 0;
        int down = (row<grid.size()-1 && grid[row+1][col] && !vis[row+1][col]) ? dfs(vis,row+1,col,grid) : 0;
        int left = (col>0 && grid[row][col-1] && !vis[row][col-1]) ? dfs(vis,row,col-1,grid) : 0;
        int right=(col<grid[0].size()-1 && grid[row][col+1] && !vis[row][col+1]) ? dfs(vis,row,col+1,grid) : 0;

        return 1 + up+ left+down + right;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans =0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans = max(ans,dfs(vis,i,j,grid));
                }
            }
        }

        return ans;
    }
};