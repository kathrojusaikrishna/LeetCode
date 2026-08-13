// Problem: Pacific and Atlantic water flow
// Difficulty: Medium
//platform: Leetcode
// Approach: dfs + connected components
// Time: O(m*n)
// Space: O(m*n)

class Solution {
private:
    
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& vis, int row, int col){

        vis[row][col]=true;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && !vis[nr][nc] && heights[nr][nc] >= heights[row][col]){
                dfs(heights,vis,nr,nc);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m= heights.size();
        int n = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0) && !pacific[i][j]){
                    dfs(heights,pacific,i,j);
                }
                if((i==m-1 || j==n-1) && !atlantic[i][j]){
                    dfs(heights,atlantic,i,j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

        
    }
};