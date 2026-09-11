// Problem: Min cost path with k turns
// Difficulty: Hard
//platform: Leetcode
// Approach: Dijkstras
// Time: O(mnklog(mnk))
// Space: O(mnk)

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;

        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>>pq;

        vector<vector<vector<vector<int>>>>dist(m,vector<vector<vector<int>>>(n,vector<vector<int>>(k+1,vector<int>(5,INF))));

        dist[0][0][0][4] = grid[0][0];

        pq.push({grid[0][0],0,0,0,4});

        while(!pq.empty()){
            auto p  = pq.top();
            pq.pop();
            int cost = p[0];
            int row = p[1];
            int col = p[2];
            int turns = p[3];
            int dir = p[4];

            if(cost != dist[row][col][turns][dir])continue;
            if(turns > k)continue;

            if(row==m-1 && col==n-1)return cost;

            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

            for(int i=0;i<4;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n){

                    int newTurns = turns;

                    if(dir!=4 && dir!=i){
                        newTurns++;
                    }
                    if(newTurns > k)continue;

                    int newCost = cost+grid[nr][nc];
                    
                    if(newCost < dist[nr][nc][newTurns][i]){
                        dist[nr][nc][newTurns][i] = newCost;

                        pq.push({newCost,nr,nc,newTurns,i});
                    }
                }
            }

        }

        return -1;
    }
};