// Problem: Perfect squares
// Difficulty: Medium
//platform: Leetcode
// Approach: using DP 
// Time: O(n*sqrt(n))
// Space: O(n) -> for dp

class Solution{
public:
    int numSquares(int n){

        vector<int>dp(n+1,1e9);
        dp[0]=0;

        for(int rem=1;rem<=n;rem++){
            for(int j=1;j*j<=rem;j++){
                
                dp[rem] = min(dp[rem], 1+dp[rem-j*j]);
            }
        }

        return dp[n];
    }
};

// class Solution {
// public:
//     vector<int>dp;

//     int solve(int rem, vector<int>& nums){
//         int m = nums.size();
//         if(rem<0)return 1e9;
//         if(rem==0)return 0;

//         if(dp[rem]!=-1){
//             return dp[rem];
//         }

//         int ans=1e9;
//         for(auto& x : nums){
//             if(x<= rem){
//                 ans = min(ans, 1+solve(rem-x,nums));
//             }
//         }

//         return dp[rem] = ans;
//     }
//     int numSquares(int n) {

//         vector<int>sq;
//         for(int i=1;i*i<=n;i++){
//             sq.push_back(i*i);
//         }


//         dp.assign(n+1,-1);

//         return solve(n,sq);
//     }
// };
