// Problem: Ones and zeros
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(s*m*n)
// Space: O(s*m*n) -> for dp


class Solution{
public:
    int findMaxForm(vector<string>& strs, int m, int n){
        int s = strs.size();
        vector<vector<vector<int>>>dp(s+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));


        for(int i=s-1;i>=0;i--){
            int zeros=0;
            int ones=0;
            for(auto& x : strs[i]){
                if(x=='0')zeros++;
                if(x=='1')ones++;
            }
            for(int z=0;z<=m;z++){
                for(int o=0;o<=n;o++){
                    
                    int ans =0;

                    ans = max(ans, dp[i+1][z][o]);

                    if(zeros<=z && ones<=o){
                        ans = max(ans, 1 + dp[i+1][z-zeros][o-ones]);
                    }

                    dp[i][z][o] = ans;


                }
            }
        }

        return dp[0][m][n];
    }
};


// class Solution {
// public:
//     vector<vector<vector<int>>>dp;

//     int solve(int level, int m, int n, vector<string>& strs){
//         int s = strs.size();
//         if(level==s)return 0;
//         if(m<0 || n<0)return -1e9;

//         if(dp[level][m][n]!=-1){
//             return dp[level][m][n];
//         }

//         int ans =0;
//         ans = max(ans, solve(level+1,m,n,strs));
//         int ones=0;
//         int zeros=0;
//         for(auto& x : strs[level]){
//             if(x=='0')zeros++;
//             if(x=='1')ones++;
//         }
//         if(zeros<=m && ones<=n){
//             ans = max(ans, 1+solve(level+1,m-zeros,n-ones,strs));
//         }

//         return dp[level][m][n] =ans;
//     }
//     int findMaxForm(vector<string>& strs, int m, int n) {

//         int s = strs.size();
//         dp.assign(s,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
//         return solve(0,m,n,strs);
//     }
// };