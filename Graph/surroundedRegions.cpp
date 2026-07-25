// Problem: Surrounded Regions
// Difficulty: Medium
//platform: Leetcode
// Approach: Connected components + simple dfs on border with 'O'
// Time: O(n*m)
// Space: O(n*m) 


class Solution {
public:
   
    void dfs(vector<vector<char>>& board , vector<vector<bool>>& vis, int row, int col){

        vis[row][col]=true;

        int dr[]= {-1,1,0,0};
        int dc[]={0,0,-1,1};

        for(int i=0;i<4;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && !vis[nr][nc] &&board[nr][nc]=='O'){
                dfs(board, vis, nr, nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n,false));


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){
                    dfs(board,vis,i,j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j=='O']){
                    board[i][j]='X';
                }
            }
        }
    }
};