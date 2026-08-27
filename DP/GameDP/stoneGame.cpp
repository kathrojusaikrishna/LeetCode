// Problem: Stone game
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(1)
// Space: O(1)


class Solution{
public:
    bool stoneGame(vector<int>& piles){
        return true;
    }
};

// class Solution {
// public:
//     vector<vector<int>>dp;
//     int solve(int l, int r, vector<int>& piles){
//         //max score found in [L...R]

//         //pruning
//         if(l>r)return 0;

//         //basecase
//         if(l==r){
//             return piles[l];
//         }

//         //cache
//         if(dp[l][r]!=-1){
//             return dp[l][r];
//         }

//         int ans=0;

//         int left = piles[l] - solve(l+1,r,piles);
//         int right = piles[r] - solve(l,r-1,piles);

//         ans = max(left,right);

//         return dp[l][r] = ans;
//     }
//     bool stoneGame(vector<int>& piles) {
//         int n = piles.size();

//         dp.assign(n,vector<int>(n,-1));

//         return solve(0,n-1,piles)>0;
//     }
// };
