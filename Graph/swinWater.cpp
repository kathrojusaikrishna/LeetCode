// Problem: Swin in rising water
// Difficulty: Hard
//platform: Leetcode
// Approach: Modified Dijkstras algo
// Time: O(n^2logn)
// Space: O(n*n) 

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        priority_queue< vector<int>, vector<vector<int>> ,greater<vector<int>>>pq;

        pq.push({grid[0][0],0,0});
        dist[0][0]=grid[0][0];

        while(!pq.empty()){

            auto current = pq.top();
            pq.pop();

            int time = current[0];
            int row = current[1];
            int col = current[2];

            if(time > dist[row][col])continue;

            int dr[] ={-1,1,0,0};
            int dc[] = {0,0,-1,1};

            for(int i=0;i<4;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr>=0 && nr < n && nc >=0 && nc < m){

                    int maxi = max(time,grid[nr][nc]);

                    if(maxi < dist[nr][nc]){
                        dist[nr][nc] = maxi;

                        pq.push({dist[nr][nc], nr,nc});
                    }
                }
            }
        }

        return dist[n-1][m-1];

        
    }
};