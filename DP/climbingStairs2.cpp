// Problem: Climbing stairs 2
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n)
// Space: O(n)

class Solution{
public:
    int climbStairs(int n, vector<int>& costs){

        vector<int>dp(n+1,1e9);
        dp[n]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=3;j++){
                if(i+j<=n){
                    dp[i] = min(dp[i], costs[i+j-1]+j*j+dp[i+j]);
                }
            }
        }
        return dp[0];
    }
};

// class Solution {
// public:
//     vector<int>dp;

//     int solve(int level, int n, vector<int>&costs){
//         if(level==n)return 0;
//         if(level >n)return 1e9;

//         if(dp[level]!=-1){
//             return dp[level];
//         }

//         int ans=1e9;
//         for(int i=1;i<=3;i++){
//             if(level+i<=n){
//                 ans = min(ans, costs[level+i-1]+i*i + solve(level+i,n,costs));
//             }
//         }

//         return dp[level] = ans;
//     }
//     int climbStairs(int n, vector<int>& costs) {

//         dp.assign(n+1,-1);
        
//         return solve(0,n,costs);
//     }
// };