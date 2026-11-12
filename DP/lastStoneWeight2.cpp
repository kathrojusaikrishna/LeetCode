// Problem: Last stone weight 2
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*sum)
// Space: O(n*sum)

class Solution {
public:
    vector<vector<int>>dp;

    int solve(int level, int sum, int total, vector<int>& stones){
        int n = stones.size();

        if(sum>total/2)return 1e9;
        if(level==n){
            if(sum <=total/2){
                int second = total - sum;
                return abs(sum-second);
            }else{
                return 1e9;
            }
        }

        if(dp[level][sum]!=-1){
            return dp[level][sum];
        }

        int ans = 1e9;

        ans = min(ans, solve(level+1,sum,total,stones));
        ans = min(ans, solve(level+1,sum+stones[level],total,stones));

        return dp[level][sum] = ans;

    }
    int lastStoneWeightII(vector<int>& stones) {

        int n = stones.size();
        int sum=0;
        for(auto& x : stones)sum += x;
        dp.assign(n,vector<int>(sum+1,-1));

        return solve(0,0,sum,stones);
    }
};