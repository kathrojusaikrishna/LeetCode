// Problem: Frog Jump
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: DP
// Time: O(n)
// Space: O(1) 


class Solution {
  public:
    // int f(int i, vector<int>& height, vector<int>& dp){
        
    //     if(i==0)return 0;
    //     if(i==1)return abs(height[1]-height[0]);
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
        
    //     return dp[i] = min(f(i-1,height,dp)+abs(height[i]-height[i-1]), f(i-2,height,dp)+abs(height[i]-height[i-2]));
    // }
    
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        // vector<int>dp(n,-1);
        
        // return f(n-1,height, dp);
        
        // dp[0]=0;
        // dp[1] = abs(height[1]-height[0]);
        
        // for(int i=2;i<n;i++){
        //     dp[i] = min(dp[i-1]+ abs(height[i]-height[i-1]), dp[i-2]+abs(height[i]-height[i-2]));
            
        // }
        // return dp[n-1];
        
        int prev2=0;
        int prev1 = abs(height[1]-height[0]);
        
        if(n==1)return prev2;
        else if(n==2)return prev1;
        else{
            for(int i=2;i<n;i++){
            int curr = min(prev1 + abs(height[i]-height[i-1]), prev2 + abs(height[i]-height[i-2]));
            
            prev2 = prev1;
            prev1 = curr;
                
            }
        }
        
        return prev1;
        
        
        
    }
};