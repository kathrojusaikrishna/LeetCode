// Problem: Minimum steps by knight
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: BFS
// Time: O(n*n)
// Space: O(n*n)

class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        
        queue<pair<int,int>>q;
        q.push({knightPos[0],knightPos[1]});
        int ans =0;
        
        vector<vector<bool>>vis(n+1,vector<bool>(n+1,false));
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                
                auto node = q.front();
                q.pop();
                
                int row = node.first;
                int col = node.second;
                
                if(row==targetPos[0] && col==targetPos[1])return ans;
                
                int dr[] = {2,2,-2,-2,1,1,-1,-1};
                int dc[] = {1,-1,1,-1,2,-2,2,-2};
                
                for(int i=0;i<8;i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    
                    if(nr>=1 && nr<=n && nc>=1 && nc<=n && !vis[nr][nc]){
                        vis[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
                
            }
            ans++;
        }
    }
};