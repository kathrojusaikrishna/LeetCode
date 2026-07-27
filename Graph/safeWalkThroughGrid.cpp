// Problem: Find a safe walk through grid
// Difficulty: Medium
//platform: Leetcode
// Approach: BFS
// Time: O(n*m)
// Space: O(n*m) - visited matrix

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;

        q.push({0,0});

        vis[0][0]=grid[0][0];

        while(!q.empty()){

            int size = q.size();

            while(size--){

                auto [row,col] = q.front();
                q.pop();

                int dr[] = {-1,1,0,0};
                int dc[] = {0,0,-1,1};

                for(int i=0;i<4;i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if(nr>=0 && nr < m && nc>=0 && nc<n ){

                        int newCost = grid[nr][nc] + vis[row][col];

                        if(newCost < vis[nr][nc]){
                            vis[nr][nc] = newCost;

                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return vis[m-1][n-1] < health;
    }
};