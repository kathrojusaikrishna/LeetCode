// Problem: Flood fill
// Difficulty: Easy
//platform: Leetcode
// Approach: Dfs
// Time: O(n*m)
// Space: O(n*m) - visited array

class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& vis, int sr, int sc,int start, int color ){
        
        vis[sr][sc]=true;
        image[sr][sc]=color;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];

            if(nr>=0 && nr < image.size() && nc >=0 && nc<image[0].size() && image[nr][nc]==start && !vis[nr][nc]){
                dfs(image,vis,nr,nc,start,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n,false));

        dfs(image,vis,sr,sc,image[sr][sc],color);

        return image;
    }
};