// Problem: Minimum difficulty of a job schedule
// Difficulty: Hard
//platform: Leetcode
// Approach: Dp
// Time: O(n^2 * d)
// Space: O(n)

class Solution {
public:
    
    vector<vector<int>>dp;
    int solve(int level, int d, vector<int>& jobDifficulty){
        
        int n = jobDifficulty.size();

        //base case
        if(d==0){
            return level==n ? 0 : 1e9;
        }

        if(n-level < d)return 1e9;
        //cache check
        if(dp[level][d]!=-1){
            return dp[level][d];
        }

        //compute 
        int ans = 1e9;
        int maxi=0;

        for(int i=level; i<= n-d;i++){
            maxi = max(maxi, jobDifficulty[i]);

            int remaining = solve(i+1,d-1,jobDifficulty);

            ans = min(ans, remaining+maxi);
        }

        //save and return
        return dp[level][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if(d > n){
            return -1;
        }

        dp.assign(n,vector<int>(d+1,-1));

        return solve(0,d,jobDifficulty);


    }
};