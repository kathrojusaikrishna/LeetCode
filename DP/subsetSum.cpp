// Problem: Subset sum problem
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: DP
// Time: O(n*sum)
// Space: O(n*sum) -> for dp

class Solution {
  public:
    vector<vector<int>>dp;
    
    int solve(int level, int left,vector<int>& arr, int n){
        
        //pruning
        if(left < 0){
            return 0;
        }
        //base case
        if(left==0){
            return 1;
        }
        if(level==n){
            return 0;
        }
        //caching
        
        if(dp[level][left]!=-1){
            return dp[level][left];
        }
        //compute
        int ans=0;
        if(solve(level+1,left,arr,n)){
            ans = 1;
        }else if(solve(level+1,left-arr[level],arr,n)){
            ans = 1;
        }
        //save and return
        return dp[level][left] = ans;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        dp.assign(n+1,vector<int>(sum+1,-1));
        return solve(0,sum,arr,n);
    }
};