// Problem: Min cost Stairs
// Difficulty: Easy
//platform: Leetcode
// Approach: Dp
// Time: O(n)
// Space: O(1)




// class Solution {
// public:
//     int f(int i, vector<int>& cost, vector<int>& dp){
//         if(i==0)return cost[0];
//         if(i==1)return cost[1];

//         if(dp[i]!=-1)return dp[i];

//         return dp[i] = min(f(i-1,cost,dp),f(i-2,cost,dp))+cost[i];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
        
//         int n = cost.size();
//         vector<int>dp(n,-1);

//         return min(f(n-1,cost,dp),f(n-2,cost,dp));
//     }
// };

// class Solution{
// public:
//    int minCostClimbingStairs(vector<int>& cost){

//     int n = cost.size();
//     vector<int>dp(n,-1);

//     for(int i=0;i<n;i++){
//         if(i<=1)dp[i]=cost[i];
//         else{
//             dp[i] = min(dp[i-1],dp[i-2])+cost[i];
//         }
//     }

//     return min(dp[n-1],dp[n-2]);
//    }
// };

class Solution{
public:
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        int prev2 = cost[0];
        int prev = cost[1];

        for(int i=2;i<n;i++){
            int curr = min(prev,prev2) + cost[i];
            prev2 = prev;
            prev = curr;
        }

        return min(prev,prev2);
    }
};