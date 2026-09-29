// Problem: Check if There Is a Valid Parentheses String Path
// Difficulty: Hard
//platform: Leetcode
// Approach: DP
// Time: O(n*m*(n+m))
// Space: O(n*m*(n+m))

class Solution{
public:
    vector<vector<vector<int>>>dp;

    int solve(int i, int j, int total,vector<vector<char>>& grid){
        
        //base case
        if(grid[i][j]=='(')total++;
        if(grid[i][j]==')')total--;

        if(total < 0)return 0;

        if(i==grid.size()-1 && j==grid[0].size()-1){
            return total==0;
        }

        //cache
        if(dp[i][j][total]!=-1){
            return dp[i][j][total];
        }

        //compute
        int ans=0;

        int dr[] = {1,0};
        int dc[] = {0,1};
        for(int k=0;k<2;k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size()){
                ans |= solve(nr,nc,total,grid);
            }
        }

        //save and return
        return dp[i][j][total] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m,vector<vector<int>>(n,vector<int>(n+m,-1)));

        return solve(0,0,0,grid);
    }
};
