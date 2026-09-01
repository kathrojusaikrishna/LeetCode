// Problem: Minimum moves to clean the classroom
// Difficulty: Medium
//platform: Leetcode
// Approach: BFS
// Time: O(n*m*e*2^L)
// Space: O(n*m*e*2^L)

class Solution {
public:
    int minMoves(vector<string>& grid, int energy) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int sr=-1;
        int sc=-1;
        int lcount=0;

        vector<vector<int>>id(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                if(grid[i][j]=='L'){
                    id[i][j]=lcount++;
                }
            }
        }

        int fullmask = (1 << lcount)-1;

        queue<tuple<int,int,int,int>>q;

        //[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>>vis(m,vector<vector<vector<bool>>>(n,vector<vector<bool>>(energy+1,vector<bool>(1 << lcount,false))));

        q.push({sr,sc,energy,0});
        vis[sr][sc][energy][0]=true;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        int moves=0;
        while(!q.empty()){
            int size = q.size();

            while(size--){

                auto [r,c,e,mask] = q.front();
                q.pop();

                if(mask == fullmask)return moves;
                for(int i=0;i<4;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr<0 || nr>=m || nc<0 || nc>=n)continue;

                    if(grid[nr][nc]=='X')continue;

                    if(e==0)continue;

                    int newmask = mask;
                    int ne = e-1;
                    if(grid[nr][nc]=='L'){
                        newmask |= (1<<id[nr][nc]);
                    }

                    if(grid[nr][nc]=='R'){
                        ne = energy;
                    }

                    if(!vis[nr][nc][ne][newmask]){
                        vis[nr][nc][ne][newmask]=true;
                        q.push({nr,nc,ne,newmask});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};