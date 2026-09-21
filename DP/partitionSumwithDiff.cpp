// Problem: Partition sum with difference
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*sum)
// Space: O(n*sum) -> for dp

class Solution {
  public:
    vector<vector<int>>dp;
    
    int solve(int level, int sum1, int total,vector<int>& arr, int diff){
        //pruning
        
        if(level > arr.size())return 0;
        //base case
        if(level==arr.size()){
            int sum2 = total - sum1;
            
            return sum1-sum2==diff;
        }
        
        //cache check
        if(dp[level][sum1]!=-1){
            return dp[level][sum1];
        }
        //compute
        int ans = 0;
        
        ans += solve(level+1,sum1,total,arr,diff);
        ans += solve(level+1,sum1+arr[level], total, arr, diff);
        
        //save and return 
        return dp[level][sum1] = ans;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum=0;
        for(auto& x : arr)sum += x;
        dp.assign(n+1,vector<int>(sum+1,-1));
        
        return solve(0,0,sum,arr,diff);
    }
};