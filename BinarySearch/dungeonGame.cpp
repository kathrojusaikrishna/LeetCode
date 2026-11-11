// problem : Dungeon Game
// Level : Hard
//platform: Leetcode
// Time complexity : O(mnLog(s))
// space complexity : O(mn)

class Solution{
public:
    bool isPossible(long long health, vector<vector<int>>& dun){
        int m = dun.size();
        int n = dun[0].size();

        vector<vector<long long>>dp(m,vector<long long>(n,-1));

        dp[0][0] = health + dun[0][0];
        if(dp[0][0]<=0)return false;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                long long best = -1;
                if(i==0 && j==0)continue;

                if(i>0 && dp[i-1][j]>0){
                    best = max(best,dp[i-1][j]);
                }
                if(j>0 && dp[i][j-1]>0){
                    best = max(best, dp[i][j-1]);
                }

                if(best >0 ){
                    dp[i][j] = best + dun[i][j];
                }
            }
        }
        return dp[m-1][n-1]>0;

    }
    int calculateMinimumHP(vector<vector<int>>& dun){

        int m = dun.size();
        int n = dun[0].size();

        long long low = 1;
        long long high = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dun[i][j]<0){
                    high += -(long long)dun[i][j];
                }
            }
        }

        while(low <= high){
            long long mid = low + (high-low)/2;

            if(isPossible(mid,dun)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};