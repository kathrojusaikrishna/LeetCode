// Problem: Number of closed islands
// Difficulty: Medium
//platform: Leetcode
// Approach: number of connected components that doesnt touch the border
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:

    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis, int row, int col ){

        vis[row][col]=true;

        int dr[] ={-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]==0){
                dfs(grid, vis, nr,nc);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int islands=0;

        vector<vector<bool>>vis(n, vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==0){
                    dfs(grid,vis, i, j);
                }
            }
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    dfs(grid,vis,i,j);
                    islands++;
                }
            }
        }

        return islands;
    }
};