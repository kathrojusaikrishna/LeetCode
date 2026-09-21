// Problem: maximize the cut segments
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using DP - form 1
// Time: O(n)
// Space: O(n) -> for dp

class Solution {
  public:
    vector<int>dp;
    
    int solve(int sum, int n, int x, int y, int z){
        
        //pruning
        if(sum > n)return -1e9;
        //base case
        
        if(n==0)return 0;
        if(sum==n)return 0;
        
        //cache check
        if(dp[sum]!=-1){
            return dp[sum];
        }
        
        //compute
        int ans =-1e9;
        
        ans = max(ans,1+solve(sum+x,n,x,y,z));
        ans = max(ans,1+solve(sum+y,n,x,y,z));
        ans = max(ans,1+ solve(sum+z,n,x,y,z));
        
        //save and return
        return dp[sum] = ans;
    }
    int maximizeCuts(int n, int x, int y, int z) {
        // code here
        dp.assign(n+1,-1);
        
        int ans = solve(0,n,x,y,z);
        return ans < 0 ? 0 : ans;
        
        
    }
};