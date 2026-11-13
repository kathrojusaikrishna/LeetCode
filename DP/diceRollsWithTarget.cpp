// Problem: Dice rolls with target
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*target)
// Space: O(n*target)

class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int MOD = 1e9+7;
    int solve(int dice, int target, int k){
        if(dice==n+1){
            return target==0;
        }
        if(target<0)return 0;

        if(dp[dice][target]!=-1){
            return dp[dice][target];
        }

        int ans=0;
        
        for(int i=1;i<=k;i++){
            ans = (ans+solve(dice+1, target-i,k))%MOD;
        }

        return dp[dice][target] = ans%MOD;
    }
    int numRollsToTarget(int n, int k, int target) {

        this->n = n;
        dp.assign(n+2,vector<int>(target+1,-1));

        return solve(1,target,k);
    }
};