// Problem: Path with minimum effort 
// Difficulty: Medium
//platform: Leetcode
// Approach: Modified Dijkstras algo
// Time: O(n*m)
// Space: O(n*m) - distance matrix

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        priority_queue< vector<int>,vector<vector<int>>, greater<vector<int>>>pq;

        dist[0][0]=0;

        pq.push({0,0,0});

        while(!pq.empty()){

            auto current = pq.top();
            pq.pop();

            int effort = current[0];
            int row = current[1];
            int col = current[2];

            if(effort > dist[row][col])continue;

            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

            for(int i=0;i<4;i++){

                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc < m){

                    int newEffort = max(effort, abs(heights[row][col] - heights[nr][nc]));

                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;

                        pq.push({dist[nr][nc], nr, nc});
                    }
                   
                }
            }
        }

        return dist[n-1][m-1];

    }
};