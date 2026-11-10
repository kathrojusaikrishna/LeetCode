// Problem: Longest increasing path in grid
// Difficulty: Hard
//platform: Leetcode
// Approach: using DP
// Time: O(n*m)
// Space: O(n*m) -> for dp


class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=1;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int k=0;k<4;k++){
            
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr<0 || nr>m-1 || nc<0 || nc>n-1)continue;

            if(mat[nr][nc]>mat[i][j]){
                ans = max(ans, 1+solve(nr,nc,mat));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        dp.assign(m,vector<int>(n,-1));
        
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, solve(i,j,mat));
            }
        }
        return ans;
    }
};
