// Problem: Path maximum score
// Difficulty: Medium
//platform: Leetcode
// Approach: using DP 
// Time: O(n*m)
// Space: O(n*m) -> for dp

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m =board[0].size();
        const int MOD = 1e9+7;

        vector<vector<int>>dpSum(n,vector<int>(m,INT_MIN));
        vector<vector<int>>dpWays(n,vector<int>(m,0));

        dpSum[0][0]=0;
        dpWays[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X')continue;
                if(i==0 && j==0)continue;

                int curr = 0;
                if(board[i][j]!='E' && board[i][j]!='S'){
                    curr = board[i][j]-'0';
                }

                int best = INT_MIN;
                
                if(i>0)best = max(best,dpSum[i-1][j]);
                if(j>0)best = max(best,dpSum[i][j-1]);
                if(i>0 && j>0)best = max(best, dpSum[i-1][j-1]);

                if(best==INT_MIN)continue;
                dpSum[i][j]=curr+best;

                if(i>0 && dpSum[i-1][j]==best){
                    dpWays[i][j] += (dpWays[i-1][j])%MOD;
                }
                if(j>0 && dpSum[i][j-1]==best){
                    dpWays[i][j] += (dpWays[i][j-1])%MOD;
                }
                if(i>0 && j>0 && dpSum[i-1][j-1]==best){
                    dpWays[i][j] += (dpWays[i-1][j-1])%MOD;
                }

                dpWays[i][j] %=MOD;

            }
        }

        if(dpWays[n-1][m-1]==0){
            return {0,0};
        }

        return {dpSum[n-1][m-1], dpWays[n-1][m-1]};

    }
};