// Problem: Number of enclavs
// Difficulty: Medium
//platform: Leetcode
// Approach: Connected components + simple dfs on border with '1'
// Time: O(n*m)
// Space: O(n*m) 

class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col){

        vis[row][col]=true;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr>=0 && nr<grid.size() && nc>=0 && nc <grid[0].size() && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(grid, vis, nr,nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int ans=0;

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1){
                    dfs(grid,vis,i,j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1)ans++;
            }
        }

        return ans;
    }
};