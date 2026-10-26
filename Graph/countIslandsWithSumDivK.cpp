// Problem: Count the islands with sum divisible by k
// Difficulty: Medium
//platform: Leetcode
// Approach: Connected components
// Time: O(n*n)
// Space: O(n*n) 

class Solution {
public:
    long long solve(int row, int col,vector<vector<int>>& grid, vector<vector<bool>>& vis){

        vis[row][col]=true;

        long long ans=grid[row][col];
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]>0){
                ans += solve(nr,nc,grid,vis);
            }
        }
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));   

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]>0){
                   (solve(i,j,grid,vis)%k==0) ? ans++ : ans+=0;
                }
            }
        }
        return ans;
    }
};