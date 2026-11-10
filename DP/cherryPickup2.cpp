// Problem: Cherry pickup 2
// Difficulty: Hard
//platform: Leetcode
// Approach: DP
// Time: O(n*m*m)*9
// Space: O(n*m*m)

class Solution{
public:
    vector<vector<vector<int>>>dp;
    int solve(int i, int j1, int j2,vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();
        if(i==m-1){
            if(j1==j2){
                return grid[i][j1];
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }

        int value = grid[i][j1];
        if(j1!=j2){
            value += grid[i][j2];
        }
        int maxi = 0;
        int dc[] = {-1,0,1};
        for(int k1=0;k1<3;k1++){
            for(int k2=0;k2<3;k2++){
                
                int nc1 = j1 + dc[k1];
                int nc2 = j2 + dc[k2];

                if(nc1<0 || nc1>=n || nc2<0 || nc2>=n)continue;

                maxi = max(maxi, solve(i+1,nc1,nc2,grid));
            }
        }

        return dp[i][j1][j2] = maxi + value;
        
    }
    int cherryPickup(vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m,vector<vector<int>>(n,vector<int>(n,-1)));

        return solve(0,0,n-1,grid);
    }
};

// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {

//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<vector<int>>> dp(
//             m, vector<vector<int>>(n, vector<int>(n, -1e9)));

//         for(int j1=0;j1<n;j1++){
//             for(int j2=0;j2<n;j2++){

//                 if(j1==j2){
//                     dp[m-1][j1][j2] = grid[m-1][j1];
//                 }else{
//                     dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
//                 }
//             }
//         }

//         for(int i=m-2;i>=0;i--){
//             for(int j1=0;j1<n;j1++){
//                 for(int j2=0;j2<n;j2++){

//                     int value = grid[i][j1];
//                     if(j1!=j2){
//                         value += grid[i][j2];
//                     }

//                     int maxi = -1e9;

//                     int dc[] = {-1,0,1};
                    
//                     for(int k1=0;k1<3;k1++){
//                         for(int k2=0;k2<3;k2++){

//                             int nc1 = j1 + dc[k1];
//                             int nc2 = j2 + dc[k2];

//                             if(nc1<0 || nc1>=n || nc2<0 || nc2>=n)continue;

//                             maxi = max(maxi, dp[i+1][nc1][nc2]);
//                         }
//                     }

//                     dp[i][j1][j2] = maxi + value;
//                 }
//             }
//         }
//         return dp[0][0][n-1];
//     }
// };