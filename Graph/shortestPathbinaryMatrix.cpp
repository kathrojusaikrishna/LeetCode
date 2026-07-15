// Problem: Shortest path in Binary matrix
// Difficulty: Medium
//platform: Leetcode
// Approach: using queue
// Time: O(n*n)
// Space: O(n*m) - using for visted array

class Solution {
public:

    bool check(int nr, int nc, int rows, int cols){

        if(nr<0 || nr>=rows || nc<0 || nc >= cols)return false;

        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]!=0)return -1;
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        q.push({0,0});

        vis[0][0]=true;
        int steps=1;


        while(!q.empty()){

            int size = q.size();

            while(size--){

                auto [r,c] = q.front();
                q.pop();

                if(r==n-1 && c==n-1)return steps;

                int dr[]={-1,-1,-1,0,0,1,1,1};
                int dc[]={-1,0,1,-1,1,-1,0,1};

                for(int i=0;i<8;i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];

                    if(check(nr,nc,n,m)&& grid[nr][nc]==0 && !vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc]=true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};